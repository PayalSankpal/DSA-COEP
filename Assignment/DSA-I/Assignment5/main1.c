#include<stdio.h>
#include<stdlib.h>

typedef struct entry {
    double x;
    struct entry *e;
}entry;
entry *f(entry **epp) {
    entry *ep = *epp;
    printf("%f\n",(ep)->x);
    ep = (entry *)malloc(sizeof(entry));
    printf("%f\n",(ep)->x);
    ep->e = NULL;
    ep->x = 1.2;
 return ep;
}
int main() {
    entry e, *ep, *eq;
    ep = &e;
    e.e = (entry *)malloc(sizeof(entry));
    e.e->x=2.3;
    printf("%f\n",(e.e)->x);
    eq = f(&(e.e));
    e.x = eq->x;
}
