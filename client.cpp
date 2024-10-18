#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <thread>

void handlClient(){

}



int main(){
	int client = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in server_addr;
	
	server_addr.sin_port = htons(8080);
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;

	int connection_status = connect(client, (struct sockaddr *) &server_addr, sizeof(server_addr));
	if(connection_status == -1){
		std::cout<<"connection failed \n";
		return 1;
	}

	char buffer[1024];
	
	recv(client, buffer, sizeof(buffer), 0);
	
	std::cout<<buffer;
	
	close(client);
	return 0;
}
