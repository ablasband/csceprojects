# makefile

all: dataserver client

NetworkRequestChannel.o: NetworkRequestChannel.H NetworkRequestChannel.C
	g++ -c -g NetworkRequestChannel.C
	
semaphore.o: semaphore.H semaphore.C
	g++ -c -g semaphore.C -o semaphore.o
	
#item.o: item.H
#	g++ -c -g item.H
	
#boundedbuffer.o: boundedbuffer.H boundedbuffer.C semaphore.H
#	g++ -c -g boundedbuffer.C -o boundedbuffer.o

dataserver: dataserver.C NetworkRequestChannel.o 
	g++ -g dataserver.C NetworkRequestChannel.o -o dataserver.o -lsocket -lnsl
	
#client: client.C reqchannel.o semaphore.o boundedbuffer.o item.o
client: client.C NetworkRequestChannel.o semaphore.o
	g++ -g client.C semaphore.o NetworkRequestChannel.o -o client -lsocket -lnsl
	
clean:
	rm -f *.o core
