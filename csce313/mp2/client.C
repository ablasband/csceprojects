/* 
    File: client.C

    Author: R. Bettati
            Department of Computer Science
            Texas A&M University
    Date  : 2012/07/11

    Simple client main program for MP2 in CSCE 313
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
#include <sstream>
#include <sys/types.h>
#include <ctime>
#include <sys/stat.h>

#include <errno.h>

#include "reqchannel.H"

using namespace std;

/*--------------------------------------------------------------------------*/
/* DATA STRUCTURES */ 
/*--------------------------------------------------------------------------*/

struct timeval mainstart;
struct timeval requeststart;
struct timeval mainend;
struct timeval requestend;

/*--------------------------------------------------------------------------*/
/* CONSTANTS */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* FORWARDS */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* LOCAL FUNCTIONS -- SUPPORT FUNCTIONS */
/*--------------------------------------------------------------------------*/

string int2string(int number) {
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

//used for calculating the running time of requests
void printtimediff(struct timeval* a, struct timeval* b) {
  long musec = b->tv_usec - a->tv_usec;
  cout << "timed " << musec << endl;

}

/*--------------------------------------------------------------------------*/
/* MAIN FUNCTION */
/*--------------------------------------------------------------------------*/

	int main(int argc, char * argv[]) {
	
	gettimeofday(&mainstart, 0); //get starting time for entire program
	cout << "CLIENT STARTED:\n" << flush;
	
	// create the dataserver
	pid_t child_pid = fork();
	
	if (child_pid == 0) {
		execl("dataserver.o", "", 0);
	}
	
	cout << "Establishing control channel... " << flush;
	RequestChannel chan("control", RequestChannel::CLIENT_SIDE);
	cout << "done.\n" << flush;
	
	/* -- Start sending a sequence of requests */
	
	gettimeofday(&requeststart, 0); 
	string reply1 = chan.send_request("hello");
	gettimeofday(&requestend, 0);
	
	cout << "Reply to request 'hello' is '" << reply1 << endl;
	cout << "Response time for request 1: "; 
	printtimediff(&requeststart, &requestend);
	
	gettimeofday(&requeststart, 0); 
	string reply2 = chan.send_request("data Joe Smith");
	gettimeofday(&requestend, 0); 
	
	cout << "Reply to request 'data Joe Smith' is '" << reply2 << endl;
	cout << "Response time for request 2: ";
	printtimediff(&requeststart, &requestend); 
	
	gettimeofday(&requeststart, 0); 
	string reply3 = chan.send_request("data Jane Smith");
	gettimeofday(&requestend, 0); 
	
	cout << "Reply to request 'data Jane Smith' is '" << reply3 << endl;
	cout << "Response time for request 3: ";
	printtimediff(&requeststart, &requestend); 
	
	for (int i = 0; i < 100; i++) {
		gettimeofday(&requeststart, 0); 
		string request_string("data TestPerson" + int2string(i));
		string reply_string = chan.send_request(request_string);
		gettimeofday(&requestend, 0);
		cout << "Reply to request " << i << ":" << reply_string << "\n";
		printtimediff(&requeststart, &requestend);
	}
	gettimeofday(&requestend, 0); 
	cout << "Response time for request 4: ";
	printtimediff(&requeststart, &requestend); 
	
	gettimeofday(&requeststart, 0); 
	string reply4 = chan.send_request("quit");
	gettimeofday(&requestend, 0); 
	
	cout << "Reply to request 'quit' is '" << reply4 << endl;
	cout << "Response time for request 5: ";
	printtimediff(&requeststart, &requestend);
	
	
	gettimeofday(&mainend, 0);
	cout << "Total time: ";
	printtimediff(&mainstart, &mainend); //calculate time elapsed
	
	usleep(1000000);
	}
