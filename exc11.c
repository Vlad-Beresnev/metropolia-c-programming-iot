#include <stdio.h>
#include <string.h>

int replace_char(char *str, char *repl) {
    int count = 0;
    int i;
    int length = 0;
    str[strcspn(str, "\n")] = 0;
    length = strlen(str);
    for (i = 0; i < length; i++) {
        if (str[i] == repl[0]) {
            str[i] = repl[1];
            count = count + 1;
        } 
    }
    return count;
}

int main(void) {
    char str1[80];
    char str2[3];
    int res;
    printf("Enter the string: ");
    fgets(str1, 80, stdin);
    printf("Enter 2 chars: ");
    scanf("%s", str2);
    res = replace_char(str1, str2);
    if (res == 0) {
        printf("String was not modified");
    } else {
        printf("Replaced %d times\n", res);
        printf("%s\n", str1);
    }
    return 0;
}