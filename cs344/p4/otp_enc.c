#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	
	char buffer[256];
	//error checking
	if (argc < 4)
		error("ERROR in arguments");
	//set up port as given in argument
	portno = atoi(argv[3]);
	//set up socket fd
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	//error checking
	if (sockfd < 0)
		error("ERROR opening socket");
	//set up server
	server = gethostbyname("localhost"); //is this correct?
	//error checking
	if (server == NULL)
		error("ERROR, no such host");
	
	//zero the bits of the server address
	bzero((char*) &serv_addr, sizeof(serv_addr));
	//set up server struct
	serv_addr.sin_family = AF_INET;
	bcopy((char*)server->h_addr, (char*)&serv_addr.sin_addr.s_addr,
			server->h_length);
	//set port
	serv_addr.sin_port = htons(portno);
	//error checking
	if (connect(sockfd,(struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		error("ERROR connecting");
	printf("writing to otp_enc_d...\n");
	bzero(buffer,256);
	//set buffer to be the args to otp_enc_d
	fgets(buffer,255/*why 255?*/,stdin);
	//write buffer to socket
	n = write(sockfd,buffer,strlen(buffer));
	//error checking
	if (n < 0)
		error("ERROR writing to socket");
	//get input from socket
	//clean the buffer
	bzero(buffer,256);
	//read
	n = read(sockfd,buffer,255);
	//error checking
	if (n < 0)
		error("ERROR reading from socket");
	//print results of daemon
	printf("%s\n",buffer);

	close(sockfd);
	return 0;
	
		

}
