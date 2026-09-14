#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 20

int find_first(const unsigned int *array, unsigned int what) {
    int i = 0;

    while (array[i] != 0) {
        if (array[i] == what) {
            return i;
        }
        i = i + 1;
    }

    return -1;
}

void print_array(const unsigned int *array, int count) {
    int i = 0;

    for (i = 0; i < count; i++) {
        printf("%u\n", array[i]);
    }
}

int main(void) {
    unsigned int numbers[ARRAY_SIZE];
    unsigned int what = 0;
    int index = 0;
    int count = 0;
    int running = 1;
    int ch = 0;
    int i = 0;

    srand((unsigned int) time(NULL));

    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        numbers[i] = rand() % 20 + 1;
    }
    numbers[ARRAY_SIZE - 1] = 0;

    print_array(numbers, ARRAY_SIZE);

    while (running == 1) {
        printf("Enter a number to search or zero to stop: ");

        count = scanf("%u", &what);

        ch = getchar();
        while (ch != '\n' && ch != EOF) {
            ch = getchar();
        }

        if (count == EOF) {
            running = 0;
        } else if (count != 1) {
            printf("invalid input\n");
        } else if (what == 0) {
            running = 0;
        } else {
            index = find_first(numbers, what);

            if (index >= 0) {
                printf("%u found at index %d\n", what, index);
            } else {
                printf("not found\n");
            }
        }
    }

    printf("Bye!\n");

    return 0;
}
