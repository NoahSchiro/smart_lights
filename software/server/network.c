#include "network.h"

#define PACKET_SIZE 8;

static int      server     = -1;
static uint16_t serverPort = 5005;

/*
Opens up a server port
*/
int serverSetup() {

    //Will hold address data for server and incoming clients
    struct sockaddr_in serverAddr;

    //Define server address parameters
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    //Create a socket
    server = socket(AF_INET, SOCK_STREAM, 0);
    
    //If socket creation fails, report it
    if(server == -1) {
        printf("Error on socket creation [%s]\n", strerror(errno));
        close(server);
        server = -1;
        return 0;
    } else {
        printf("Created socket...\n");
    }

    //Try to bind that socket to a port
    if(bind(server, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) == -1) {
        printf("Error on socket bind [%s]\n", strerror(errno));
        close(server);
        server = -1;
        return 0;
    } else {
        printf("Socket bound to %d...\n", serverPort);    
    }

    //Prepare the server for incoming client requests. In this case, 5 
    //is the max backlog we will allow though this should not matter with
    //threading enabled
    if(listen(server, 5) == -1) {
        printf("Error on socket listen [%s]\n", strerror(errno));
        return 0;
    } else {
        printf("Listening...\n");
    }

    //Server is set up
    return 1;
}

/*
Accepts incoming connections from clients and 
hands them off to a thread. TODO: Implement threads
*/
int serverConnect(int* connections, int size) {

    //Ensure that the server is live
    if(server == -1) {
        printf("Server is not set up! Failing...\n");
        return -1;
    }
    
    //Setup client info
    int clientFD;
    struct sockaddr_in clientAddr;
    int len = sizeof(clientAddr);

    //Accept a connection to this client
    clientFD = accept(server, (struct sockaddr *) &clientAddr, &len);
    if(clientFD == -1) {
        printf("Could not accept client!\n");
        return -1;
    } else {
        printf("Server accepted new client\n");
    }

    //Look for an available slot where we can put the client into our array
    for(int i = 0; i < size; i++) {

        if(connections[i] == 0) {
            connections[i] = clientFD;
            break;
        }

        //If array is full
        if(i == size-1 && connections[i] != 0) {
            printf("Connections are full! Failing...\n");
            return -1;
        }
    }

    return 1;
}

/*
Writes data to a given client
*/
int serverWrite(int clientFD) {

    //Ensure that the server is live
    if(server == -1) {
        printf("Server is not set up! Failing...");
        return -1;
    }
}

/*
Close server
*/
void serverShutdown() {
    
    //Ensure that the server is live
    if(server == -1) {
        printf("Server is not set up! Failing...");
        return;
    }

    close(server);
    server = -1;
}