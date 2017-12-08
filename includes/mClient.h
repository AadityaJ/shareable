#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define MX 10000
using namespace std;
class Client
{
	int cliSocket;
public:
	Client(int port);
	int Send(string str);
	string receive();
};
Client::Client(int port){
	this->cliSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(this->cliSocket==-1){
       	cout<<"Socket not properly constructed\n"; return ;
    }
    int iRetval=-1;
    int ServerPort = port;
    struct sockaddr_in remote={0};
    remote.sin_addr.s_addr = inet_addr("127.0.0.1"); //Local Host
    remote.sin_family = AF_INET;
    remote.sin_port = htons(ServerPort);
    iRetval = connect(this->cliSocket , (struct sockaddr *)&remote , sizeof(struct sockaddr_in));
    if(iRetval < 0){
    	cerr<<"Error in Listening\n";
    	return;
    }
}
int Client::Send(string str){
	int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;  /* 20 Secs Timeout */
    tv.tv_usec = 0;
 	const char *Rqst=str.c_str();
    if(setsockopt(this->cliSocket, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv,sizeof(tv)) < 0){
         cerr<<"Timeout\n";
      return -1;
    }
    shortRetval = send(this->cliSocket , Rqst , str.length() , 0);
    return shortRetval;
}
string Client::receive(){
	int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;  /* 20 Secs Timeout */
    tv.tv_usec = 0;
    if(setsockopt(this->cliSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv,sizeof(tv)) < 0){
        cout<<("Time Out\n");
        return " ";
    }
    char Rsp[MX]={0};
    int RvcSize=sizeof(Rsp);
	shortRetval = recv(this->cliSocket, Rsp , RvcSize , 0);
    string resp(Rsp);
    return resp;
}
