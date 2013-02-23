#include "my_allocator.h"
#include "ackerman.h"

int main(int argc, char ** argv) {
	init_allocator(128,512*1024);
	release_allocator();
}
