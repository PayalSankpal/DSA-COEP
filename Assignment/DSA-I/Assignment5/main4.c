#include<stdio.h>
#include<stdlib.h>

typedef struct test {
    struct test **a;
}test;

test *f(test ***ppp) {
    printf("*ppp=%p\n",*ppp);
    test *p, **pp;
    pp = *ppp;
    printf("pp=%p\n",pp);
    printf("*pp=%p\n",*pp);
    p = *pp;
    *pp = (test *)malloc(2 * sizeof(test));
    return pp[1];
}

int main() {
    test *m;
    int i;
    m = (test *)malloc(sizeof(test));
    m->a = (test **)malloc(sizeof(test *) * 3);
    for(i = 0; i < 2; i++) {
        m->a[i] = (test *)malloc(sizeof(test));
    }
    printf("m->a=%p\n",(m->a));
    printf("m->a+1=%p\n",(m->a+1));
    printf("m->a+2=%p\n",(m->a+2));
    printf("m->a[0]=%p\n",m->a[0]);
    printf("m->a[1]=%p\n",m->a[1]);
    m->a[2] = (test*)malloc(3 * sizeof(test));
    printf("m->a[2]=%p\n",m->a[2]);
    m = f(&(m->a));
    printf("%d\n", 1234%4);
    return 0;
}

