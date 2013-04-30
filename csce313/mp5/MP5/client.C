 /* 
    File: simpleclient.C

    Author: Doug Lasater
            Department of Computer Science
            Texas A&M University
    Date  : 2013/04/27

    Simple client main program for MP5 in CSCE 313
*/

/*--------------------------------------------------------------------------*/
/* DEFINES */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/
#include <cassert>
#include <cstring>
#include <errno.h>
#include <iostream>
#include <queue>
#include <string>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <unistd.h>
#include <vector>

#include "NetworkRequestChannel.H"
#include "semaphore.H"

using namespace std;

/*--------------------------------------------------------------------------*/
/* DATA STRUCTURES */ 
/*--------------------------------------------------------------------------*/
class Item
{
private:
    int request_id;
    string request_data;
    
public:
    Item(string _rd, int _rid = 0)
    {
        request_id = _rid;
        request_data = _rd;
    
    }
    Item(){}
	
	~Item(){}
	
	string get_data() { return request_data; }
	int get_id() { return request_id; }
	
	void set_request_id(int id) {request_id = id;}
	void set_request_data(string _data) {request_data = _data;}
};


class BoundedBuffer 
{
private:
	Semaphore * LOCK;				// Binary Semaphore
	Semaphore * FULL_SLOTS;			
	Semaphore * EMPTY_SLOTS;
	
    long maxSize;
    

public:

queue<Item> bound_buffer;

    BoundedBuffer(int _size)
    {
        maxSize = _size;
		LOCK = new Semaphore(1);
		FULL_SLOTS = new Semaphore(0);
		EMPTY_SLOTS = new Semaphore(maxSize);
        
    }
    BoundedBuffer(){}
    
    void deposit_item(Item _item)
    {
		EMPTY_SLOTS->P();
		LOCK->P();
		bound_buffer.push(_item);
		LOCK->V();
		FULL_SLOTS->V();
       
    }

    Item * retrieve_item()
	{
		FULL_SLOTS->P();
		LOCK->P();
		
		Item *return_item = new Item;			
		*return_item = bound_buffer.front();	// get item from queue
		bound_buffer.pop();						// delete item from queue
		
		LOCK->V();
		EMPTY_SLOTS->V();
		
		return return_item;
	
	}
    
	void setMaxSize(int size) { maxSize = size; }
	int size() {return (int)bound_buffer.size(); }
    


};


struct timeval tp_start1; /* Used to compute elapsed time. */
struct timeval tp_end1;

/*--------------------------------------------------------------------------*/
/* 	Global Variables */
/*--------------------------------------------------------------------------*/
BoundedBuffer bb;
BoundedBuffer stat_buffer;


int data_requests_per_person = 0;
int num_request_channels = 0;


pthread_t joes_thread;
pthread_t janes_thread;
pthread_t johns_thread;

pthread_t stat_thread_1;
pthread_t stat_thread_2;
pthread_t stat_thread_3;

vector<NetworkRequestChannel*> channels;
int * written_names;

Semaphore * PRINT;

// Statistcs Arrays for Each Person
//	- Server returns values between 0 and 99 
//	- Store the number of times the value i was returned in the ith position
//	- Ex: every time the server returns 10 to Joe, joes_stats[10] is incremented by 1 
long joes_stats[100];
long janes_stats[100];
long johns_stats[100];



/*--------------------------------------------------------------------------*/
/* Helper Functions
/*--------------------------------------------------------------------------*/

// Description:
// function takes in an item , then sends that item as a request the ammount of time 
// specified by the user to the Bounded buffer
void * send_Requests(void * _item)
{
	Item *request_item = new Item; 
	*request_item = *((Item*)_item);
	
	
	// send the item to the bounded buffer
	for(int i = 0; i < data_requests_per_person; i++)
    {        
		bb.deposit_item(*request_item);
	}	
    
    // clean up
    delete request_item;
    
    
	// done adding to the buffer, end thread
	pthread_exit(NULL);
	
}

// Description:
// Function makes the seperate threads for each person 
void generate_requests()
{
	for(int i = 0; i < 3; i++)
	{
		Item * itm = new Item;
		itm->set_request_id(i);
		
		
		if(i == 0)			// thread creation for joe smith
		{
			itm->set_request_data("data Joe Smith");

			pthread_create(&joes_thread, NULL, send_Requests, itm);
		}
		
		else if(i == 1)		// thread creation for jane smith
		{
			itm->set_request_data("data Jane Smith");
			pthread_create(&janes_thread, NULL, send_Requests, itm);
		}
		
		else if(i == 2)		// thread creation for john smith
		{
			itm->set_request_data("data John Doe");
            pthread_create(&johns_thread, NULL, send_Requests, itm);
		}
	
	
	}

}


// Description:
// Write the first w items to w request channels (w = num_request_channels)
void write_to_fds()
{

	for(int i = 0; i < num_request_channels; i++)
	{
		Item * requested_item;
		requested_item = bb.retrieve_item();
		
		string dat = requested_item->get_data();
		written_names[i] = requested_item->get_id();
		
		
		channels[i]->cwrite(dat.c_str());
		
		
		// clean up
		delete requested_item;
	}
	
}


// Description:
// loops through the bounded buffer (bb) and removes the items, send the request to the server
// then deposits the item in the stat_buffer
void * worker_requests(void * channel)
{

	
	// Initialization
	write_to_fds();
	
	while(stat_buffer.size() < 3*data_requests_per_person)
	{
		int ready;
		int maxFD = 0;
		fd_set read_set;
		
		
		// Clear Previous File Descriptor Set (read_set) and add all get_fd to read_set
		//FD_ZERO(&read_set);
		for(int i = 0; i < num_request_channels; i++)
		{
			FD_SET(channels[i]->get_fd(), &read_set);
			
		}
		
		// Find the max value of the get_fd
		for(int j = 0; j < num_request_channels; j++)
		{
			if(channels[j]->get_fd() > maxFD)
				maxFD = channels[j]->get_fd();
		}
		
		
		// Process Select Function 
		ready = select( (maxFD + 1) , &read_set, NULL, NULL, NULL);
		
		// Error check
		if(ready == -1)
			break;
		
		for(int i = 0; i < num_request_channels; i++)
		{
			if(FD_ISSET(channels[i]->get_fd(), &read_set))
			{
				
				// Get Reply From Server
				Item* read_itm = new Item;
				string reply = channels[i]->cread();
				
				
				// Now building statistics bounded buffer
				//---------------------------------------
				// 1. Set the data string of the item to the reply from server
				read_itm->set_request_id(written_names[i]);
				read_itm->set_request_data(reply);
				
				// 2. add the item to the stat_buffer
				stat_buffer.deposit_item(*read_itm);
				
				
				// Reuse The Request Channels
				// -----------------------------
				// 1. If there are more requests to be sent
				if(bb.size() > 0)
				{
					// 2. Get another Item from the bounded buffer
					Item* write_itm;
					write_itm = bb.retrieve_item();
					
					string dat = write_itm->get_data();
					written_names[i] = write_itm->get_id();
			
					// 3. Write it's data to this fd 
					channels[i]->cwrite(dat.c_str());
		
				}
				
				// clean up
				delete read_itm;
			}

		}
	}
	
	// clean up: closing all of the request channels 
	for(int i = 0; i < num_request_channels; i++)
	{		
		channels[i]->cwrite("quit");
		usleep(1000);
		delete channels[i];
	}	
	// ending the thread
	pthread_exit(NULL);
	
}


// Description:
// Goes through stat buffer and epties the items into the corresponding array
// 0 for joe, 1 for jane, 2 for john 
void *create_statistics(void * nothing)
{

	while(stat_buffer.size() > 0)
	{
		// maybe use semaphore in here to prevent interrupts
	
		Item * stat_item = new Item;
		stat_item = stat_buffer.retrieve_item();
		
		// turns items data value that was returned by server into an int
		int idx = atoi((stat_item->get_data()).c_str());
		
		if(idx - 1 < 100) 	// make sure the server didnt return a value greater than 100 
		{
			// sort the items based on their id value
			if(stat_item->get_id() == 0)
			{
				joes_stats[idx] += 1;
			}
			else if(stat_item->get_id() == 1)
			{
				janes_stats[idx] += 1;
			}
			else if(stat_item->get_id() == 2)
			{
				johns_stats[idx] += 1;
				
			}
		}
	
		// clean up
        delete stat_item;
	}
	
	// stat_threads are done, end threads
	pthread_exit(NULL);

}


// Description:
// Function creates 3 general threads that are used to remove items from single stat buffer 
void generate_stat_threads()
{

	pthread_create(&stat_thread_1, NULL, create_statistics, NULL);
	pthread_create(&stat_thread_2, NULL, create_statistics, NULL);
	pthread_create(&stat_thread_3, NULL, create_statistics, NULL);

}


// Description:
// print the stats for each person
void print_stats(string name, long * stat_bucket)
{
	int sub_total = 0;
	int total = 0;
	
    cout << "\n";
	cout << "##############################################################" << endl;
	cout << "Statistcs for " << name << " are..." << endl;
    cout << "--------------------------------------------------------------" << endl;
	for(int i = 0; i < 101; i++)
	{
		if(i % 10 == 0 && i !=0)
		{
            if(i != 100)
                total += stat_bucket[i];
            
			cout << "Returned Value:\t" << i - 10 << " to\t" << i - 1 << "\t" << sub_total << " times "
				 << "\t \t (" << (((double)sub_total)/((double)data_requests_per_person))*100  << "%)" << endl;
	
			total += sub_total;
            sub_total = 0;
		}
		
		else
			sub_total += stat_bucket[i];
	
	}
    cout << "--------------------------------------------------------------" << endl;
    cout << "\t Total Replies to " << name << " From Server: " << total << endl;
	cout << "##############################################################" << endl;
	
}


// Description:
// Prints to stdout the difference, in seconds and museconds, between two timevals
void cout_time_diff(struct timeval * tp1, struct timeval * tp2)
 {
	long sec = tp2->tv_sec - tp1->tv_sec;
	long musec = tp2->tv_usec - tp1->tv_usec;
	if (musec < 0) {
	musec += 1000000;
	sec--;
	}
	printf(" [sec = %ld, musec = %ld] \n", sec, musec);

}


/*--------------------------------------------------------------------------*/
/* MAIN FUNCTION */
/*--------------------------------------------------------------------------*/

int main(int argc, char * argv[]) 
{
	int opterr = 0;
	int c;
	int bb_size = 0;
	int portNumber = 11335;
	long stat_size = 0;
	
	string serverHostName = "localHost";
	string temp;
    string quit_string = "";
	PRINT = new Semaphore(1);

	
	while( (c = getopt(argc, argv, "n:b:w:h:p:") ) != -1)
	{
	 switch(c)
	 {
		case 'b':
			bb_size = (atoi(optarg));
			break;
		case 'h':
			temp = optarg;
			if(temp != "")
				serverHostName = temp;
			break;
		case 'n':
			data_requests_per_person = atoi(optarg);
			break;
		case 'p':
			portNumber = atoi(optarg);
			break;
		case 'w':
			num_request_channels = atoi(optarg);
		break;
		 case '?':
			break;
		default:
			abort();
	 
	 }

	} 

    
	// stat_size = 3 people all with data_requests_per_person
	stat_size = 3 * data_requests_per_person;
	
	
	// initialize the buffers 
	bb = BoundedBuffer(bb_size);
	stat_buffer = BoundedBuffer(stat_size);
	
	// initialize fd arrays
	written_names = new int[num_request_channels];
	
	// initialize the threads 
	pthread_t event_handler;

	
	usleep(100000);
	
	// Timing begin 
	assert(gettimeofday(&tp_start1, 0) == 0);			        
	
	
	// make the other pthreads to start the whole shabang
	cout << "Client started...\n" << endl;
	cout << endl;

	// making the request threads
	generate_requests();
  
	usleep(100000); 

	// Creating the NetworkRequestChannels 
	for(int r = 0; r < num_request_channels; r++)
	{
		NetworkRequestChannel* workers_channel = new NetworkRequestChannel(serverHostName, portNumber);
		channels.push_back(workers_channel);
	}
	
	
	// Create and run the event handler thread 
	pthread_create(&event_handler, NULL, worker_requests, NULL);
	
	pthread_join(event_handler, NULL);

	
	// create statistics thread and generate stats 
	generate_stat_threads();
	
	usleep(1000000); 
	
	// print statistics
	print_stats("Joe Smith", joes_stats);
	print_stats("Jane Smith", janes_stats);
	print_stats("John Doe", johns_stats);
	
	// end timing 
   assert(gettimeofday(&tp_end1, 0) == 0); 
	
	// printing timing
	cout << "\nTotal Time to Finish:   ";
	cout_time_diff(&tp_start1, &tp_end1);
	cout << endl; 
	
	usleep(1000000);
	usleep(100);
	
	
	delete PRINT;
	
	return 0;
  
}
