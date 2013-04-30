 /* 
    File: dataserver.C

    Author: Doug Lasater
            Department of Computer Science
            Texas A&M University
    Date  : 2013/04/27

    
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
#include <sstream>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <pthread.h>
#include <errno.h>

#include "NetworkRequestChannel.H"
#include "semaphore.H"

using namespace std;


/*--------------------------------------------------------------------------*/
/* GLOBALS */
/*--------------------------------------------------------------------------*/

static int nthreads = 0;
int MAX_MSG = 255;

Semaphore * PRINT;


/*--------------------------------------------------------------------------*/
/* FORWARDS */
/*--------------------------------------------------------------------------*/

void handle_process_loop(int fd);

/*--------------------------------------------------------------------------*/
/* LOCAL FUNCTIONS -- SUPPORT FUNCTIONS */
/*--------------------------------------------------------------------------*/

string int2string(int number) 
{
   stringstream ss;
   ss << number;
   return ss.str();
}

string server_read(int * fd){
	char buf[MAX_MSG];
	

	if(read(*fd, buf, MAX_MSG) < 0)
		cerr << "Error reading\n";
	
	string s = buf;
	return s;
}

int server_write(int * fd, string message){
	if(message.length() >= MAX_MSG)
		cerr << "Message too long.\n";
	
	if(write(*fd, message.c_str(), message.length()+1) < 0)
		cerr << "Error writing.\n";
	
}
/*--------------------------------------------------------------------------*/
/* LOCAL FUNCTIONS -- INDIVIDUAL REQUESTS */
/*--------------------------------------------------------------------------*/

void process_hello(int * fd, const string & _request) 
{
	server_write(fd, "hello to you too");
}

void process_data(int * fd, const string &  _request) 
{
	usleep(1000 + (rand() % 5000));
 
	server_write(fd, int2string(rand() % 100));
}

/*--------------------------------------------------------------------------*/
/* LOCAL FUNCTIONS -- THE PROCESS REQUEST LOOP */
/*--------------------------------------------------------------------------*/

void process_request(int * fd, const string & _request) 
{

  if (_request.compare(0, 5, "hello") == 0) 
    process_hello(fd, _request);
  
  else if (_request.compare(0, 4, "data") == 0) 
    process_data(fd, _request);
  
  else 
    server_write(fd, "unknown request");
  

}

void * connection_handler(void * arg) 
{ 
	int * fd = (int*)arg;
	
	if(fd == NULL)
		cout << "FD is null \n";
		
	for(;;) 
	{		
		string request = server_read(fd);
		cout << "New request is " << request << endl;

		if (request.compare("quit") == 0) 
		{
			server_write(fd, "bye");
			usleep(10000);          // give the other end a bit of time.
			break;                  // break out of the loop;
		}

		process_request(fd, request);
	}
  
}

/*--------------------------------------------------------------------------*/
/* MAIN FUNCTION */
/*--------------------------------------------------------------------------*/

int main(int argc, char * argv[]) {
	/* Get command line options */ 
	
	
	unsigned short portNum = 11335; 
	int backLog = 200;  
	int get = 0; 
	unsigned short pNum = 0;
	int bLog = 0;
	
	while((get = getopt(argc, argv, "p:b:")) != -1){
		switch(get){
			case 'p':
				pNum = atoi(optarg);
				break;
			case 'b':
				bLog = atoi(optarg);
				break;
		}
	}
	if(pNum != 0)
		portNum = pNum;
	
	if(bLog != 0)
		backLog = bLog;
	
	cout << "Command Arguments: ";
	cout << "port: " << portNum << "\t backLog buffer: " << backLog << endl; 
		
	cout << "Server is Statrting on Port: " << portNum << endl;

	NetworkRequestChannel server(portNum, connection_handler, backLog);

	cout << "Closing server," << endl;
	server.~NetworkRequestChannel();

}

