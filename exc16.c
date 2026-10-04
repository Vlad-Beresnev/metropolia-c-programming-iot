#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int number;
    struct node *next;
} nnode;

int main(void) {
    char input[80];
    int number;
    char extra;
    int character;
    int length;
    int memory_error = 0;
    int finished = 0;
    nnode *head = NULL;
    nnode *tail = NULL;
    nnode *current;

    do {
        printf("Enter a number or end to stop: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            finished = 1;
        } else {
            length = strlen(input);
            if (length == sizeof(input) - 1 && input[length - 1] != '\n') {
                while ((character = getchar()) != '\n' && character != EOF) {
                }
                printf("Invalid input\n");
            } else {
                if (length > 0 && input[length - 1] == '\n') {
                    input[length - 1] = '\0';
                }

                if (strcmp(input, "end") == 0) {
                    finished = 1;
                } else if (sscanf(input, "%d %c", &number, &extra) != 1) {
                    printf("Invalid input\n");
                } else {
                    current = (nnode *) malloc(sizeof(nnode));
                    if (current == NULL) {
                        fprintf(stderr, "Could not allocate memory\n");
                        memory_error = 1;
                        finished = 1;
                    } else {
                        current->number = number;
                        current->next = NULL;

                        if (head == NULL) {
                            head = current;
                        } else {
                            tail->next = current;
                        }
                        tail = current;
                    }
                }
            }
        }
    } while (finished == 0);

    if (memory_error == 0) {
        printf("Entered numbers:\n");
        current = head;
        while (current != NULL) {
            printf("%d\n", current->number);
            current = current->next;
        }
    }

    current = head;
    while (current != NULL) {
        nnode *next = current->next;
        free(current);
        current = next;
    }

    return memory_error;
}
