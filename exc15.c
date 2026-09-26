#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 80
#define MAX_ITEMS 40

typedef struct menu_item_ {
    char name[50];
    double price;
} menu_item;

int main(void) {
    char filename[32];
    char line[LINESIZE];
    menu_item menu[MAX_ITEMS];
    int count = 0;
    FILE *my_file;

    printf("Enter file name: ");
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        return 1;
    }
    if (strlen(filename) > 0 && filename[strlen(filename) - 1] == '\n') {
        filename[strlen(filename) - 1] = '\0';
    }

    my_file = fopen(filename, "r");
    if (my_file == NULL) {
        fprintf(stderr, "Error: %s wasn't openned!\n", filename);
        exit(1);
    } else {
        while (count < MAX_ITEMS && !feof(my_file)) {
            if (fgets(line, LINESIZE, my_file) != NULL) {
                int pos = 0;
                char *name_part;
                char *price_part;
                double price;

                if (strlen(line) > 0 && line[strlen(line) - 1] == '\n') {
                    line[strlen(line) - 1] = '\0';
                }
                if (line[0] == '\0') {
                    continue;
                }

                while (line[pos] != ';' && line[pos] != '\0') {
                    pos++;
                }
                if (line[pos] != ';') {
                    continue;
                }
                line[pos] = '\0';
                name_part = line;
                price_part = &line[pos + 1];

                while (*price_part == ' ' || *price_part == '\t') {
                    price_part++;
                }
                if (sscanf(price_part, "%lf", &price) != 1) {
                    continue;
                }
                while (*name_part == ' ' || *name_part == '\t') {
                    name_part++;
                }

                if (strlen(name_part) < sizeof(menu[count].name)) {
                    strcpy(menu[count].name, name_part);
                    menu[count].price = price;
                    count++;
                }
            }
        }
        fclose(my_file);
    }

    for (int i = 0; i < count; i++) {
        printf("%8.2f %s\n", menu[i].price, menu[i].name);
    }

    return 0;
}
