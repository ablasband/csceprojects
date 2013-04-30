# makefile

all: dataserver client

semaphore.o: semaphore.H semaphore.C
	g++ -c semaphore.C

NetworkRequestChannel.o: NetworkRequestChannel.H NetworkRequestChannel.C semaphore.o
	g++ -c -g NetworkRequestChannel.C semaphore.o
	
dataserver: dataserver.C NetworkRequestChannel.o semaphore.o
	g++ -g -o dataserver dataserver.C NetworkRequestChannel.o semaphore.o -lsocket -lnsl


client: client.C NetworkRequestChannel.o semaphore.o
	g++ -g -o client client.C NetworkRequestChannel.o semaphore.o -lsocket -lnsl