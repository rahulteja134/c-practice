#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int val; struct Node *next; } Node;

void push(Node **top, int v){
    Node *n = malloc(sizeof *n);
    n->val = v; n->next = *top; *top = n;
}

int pop(Node **top){
    if (!*top) return 0;
    Node *t = *top; int v = t->val; *top = t->next; free(t); return v;
}

int main(void){
    Node *top = NULL;
    push(&top, 5); push(&top, 10); push(&top, 15);
    printf("%d\n", pop(&top));
    printf("%d\n", pop(&top));
    printf("%d\n", pop(&top));
    return 0;
}
