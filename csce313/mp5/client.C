/* 
    File: client.C

    Author: R. Bettati
            Department of Computer Science
            Texas A&M University
    Date  : 2013/01/31

    Simple client main program for MP3 in CSCE 313
    
    EDITED BY : Graham Leslie
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
#include <unistd.h>    /* for getopt */
#include <queue>
#include <sys/select.h>
#include <cmath>

#include <errno.h>

#include "NetworkRequestChannel.H"
#include "semaphore.H"

using namespace std;

/*--------------------------------------------------------------------------*/
/* DATA STRUCTURES */ 
/*--------------------------------------------------------------------------*/

class Item {
private:
	//
public:
	int id;
	string data;
	
	Item(): id(-1), data("") { }
	Item(int _id, string _data_string, int _req_num): id(_id), data(_data_string) { }
	
	virtual void PPrint() {
		cout << "[" << id << "]:[" << data << "]";
	}
	
	~Item() { }
};

class BoundedBuffer {
private:
	Semaphore* LOCK;
	Semaphore* FULL;
	Semaphore* EMPTY;	
	int MAX_SIZE;
	queue<Item*> list;
	
public:
	BoundedBuffer(int _size);
	BoundedBuffer() { }
	
	void depositItem(Item* _item);
	Item* RetrieveItem();
	bool empty();
	int size();
	
	~BoundedBuffer() { }
	
	void print() {
		queue<Item*> listc = list;
		cout << "\tBB: " << endl;
		while(listc.empty() == false) {
			cout << "\t" << listc.front()->id << " " << listc.front()->data << endl;
			listc.pop();
		}
	}
};

struct timeval mainstart;
struct timeval mainend;

/*--------------------------------------------------------------------------*/
/* CONSTANTS */
/*--------------------------------------------------------------------------*/

const int NUM_PERSONS = 3;
const string PERSONS[NUM_PERSONS] = { "Joe Smith", "Jane Smith", "John Doe" };
const int STATISTICS_SIZE = 100;

/*--------------------------------------------------------------------------*/
/* FORWARDS */
/*--------------------------------------------------------------------------*/

void createRequestThreads();
void createStatThreads();
void printStatistics();
void printHorizontal(int l);
void write_initial_items();
void* req_thread_do(void* _person);
void* histo_thread_do(void* _nothing);
void* evt_thread_do(void* _channel);
void* sta_thread_do(void* nothing);
void printtimediff(struct timeval* a, struct timeval* b);
long long timediff(struct timeval* a, struct timeval* b);

/*--------------------------------------------------------------------------*/
/* GLOBALS */
/*--------------------------------------------------------------------------*/

NetworkRequestChannel* CHAN_CONTROL;
int NUM_REQS;
int BB_SIZE;
int NUM_CHANNELS;
int PORT;
string HOST;
BoundedBuffer bb;
BoundedBuffer sbb;

pthread_t event_handler;

pthread_t joe_t;
pthread_t jane_t;
pthread_t john_t;

pthread_t sjoe_t;
pthread_t sjane_t;
pthread_t sjohn_t;

pthread_t histothread;
int histothread_pid;

const int MESSAGE_SIZE = 255;
char READ_BUFFER[MESSAGE_SIZE];

const int MAX_CHANNELS = 155;

// file descriptors
vector<NetworkRequestChannel*> channels;
int * ids;

long stats[NUM_PERSONS][STATISTICS_SIZE] = {0}; // initialize to zero

/*--------------------------------------------------------------------------*/
/* MAIN FUNCTION */
/*--------------------------------------------------------------------------*/

int main(int argc, char * argv[]) {
	
	// get command line arguments
	int c, n, b, w;
	string hostStr;
	
	// defaults
	HOST = "localhost";
	PORT = 11335;
   
   	while((c = getopt(argc, argv, "n:b:w:h:p:")) != -1) {
    	switch(c) {
			case 'n':
				NUM_REQS = atoi(optarg);
				break;
			case 'b':
				BB_SIZE = atoi(optarg);
				break;
			case 'w':
				NUM_CHANNELS = atoi(optarg);
				break;
			case 'h':
				hostStr = optarg;
				HOST = hostStr;
				break;
			case 'p':
				PORT = atoi(optarg);
				break;
			case '?':
				break;
			default:
				exit(-1);
		}
    }   
    
    gettimeofday(&mainstart, 0); //get starting time for entire program

	cout << "CLIENT STARTED, data:" << endl;
	cout << "\tNumber of data requests per person: " << NUM_REQS << endl << 
		    "\tSize of bounded buffer in requests: " << BB_SIZE << endl << 
		    "\tNumber of worker threads: " << NUM_CHANNELS << endl <<
		    "\tServer: " << HOST << "::" << PORT << endl;
	
	cout << "ATTEMPTING TO CREATE DATASERVER" << endl;
	pid_t child_pid = fork();
	
	// set arrays
	ids =		new int[MAX_CHANNELS];
	
	// child creates dataserver
	if (child_pid == 0) {
		execl("dataserver.o", "", 0);
	} 
	// parent continues on
	else {
		usleep(100000); // wait on dataserver
		
		/* n: number of data requests per person
		 * b: size of bounded buffer in requests
		 * w: number of request channels
		 */
		 
		cout << "CREATING BOUNDED BUFFERS" << endl;
		bb = BoundedBuffer(BB_SIZE);
		sbb = BoundedBuffer(BB_SIZE);
		 
		//cout << "ATTEMPTING TO CONTACT DATASERVER" << endl;
		//CHAN_CONTROL = new NetworkRequestChannel(HOST, PORT);
		//string REPLY = CHAN_CONTROL->cwrite("hello");
		//cout << "\tSERVER: " << REPLY << endl;
		
		cout << "ATTEMPTING TO CREATE REQUEST THREADS" << endl;
		createRequestThreads();
		
		cout << "ATTEMPTING TO CREATE REQUEST CHANNELS" << endl;
		for (int i = 0; i < NUM_CHANNELS; i ++) {
			//string channel_name = CHAN_CONTROL->cwrite("newthread");
			NetworkRequestChannel * channel = new NetworkRequestChannel(HOST, PORT);
			
			channels.push_back(channel);
		}
				
		cout << "ATTEMPTING TO CREATE EVENT THREAD" << endl;
		pthread_create(&event_handler, NULL, evt_thread_do, NULL);
		
		cout << "ATTEMPTING TO CREATE STATISTICS THREADS" << endl;
		createStatThreads();
		
		cout << "ATTEMPTING TO CREATE HISTOGRAM THREAD" << endl;
		//histothread_pid = pthread_create(&histothread, NULL, histo_thread_do, NULL);
		        
		// wait for the workers to finish
        pthread_join(event_handler, NULL);
		
		// kill the histothread
		//pthread_kill(histothread_pid);
		
		printStatistics();
		
		//cout << "CLOSING CHAN_CONTROL:" << endl;
		//CHAN_CONTROL->cwrite("quit");
		//cout << "\tSERVER: " << REPLY << endl;
		
		gettimeofday(&mainend, 0);
		cout << "Total time: ";
		printtimediff(&mainstart, &mainend); //calculate time elapsed
		
		usleep(1000000);
	}
}

/*--------------------------------------------------------------------------*/
/* DEFINITIONS - CLASSES */
/*--------------------------------------------------------------------------*/

BoundedBuffer::BoundedBuffer(int _size) {
	LOCK = new Semaphore(1);
	FULL = new Semaphore(0);
	EMPTY = new Semaphore(_size);	
	MAX_SIZE = _size;
}

void BoundedBuffer::depositItem(Item* _item) {
	EMPTY->P();
	LOCK->P();
	list.push(_item);
	LOCK->V();
	FULL->V();
}

Item* BoundedBuffer::RetrieveItem() {
	Item* ret_item;
	FULL->P();
	LOCK->P();
	ret_item = list.front();
	list.pop();
	LOCK->V();
	EMPTY->V();
	
	return ret_item;
}

bool BoundedBuffer::empty() {
	if (list.size() == 0) return true;
	return false;
}

int BoundedBuffer::size() {
	return list.size();
}

/*--------------------------------------------------------------------------*/
/* DEFINITIONS - FUNCTIONS */
/*--------------------------------------------------------------------------*/

void createRequestThreads() {	
	void* person0 = new int(0);
	pthread_create(&joe_t, NULL, req_thread_do, person0);
	
	void* person1 = new int(1);
	pthread_create(&jane_t, NULL, req_thread_do, person1);

	void* person2 = new int(2);
	pthread_create(&john_t, NULL, req_thread_do, person2);
}

void createStatThreads() {	
	pthread_create(&sjoe_t, NULL, sta_thread_do, NULL);
	pthread_create(&sjane_t, NULL, sta_thread_do, NULL);
	pthread_create(&sjohn_t, NULL, sta_thread_do, NULL);
}

void printStatistics() {
	cout << endl << endl;
	
	for (int i = 0; i < NUM_PERSONS; i ++) {
		int seg_total = 0;
		
		string header = "Statistics for " + PERSONS[i];
		printHorizontal(header.length());
		cout << header << endl;
		printHorizontal(header.length());
		
		for (int j = 0; j <= STATISTICS_SIZE; j ++) {
			if (j % 10 == 0 && j != 0) {
				cout << j - 10 << " - " << j - 1 << "\t\t" << seg_total << " times\t";
				
				double percent = ((double)seg_total / (double)NUM_REQS)*100;
				cout << percent << "%\t|";
				for (int i = 0; i < ceil(percent/10); i ++) {
					cout << '=';
				}
				for (int i = (int)ceil(percent/10); i < 10; i ++) {
					cout << " ";
				}
				cout << "|" << endl;
				
				seg_total = 0;
			} else {
				if (j != 100)
					seg_total += stats[i][j];
			}
		}
		printHorizontal(header.length());
		cout << "Total requests: " << NUM_REQS << endl;
		printHorizontal(header.length());
		cout << endl;
	}			
}

void printHorizontal(int l) {
	for (int j = 0; j < l; j ++) cout << "-";
	cout << endl;
}

void printtimediff(struct timeval* a, struct timeval* b) {
	long long sec = b->tv_sec - a->tv_sec;
  	cout << "timed " << sec << " seconds" << endl;
}

long long timediff(struct timeval* a, struct timeval* b) {
	return b->tv_sec - a->tv_sec;
}

void write_initial_items() {
	for (int i = 0; i < NUM_CHANNELS; i ++) {
		Item * item;
		item = bb.RetrieveItem();
		
		string data = item->data;
		ids[i] = item->id;
		
		channels[i]->cwrite(data.c_str());
	}
}

/*--------------------------------------------------------------------------*/
/* DEFINITIONS - THREAD FUNCTIONS */
/*--------------------------------------------------------------------------*/

void* req_thread_do(void* _person) {
	int person = *(int*)_person;
	
	for (int i = 0; i < NUM_REQS; i ++) {
		Item* item = new Item;
		item->id = person;
		item->data = "data " + PERSONS[person];
		//cout << endl << "\t* * Request thread is depositing " << PERSONS[person] << "'s item in bb" << endl;
		//cout << "\t* * i = " << i << endl;
		bb.depositItem(item);
	}
	
	delete (int*)_person;
	pthread_exit(NULL);
}

void* histo_thread_do(void * _nothing) {
	// yeah I guess this isn't exactly up to the rubric's standards, lol
	while (true) {
		cout << "UPDATE: " << endl;
		printStatistics();
		usleep(100);
	}
}

void* evt_thread_do(void* _nothing) {
	write_initial_items(); // write the initial items
	
	bool done = false;
	int maxfd = 0;
	
	while(!done) {
		fd_set read_set;
		
		// zero em out
		//FD_ZERO(&read_set);
		
		// set initially
		for (int i = 0; i < NUM_CHANNELS; i++) {
			FD_SET(channels[i]->get_fd(), &read_set);
		}
		
		// get max value of fds
		for(int i = 0; i < NUM_CHANNELS; i++)
		{
			if (channels[i]->get_fd() > maxfd) maxfd = channels[i]->get_fd();
		}
		
		int ready = select(maxfd + 1, &read_set, NULL, NULL, NULL);
		
		if (ready == -1) {
			cout << "Error calling select.";
			exit(1);
		}
		
		else {
			for (int i = 0; i < NUM_CHANNELS; i ++) {
				// if isset
				if (FD_ISSET(channels[i]->get_fd(), &read_set)) {
					Item * item_r;
					
					string reply = channels[i]->cread();
					item_r = new Item(ids[i], reply, 0);
					
					sbb.depositItem(item_r); // deposit that item in the statistics buffer
					
					if (!bb.empty()) {
						Item * item_w;
						
						item_w = bb.RetrieveItem();
						ids[i] = item_w->id;
						string data = item_w->data;
						
						channels[i]->cwrite(data.c_str()); // send the next item to the server now a spots opened up
					} else {
						usleep(10000); // make sure we're finished
						done = true;
					}
				}
			}
		}
		
		
	}
	
	// close the channels
	for (int i = 0; i < NUM_CHANNELS; i ++) {
		channels[i]->cwrite("quit");
		usleep(1000);
	}
	
	pthread_exit(NULL);
}

void* sta_thread_do(void* nothing) {
	while (!bb.empty()) {
		while (!sbb.empty()) {
			Item* sta_item = sbb.RetrieveItem();
			
			int id = sta_item->id;
			int value = atoi(sta_item->data.c_str());
			if (value < STATISTICS_SIZE - 1) {
				stats[id][value] += 1;
			} else {
				// max statistics exceeded
			}
			
			//cout << "sta: " << endl;
			//cout << "\tbb is at size " << bb.size() << endl;
			//cout << "\tsbb is at size " << sbb.size() << endl;
		
			delete sta_item; // finally clean up this item
		}
	}
	
	pthread_exit(NULL);
}
