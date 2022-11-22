#include"server_client.h"
int main(int argc, char const* argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = { 0 };
   // char* hello = "Hello from server";
 
    
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
 
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET,
                   SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
   address.sin_addr.s_addr=inet_addr("10.0.2.15");
    // address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
 
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr*)&address,
             sizeof(address))
        < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket
         = accept(server_fd, (struct sockaddr*)&address,
                  (socklen_t*)&addrlen))
        < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
 
    while(1){
	     bzero(buffer,1024);


           // printf("\n:");
           // fgets(buffer,1024,stdin);
            valread=read(new_socket,buffer,1024);
            if(valread<0)
                    error("Error on reading");
	    printf("Customer :%s\n",buffer);
            bzero(buffer,1024);
	    fgets(buffer,1024,stdin);
            valread = write(new_socket, buffer, strlen(buffer));
            if(valread<0)
                    perror("Error on Writing.");
      

            int i=strncmp("Thank You",buffer,3);
            if(i==0)
                   break;
    }
  
    close(new_socket);
 
    shutdown(server_fd, SHUT_RDWR);
    return 0;
}
