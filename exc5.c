#include <stdio.h>

int read_range(int low, int high) {
    int roll = 0;
    int ok = 0;
    int ch = 0;
    int count = 0;

    do {
        ok = 1;

        printf("Enter a number between %d and %d: ", low, high);

        count = scanf("%d", &roll);

        if (count == EOF) {
            roll = low - 1;
        } else if (count != 1) {
            printf("That is not a number. Please enter digits only.\n");
            ok = 0;
        } else if (roll < low || roll > high) {
            printf("%d is not between %d and %d.\n", roll, low, high);
            ok = 0;
        }

        ch = getchar();
        while (ch != '\n' && ch != EOF) {
            ch = getchar();
        }
    } while (ok == 0);

    return roll;
}

int main(void) {
    int low = 1;
    int high = 6;
    int rounds = 0;
    int roll = 0;
    int playing = 1;

    printf("Let's play!\n");

    while (rounds < 3 && playing == 1) {
        printf("Roll a die and enter your result.\n");
        roll = read_range(low, high);

        if (roll < low) {
            printf("No more input. Stopping the game.\n");
            playing = 0;
        } else {
            if (roll != high) {
                printf("I got %d. I win!\n", roll + 1);
            } else {
                printf("I got %d. It is a tie!\n", roll);
            }
            rounds = rounds + 1;
        }
    }

    if (playing == 1) {
        printf("Better luck next time. Bye!\n");
    }

    return 0;
}
