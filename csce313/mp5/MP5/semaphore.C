/* 
    File: semaphore.C

    Author: Doug Lasater
            Department of Computer Science
            Texas A&M University
    Date  : 1 March 2013

*/

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include <pthread.h>
#include "semaphore.H"

/*--------------------------------------------------------------------------*/
/* Semaphore Class Functions  */
/*--------------------------------------------------------------------------*/


Semaphore::Semaphore(int _val)
{
	value = _val;
	pthread_mutex_init(&m, NULL);
	pthread_cond_init(&c, NULL);
};

Semaphore::~Semaphore() 
{
	pthread_mutex_destroy(&m);
	pthread_cond_destroy(&c);
}


int Semaphore::P(){		 // Decrements the value by 1. Process blocked if val < 0

	pthread_mutex_lock(&m);

	while(value <= 0) 
		pthread_cond_wait(&c, &m);
        
    value = value - 1;
	
	pthread_mutex_unlock(&m);
	
	return 0;
} 

int Semaphore::V() 	{	// Increments the value by 1. Process blocked if val < 0

	pthread_mutex_lock(&m);
	value = value + 1;
	
    pthread_cond_broadcast(&c);
    
	pthread_mutex_unlock(&m);





	return 0;
}
