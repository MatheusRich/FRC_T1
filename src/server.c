#include <base.h>
#include <server.h>

#include <fcntl.h>
#include <arpa/inet.h>

#define SERV_PORT 6100
#define MAXLINE 1024
#define END_FLAG "END"

void server_client_comunication(int sockfd, struct sockaddr *clientaddr, socklen_t client)
{
    int reecive_message, file;
    socklen_t client_size;
    char buf[MAXLINE];

    client_size = client;
    // reecive_message = recvfrom(sockfd, buf, MAXLINE, 0, clientaddr, &client_size);
    // buf[reecive_message] = 0;
    // printf("Received from client: [%s]\n", buf);
    // sendto(sockfd, "ok", strlen("ok"), 0, cliaddr, client_size);
    file = open(buf, O_RDWR | O_CREAT, 0666);

    while ((reecive_message = recvfrom(sockfd, buf, MAXLINE, 0, clientaddr, &client_size))) {
        buf[reecive_message] = 0;
        printf("%s", buf);
        if (!(strcmp(buf, END_FLAG))) {
            break;
        }
        write(file, buf, reecive_message);
    }
    printf("%s", buf);
    close(file);
  }


int main(int argc, char **argv)
{
  int sockfd;
  struct sockaddr_in serveraddr, clientaddr;

  //Creating socket
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  
  //Clean server address memory
  bzero(&serveraddr, sizeof(serveraddr));

  //Inicializando porta e ip do servidor
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
  serveraddr.sin_port = htons(SERV_PORT);

  //Liga o socket criado
  bind(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr));

  //Ação a ser realizada
  server_client_comunication(sockfd, (struct sockaddr *) &clientaddr, sizeof(clientaddr));

  return 0;
}