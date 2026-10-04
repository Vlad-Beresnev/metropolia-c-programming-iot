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
    nnode *head = NULL;
    nnode *tail = NULL;
    nnode *current;

    while (1) {
        printf("Enter a number or end to stop: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        length = strlen(input);
        if (length == sizeof(input) - 1 && input[length - 1] != '\n') {
            while ((character = getchar()) != '\n' && character != EOF) {
            }
            printf("Invalid input\n");
            continue;
        }
        if (length > 0 && input[length - 1] == '\n') {
            input[length - 1] = '\0';
        }

        if (strcmp(input, "end") == 0) {
            break;
        }
        if (sscanf(input, "%d %c", &number, &extra) != 1) {
            printf("Invalid input\n");
            continue;
        }

        current = (nnode *) malloc(sizeof(nnode));
        if (current == NULL) {
            fprintf(stderr, "Could not allocate memory\n");
            memory_error = 1;
            break;
        }
        current->number = number;
        current->next = NULL;

        if (head == NULL) {
            head = current;
        } else {
            tail->next = current;
        }
        tail = current;
    }

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
