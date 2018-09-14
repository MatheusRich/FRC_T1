#ifndef CLIENT_H
#include <base.h>
// Constants
#define ARG_AMOUNT 4
#define OPERATION_MAX_SIZE 3  // Characters
#define FILEPATH_MAX_SIZE 256 // Characters
#define SERVER_IP_MAX_SIZE 15 // Characters

void validate_argc(int argc);
int get_operation(char *argv_operation);
int client(int argc, char **argv);

#endif

