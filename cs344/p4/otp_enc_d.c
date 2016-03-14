#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
	perror(msg);
	exit(1);
}

char* crypt(char* input)
{
	char *buffer;
	char *text;
	int k,i,r;
	buffer = strtok(input," \n");
	printf("file to encode=%s\n",buffer);

	//careful, this might be a bad idea
	FILE* SRC = fopen(buffer,"r");
	if (SRC == NULL)
		error("ERROR opening src");


	buffer = strtok(NULL," \n");
	printf("key file=%s\n",buffer);
	
	FILE* KEY = fopen(buffer,"r");

	if (KEY == NULL)
		error("ERROR opening key");

	do //while key is not empty and while file is not empty
	{
		i = fgetc(SRC);
		if (i == EOF || i == '\n')
		{
			printf("src: end of file");
			break;
		}
		if (i == ' ')
			i = 91;
		//add space case here

		k = fgetc(KEY); 
		if (k == EOF)
		{
			printf("key: end of file");
			break;
		}
		if (k == ' ')
			k = 91;
		//add space case here

		r = (i - 64 + k - 64)%27;
		
		//trace statements here
		printf("src char: %c,%d,%d\t",i,i,i-64);
		printf("key char: %c,%d,%d\t",k,k,k-64);
		printf("res char: %c,%d,%d\t",r+64,r+64,r);	
		printf("\n");
		//end trace statements
		
		fprintf(stdout,"%c",r+64);

	} while	(k != EOF && i != EOF);

	fclose(SRC);
	fclose(KEY);

	return buffer;
}

int main(int argc, char* argv[])
{
	int sockfd,newsockfd,portno,n;
	socklen_t clilen; //what does this do?
	char buffer[256];
	char *cryptb;
	struct sockaddr_in serv_addr, cli_addr;
	
	if (argc < 2)
	{
		fprintf(stderr,"ERROR, no port proivded\n");
		exit(1);
	}

	//set up socket FD
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	//error checking
	if (sockfd < 0)
		error("ERROR opening socket");
		//brewster's error code; does what expected? maybe
	
	bzero((char*) &serv_addr, sizeof(serv_addr)); //put zeroes in server addy
	portno = atoi(argv[1]); //set port # from FIRST arg; correct here but care
	//set up listening on a port
	serv_addr.sin_family = AF_INET; //IP
	serv_addr.sin_addr.s_addr = INADDR_ANY; //any IPv4 addy
	serv_addr.sin_port = htons(portno); //port = given arg to program
	//bind socket to desired port, do some error checking
	if (bind(sockfd, (struct sockaddr *) &serv_addr,
				sizeof(serv_addr)) < 0)
		error("ERROR on binding");
	//listen to up to **5** connections
	listen(sockfd,5);
	//set length of client address
	clilen = sizeof(cli_addr);
	//fd to be accepting input on
	newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr, &clilen);
	//error checking
	if (newsockfd < 0)
		error("ERROR on accept");
	bzero(buffer,256); //zero the buffer
	//read 255 characters from the socket at newsockfd (client),
	//into buffer, stores result of read call in n
	n = read(newsockfd,buffer,255);
	//error checking on read
	if (n < 0)
		error("ERROR reading from socket"); //perhaps specify socket?
	//DO ENCRYPTING OR DECRPYTING HERE once you've read the message! NBD?
	
	printf("Let's do some cryptography!\n");
	printf("string read in is %s\n",buffer);

	cryptb = crypt(buffer);

	//write encrypted message back to connected process
	//note: change "buffer" to whatever your result of encryption is
	n = write(newsockfd,buffer,sizeof(buffer));
   	//NB #arg is # **BYTES** allowed
	if (n < 0)
		error("ERROR writing to socket");
	//close up connections
	close(newsockfd);
	close(sockfd);
	return 0;
	
}
