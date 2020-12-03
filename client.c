//2017030073
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
void error_handling(char *message);
int main(int argc, char* args[]){
	int sd;
	int n;
	int bytesToRecv;
	char sendBuffer[256];
	char recvBuffer[256];
	char* movePtr;
	struct sockaddr_in serverAddr;

	sd=socket(PF_INET, SOCK_STREAM, 0);//socket(): make socket, SOCK_STREAM: TCP
	if(sd == -1)
		error_handling("Socket error");

	memset(&serverAddr,0, sizeof(serverAddr));
	serverAddr.sin_family=AF_INET;//AF_INET: IPv4
	inet_pton(AF_INET, "server address", &serverAddr.sin_addr);//inet_pton(): change to IP adress by server name
	serverAddr.sin_port=htons(3550);//set port number
	
	if(connect(sd, (struct sockaddr*)&serverAddr, sizeof(serverAddr))==-1)//connect(): send a connection request through the socket
		error_handling("Connect error");

	fgets(sendBuffer,256,stdin);
	if(send(sd,sendBuffer,strlen(sendBuffer),0)==-1)//send(): send data through socket
		error_handling("Send error");

	bytesToRecv=strlen(sendBuffer);
	movePtr=recvBuffer;

	recv(sd, movePtr, bytesToRecv, 0);//recv(): receive data through socket
	recvBuffer[bytesToRecv]=0;

	printf("Received from server: ");
	fputs(recvBuffer, stdout);
	
	if(close(sd)==0)
		printf("Connection terminated\n");
	exit(0);
}
void error_handling(char* message){
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
