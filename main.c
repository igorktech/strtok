#include <stdio.h>
#include "simple_strtok.h"
#include <assert.h>
int main() {
    char testString[] = "Hello, world!;Hello, world!";
    
    char* delimiters = ",;";

    char* token = simple_strtok(testString, delimiters);
    while (token != NULL) {
        printf("Current token: %s\n", token);
        token = simple_strtok(NULL, delimiters);
    }
    
    return 0;
}
