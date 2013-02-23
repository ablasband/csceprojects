# makefile

all: client dataserver client

reqchannel.o: reqchannel.H reqchannel.C
	g++ -c reqchannel.C -o reqchannel.o

dataserver: dataserver.C reqchannel.o 
	g++ dataserver.C reqchannel.o -o dataserver.o

client: client.C reqchannel.o
	g++ client.C reqchannel.o -o client

