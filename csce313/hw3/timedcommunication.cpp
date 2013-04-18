// timedcommunication.cpp

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_BUF = 4096;
char MSG1[1024];
char MSG2[2048];
char MSG3[4096];
const int waittime = 1000000;
struct timeval mainstart;
struct timeval mainend;

void printtimediff(struct timeval* a, struct timeval* b);

int main(int argc, char *argv[]) {
	
	string leng1024 = "WUWtO7ZwIunfMu4kE78GVcEfahvFu0sh7YbedRHUxw3qDePHLpat7jV5EmHXsK4X6rmfUQoEj2Me2j1GzozJ4ObhNF2FHT45CrkqFsTxYdSK9SmEUgoMJ4ncLPG7Zhvc4E3PsoMpzSJMDaO4os6f8or4Inbwtl4YVeGK1S25j7IdKGvoatpdJZ5N8PF0SREV6TyTuE65lttNhccymURHEOwI2WSmrULzY6nxUM0AYsGi3aS4YEWdjyRwNrS4JRR17E1WJQrQkD042oVHrKI1vLq17eu8AJArccoDK7yhxYny0rsv0FgMwcM6nqq3M5Z1L2SvuhbIfgFrK6kSyGS3MfPebcZlb1urDdSlgQ6N5L3HYdy43Su3UD7TTGxjQF76EzwvlZDwszEvrRHIODTfsZy2Qr9UatsGUn6gASs9UCCaE4D8YS56Xsuz60YPGlpTzCQKTZfiYzkg99VElibyJfLv62AtBt7jwO9UKovtOZ4mkCPxj8ilrlTOIuP60TvumJxmCTfos46l7kUeaJ1TcsLx8wvQlT0Hnh5Z23IQKa91VtXFFGfj9rTAgr7y38wWmN72142HnnXPiy7XdOQnf3ywQWo4HHBwzBxHgMDCJFHXDhH6iICLFSfvkVZU4ZTWcAklfb44nBXo32KLMd3YrWW1BVkJMRCuHAt6dg2pvtjhvI7pv2ZCzG2sNfYaI0XNhXJCrCeotNZd60fSNF40o7wZMwtBxzIKjV0xaQpIKCc1gpxavV0kUAsQoPgedil4KmY8yLUAMCrzb5KaHoBNPatF3RanAZHFY0rDKgPVwyRsqgImIFnGftCS7c332ZU2z9NdlurYwRHnFyonWa0bFJgtN8RvXGHGWRK2zxj3WfUAvOqnFro8S0Tpcz1xxL1PgfkQXpdIhTAXK6E2UOArPaMmGqbLhf85CLCeTtvtVPGt7EBSJc5SsZiIvLoAOVCpejnrFI2HgxCPYmi2kXkc7pT47VEOha4p7H34PyMhEM3CTmKp5bEXx9LR7Gt0TbmU";
	
	string leng2048 = leng1024 + leng1024;
	string leng4096 = leng2048 + leng2048;
	
	copy(leng1024.begin(), leng1024.end(), MSG1);
	copy(leng2048.begin(), leng2048.end(), MSG2);
	copy(leng4096.begin(), leng4096.end(), MSG3);
	
	gettimeofday(&mainstart, 0);
	
	pid_t this_pid = fork();
	
	if (this_pid == 0) {
		// this is the child, will be writer
		cout << "Writer is awake..." << endl;
		int fd;
		char * myfifo = "fifo";
		
		/* create the FIFO (named pipe) */
		mkfifo(myfifo, 0666);
		
		/* write "Hi" to the FIFO */
		fd = open(myfifo, O_WRONLY);
		write(fd, MSG3, sizeof(MSG3));
		write(fd, "Bye", sizeof("Bye"));
		close(fd);
		
		/* remove the FIFO */
		unlink(myfifo);
		
		return 0;
		
	} else {
		usleep(waittime);
		
		// this is the parent, will be reader
		cout << "Reader is awake..." << endl;
		
		int fd;
		char * myfifo = "fifo";
		char buf[MAX_BUF];
		
		/* open, read, and display the message from the FIFO */
		fd = open(myfifo, O_RDONLY);
		
		while (strcmp(buf,"Bye") != 0) {
			read(fd, buf, MAX_BUF);
			cout << "Size of buf: " << sizeof(buf) << endl;
			cout << "Received: " << string(buf) << endl;
		}
		
		gettimeofday(&mainend, 0);
		printtimediff(&mainstart, &mainend); //calculate time elapsed
		
		close(fd);
		
		return 0;
	}
}

void printtimediff(struct timeval* a, struct timeval* b) {
	long long sec = b->tv_usec - a->tv_usec;
  	cout << "timed " << sec << " usec" << endl;
}
