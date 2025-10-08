#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
    int coeff, exp;
    struct Term *next;
} Term;

Term* make_term(int c, int e){ Term *t = malloc(sizeof *t); t->coeff=c; t->exp=e; t->next=NULL; return t; }

Term* add_poly(Term *p1, Term *p2){
    Term dummy = {0,0,NULL}, *tail=&dummy;
    while (p1 && p2){
        if (p1->exp > p2->exp) { tail->next = make_term(p1->coeff, p1->exp); p1 = p1->next; }
        else if (p1->exp < p2->exp) { tail->next = make_term(p2->coeff, p2->exp); p2 = p2->next; }
        else { tail->next = make_term(p1->coeff + p2->coeff, p1->exp); p1=p1->next; p2=p2->next; }
        tail = tail->next;
    }
    while (p1){ tail->next = make_term(p1->coeff, p1->exp); tail = tail->next; p1=p1->next; }
    while (p2){ tail->next = make_term(p2->coeff, p2->exp); tail = tail->next; p2=p2->next; }
    return dummy.next;
}

/* Example simple driver constructs two polynomials and prints their sum. */
int main(void){
    Term *p1 = make_term(3,4); p1->next = make_term(2,2); p1->next->next = make_term(1,0);
    Term *p2 = make_term(5,3); p2->next = make_term(2,2); p2->next->next = make_term(-1,0);
    Term *sum = add_poly(p1,p2);
    for (Term *t = sum; t; t = t->next) printf("%+d x^%d ", t->coeff, t->exp);
    printf("\n");
    return 0;
}
