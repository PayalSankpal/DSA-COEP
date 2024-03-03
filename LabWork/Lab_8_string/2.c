#include <stdio.h>
#include <string.h>

typedef struct {
    int length;
    const char* subsequence;
} result;

result find(char* str1, char* str2) {
    	int len1 = strlen(str1);
    	int len2 = strlen(str2);
    	int max_len = 0;
    	char* max_sub = NULL;

    	for (int i = 0; i < len2; ++i) {
        	for (int j = 0; j < len1; ++j) {
            		if (str2[i] == str1[j]) {
                		int len = 1;
                		while (i + len < len2 && j + len < len1 && str2[i + len] == str1[j + len]) {
                    			len++;
                		}

                		if (len > max_len) {
                    			max_len = len;
                    			max_sub = &str1[j];
                		}
            		}
        	}
    	}

    	result R = {max_len, max_sub};
    	return R;
}

int main() {
	char* str1 = "abcdemnopxyz";
    	char* str2 = "mnotq";

    	result R = find(str1, str2);

    	if (R.length > 0) {
        	printf("Longest subsequence: %.*s\n", R.length, R.subsequence);
        	printf("Length of the longest subsequence: %d\n", R.length);
    	}
    	else 
        	printf("No common subsequence found.\n");
    

    	return 0;
}

