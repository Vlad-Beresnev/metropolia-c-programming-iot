#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int count_words(char *str, char *str2) {
    int count = 0;
    int countMatch = 0;
    bool matchFound = true;
    int i;
    int length = 0;
    str[strcspn(str, "\n")] = 0;
    length = strlen(str);
    char match[10];
    int target_length = strlen(str2);
    int res_count = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == str2[countMatch]) {
            countMatch = countMatch + 1;
            
            if (countMatch == target_length) {
                res_count = res_count + 1;
                countMatch = 0; 
            }
        } else {
            countMatch = 0;
        }
    }
    return res_count;
}

int main(void) {
    char char1[] = "who is who me, am I? Yes, It is you!";
    char char2[] = "yous";
    int res = count_words(char1, char2);
    printf("%d\n", res);
    return 0;
}