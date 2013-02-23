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
Addr END_MEMORY;
unsigned int HEADER_SIZE;
unsigned int _LENGTH;

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
	NUM_LISTS = log2(_length / _basic_block_size) + 1;
	HEADER_SIZE = 13;
	_LENGTH = _length;
		
	// create the memory
	START_MEMORY = malloc(_length);
	END_MEMORY = START_MEMORY - _length;
	
	// create the freelist
	// 1. malloc the first dimension
	FREE_LIST = malloc(NUM_LISTS * sizeof(Addr**));
	
	// 2. malloc each row in the freelist
	int i;
	for (i = 0; i < NUM_LISTS; i ++) {
		FREE_LIST[i] = (Addr*)malloc(sizeof(Addr**));
	}
	
	// 3. set FREE_LIST entries to NULL
	for (i = 0; i < NUM_LISTS; i ++) {
		FREE_LIST[i][0] = NULL;
		FREE_LIST[i][1] = NULL;
	}
	
	// create the first Header
	Header* h = START_MEMORY;
		h->empty = 1;
		h->next = NULL;
		h->prev = NULL;
		h->size = (_length - HEADER_SIZE);
	
	// store it in the freelist
	FREE_LIST[NUM_LISTS-1][0] = h;	
		
	// return bytes available
	return h->size;
}

int release_allocator() {
	free(START_MEMORY);
}

extern Addr my_malloc(unsigned int _length) {
	Header* h = NULL;
	Header* touse = NULL;
	Header* tNext = NULL;
		
	printf("\n\n -- allocating: [%i]\n\n",_length);
		
	int i, j, i_f, j_f;
	for (i = NUM_LISTS-1; i >= 0; i --) {
		for (j = 1; j >= 0; j --) {	
			if (FREE_LIST[i][j] != NULL) {
				// get the temp header
				h = FREE_LIST[i][j];
				
				// if it fits, set touse
				if (h->size >= _length) {
					touse = FREE_LIST[i][j];
					i_f = i;
					j_f = j;
					break;
				}
			}
		}
	}
			
	// if we got a size that fits
	if (touse != NULL) {
		int sizeAfterSplit;
		sizeAfterSplit = (touse->size + HEADER_SIZE) / 2 - HEADER_SIZE;
		
		// if the very first block, or otherwise splittable [ ][x] - -fixed!
		if (1==1) {
			while (sizeAfterSplit >= _length && i_f > 0) {
				// update sizeAfterSplit
				sizeAfterSplit = (touse->size + HEADER_SIZE) / 2 - HEADER_SIZE;
				
				printf("split %i into\t",touse->size + HEADER_SIZE);
				
				// update the first header
				touse->size = sizeAfterSplit;
				touse->empty = 1;
				
				printf("[%i][%i]\n",sizeAfterSplit + HEADER_SIZE,sizeAfterSplit + HEADER_SIZE);
				
				// create a new header at halfway of touse
				Header *hNew = (Addr)(((void*)touse) + (touse->size));
				
				// set the data for the new header
				hNew->empty = 1;
				hNew->size = sizeAfterSplit;
				
				// point them at each other
				tNext = touse->next;
				touse->next = hNew;
				hNew->prev = touse;
				hNew->next = tNext;
			
				// update the FREE_LIST
				// 1. remove the old one
				FREE_LIST[i_f][j_f] = NULL;
				
				// 2. add the new Headers
				i_f --;
				if (j_f < 1) j_f ++;
				FREE_LIST[i_f][0] = touse;
				FREE_LIST[i_f][1] = hNew;
													
				touse = hNew;
			}
		}
		
		// allocate now
		touse->empty  = 0;
		FREE_LIST[i_f][j_f] = NULL;
		
		print();
		
		return (Addr)touse;
		
	} else {
		printf("ERROR: OUT OF MEMORY!\n");
		exit(EXIT_FAILURE);
	}
}

extern int my_free(Addr _a) {
  	Header *h = _a;
  	Header *o;
  	int l = getList(h);
  	
  	h->empty = 1;
  	
  	if (FREE_LIST[l][0] == NULL) {
  		FREE_LIST[l][0] = h;
  		printf("my_free(%i) at [%i][%i]\t",h->size + HEADER_SIZE,l,0);
  	} else if (FREE_LIST[l][1] == NULL) {
  		FREE_LIST[l][1] = h;
  		printf("my_free(%i) at [%i][%i]\t",h->size + HEADER_SIZE,l,1);
  	}
  		
  	if (h->next != NULL) {
  		o = h->next;
  		
  		// [_a][o]
  		if (o->empty == 1 && o->size == h->size) {
  			
  			h->size = (h->size + HEADER_SIZE)*2 - HEADER_SIZE;
  			h->next = o->next;
  			if (o->next != NULL) o->next->prev = h;
  			h->empty = 1;
  			
  			FREE_LIST[l][0] = NULL;
  			FREE_LIST[l][1] = NULL;
  			
  			FREE_LIST[l+1][1] = h;
  			printf("coalesce with (%i) (case [_a][o]) to [%i][%i]\n",h->size + HEADER_SIZE,l+1,1);
  			my_free((Addr*)h);
  		}
  	}
  	
  	if (h->prev != NULL) {
  		o = h->prev;
  		
  		// [o][_a]
  		if (o->empty == 1 && o->size == h->size) {
  			
  			o->size = (h->size + HEADER_SIZE)*2 - HEADER_SIZE;
  			o->next = h->next;
  			if (h->next != NULL) h->next->prev = o;
  			o->empty = 1;
  			
  			FREE_LIST[l][0] = NULL;
  			FREE_LIST[l][1] = NULL;
  			
  			FREE_LIST[l+1][1] = o;
  			printf("coalesce with (%i) (case [o][_a]) to [%i][%i]\n",h->size + HEADER_SIZE,l+1,1);
  			my_free((Addr*)o);
  		}
  	}	 	
  	
  	printf("just set to 1\n");
}

int getList(Addr _a) {
	Header *a = _a;
	
	int i = NUM_LISTS, j = a->size + HEADER_SIZE;
	while (j != _LENGTH/(int)pow(2,i)) {
		i --;
		if (i < 0) {
			printf("ERROR: GETLIST FAILED ON %i!",a->size + HEADER_SIZE);
			exit(EXIT_FAILURE);
		}
	}
	
	return NUM_LISTS-i-1;
}

// debug
extern void print() {
	int i, j;
	Header *h = NULL;
	
	printf("FREE_LIST:\n");
	for (i = NUM_LISTS-1; i >= 0; i --) {
	
		printf("%i: ",i);
		for (j = 0; j <= 1; j ++) {
			if (FREE_LIST[i][j] == NULL) {
				printf("[ ]");
			} else {
				h = FREE_LIST[i][j];
				printf("[%i]",h->size + HEADER_SIZE);
			}
		}
		
		printf("\n");
	}
	
	printf("MEMORY: \n");
	h = START_MEMORY;
	
	int oC = 0;
	while(h != NULL && oC < 100) {
		printf("[");
		if (h->prev != NULL) printf("%i<-", h->prev->size + HEADER_SIZE);
		printf("(%i,%i)",h->size + HEADER_SIZE, h->empty);
		if (h->next != NULL) printf("->%i", h->next->size + HEADER_SIZE);
		printf("]\t");
		
		h = h->next;
		oC ++;
	}
	printf("\n\n\n");
}
	

