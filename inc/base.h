#ifndef BASE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sockets
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

// Constants
#define TRUE 1
#define FALSE 0
#define ENV 1
#define REC 2
#define CAL 3
#define ERROR -1

void error(char *msg);

#endif