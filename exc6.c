#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int roll_die(int sides) {
    return rand() % sides + 1;
}

void print_menu(void) {
    printf("\n");
    printf("Select an operation:\n");
    printf("1) Roll D6\n");
    printf("2) Roll D10\n");
    printf("3) Quit\n");
}

int main(void) {
    int selection = 0;
    int result = 0;
    int running = 1;

    srand((unsigned int) time(NULL));

    while (running == 1) {
        print_menu();
        selection = read_range(1, 3);

        if (selection < 1) {
            printf("No more input. Stopping\n");
            running = 0;
        } else {
            switch (selection) {
                case 1:
                    result = roll_die(6);
                    printf("You rolled %d.\n", result);
                    break;
                case 2:
                    result = roll_die(10);
                    printf("You rolled %d.\n", result);
                    break;
                case 3:
                    printf("Bye!\n");
                    running = 0;
                    break;
            }
        }
    }
    return 0;
}