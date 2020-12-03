//2017030073
#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>//socketaddr_in, read, write
#include<arpa/inet.h>//htnol, htons, INADDR_ANY, sockaddr_in
#include<sys/socket.h>

void error_handling(char *message);

int main(int argc, char* args[]){
	int listensd;
	int connectsd;
	int n;
	int bytesToRecv;
	int processID;
	char buffer[256];
	char* movePtr;
	struct sockaddr_in serverAddr;
	struct sockaddr_in clientAddr;
	int clAddrLen;

	listensd = socket(PF_INET, SOCK_STREAM, 0);//socket(): make socket, SOCK_STREAM: TCP
	if(listensd == -1)
		error_handling("socket error");
	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family=AF_INET;//AF_INET: IPv4
	serverAddr.sin_addr.s_addr=htonl(INADDR_ANY);//htonl: change to big endian
	//INADDR_ANY: find server's address
	serverAddr.sin_port=htons(3550);
	
	if(bind(listensd, (struct sockaddr*)&serverAddr, sizeof(serverAddr))==-1)//bind address and port number at socket
		error_handling("bind error");

	if(listen(listensd, 5) == -1)//listen(): waiting for client connection request
		error_handling("listen error");
	
	while(1){
		connectsd = accept(listensd, (struct sockaddr*)&clientAddr, &clAddrLen);//accept(): establishing client connection	
		processID=fork();//fork(): make child process to handle request
		if(processID==0){
			printf("Client connected\n");
			bytesToRecv=256;
			movePtr=buffer;
			
			recv(connectsd, buffer, bytesToRecv,0);//recv(): receive data through socket

			send(connectsd, buffer, 256, 0);//send(): send data through socket
			
			close(listensd);//close(): end socket
			
			printf("Connection terminated\n");
			exit(0);
		}
		close(connectsd);
	}
}
void error_handling(char *message){
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
