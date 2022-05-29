#include "network.h"

#define NUM_CONNECTS 16

//Can accept up to 16 connections... for now
static int connections[NUM_CONNECTS];

int main() {

	memset(connections, 0x00, NUM_CONNECTS);

	serverSetup();

	while(1) {
		serverConnect(connections, NUM_CONNECTS);	
	}

	return 0;
}