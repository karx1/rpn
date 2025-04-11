#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include "ll.h"

char* gline() {
    int cap = 2 * sizeof(char);
    char* line = (char*) malloc(cap);
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
        printf(">> ");
        line = gline();
        if (strcmp(line, "done") == 0) {
            break;
        }
        
        char* token;
        ll_node_t* top = NULL;

        token = strtok(line, " ");
        while (token != NULL) {
            /* printf("%s\n", token); */
            if (strcmp(token, "+") == 0) {
                long a = top->data;
                top = remove_front(top);
                long b = top->data;
                top = remove_front(top);

                top = insert_front(a + b, top);
            } else if (strcmp(token, "*") == 0) {
                long a = top->data;
                top = remove_front(top);
                long b = top->data;
                top = remove_front(top);

                top = insert_front(a * b, top);
            } else if (strcmp(token, "-") == 0) {
                long b = top->data;
                top = remove_front(top);
                long a = top->data;
                top = remove_front(top);

                top = insert_front(a - b, top);
            } else if (strcmp(token, "/") == 0) {
                long b = top->data;
                top = remove_front(top); 
                long a = top->data;
                top = remove_front(top);

                top = insert_front(a / b, top);
            } else {
                char* endptr;
                long num = strtol(token, &endptr, 10);
                if (endptr == token) {
                    printf("Failed to convert an argument, skipping!\n");
                    break;
                } else {
                    top = insert_front(num, top);
                }
            }
            /* dbg_stack(&s); */
            token = strtok(NULL, " ");
        }

        printf("%d\n", top->data);
    }

    free(line);
    return 0;
}
