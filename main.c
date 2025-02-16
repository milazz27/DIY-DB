#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* buffer;
    size_t bufferLength;
    size_t inputLength; 
}InputBuffer;

InputBuffer* newInputBuffer(){
    InputBuffer* inputBuff = (InputBuffer*)malloc(sizeof(InputBuffer));
    inputBuff-> buffer = NULL;
    inputBuff->bufferLength = 0;
    inputBuff->inputLength = 0;

    return inputBuff;
}

void closeInputBuffer(InputBuffer* inputBuff){
    free(inputBuff->buffer);
    free(inputBuff);
}

void printPrompt() { printf("db > ");}

void readInput(InputBuffer* inputBuff){
    ssize_t bytesRead = getline(&(inputBuff->buffer), &(inputBuff->bufferLength), stdin);

    if(bytesRead <= 0){
        printf("Input Reading Error\n");
        exit(EXIT_FAILURE);
    }
    inputBuff->inputLength = bytesRead -1;
    inputBuff->buffer[bytesRead - 1] = 0;
}

int main(int argc, char** argv){
    InputBuffer* inputBuff = newInputBuffer();
    while(true){
        printPrompt();
        readInput(inputBuff);
    }

    if(strcmp(inputBuff->buffer, ".exit") == 0){
        closeInputBuffer(inputBuff);
        exit(EXIT_SUCCESS);
    }
    else{
        printf("Unrecognized Command '%s'.\n", inputBuff->buffer);
    }
    
}