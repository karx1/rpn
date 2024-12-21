#include "stdio.h"
#include "stdlib.h"
#include <string.h>

char* gline() {
    int cap = 2;
    char* line = (char*) malloc(cap*sizeof(char));
    int size = 0;
    char c;
    c = getchar();

    while (c != '\n') {
        if (size > cap) {
            cap = cap * 2;
            line = (char*) realloc(line, cap);
        }

        line[size] = c;
        size++;
        c = getchar();
    }

    // trim pointer to fit
    line = (char*) realloc(line, size);
    return line;
}

int main() {
    char* line = NULL;
    
    while (1) {
        printf("Enter a line:\n");
        line = gline();
        if (strcmp(line, "done") == 0) {
            break;
        }
        
        char* pch;

        pch = strtok(line, " ");
        while (pch != NULL) {
            printf("%s\n", pch);
            pch = strtok(NULL, " ");
        }
    }

    free(line);
    return 0;
}
