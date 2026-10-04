#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

bool generate_password(char *password, int size, const char *word) {
    int length = strlen(word);

    if (size < length * 2 + 2) {
        return false;
    }

    for (int i = 0; i < length; i++) {
        password[i * 2] = (char) (rand() % 95 + 32);
        password[i * 2 + 1] = word[i];
    }
    password[length * 2] = (char) (rand() % 95 + 32);
    password[length * 2 + 1] = '\0';

    return true;
}

int main(void) {
    char word[32];
    char password[64];
    int length;
    int character;
    int too_long;

    srand((unsigned int) time(NULL));

    do {
        printf("Enter a word or stop to quit: ");
        if (fgets(word, sizeof(word), stdin) == NULL) {
            break;
        }
        length = strlen(word);
        too_long = 0;

        if (length > 0 && word[length - 1] == '\n') {
            word[length - 1] = '\0';
        } else if (length == sizeof(word) - 1) {
            character = getchar();
            if (character != '\n' && character != EOF) {
                too_long = 1;
                while ((character = getchar()) != '\n' && character != EOF) {
                }
            }
        }

        if (too_long == 1) {
            printf("Word is too long\n");
        } else if (strcmp(word, "stop") != 0) {
            if (generate_password(password, sizeof(password), word)) {
                printf("Password: %s\n", password);
            } else {
                printf("Password does not fit\n");
            }
        }
    } while (strcmp(word, "stop") != 0);

    return 0;
}
