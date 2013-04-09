 /* 
    File: simpleclient.C

    Author: R. Bettati
            Department of Computer Science
            Texas A&M University
    Date  : 2013/01/31

    Simple client main program for MP3 in CSCE 313
*/

/*--------------------------------------------------------------------------*/
/* DEFINES */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/
#include <cassert>
#include <string>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <queue>
#include <errno.h>

#include "reqchannel.H"
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
	Semaphore * LOCK;
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


/*--------------------------------------------------------------------------*/
/* 	Global Variables */
/*--------------------------------------------------------------------------*/
BoundedBuffer bb;
BoundedBuffer stat_buffer;

int data_requests_per_person = 0;
int num_worker_threads = 0;

pthread_t joes_thread;
pthread_t janes_thread;
pthread_t johns_thread;

pthread_t stat_thread_1;
pthread_t stat_thread_2;
pthread_t stat_thread_3;

long joes_stats[100];
long janes_stats[100];
long johns_stats[100];



/*--------------------------------------------------------------------------*/
/* Helper Functions
/*--------------------------------------------------------------------------*/

void * send_Requests(void * _item)
{	// Description:
	// function take in a Package type with a template item type, then sends in the amount of
	// requests specified bu the user to the Bounded buffer
	

	Item *request_item = new Item; 
	*request_item = *((Item*)_item);
	
	
	for(int i = 0; i < data_requests_per_person; i++)
    {        
		bb.deposit_item(*request_item);
	}	
    
    // clean up
    delete request_item;
    
    
	// done adding to the buffer, end thread
	pthread_exit(NULL);
	
}

void generate_requests()
{
	// Description:
	// Function makes the seperate threads for each person 
	for(int i = 0; i < 3; i++)
	{
		Item * itm = new Item;
		itm->set_request_id(i);
		
		
		if(i == 0)			// thread for joe smith
		{
			itm->set_request_data("data Joe Smith");

			pthread_create(&joes_thread, NULL, send_Requests, itm);
		}
		
		else if(i == 1)		// thread for jane smith
		{
			itm->set_request_data("data Jane Smith");
			pthread_create(&janes_thread, NULL, send_Requests, itm);
		}
		
		else if(i == 2)		// thread for john smith
		{
			itm->set_request_data("data John Doe");
            pthread_create(&johns_thread, NULL, send_Requests, itm);
		}
	
	
	}

}





void * worker_requests(void * channel)
{
	// Description:
	// loops through the bounded buffer (bb) and removes the items, send the request to the server
	// then deposits the item in the stat_buffer
	string quit_string = "";
	RequestChannel * worker_channel = (RequestChannel*)channel;

	while(bb.size() > 0)
	{
		Item * requested_item = new Item;
		requested_item = bb.retrieve_item();
	
		string data_request = requested_item->get_data();
		string reply_to_request = (*worker_channel).send_request(data_request);
		
		
		// Now building statistics bounded buffer
		//1. Set the data string of the item to the reply from server
		//2. add the item to the stat_buffer
		
		requested_item->set_request_data(reply_to_request);
		stat_buffer.deposit_item(*requested_item);
        
        // clean up
        delete requested_item;
	}
    
    quit_string = worker_channel->send_request("quit");
    usleep(1000000);
	
}


void *create_statistics(void * nothing)
{
	// Description:
	// Goes through stat buffer and epties the items from there into the corresponding array
	// 0 for joe, 1 for jane, 2 for john

	while(stat_buffer.size() > 0)
	{
		Item * stat_item = new Item;
		stat_item = stat_buffer.retrieve_item();
		
		// turns items data value that was returned by server to int
		int idx = atoi((stat_item->get_data()).c_str());
		
		
		if(idx - 1 < 100) 	// make sure the server didnt return a value greater than 100 
		{
			// sort the items based on their id value
			if(stat_item->get_id() == 0)
			{
				joes_stats[idx - 1] += 1;
			}
			else if(stat_item->get_id() == 1)
			{
				janes_stats[idx - 1] += 1;
			}
			else if(stat_item->get_id() == 2)
			{
				johns_stats[idx - 1] += 1;
				
			}
		}
	
        delete stat_item;
	}
	
	// stat_threads are done, end threads
	pthread_exit(NULL);

}

void generate_stat_threads()
{

	pthread_create(&stat_thread_1, NULL, create_statistics, NULL);
	pthread_create(&stat_thread_2, NULL, create_statistics, NULL);
	pthread_create(&stat_thread_3, NULL, create_statistics, NULL);

}

void print_stats(string name, long * stat_bucket)
{
	// Description:
	// print the stats for each person
	
	int total = 0;
	
    cout << "\n\n";
	cout << "##############################################################" << endl;
	cout << "Statistcs for " << name << " are..." << endl;
    cout << "--------------------------------------------------------------" << endl;
	for(int i = 0; i < 101; i++)
	{
		if(i % 10 == 0 && i !=0)
		{
            if(i != 100)
                total += stat_bucket[i];
            
			cout << "Returned Value:\t" << i - 10 << " to\t" << i - 1 << "\t" << total << " times "
				 << "\t \t (" << (((double)total)/((double)data_requests_per_person))*100  << "%)" << endl;
	
            total = 0;
		}
		
		else
			total += stat_bucket[i];
	
	}
    cout << "--------------------------------------------------------------" << endl;
    cout << endl;
	cout << "############################################################## \n" << endl;
	
}

/*--------------------------------------------------------------------------*/
/* MAIN FUNCTION */
/*--------------------------------------------------------------------------*/

int main(int argc, char * argv[]) 
{
	int opterr = 0;
	int c;
	int bb_size = 0;
	long stat_size = 0;
    string quit_string = "";
    Semaphore * TEMP = new Semaphore(1);

	while( (c = getopt(argc, argv, "n:b:w:") ) != -1)
	{
	 switch(c)
	 {
		case 'b':
			bb_size = (atoi(optarg));
			break;
		case 'n':
			data_requests_per_person = atoi(optarg);
			break;
		case 'w':
			num_worker_threads = atoi(optarg);
		break;
		 case '?':
			break;
		default:
			abort();
	 
	 }

	} 

    
	// stat_size = 3 people with data_requests_per_person
	stat_size = 3 * data_requests_per_person;
	
	
	// initialize the buffers 
	bb = BoundedBuffer(bb_size);
	stat_buffer = BoundedBuffer(stat_size);
	
	
	// initialize the threads 
	pthread_t workers[num_worker_threads];
	pid_t child_pid = fork();

	
	
	if(child_pid == 0)
	{
        usleep(100000);
		// make the other pthreads to start the whole shabang
		cout << "Client started...\n" << endl;
		cout << "Establishing control channel... " << flush;
		cout << endl;
		RequestChannel chan("control", RequestChannel::CLIENT_SIDE);
		cout << "done.\n" << flush;

		// making the request threads
        cout << "*********************************************" << endl;
        cout << "Starting the Request threads" << endl;
        cout << "*********************************************" << endl;

		generate_requests();
      
        usleep(10000); 

        // start the worker threads
		for(int i = 0; i < num_worker_threads; i++)
		{
			string channel_name = chan.send_request("newthread");
			RequestChannel* workers_channel = new RequestChannel(channel_name, RequestChannel::CLIENT_SIDE);
			
			pthread_create(&workers[i], NULL, worker_requests, workers_channel);

            usleep(1000000); 
           
		}

        usleep(1000);
        
        for(int i = 0; i < num_worker_threads; i++)
        {
            
			pthread_join(workers[i], NULL);
           
        }
        
		// create statistics thread and generate stats 
  		generate_stat_threads();
		
        
        
        usleep(1000000); 
        
		// print statistics
		print_stats("Joe Smith", joes_stats);
		print_stats("Jane Smith", janes_stats);
		print_stats("John Doe", johns_stats);
        
        
        
        usleep(1000000);
        quit_string = chan.send_request("quit");
	}

	
	else if(child_pid < 0)
	{
		cout << "ERROR! Something has gone worng! Abandon ship!" << endl;
		cout << "Process ID: " << child_pid << endl;

	}

	
	else
	{
		execl("./dataserver", "dataserver", NULL);

	}

	
	return 0;
  
}
