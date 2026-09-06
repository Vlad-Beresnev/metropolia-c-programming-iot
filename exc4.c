#include <stdio.h>

int read_integer(void) {
    int solo;
    int index = 0;
    float sum = 0;
    do {
        printf("Enter positive numbers or negative to stop: ");
        scanf("%d", &solo);
        if (scanf("%d", &solo) != 1) {
            while (getchar() != '\n');
            printf("Invalid input");
        }
        if (solo == 0) {
            printf("Invalid input");
        } else {
            if (solo == -1 ) {
                return 0;
            } else {
                index = index + 1;
                sum = sum + solo;
            }
        }
    } while (solo > 0);
    float avg = sum / index;
    printf("You entered 5 positive numbers. The average is: %.3f\n", avg);
    return 0;
}

int main(void) {
    read_integer();
}