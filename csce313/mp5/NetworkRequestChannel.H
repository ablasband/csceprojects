/*
    File: reqchannel.H

    Author: R. Bettati
            Department of Computer Science
            Texas A&M University
    Date  : 2012/07/11
    
    Edited by : Graham Leslie

*/

#ifndef _NETWORKREQUESTCHANNEL_H_                   // include file only once
#define _NETWORKREQUESTCHANNEL_H_

/*--------------------------------------------------------------------------*/
/* DEFINES */
/*--------------------------------------------------------------------------*/

/* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <string>
#include "semaphore.H"

using namespace std;

/*--------------------------------------------------------------------------*/
/* DATA STRUCTURES */ 
/*--------------------------------------------------------------------------*/

/* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* FORWARDS */ 
/*--------------------------------------------------------------------------*/

/* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* CLASS   Network R e q u e s t C h a n n e l */
/*--------------------------------------------------------------------------*/

class NetworkRequestChannel {

private:

  int fd; // file descriptor for socket

public:

  /* -- CONSTRUCTOR/DESTRUCTOR */

  NetworkRequestChannel(const string _host, const unsigned short _port);
  NetworkRequestChannel(const unsigned short _port, void * (*connection_handler) (void *), int backlog);
 
  ~NetworkRequestChannel();
  
  string cread(); // blocking reads a message
  
  int cwrite(string _msg); // writes a message
  int get_fd(); // gets the file descriptor
  
};


#endif


