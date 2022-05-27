#ifndef NETWORK_H
#define NETWORK_H

#include <stdio.h>			//For networking
#include <unistd.h>			//For read networking function
#include <stdint.h>			//For uint types
#include <sys/socket.h>		//For socket creation
#include <sys/types.h>		//For socket creation
#include <arpa/inet.h>		//For networking
#include <errno.h>			//Error reporting
#include <err.h>			//Error reporting
#include <string.h>			//Error reporting

//Sets up connection to the server 
//provided an IP and port number
int netSetup(const char* ip, uint16_t port);

//Reads data from the server
void netRead();

//Destroys the connection to the
//server and properly handles memory
//Returns success or failure
void netShutdown();

#endif