#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* create_node(int v){
    Node *p = malloc(sizeof *p);
    p->data = v; p->prev = p->next = NULL; return p;
}

void push_front(Node **head, int v){
    Node *n = create_node(v);
    n->next = *head;
    if (*head) (*head)->prev = n;
    *head = n;
}

void print_forward(Node *head){
    for (; head; head = head->next) printf("%d ", head->data);
    printf("\n");
}

int main(void){
    Node *head = NULL;
    push_front(&head, 10);
    push_front(&head, 20);
    push_front(&head, 30);
    print_forward(head); /* prints 30 20 10 */
    /* free memory */
    Node *cur = head;
    while (cur){ Node *t = cur->next; free(cur); cur = t; }
    return 0;
}
