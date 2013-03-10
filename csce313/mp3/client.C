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

#include <errno.h>

#include "reqchannel.H"
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
void* req_thread_do(void* _person);
void* wrk_thread_do(void* _channel);
void* sta_thread_do(void* nothing);

/*--------------------------------------------------------------------------*/
/* GLOBALS */
/*--------------------------------------------------------------------------*/

RequestChannel* CHAN_CONTROL;
int NUM_REQS;
int BB_SIZE;
int NUM_WRKS;
BoundedBuffer bb;
BoundedBuffer sbb;

pthread_t joe_t;
pthread_t jane_t;
pthread_t john_t;

pthread_t sjoe_t;
pthread_t sjane_t;
pthread_t sjohn_t;

long stats[NUM_PERSONS][STATISTICS_SIZE] = {0}; // initialize to zero

/*--------------------------------------------------------------------------*/
/* MAIN FUNCTION */
/*--------------------------------------------------------------------------*/

int main(int argc, char * argv[]) {
	
	// get command line arguments
	int c, n, b, w;
   
   	while((c = getopt(argc, argv, "n:b:w:")) != -1) {
    	switch(c) {
			case 'n':
				NUM_REQS = atoi(optarg);
				break;
			case 'b':
				BB_SIZE = atoi(optarg);
				break;
			case 'w':
				NUM_WRKS = atoi(optarg);
				break;
			case '?':
				break;
			default:
				exit(0);
		}
    }   

	cout << "CLIENT STARTED, data:" << endl;
	cout << "\tNumber of data requests per person: " << NUM_REQS << endl << 
		    "\tSize of bounded buffer in requests: " << BB_SIZE << endl << 
		    "\tNumber of worker threads: " << NUM_WRKS << endl;
		    
	/*
	string mock;
	cout << endl << "\t * * Continue?" << endl;
	cin >> mock;
	cin.ignore();
	*/
	
	cout << "ATTEMPTING TO CREATE DATASERVER" << endl;
	pid_t child_pid = fork();
	
	// child creates dataserver
	if (child_pid == 0) {
		execl("dataserver.o", "", 0);
	} 
	// parent continues on
	else {
		usleep(100000); // wait on dataserver
		
		/* n: number of data requests per person
		 * b: size of bounded buffer in requests
		 * w: number of worker threads
		 */
		 
		cout << "CREATING BOUNDED BUFFERS" << endl;
		bb = BoundedBuffer(BB_SIZE);
		sbb = BoundedBuffer(BB_SIZE);
		 
		cout << "ATTEMPTING TO CONTACT DATASERVER" << endl;
		CHAN_CONTROL = new RequestChannel("control", RequestChannel::CLIENT_SIDE);
		string REPLY = CHAN_CONTROL->send_request("hello");
		cout << "\tSERVER: " << REPLY << endl;
		
		cout << "ATTEMPTING TO CREATE REQUEST THREADS" << endl;
		createRequestThreads();
				
		cout << "ATTEMPTING TO CREATE WORKER THREADS" << endl;
		pthread_t workers[NUM_WRKS];
		for (int i = 0; i < NUM_WRKS; i ++) {
			//cout << "\t* * Creating wrk_thread ----" << i << endl;
			string channel_name = CHAN_CONTROL->send_request("newthread");
			RequestChannel* channel = new RequestChannel(channel_name, RequestChannel::CLIENT_SIDE);
	
			pthread_create(&workers[i], NULL, wrk_thread_do, channel);
			
		}
		
		cout << "ATTEMPTING TO CREATE STATISTICS THREADS" << endl;
		createStatThreads();
		        
		// wait for the workers to finish
        for(int i = 0; i < NUM_WRKS; i++)
        {
			pthread_join(workers[i], NULL);  
        }
		
		printStatistics();
		
		cout << "CLOSING CHAN_CONTROL:" << endl;
		REPLY = CHAN_CONTROL->send_request("quit");
		cout << "\tSERVER: " << REPLY << endl;
		
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
				
				cout << ((double)seg_total / (double)NUM_REQS)*100 << "%" << endl;
				
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

void* wrk_thread_do(void* _channel) {
	RequestChannel * channel = (RequestChannel*)_channel;
	
	while (!bb.empty()) {		
		Item* req_item = bb.RetrieveItem();
		//cout << "\t * * worker thread sends " << req_item->data;
		string reply = channel->send_request(req_item->data);
		//cout << " gets " << reply << endl;
		//cout << "\t SERVER: " << reply << endl;
		
		//cout << "wrk: " << endl;
		//cout << "\tbb is at size " << bb.size() << endl;
		//cout << "\tsbb is at size " << sbb.size() << endl;
		
		req_item->data = reply;
		sbb.depositItem(req_item);
	}
	
    channel->send_request("quit");
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
