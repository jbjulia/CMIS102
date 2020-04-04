// C Code
// This program will calculate the average of 3
// exams for a specified amount of students.
// Developer: Joseph Julian

#include <stdio.h>

int main(void) {

    /* Variable Definition */
    char name[100];
    float sum, grade, average;
    int students, total, exams;

    printf("\nPlease enter how many students you wish to average grades for: ");
    scanf("%d", &total);

    // Loop through total students
    for (students = 0; students < total; students++) {
        printf("\nEnter 3 grades and student name: ");
        sum = 0;
        for (exams = 0; exams < 3; exams++) {
            // float uses %f, double uses %lf
            scanf("%f", &grade);
            sum = sum + grade;
        } // End for each exam
        average = sum / 3;
        scanf("%s", name);
        printf("\nAverage for %s is %.2f\n", name, average);
    } // End for each student

    printf("\n... Bye ...");

    return 0;
} // End main
