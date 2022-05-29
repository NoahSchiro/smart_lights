#ifndef NETWORK_H
#define NETWORK_H

#include <stdio.h>			//For networking
#include <arpa/inet.h>		//For networking
#include <unistd.h>			//For write networking function
#include <stdint.h>			//For uint types
#include <sys/socket.h>		//For socket creation
#include <sys/types.h>		//For socket creation
#include <errno.h>			//Error reporting
#include <err.h>			//Error reporting
#include <string.h>			//Error reporting

//Sets up connection to the server 
//provided an IP and port number
int serverSetup();

//Handles incoming connections
int serverConnect(int*, int);

//Reads data from the server
int serverWrite(int);

//Destroys the connection to the
//server and properly handles memory
//Returns success or failure
void serverShutdown();

#endif