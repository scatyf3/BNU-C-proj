#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUFFERSIZE 100

char* ask_for_input(char buffer[BUFFERSIZE]){
    printf(">");
    fgets(buffer, BUFFERSIZE , stdin);
    strtok(buffer, "\r\n");
}