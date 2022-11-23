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
#include "Logger.h"

using namespace std;

int Customer::customerSupport()
{
    int sock = ZERO, valread, client_fd;
    struct sockaddr_in serv_addr;
    //char* hello = "Hello from client";
    char buffer[MAX] = { ZERO };
    if ((sock = socket(AF_INET, SOCK_STREAM, ZERO)) < ZERO) {
        error("\n Socket creation error \n");
        return -ONE;
    }
 
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
 
    // Convert IPv4 and IPv6 addresses from text to binary
    // form
    if (inet_pton(AF_INET, "10.0.2.15", &serv_addr.sin_addr)
        <= ZERO) {
        error("\nInvalid address/ Address not supported \n");
        return -ONE;
    }
 
    if ((client_fd
         = connect(sock, (struct sockaddr*)&serv_addr,
                   sizeof(serv_addr)))
        < ZERO) {
        error("\nConnection Failed \n");
        return -ONE;
    }
    while(ONE){
	    info("Enter your message: ");
	    bzero(buffer,MAX);
	   cin>>buffer;
	   // fgets(buffer,1024,stdin);
	   // cin.getline(buffer,1024);
	    
	    valread=write(sock,buffer,strlen(buffer));
	    if(valread<ZERO)
		    error("Error on writing");
	    bzero(buffer,MAX);
	    valread = read(sock, buffer, MAX);
	    if(valread<ZERO)
		    error("Error on reading.");
	    notice("Server Message: ");
	    printf("%s\n",buffer);

	    int i=strcmp("Welcome",buffer);
	    if(i==ZERO)
		    break;
	   // close(client_fd); 
    }

	
    // closing the connected socket*/
    close(client_fd);
    return ZERO;
}
