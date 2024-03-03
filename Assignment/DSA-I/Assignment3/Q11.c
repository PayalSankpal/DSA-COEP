#include<stdio.h>
#include<string.h>


int main(){
    int i;
    char str1[50];
    int ftable[26]={0};

    printf("Enter a string:\n");
    fgets(str1, sizeof(str1), stdin);
    if (str1[strlen(str1)-1]=='\n'){  //fgets adds newline charcter at end we remove that and add null character.
        str1[strlen(str1)-1]='\0';
    }

    for(i=0; str1[i]!='\0'; i++){
        if ('a'<= str1[i] <= 'z'){
            ftable[str1[i]-'a']+=1;
        }
        if ('A' <= str1[i] <= 'Z'){
            ftable[str1[i]-'A']+=1;
        }
    }

    for(i=0; i<26; i++){
        if (ftable[i]!=0){
            printf("Frequency of %c = %d\n", i+97, ftable[i] );
        }
    }


    return 0;
}