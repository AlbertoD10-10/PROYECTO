#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>

int main(){
    int server_socket = socket(AF_INET , SOCK_STREAM,0);

struct sockaddr_in server_address;
server_address.sin_family = AF_INET;
server_address.sin_port = htons(80);
server_address.sin_addr.s_addr = INADDR_ANY;

bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

listen(server_socket,5);

printf("HTTP Server Initialized\n Port: %d\n",80);

int client_socket = accept(server_socket,NULL,NULL);
return 0;
}