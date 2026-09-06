#include <stdio.h>

int exc3(void) {
    int num_students = 0;
    int student_id = 0;
    int grade = 0;
    int i = 0;

    printf("How many students: ");
    scanf("%d", &num_students);

    int grades[num_students];

    for (i = 0; i < num_students; i++) {
        grades[i] = -1;
    }

    do {
        printf("\n");
        printf("Enter student number (1 - %d) or 0 to stop: ", num_students);
        scanf("%d", &student_id);

        if (student_id != 0) {
            if (student_id < 1 || student_id > num_students) {
                printf("Invalid student number!\n");
            }
            else {
                do {
                    printf("Enter grade (0 - 5) for student %d or -1 to cancel: ",
                           student_id);
                    scanf("%d", &grade);

                    if (grade < -1 || grade > 5) {
                        printf("Invalid grade!\n");
                    }
                } while (grade < -1 || grade > 5);

                if (grade != -1) {
                    grades[student_id - 1] = grade;
                }
            }
        }
    } while (student_id != 0);

    printf("\nStudent\tGrade\n");
    for (i = 0; i < num_students; i++) {
        if (grades[i] == -1) {
            printf("%d\tN/A\n", i + 1);
        }
        else {
            printf("%d\t%d\n", i + 1, grades[i]);
        }
    }

    return 0;
}

int main(void) {
    exc3();
}
