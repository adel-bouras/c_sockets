#include <sys/socket.h>
#include <iostream>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>



int main(){

	int server = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in server_address;

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(8080);
        server_address.sin_addr.s_addr = INADDR_ANY;
	
	int bined = bind(server, (struct sockaddr *) &server_address, sizeof(server_address));

	if(bined == -1){
		std::cout<<"error binding \n";
		return 1;
	}


	listen(server, 2);
	std::cout<<"listening \n";
	int client = accept(server, NULL, NULL);

	char buffer[1024] = "hello from server";
	
	send(client, buffer, sizeof(buffer), 0);

	close(client);
	close(server);


	return 0;
}
