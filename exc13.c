#include <stdio.h>
#define LINESIZE 80
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int min;
  int max;
  int count;
} Results;

Results max_min_numbers(char *filename) {
  Results res;
  int value = 0;
  res.min = 0;
  res.max = 0;
  res.count = 0;
  FILE *file;
  char line[LINESIZE];
  bool first_min = true;
  bool first_max = true;
  filename[strcspn(filename, "\n")] = '\0';
  file = fopen(filename, "r");

  if (file == NULL) {
    fprintf(stderr, "Error: %s wasn't openned!\n", filename);
    exit(1);
  } else {
    while (!feof(file)) {
      if (fgets(line, LINESIZE, file) != NULL) {
        if (sscanf(line, "%d", &value) == 1) {
          res.count = res.count + 1;
          if (first_min) {
            res.min = value;
            first_min = false;
          }
          if (first_max) {
            res.max = value;
            first_max = false;
          } else if (value < res.min) {
            res.min = value;
          } else if (value > res.max) {
            res.max = value;
          }
        }
      }
    }
    fclose(file);
  }
  return res;
}

int main(void) {
  char filename[32];
  printf("Enter file name: ");
  fgets(filename, 32, stdin);
  Results res = max_min_numbers(filename);
  printf("Total count of numbers: %d\n", res.count);
  printf("Min value from %s - %d, Max value - %d\n", filename, res.min, res.max);
}