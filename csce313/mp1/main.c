#include "my_allocator.h"
#include "ackerman.h"
#include <stdlib.h>    /* for exit */
#include <unistd.h>    /* for getopt */

int main(int argc, char ** argv) {
	int opterr = 0;
    unsigned int _basic_block_size =  128;
    unsigned int _length  = 524288; 
    
    int c;
   
   	while( (c = getopt(argc, argv, "b:s:") ) != -1) {
    	switch(c) {
			case 'b':
				_basic_block_size = atoi(optarg);
				break;
			case 's':
				_length = atoi(optarg)*1024;
				break;
			case '?':
				break;
			default:
				abort();
		}
    }   
  
  	init_allocator(_basic_block_size, _length);
	ackerman_main();
	release_allocator();
}
