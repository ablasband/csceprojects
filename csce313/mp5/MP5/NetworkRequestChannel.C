 /* 
    File: NetworkRequestChannel.C

    Author: Doug Lasater
            Department of Computer Science
            Texas A&M University
    Date  : 2013/04/27

*/


/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include <cassert>
#include <string>
#include <sstream>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <errno.h>
#include <arpa/inet.h>
#include "NetworkRequestChannel.H"

using namespace std;

/*--------------------------------------------------------------------------*/
/* DATA STRUCTURES */ 
/*--------------------------------------------------------------------------*/

	struct sockaddr_in serverIn;



/*--------------------------------------------------------------------------*/
/* 				Helper Functions 											*/
/*--------------------------------------------------------------------------*/

/* Creates a client connection to server, using method connectTCP from slides */ 
int createClientConnection(const char * host, const char * portNo)
{
	struct sockaddr_in sockIn;
	memset(&sockIn, 0, sizeof(sockIn));
	sockIn.sin_family = AF_INET;
	
	/* Set port */
	if(struct servent * pse = getservbyname(portNo, "tcp"))
		sockIn.sin_port = pse->s_port;
	
	else if ((sockIn.sin_port = htons((unsigned short)atoi(portNo))) == 0) 
		cerr << "Can't connect port,";
	
	//Resolve hostname
	if(struct hostent * hn = gethostbyname(host))
		memcpy(&sockIn.sin_addr, hn->h_addr, hn->h_length);
	
	else if((sockIn.sin_addr.s_addr = inet_addr(host)) == INADDR_NONE)
		cerr << "Cannot resolve host <" << host << ">\n";
	
	//Establish socket
	int s = socket(AF_INET, SOCK_STREAM, 0); //SOCK_STREAM finds a socket for a TCP connection
	if(s < 0) cerr << "Can't create socket\n";
	
	//Connect
	if(connect(s, (struct sockaddr *)&sockIn, sizeof(sockIn)) < 0)
		cerr << "Can't connect to " << host << ":" << portNo;
	
	return s;
}

/* Creates the server connection, passiveTCPSock from slides */ 
int createServerConnection(const char * svc, int backlog)
{

	memset(&serverIn, 0, sizeof(serverIn));
	serverIn.sin_family = AF_INET;
	serverIn.sin_addr.s_addr = INADDR_ANY;
	
	/* Map to port number */
	if(struct servent * pse = getservbyname(svc, "tcp"))
		serverIn.sin_port = pse->s_port;
	
	else if((serverIn.sin_port = htons((unsigned short)atoi(svc))) == 0)
		cerr << "can't get service entry\n";
	
	
	/* Allocate and bind */
	int snum  = socket(AF_INET, SOCK_STREAM, 0);
	
	if(snum < 0) 
		cerr << "can't create socket \n";
		
	if(bind(snum, (struct sockaddr *)&serverIn, sizeof(serverIn)) < 0)
		cerr << "can't bind...\n";
	
	/* Start listening */
	if(listen(snum, backlog) < 0)
		cerr << "can't listen in. don't want to be overheard.\n";
		
	return snum;
}

/*--------------------------------------------------------------------------*/
/* PRIVATE METHODS FOR CLASS  N e t w o r k R e q u e s t C h a n n e l     */
/*--------------------------------------------------------------------------*/

NetworkRequestChannel::NetworkRequestChannel(const string _server_host_name, const unsigned short _port_no)
{
	// ----- CLIENT'S CONSTRUCTOR ----- 
	stringstream ss;
	ss << _port_no;
	string port = ss.str();
	
	fd = createClientConnection(_server_host_name.c_str(), port.c_str());
	
}

NetworkRequestChannel::NetworkRequestChannel(const unsigned short _port_no, void * (*connection_handler) (void *), int backlog)
{
	// ----- SERVER'S CONSTRUCTOR ----- 
	
	stringstream ss;
	ss << _port_no;
	string port = ss.str();
	
	int master_sock = createServerConnection(port.c_str(), backlog);
	int serverSize = sizeof(serverIn);
	

	while(true)
	{
		int * slave_sock = new int;
		
		pthread_t thread;
		pthread_attr_t attr; 
		pthread_attr_init(&attr);
			
		
		*slave_sock = accept(master_sock,(struct sockaddr*)&serverIn, (socklen_t*)&serverSize);
		
		if(slave_sock < 0)
		{
			delete slave_sock;
			
			if(errno == EINTR) continue;
			else cerr << "Accept failure!\n";
		}	
		
		pthread_create(&thread, &attr, connection_handler, (void*)slave_sock);
		
 
	}
	cout << "Connection created. \n";
}

NetworkRequestChannel::~NetworkRequestChannel()
{
	close(fd); // Closes the socket
}

/*--------------------------------------------------------------------------*/
/* NetworkRequestChannel Functions */
/*--------------------------------------------------------------------------*/
const int MAX_MESSAGE = 255;


string NetworkRequestChannel::cread()
{
	char buf[MAX_MESSAGE];
	
	if (read(fd, buf, MAX_MESSAGE) < 0) 
		perror("Error reading\n");
	
	
	string s = buf;

	return s;
}

int NetworkRequestChannel::cwrite(string _msg)
{
	if (_msg.length() >= MAX_MESSAGE) {
		cerr << "Message too long for Channel!\n";
		return -1;
	}
	
	const char * s = _msg.c_str();

	if (write(fd, s, strlen(s)+1) < 0) 
		perror("Error writing\n");
	
	
}

int NetworkRequestChannel::get_fd()
{
	return fd;
}
