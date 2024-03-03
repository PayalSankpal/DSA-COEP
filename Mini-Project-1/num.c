#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include"num.h"

void init_num(number* n){
    n->p=NULL;
    n->sign=PLUS;
    n->dec=0;
    return;
}

char storenumber(number *n){
    int count=1;
    int dec=0;
    char c;
    while(isdigit(c=getchar()) || c=='.'){
        if(c=='.' && n->dec==0){
            dec=count;
        }
        else{
            insert_beg(&(n->p), (int)c-48);
            count++;
        }
    }
    if(dec==0){
        n->dec=0;
    }
    else{
        n->dec=count-dec;
    }
    return c;
}

number* reverseNumber(number num){
    number* num2 = (number *)malloc(sizeof(number));
    num2->p=NULL;
    num2->sign=num.sign;
    node* tail=num.p;
    int length=0;
    while(tail){
        insert_beg(&(num2->p), tail->data);
        length++;
        tail=tail->next;
    }
    if (num.dec!=0){
        num2->dec=length-num.dec;
    }
    else{
        num2->dec=0;
    }
    
    return num2;
}


void displaynumber(number num){
    number* num2 = reverseNumber(num);
    node* tail = num2->p;
    int count=0;
    if(num.sign==MINUS){
        printf("-");
    }
    while(tail){
        printf("%d",tail->data);
        count++;
        if (count==num2->dec){
            printf("%c",'.');
        }
        tail=tail->next;
    }
    printf("%c",'\n');
    return;
}

int isZero(number* num1){
    node* tail = num1->p;
    while(tail){
        if(tail->data!=0){
            return 0;
        }
        tail=tail->next;
    }
    return 1;
}

number* removeZeroes(number* num){
    if(isZero(num)){
        return num;
    }
    int d = num->dec;
    number* n = reverseNumber(*num);
    node* t = n->p;
    int count=0;
    if(t!=NULL){
        while(t->data==0){
            t=t->next;
            count+=1;
        }
    }
    n->p = t;
    n = reverseNumber(*n);
    n->dec=d;
    return n;
}

int greaterthan(number* num1, number* num2){
    node* t1=num1->p;
    node* t2=num2->p;
    int n = 0;
    if((length(t1)-num1->dec)>(length(t2)-num2->dec)){
        return 1;
    }
    else if((length(t1)-num1->dec)<(length(t2)-num2->dec)){
        return 0;
    }
    else{
        while(num2->dec<num1->dec){
            insert_beg(&(num2->p),0);
            num2->dec++;
        }
        while(num1->dec<num2->dec){
            insert_beg(&(num1->p),0);
            num1->dec++;
        }
        node* t1=num1->p;
        node* t2=num2->p;
        n=0;
        while(t1 && t2){
            if(t1->data>t2->data){
                n=1;
            }
            else if(t2->data>t1->data){
                n=0;
            }
            t1=t1->next;
            t2=t2->next;
        }
        return n;
    }

}

int isEqual(number* num1, number* num2){
    num1 = removeZeroes(num1);
    num2 = removeZeroes(num2);
    node* t1 = num1->p, *t2=num2->p;
    while(t1 && t2){
        if(t1->data!=t2->data){
            return 0;
        }
        t1=t1->next;
        t2=t2->next;
    }
    if(t1 || t2){
        return 0;
    }
    return 1;
}


number* subtractnumbers(number* num1, number* num2){
    number* n=(number *)malloc(sizeof(number));
    init_num(n);
    node* t1, * t2;
    num1=removeZeroes(num1);
    num2=removeZeroes(num2);
    int k = num1->dec > num2->dec ? num1->dec : num2->dec;
    n->dec=k;
    if(num1->sign==PLUS && num2->sign==PLUS){
        if(greaterthan(num1, num2)){
            t1=num1->p;
            t2=num2->p;
            n->sign=PLUS;
        }
        else if(isEqual(num1, num2)){
            insert_end(&(n->p),0);
            n->sign=PLUS;
            return n;
        }
        else{
            t1=num2->p;
            t2=num1->p;
            n->sign=MINUS;
        }
    }
    else if(num1->sign!=num2->sign){
        int n1s=num1->sign;
        num1->sign=PLUS;
        num2->sign=PLUS;
        n = addnumbers(num1, num2);
        n->sign=n1s;
        return n;
    }
    else{
        if(greaterthan(num1, num2)){
            t1=num1->p;
            t2=num2->p;
            n->sign=MINUS;
        }
        else if(isEqual(num1, num2)){
            insert_end(&(n->p),0);
            n->sign=PLUS;
            return n;
        }
        else{
            t1=num2->p;
            t2=num1->p;
            n->sign=PLUS;
        }
    }
    int borrow=0;
    while(t1 && t2){
        if (t1->data-t2->data-borrow < 0 && t1->next!=NULL){
            insert_end(&(n->p),((t1->data+10)-t2->data-borrow));
            borrow = 1;
        }
        else{
            insert_end(&(n->p),(t1->data-t2->data-borrow));
            borrow = 0;
        }
        t1=t1->next;
        t2=t2->next;
    }
    while(t1){
        if(t1->data-borrow<9 && t1->next!=NULL){
            insert_end(&(n->p),(t1->data+10)-borrow);
            borrow=1;
        }
        else{
            insert_end(&(n->p),t1->data-borrow);
            borrow=0;
        }
        t1=t1->next;
    }
    removeZeroes(n);
    return n;
}

number* addnumbers(number* num1, number* num2){
    number* n=(number *)malloc(sizeof(number));
    init_num(n);
    int carry=0;
    if(num1->sign==num2->sign){
        n->sign=num1->sign;
    }
    else{
        int n1d=num1->sign;
        int n2d=num2->sign;
        num1->sign=PLUS;
        num2->sign=PLUS;
        n = subtractnumbers(num1, num2);
        if(greaterthan(num1, num2)){
            n->sign=n1d;
        }
        else{
            n->sign=n2d;
        }
        return n;
    }

    if (num1->dec!=0 || num2->dec!=0){
        int k = num1->dec > num2->dec ? num1->dec : num2->dec;
        n->dec=k;
        while(k){
            if(num1->dec>0){
                num1->dec--;
            }
            else{
                insert_beg(&(num1->p),0);
            }
            if(num2->dec>0){
                num2->dec--;
            }
            else{
                insert_beg(&(num2->p),0);
            }
            k--;
        }
    }
    node* t1=num1->p;
    node* t2=num2->p;
    while(t1 && t2){
        insert_end(&(n->p),(t1->data+t2->data+carry)%10);
        carry = (t1->data+t2->data+carry)/10;
        t1=t1->next;
        t2=t2->next;
    }
    while(t1){
        insert_end(&(n->p),((t1->data+carry)%10));
        carry = (t1->data+carry)/10;
        t1=t1->next;
    }
    while(t2){
        insert_end(&(n->p),((t2->data+carry)%10));
        carry = (t2->data+carry)/10;
        t2=t2->next;
    }
    if(carry!=0){
        insert_end(&(n->p),(carry));
    }
    return n;
}

number* mulnumbers(number* num1, number* num2){
    node* t1, *t2;
    if(length(num1->p)>length(num2->p)){
        t1=num1->p;
        t2=num2->p;
    }
    else{
        t1=num2->p;
        t2=num1->p;
    }
    int count=0;
    int carry=0;
    number* result=(number *)malloc(sizeof(number));
    init_num(result);
    if(num1->sign==num2->sign){
        result->sign=num1->sign;
    }
    else{
        result->sign=MINUS;
    }
    insert_end(&(result->p),0);
    while(t2){
        number temp;
        init_num(&temp);
        for(int i=0;i<count;i++){
            insert_end(&(temp.p),0);
        }
        count++;
        carry = 0;
        while(t1){
            insert_end(&(temp.p),(((t2->data*t1->data)+carry)%10));
            carry = floor((t1->data*t2->data+carry)/10);
            t1=t1->next;
        }
        t1=num1->p;
        if(carry!=0){
            insert_end(&(temp.p),carry);
        }
        result = addnumbers(result, &temp);
        t2=t2->next;
    }
    result->dec = num1->dec+num2->dec;
    return result;
}


number* divnumbers(number* num1, number* num2){
    if(isZero(num2)){
        printf("Division by Zero\n");
        return NULL;
    }
    number* result = (number *)malloc(sizeof(number));
    if(num1->sign==num2->sign){
        result->sign=num1->sign;
    }
    else{
        result->sign=MINUS;
    }
    result->dec=0;
    int n1d = num1->dec, n2d=num2->dec;
    if(n1d>n2d){
        while (n1d){
            if(n2d>0){
                n2d--;
            }
            else{
                insert_beg(&(num2->p), 0);
            }
            n1d--;
        }
    }
    else if(n1d<n2d){
        while (n2d){
            if(n1d>0){
                n1d--;
            }
            else{
                insert_beg(&(num1->p), 0);
            }
            n2d--;
        }
    }
    number* num=reverseNumber(*num1);
    node* t1=num->p, *t2=num2->p;
    result->p=NULL;
    number* c = (number*)malloc(sizeof(number));
    number* d=(number*)malloc(sizeof(number));
    number* prod, *diff, *ten=(number*)malloc(sizeof(number));
    init_num(c);
    init_num(d);
    init_num(ten);
    insert_beg(&(ten->p), 1);
    insert_beg(&(ten->p), 0);
    int i=9;
    insert_beg(&(d->p),9);
    while(t1){
        node* temp =t1;
        while(t1 && (!isEqual(num2, c) && !greaterthan(c, num2))){
            insert_beg(&(c->p),t1->data);
            t1=t1->next;
        }
        while(t1!=temp->next){
            insert_beg(&(result->p),0);
            temp=temp->next;
        }
        i=9;
        while(i){
            d->p->data=i;
            prod = mulnumbers(num2, d);
            diff = subtractnumbers(c, prod);
            if(diff->sign==PLUS){
                break;
            }
            i--;
        }
        if(i!=0){
            insert_beg(&(result->p),i);
        }
        diff=removeZeroes(diff);
        c = diff;
    }
    int count=0;
    while(!isZero(c)){
        while(greaterthan(num2,c)){
            insert_beg(&(c->p),0);
        }
        i=9;
        while(i){
            d->p->data=i;
            prod = mulnumbers(num2, d);
            diff = subtractnumbers(c, prod);
            if(diff->sign==PLUS){
                break;
            }
            i--;
        }
        if(i!=0){
            insert_beg(&(result->p),i);
            result->dec++;
        }
        diff=removeZeroes(diff);
        c = diff;
        count++;
        if(count>5){
            break;
        }
    }
    result=removeZeroes(result);
    return result;
}

number* modulus(number* num1, number* num2){
    if(isZero(num2)){
        printf("Division by Zero\n");
        return NULL;
    }
    number* quot = divnumbers(num1, num2);
    number* prod = mulnumbers(num2, quot);
    number* result = subtractnumbers(num1, prod);
    return result;
}

number* expo(number* num1, number* num2){
    number* n = (number*)malloc(sizeof(number));
    init_num(n);
    if(num2->dec!=0){
        return NULL;
    }
    insert_beg(&(n->p),1);
    if(isZero(num2)){
        return n;
    }
    node* t1=num1->p;
    node* t2=num2->p;
    int power=1;
    while(t2){
        for (int i=0; i<(t2->data*(power)); i++){
            n = mulnumbers(n, num1);
        }
        power*=10;
        t2=t2->next;
    }
    return n;
}