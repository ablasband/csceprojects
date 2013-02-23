/* 
    File: my_allocator.c

    Author: GRAHAM LESLIE
            Department of Computer Science
            Texas A&M University
    Date  : 2/11/13

    Modified: 

    This file contains the implementation of the module "MY_ALLOCATOR".
	
	COMPILE WITH -lm FLAG FOR MATH LIBRARY (log)

*/

/*--------------------------------------------------------------------------*/
/* DEFINES */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include <stdlib.h>
#include <math.h>
#include "my_allocator.h"

/*--------------------------------------------------------------------------*/
/* DATA STRUCTURES */ 
/*--------------------------------------------------------------------------*/

Addr** FREE_LIST;

/*--------------------------------------------------------------------------*/
/* GLOBALS */ 
/*--------------------------------------------------------------------------*/

int NUM_LISTS;
Addr START_MEMORY;
unsigned int HEADER_SIZE;

/*--------------------------------------------------------------------------*/
/* CONSTANTS */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* FORWARDS */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* FUNCTIONS FOR MODULE MY_ALLOCATOR */
/*--------------------------------------------------------------------------*/

/* Don't forget to implement "init_allocator" and "release_allocator"! */

unsigned int init_allocator(unsigned int _basic_block_size, unsigned int _length) {
	// determine sizes to be used
	NUM_LISTS = log(_length / _basic_block_size) / log(2) + 1;
	HEADER_SIZE = 13;
		
	// create the memory
	START_MEMORY = malloc(_length);
	
	// create the freelist
	FREE_LIST = malloc(sizeof(Addr**[NUM_LISTS][2]));
	
	// create the first Header
	Header* h = START_MEMORY;
		h->empty = 1;
		h->next = NULL;
		h->prev = NULL;
		h->size = (_length - HEADER_SIZE);
	
	// store it in the freelist
	FREE_LIST[0][0] = h;
}

int release_allocator() {
	free(START_MEMORY);
}

extern Addr my_malloc(unsigned int _length) {
	
}

extern int my_free(Addr _a) {
  /* Same here! */
  free(_a);
  return 0;
}

