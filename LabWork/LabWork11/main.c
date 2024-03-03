#include"sll.h"

int main() {
    sll L1,L2;
    init(&L1);
    init(&L2);
   //{1, 2, 8, 9,12,16,18,11,14,13}
    append(&L1, 1);
    append(&L1, 2);
    append(&L1, 8);
    append(&L1, 9);
    append(&L1, 12);
    append(&L1, 16);
    append(&L1, 18);
    append(&L1, 11);
    append(&L1, 14);
    append(&L1, 13);
    traverse(L1);
    reverse_even(&L1);
    traverse(L1);
    isPalindrome(L1)==0? printf("Its not a palindrome\n"): printf("Its a palindrome\n");

    //{1,2,1,2,1}
    append(&L2,1);
    append(&L2,2);
    append(&L2,1);
    append(&L2,2);
    append(&L2,3);
    traverse(L2);
    isPalindrome(L2)==0? printf("Its not a palindrome\n"): printf("Its a palindrome\n");
    remove_duplicates(&L2);
    traverse(L2);
    return 0;
}
