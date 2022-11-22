#include "server_client.h"
/*#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include<ctype.h>
#define PORT 8080
*/

#include<iostream>

using namespace std;

int Customer::customerSupport()
{
    int sock = 0, valread, client_fd;
    struct sockaddr_in serv_addr;
    //char* hello = "Hello from client";
    char buffer[1024] = { 0 };
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
 
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
 
    // Convert IPv4 and IPv6 addresses from text to binary
    // form
    if (inet_pton(AF_INET, "10.0.2.15", &serv_addr.sin_addr)
        <= 0) {
        printf(
            "\nInvalid address/ Address not supported \n");
        return -1;
    }
 
    if ((client_fd
         = connect(sock, (struct sockaddr*)&serv_addr,
                   sizeof(serv_addr)))
        < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    while(1){
	    bzero(buffer,1024);
	 
	 
	   // printf("\n:");
	    //fgets(buffer,1024,stdin);
	    cin>>buffer;
	    valread=write(sock,buffer,strlen(buffer));
	    if(valread<0)
		    perror("Error on writing");
	    bzero(buffer,1024);
	    valread = read(sock, buffer, 1024);
	    if(valread<0)
		    perror("Error on reading.");
	    printf("Server:%s\n",buffer);

	    int i=strcmp("Welcome",buffer);
	    if(i==0)
		    break;
	   // close(client_fd); 
    }

	
    // closing the connected socket*/
    close(client_fd);
    return 0;
}
