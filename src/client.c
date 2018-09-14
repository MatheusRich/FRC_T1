#include <base.h>
#include <client.h>

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

  int operation = get_operation(argv_operation);
  switch(operation) { // Handle operation
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
