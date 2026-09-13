#include <stdio.h>
#include <stdbool.h>

bool read_positive(int *value) {
    int number = 0;
    int count = 0;
    int ch = 0;

    printf("Enter a positive number: ");
    count = scanf("%d", &number);

    ch = getchar();
    while (ch != '\n' && ch != EOF) {
        ch = getchar();
    }

    if (count != 1 || number <= 0) {
        return false;
    }

    *value = number;
    return true;
}


int main(void) {
    int money = 0;
    int failures = 0;

    while (failures < 3) {
        printf("Guess how much money I have!\n");

        if (read_positive(&money)) {
            printf("You didn't get it right. I have %d euros.\n", money * 2 + 20);
        } else {
            printf("Incorrect input\n");
            failures = failures + 1;
        }
    }

    printf("I give up! See you later!\n");
    return 0;
}
