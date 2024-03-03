#include<stdio.h>
#include<string.h>

int main(){
    char str[100], c;
    int i, vowel=0, consonant=0, digit=0, blank=0;

    printf("Enter a string:\n");
    fgets(str, sizeof(str), stdin);
    if (str[strlen(str)-1]=='\n'){  //fgets adds newline charcter at end we remove that and add null character.
        str[strlen(str)-1]='\0';
    }
    

    for(i=0; str[i]!='\0'; i++){
        if ((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122)){
            if(str[i]=='a' || str[i]=='e' || str[i]=='e' || str[i]=='o' || str[i]=='u' || 
               str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U' ){
                vowel++;
            }
            else{
                consonant++;
            }
        }
        else if(str[i]>=48 && str[i]<=58){
            digit++;
        }
        else if(str[i] == ' '){
            blank++;
        }

    }

    printf("The string is %s\n", str);
    printf("The no. of vowels in string is %d\n", vowel);
    printf("The no. of consonant in string is %d\n", consonant);
    printf("The no. of digit in string is %d\n", digit);
    printf("The no. of blank in string is %d\n", blank);


    return 0;
}