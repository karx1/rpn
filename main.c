#include "stdio.h"
#include "stdlib.h"
#include <string.h>

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

typedef struct {
    int size;
    int cap;
    int* ptr;
} Stack;

Stack create_stack() {
    Stack s;
    s.size = 0;
    s.cap = 2;
    s.ptr = (int*) malloc(s.cap * sizeof(int));

    return s;
}

void resize(Stack* s) {
    s->cap = s->cap * 2;
    s->ptr = (int*) realloc(s->ptr, s->cap * sizeof(int));
}

void push(Stack* s, int val) {
    if (s->size > s->cap) {
        resize(s);
    }

    s->ptr[s->size] = val;
    s->size++;
}

int pop(Stack* s) {
    int val = s->ptr[s->size - 1];
    s->size--;
    return val;
}

void stack_free(Stack* s) {
    free(s->ptr);
}

int main() {
    char* line = NULL;

    Stack s = create_stack();
    push(&s, 1);
    push(&s, 1);
    printf("%d %d\n", s.ptr[0], s.ptr[1]);
    
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

    stack_free(&s);
    free(line);
    return 0;
}
