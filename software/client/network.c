#include "network.h"

// the client socket descriptor 
//for the connection to the server
static int cli_sd = -1;

/* 
Connects to server
*/
int netSetup(const char *ip, uint16_t port) {

	//Create a socket
	cli_sd = socket(PF_INET, SOCK_STREAM, 0);

	//If it fails, return false
	if(cli_sd == -1) {
	printf("Error on socket creation [%s]\n", strerror(errno));
	return 0;
	}

	//Setup the address to connect
	struct sockaddr_in addr;		//Connection address
	addr.sin_family = AF_INET;	//Protocol definition
	addr.sin_port = htons(port);	//Port definiton

	//Try to create the address
	if(inet_aton(ip, &addr.sin_addr) == 0) {
	printf("Failed on address creation\n");
	return 0;
	}

	//Try to connect to the server
	if(connect(cli_sd, 
			(const struct sockaddr *)&addr, 
			sizeof(addr)) == -1) {

	printf("Failed attempting to connect\n");
	return 0;
	}

	//If everything succeeds, return true
	return 1;
}

/*
Will read network data in a continuous loop until told to stop
*/
void netRead() {

	//Store data
	uint8_t packet;

	//Try to read data from network into packet
	if(read(cli_sd, &packet, sizeof(packet)) == -1) {
		
		printf("Error reading network data [%s]\n", strerror(errno));
	
	//Else we read the packet succesfully!
	} else {

		printf("Recieved packet from server...\n");
		//TODO: logic with this packet

	}
}

/*
Disconnects from server
*/
void netShutdown() {

	//Close connection
	close(cli_sd);

	//Reset to -1
	cli_sd = -1;
}