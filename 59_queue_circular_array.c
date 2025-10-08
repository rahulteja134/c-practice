#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data; int capacity, head, tail, size;
} CQueue;

CQueue* cqueue_create(int cap){
    CQueue *q = malloc(sizeof *q);
    q->data = malloc(cap * sizeof *q->data); q->capacity = cap;
    q->head = q->tail = q->size = 0; return q;
}
void cqueue_free(CQueue *q){ free(q->data); free(q); }

int cqueue_push(CQueue *q, int v){
    if (q->size == q->capacity) return 0;
    q->data[q->tail] = v; q->tail = (q->tail+1)%q->capacity; q->size++; return 1;
}
int cqueue_pop(CQueue *q, int *out){
    if (q->size==0) return 0;
    *out = q->data[q->head]; q->head=(q->head+1)%q->capacity; q->size--; return 1;
}

int main(void){
    CQueue *q = cqueue_create(4);
    cqueue_push(q,1); cqueue_push(q,2); cqueue_push(q,3); cqueue_push(q,4);
    int v;
    cqueue_pop(q,&v); printf("%d\n", v);
    cqueue_pop(q,&v); printf("%d\n", v);
    cqueue_push(q,5);
    while (cqueue_pop(q,&v)) printf("%d ", v);
    printf("\n");
    cqueue_free(q);
    return 0;
}
