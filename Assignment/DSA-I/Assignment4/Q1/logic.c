#include "header.h"

int Dk[2], Dm[2];


void read_distance(int i){
    extern int Dk[2], Dm[2];
    scanf("%d%d",&Dk[i-1], &Dm[i-1]);
}

void display_distances(){
    extern int Dk[2], Dm[2];
    printf("The first distance is %d km and %d m.\n", Dk[0], Dm[0]);
    printf("The second distance is %d km and %d m.\n", Dk[1], Dm[1]);
}

void add_distances(int *sum){
    sum[0]=(Dk[0]+Dk[1]);
    sum[1]=Dm[0]+Dm[1];
    if(sum[1]>1000){
        sum[0]+=(sum[1]-(sum[1]%1000))/1000;
        sum[1]=sum[1]%1000;
    }
}

void sub_distances(int *sub){
    sub[0]=Dk[0]-Dk[1];
    sub[1]=Dm[0]-Dm[1];
    if (sub[0]<0){
        sub[0]*=(-1);
    }
    if (sub[1]<0){
        sub[1]*=(-1);
    }
}