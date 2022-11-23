#include"server_client.h"
#include<iostream>
#include "Logger.h"
using namespace std;
int main(int argc, char const* argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = ONE;
    int addrlen = sizeof(address);
    char buffer[MAX] = { ZERO };
   // char* hello = "Hello from server";
 
    
    if ((server_fd = socket(AF_INET, SOCK_STREAM, ZERO)) < ZERO) {
        error("socket failed");
        exit(EXIT_FAILURE);
    }
 
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET,
                   SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt))) {
        error("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
   address.sin_addr.s_addr=inet_addr("10.0.2.15");
    // address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
 
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr*)&address,
             sizeof(address))
        < ZERO) {
        error("bind failed");
        exit(EXIT_FAILURE);
    }
   
    if (listen(server_fd, THREE) < ZERO) {
        error("listen");
        exit(EXIT_FAILURE);
    }
client:
    if ((new_socket
         = accept(server_fd, (struct sockaddr*)&address,
                  (socklen_t*)&addrlen))
        < ZERO) {
        error("accept");
        exit(EXIT_FAILURE);
    }
 
    while(ONE){
	     bzero(buffer,MAX);


           // printf("\n:");
           // fgets(buffer,1024,stdin);
            valread=read(new_socket,buffer,MAX);
            if(valread<ZERO)
                    perror("Error on reading");
	    notice("Customer Message :");
	    printf("%s\n",buffer);
            bzero(buffer,MAX);
	    info("Enter your msg :");
	  // fgets(buffer,1024,stdin);
	   cin>>buffer;
	  //cin.getline(buffer,MAX);
            valread = write(new_socket, buffer, strlen(buffer));
            if(valread<ZERO)
                    error("Error on Writing.");
      

            if(strcmp("Welcome",buffer)==ZERO)
                   break;
    }
  
    close(new_socket);
    goto client;
 
    shutdown(server_fd, SHUT_RDWR);
    return ZERO;
}
