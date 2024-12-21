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
    long* ptr;
} Stack;

Stack create_stack() {
    Stack s;
    s.size = 0;
    s.cap = 2;
    s.ptr = (long*) malloc(s.cap * sizeof(long));

    return s;
}

void resize(Stack* s) {
    s->cap = s->cap * 2;
    s->ptr = (long*) realloc(s->ptr, s->cap * sizeof(long));
}

void push(Stack* s, long val) {
    if (s->size > s->cap) {
        resize(s);
    }

    s->ptr[s->size] = val;
    s->size++;
}

long pop(Stack* s) {
    long val = s->ptr[s->size - 1];
    s->size--;
    return val;
}

void stack_free(Stack* s) {
    free(s->ptr);
}

int main() {
    char* line = NULL;

    Stack s = create_stack();
    /* push(&s, 3);
    push(&s, 4);
    printf("%d %d\n", s.ptr[0], s.ptr[1]); */
    
    while (1) {
        printf("Enter a line:\n");
        line = gline();
        if (strcmp(line, "done") == 0) {
            break;
        }
        
        char* token;

        token = strtok(line, " ");
        while (token != NULL) {
            printf("%s\n", token);
            if (strcmp(token, "+") == 0) {
                int a = pop(&s);
                int b = pop(&s);
                push(&s, a + b);
            } else if (strcmp(token, "*") == 0) {
                int a = pop(&s);
                int b = pop(&s);
                push(&s, a * b);
            } else if (strcmp(token, "-") == 0) {
                int b = pop(&s);
                int a = pop(&s);
                push(&s, a - b);
            } else if (strcmp(token, "/") == 0) {
                int b = pop(&s);
                int a = pop(&s);
                push(&s, a / b);
            } else {
                char* endptr;
                long num = strtol(token, &endptr, 10);
                if (endptr == token) {
                    printf("Failed to convert an argument, skipping!");
                    break;
                } else {
                    push(&s, num);
                }
            }
            token = strtok(NULL, " ");
        }
    }

    printf("%zu\n", pop(&s));
    stack_free(&s);
    free(line);
    return 0;
}
