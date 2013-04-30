/* 
    File: dataserver.C

    Author: R. Bettati
            Department of Computer Science
            Texas A&M University
    Date  : 2012/07/16

    Edited by : Graham Leslie
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
/* DATA STRUCTURES */ 
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* CONSTANTS */
/*--------------------------------------------------------------------------*/

const int MAX_MESSAGE = 255;

/*--------------------------------------------------------------------------*/
/* VARIABLES */
/*--------------------------------------------------------------------------*/

static int nthreads = 0;

/*--------------------------------------------------------------------------*/
/* FORWARDS */
/*--------------------------------------------------------------------------*/

void handle_process_loop(int fd);

/*--------------------------------------------------------------------------*/
/* LOCAL FUNCTIONS -- SUPPORT FUNCTIONS */
/*--------------------------------------------------------------------------*/

string int2string(int number) {
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

string server_read(int * fd) {
	char buf[MAX_MESSAGE];
	

	if (read(*fd, buf, MAX_MESSAGE) < 0) {
		cout << "Error reading";
		exit(-1);
	}
	
	string s = buf;
	return s;
}

int server_write(int * fd, string message){
	if (message.length() >= MAX_MESSAGE) {
		cout << "Message too long";
		exit(-1);
	}
	
	if (write(*fd, message.c_str(), message.length()+1) < 0) {
		cout << "Error writing.";
		exit(-1);
	}
	
}

/*--------------------------------------------------------------------------*/
/* LOCAL FUNCTIONS -- INDIVIDUAL REQUESTS */
/*--------------------------------------------------------------------------*/

void process_hello(int * fd, const string & _request)  {
	server_write(fd, "hello to you too");
}

void process_data(int * fd, const string &  _request)  {
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
	
	if (fd == NULL)
		cout << "No file descriptor!" << endl;
		
	for(;;)  {		
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
	
	close(*fd);
  
}
/*--------------------------------------------------------------------------*/
/* MAIN FUNCTION */
/*--------------------------------------------------------------------------*/

int main(int argc, char * argv[]) {	
	unsigned short PORT = 11335; 
	int BACKLOG_BUF = 200;  
	
	int c; 
	unsigned short _port = 0;
	int _backlog = 0;
	
	while ((c = getopt(argc, argv, "p:b:")) != -1) {
		switch(c){
			case 'p':
				PORT = atoi(optarg);
				break;
			case 'b':
				BACKLOG_BUF = atoi(optarg);
				break;
		}
	}
	
	cout << "port: " << PORT << "\t buffer: " << BACKLOG_BUF << endl; 

	NetworkRequestChannel server(PORT, connection_handler, BACKLOG_BUF);

	cout << "Server closing..." << endl;
	server.~NetworkRequestChannel();

}

