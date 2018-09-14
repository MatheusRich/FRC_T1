#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define ARG_AMOUNT 4
#define OPERATION_MAX_SIZE 2 // Characters
#define FILEPATH_MAX_SIZE 256  // Characters
#define SERVER_IP_MAX_SIZE 15 // Characters
#define ENV 1
#define REC 2
#define CAL 3
#define ERROR -1

void validate_argc(int argc) {
  if (argc != ARG_AMOUNT)
  {
    printf("ERROR: Insufficient arguments!\n");

    exit(-1);
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

  int operation = get_operation(argv_operation);

  switch(operation) {
    case ENV:
      printf("env\n");
      break;
    case REC:
      printf("rec\n");
      break;
    case CAL:
      printf("cal\n");
      break;
    default:
      printf("ERROR: Invalid Operation!\n");
  }

  //Abrir arquivo
  //Abrir arquivo
  return 0;
}
