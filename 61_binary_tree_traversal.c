#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

Node* new_node(int v){ Node *n = malloc(sizeof *n); n->val=v; n->left=n->right=NULL; return n; }

void inorder(Node *r){ if (!r) return; inorder(r->left); printf("%d ", r->val); inorder(r->right); }
void preorder(Node *r){ if (!r) return; printf("%d ", r->val); preorder(r->left); preorder(r->right); }
void postorder(Node *r){ if (!r) return; postorder(r->left); postorder(r->right); printf("%d ", r->val); }

int main(void){
    Node *root = new_node(1);
    root->left = new_node(2); root->right = new_node(3);
    root->left->left = new_node(4); root->left->right = new_node(5);
    printf("Inorder: "); inorder(root); printf("\nPreorder: "); preorder(root);
    printf("\nPostorder: "); postorder(root); printf("\n");
    return 0;
}
