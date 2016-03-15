#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>

void error(const char *msg)
{
	perror(msg);
	exit(1);
}

char* decrypt(char* input)
{
	char *buffer;
	char text[256];
	char *ret;
	bzero(text,245);
	int k,i,r,tpos;
	buffer = strtok(input," \n");
	FILE* SRC = fopen(buffer,"r");
	if (SRC == NULL)
		error("ERROR otp_enc_d opening src");
	buffer = strtok(NULL," \n");
	FILE* KEY = fopen(buffer,"r");
	if (KEY == NULL)
		error("ERROR otp_enc_d opening key");
	do //while key is not empty and while file is not empty
	{
		i = fgetc(SRC);
		if (i == EOF || i == '\n')
		{
//			printf("src: end of file");
			break;
		}
		if (i == ' ')
			i = 64;
		//add space case here

		k = fgetc(KEY); 
		if (k == EOF)
		{
//			printf("key: end of file");
			break;
		}
		if (k == ' ')
			k = 64;
		//add space case here

		r = (i - 64 - k - 64);
		if (r < 0)
			r += 27;
		else if (r == 0)
			text[tpos] = ' ';
		else text[tpos] = r+64;
		
		//trace statements here
		printf("src char: %c,%d,%d\t",i,i,i-64);
		printf("key char: %c,%d,%d\t",k,k,k-64);
		printf("res char: %c,%d,%d\t",r+64,r+64,r);	
		//end trace statements
		if (r == 0)
		{
			text[tpos] = ' ';
		}
		else
		{	
			text[tpos] = r+64;
		}
		printf("\n");
		
		tpos++;

	} while	(k != EOF && i != EOF);

	fclose(SRC);
	fclose(KEY);
	ret = text;
	return ret;
}

int main(int argc, char* argv[])
{
	int sockfd,newsockfd,portno,n,status;
	int yes = 1;
	socklen_t clilen; //what does this do?
	pid_t cPid;
	char buffer[256];
	char *cryptb;
	struct sockaddr_in serv_addr, cli_addr;
	
	if (argc < 2)
	{
		fprintf(stderr,"ERROR otp_enc_d, no port proivded\n");
		exit(1);
	}

	//set up socket FD
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	//error checking
	if (sockfd < 0)
		error("ERROR otp_enc_d opening socket");
		//brewster's error code; does what expected? maybe
	
	if (setsockopt(sockfd,SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) < 0)
		error("ERROR otp_enc_d setting socket");

	bzero((char*) &serv_addr, sizeof(serv_addr)); //put zeroes in server addy
	portno = atoi(argv[1]); //set port # from FIRST arg; correct here but care
	//set up listening on a port
	serv_addr.sin_family = AF_INET; //IP
	serv_addr.sin_addr.s_addr = INADDR_ANY; //any IPv4 addy
	serv_addr.sin_port = htons(portno); //port = given arg to program
	//bind socket to desired port, do some error checking
	if (bind(sockfd, (struct sockaddr *) &serv_addr,
				sizeof(serv_addr)) < 0)
		error("ERROR otp_enc_d on binding");
	
	//listen to up to **5** connections
	listen(sockfd,5);
	
	//trace statement

	signal(SIGCHLD,SIG_IGN);

	while(1)
	{
//		printf("Beginning loop\n");
		//set length of client address
		clilen = sizeof(cli_addr);
		//fd to be accepting input on
		newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr, &clilen);
		//error checking
		if (newsockfd < 0)
			error("ERROR otp_enc_d on accept");
		switch(cPid = fork())
		{
			case 0:
//				printf("in child\n");
				close(sockfd);
				bzero(buffer,256); //zero the buffer
				//read 255 characters from the socket at newsockfd (client),
				//into buffer, stores result of read call in n
				n = read(newsockfd,buffer,255);
				//error checking on read
				if (n < 0)
					error("ERROR otp_enc_d reading from socket");
				
//				printf("Let's do some cryptography!\n");
//				printf("string read in is %s\n",buffer);
			
				cryptb = decrypt(buffer);
//				printf("cryptb = %s\n",cryptb);	
				//write encrypted message back to connected process
				n = write(newsockfd,cryptb,sizeof(char)*strlen(cryptb));
   				//NB #arg is # **BYTES** allowed
				if (n < 0)
					error("ERROR otp_enc_d writing to socket");
				exit(0);
				break;
			default:
//				printf("in parent\n");
				close(newsockfd);
				do
				{
					waitpid(cPid,&status,WUNTRACED);
				}
				while (!WIFEXITED(status) && !WIFSIGNALED(status));
				break;
		}
//		printf("--end of daemon loop--\n");
	}
	return 0;
	
}
