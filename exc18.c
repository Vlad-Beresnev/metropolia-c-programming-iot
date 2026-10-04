#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
    char input[80];
    char extra;
    int shift;
    int length;
    int character;
    unsigned int number;
    unsigned int result;

    srand((unsigned int) time(NULL));

    do {
        printf("Enter a number from 0 to 15 or a negative number to stop: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        } else {
            shift = 0;
            length = strlen(input);
            if (length == sizeof(input) - 1 && input[length - 1] != '\n') {
                while ((character = getchar()) != '\n' && character != EOF) {
                }
                printf("Invalid input\n");
            } else {
                if (length > 0 && input[length - 1] == '\n') {
                    input[length - 1] = '\0';
                }

                if (sscanf(input, "%d %c", &shift, &extra) != 1) {
                    printf("Invalid input\n");
                    shift = 0;
                } else if (shift > 15) {
                    printf("Number must be between 0 and 15\n");
                } else if (shift >= 0) {
                    number = (unsigned int) rand();
                    result = (number >> shift) & 0x3F;
                    printf("Random number: %X\n", number);
                    printf("Result: %02X\n", result);
                }
            }
        }
    } while (shift >= 0);

    return 0;
}
