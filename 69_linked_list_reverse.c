#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int v; struct Node *next; } Node;

Node* push(Node *head,int v){ Node *n=malloc(sizeof *n); n->v=v; n->next=head; return n; }

Node* reverse(Node *head){
    Node *prev = NULL, *cur = head;
    while (cur){ Node *nxt = cur->next; cur->next = prev; prev = cur; cur = nxt; }
    return prev;
}

int main(void){
    Node *h = NULL;
    h = push(h,1); h = push(h,2); h = push(h,3); /* list 3->2->1 */
    h = reverse(h); /* becomes 1->2->3 */
    for (Node *p = h; p; p = p->next) printf("%d ", p->v);
    printf("\n");
    return 0;
}
