#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
using namespace std;
class Server{
	int hSocket;
	int sock;
public:
	Server();
	void listen_(int);
	string receive();
	void send_(string);
	void close_();
};
Server::Server(){
	this->hSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(hSocket==-1){cerr<<"Socket Not Properly Constructed\n";}
}
void Server::listen_(int ClientPort){
	int iRetval=-1;
	struct sockaddr_in  remote={0};
	remote.sin_family = AF_INET; /* Internet address family */
	remote.sin_addr.s_addr = htonl(INADDR_ANY); /* Any incoming interface */
	remote.sin_port = htons(ClientPort); /* Local port */
	iRetval = bind(this->hSocket,(struct sockaddr *)&remote,sizeof(remote));
    if(iRetval<0){
    	cerr<<"Error in binding\n";
    	return;
    }
    listen(this->hSocket , 3);
}
string Server::receive(){
	int socket_desc  , clientLen;
	struct sockaddr_in server , client;
	char client_message[200]={0};
	clientLen = sizeof(struct sockaddr_in);
	this->sock = accept(this->hSocket, (struct sockaddr *)&client, (socklen_t*)&clientLen);
	if (this->sock < 0){
			cerr<<("accept failed");
			return " ";
	}
	memset(client_message, '\0', sizeof client_message);
	if( recv(this->sock , client_message , 200 , 0) < 0){
			cout<<("recv failed");
			return " ";
	}
	string cli_m(client_message);
	return cli_m;
}
void Server::send_(string msg){
	if( send(this->sock , msg.c_str() , msg.length() , 0) < 0)
		{
			cout<<"Send failed";
			return ;
		}
}
void Server::close_(){
	close(this->sock);
	close(this->hSocket);
}
