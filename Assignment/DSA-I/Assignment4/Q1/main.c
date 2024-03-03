#include<stdio.h>
#include"header.h"
#include"logic.c"

int main(){
    int choice=0, sum[2]={0,0}, sub[2]={0,0};

    printf("******** MAIN MENU *********\n");
    printf("1.Read the distances\n");
    printf("2.Display the distances\n");
    printf("3.Add the distances\n");
    printf("4.Subtract the distances\n");
    printf("5.EXIT\n");
    
             
    while(1){
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice==1){
            printf("Enter the first distance in kms and meters: ");
            read_distance(1);
            printf("Enter the second distance in kms and meters: ");
            read_distance(2);
        }
        else if(choice==2)
            display_distances();
        else if(choice==3){
            add_distances(sum);
            printf("Sum of distances : %d kms %d metres\n", sum[0],sum[1]);
        }
        else if(choice==4){
            sub_distances(sub);
            printf("Subtraction of distances : %d kms %d metres\n",sub[0],sub[1]);
        }
        else if(choice==5)
            break;
        else
            printf("Invalid choice");
    }

    return 0;
}
