#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 15

void print_numbers(const int *array, int count) {
    int i = 0;

    for (i = 0; i < count; i++) {
        printf("%8d\n", array[i]);
    }
}

int main(void) {
    int numbers[ARRAY_SIZE];
    int i = 0;

    srand((unsigned int) time(NULL));

    for (i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = rand() % 1000 + 1;
    }

    print_numbers(numbers, ARRAY_SIZE);

    return 0;
}
