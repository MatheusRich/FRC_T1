#include <base.h>
#include <client.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define SERV_PORT 6100
#define MAXLINE 1024
#define END_FLAG "END"

void validate_argc(int argc) {
  if (argc < ARG_AMOUNT) {
    error("Insufficient arguments!");
  } else if (argc > ARG_AMOUNT) {
    error("Too many arguments!");
  }
}

int get_operation(char *argv_operation) {
  if (!strcmp(argv_operation, "-e")) {
    return ENV;
  } else if (!strcmp(argv_operation, "-r")) {
    return REC;
  } else if (!strcmp(argv_operation, "-c")) {
    return CAL;
  } else {
    return ERROR;
  }
}


int main(int argc, char **argv) {
  validate_argc(argc);
  // TODO: validate_argv(argv);

  char argv_operation[OPERATION_MAX_SIZE], file_path[FILEPATH_MAX_SIZE], server_ip[SERVER_IP_MAX_SIZE] = "";
  strcpy(argv_operation, argv[1]);
  strcpy(file_path, argv[2]);
  strcpy(server_ip, argv[3]);

  int sockfd, n, file;
  struct sockaddr_in serveraddr;
  char buf[MAXLINE];

  bzero(&serveraddr, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons(SERV_PORT);
  inet_pton(AF_INET, argv[1], &serveraddr.sin_addr);

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
 

  int operation = get_operation(argv_operation);
  switch(operation) { // Handle operation
    case ENV:
      file = open(file_path, O_RDONLY);
      printf();
      while ((n = read(file, buf, MAXLINE)) > 0) {
        sendto(sockfd, buf, n, 0, (struct sockaddr *) &serveraddr, sizeof(serveraddr));
      }
      sendto(sockfd, END_FLAG, strlen(END_FLAG), 0, (struct sockaddr *) &serveraddr, sizeof(serveraddr));
      close(file);
      break;
    case REC:
      printf("rec\n");
      break;
    case CAL:
      printf("cal\n");
      break;
    default:
      error("Invalid Operation!");
  }

  // // Opening file
  // FILE *file;
  // file = fopen(file_path, "r");

  // if (file == NULL) {
  //   error("File could not be opened!");
  // }
    
  return 0;
}
