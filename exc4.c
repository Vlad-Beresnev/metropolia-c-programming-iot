#include <stdio.h>

int read_integer(void) {
    int number = 0;
    int status = 0;

    do {
        status = scanf("%d", &number);
        if (status != 1) {
            while (getchar() != '\n');
            printf("invalid input\n");
        }
    } while (status != 1);

    return number;
}

int main(void) {
    int number = 0;
    int count = 0;
    float sum = 0;

    do {
        printf("Enter positive numbers or negative to stop: ");
        number = read_integer();

        if (number == 0) {
            printf("Zero is not positive, enter a positive number\n");
        }
        else if (number > 0) {
            count = count + 1;
            sum = sum + number;
        }
    } while (number >= 0);

    if (count > 0) {
        printf("You entered %d positive numbers. The average is: %.3f\n",
               count, sum / count);
    }
    else {
        printf("You entered 0 positive numbers.\n");
    }

    return 0;
}
