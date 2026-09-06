#include <stdio.h>

int study_notes(void) {
    int my_variable;
    int b;
    char c;
    c = 5;
    float x;
    x = 1.213131;

    const char *name;
    name = "Vlad";

    int weight = 2;
    float height = 1.23;

    char confirmation[16];

    printf("my weight is %d kg, I am %.2f m tall, my name is %s!\n", weight, height, name);
    printf("Is this information correct?\n");
    scanf("%15s", confirmation);
    return 0;
}

int ex1(void) {
    float ticket = 0;
    float taxi = 0;
    float budget = 0;
    int selection = 0;

    printf("Enter price of bus ticket: ");
    scanf("%f", &ticket);
    printf("Enter price of taxi: ");
    scanf("%f", &taxi);
    printf("How much money you have: ");
    scanf("%f", &budget);
    printf("You have %.2f euros left.\n", budget);

    while (budget >= ticket || budget >= taxi) {
        printf("Do you want to take\n");
        printf("1) bus (%.2f euros)\n", ticket);
        printf("2) taxi (%.2f euros)\n", taxi);
        printf("Enter your selection: ");
        scanf("%d", &selection);

        if (selection == 1) {
            printf("You chose bus.\n");
            if (budget >= ticket) {
                budget = budget - ticket;
            }
            else {
                printf("You don't have enough money for bus.\n");
            }
            printf("You have %.2f euros left.\n", budget);
        }
        else if (selection == 2) {
            printf("You chose taxi.\n");
            if (budget >= taxi) {
                budget = budget - taxi;
            }
            else {
                printf("You don't have enough money for taxi.\n");
            }
            printf("You have %.2f euros left.\n", budget);
        }
        else {
            printf("Incorrect value\n");
            printf("You have %.2f euros left.\n", budget);
        }
    }
    printf("You need to walk. Bye.\n");
    return 0;
}

int main(void) {
    ex1();
}
