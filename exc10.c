#include <stdio.h>
#include <string.h>

int string_checker(void) {
    char string[6];
    int length = 0;
    do {
        printf("Write the string: ");
        fgets(string, 6, stdin);
        string[strcspn(string, "\n")] = 0;
        length = strlen(string);
        printf("Length of the string: %d\n", length);
    } while (strcmp("stop", string) != 0);
    return 0;
}

int main(void) {
    string_checker();
    return 0;
}