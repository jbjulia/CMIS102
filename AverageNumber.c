// C Code
// This program will calculate the sum and average of 5 integers.
// Developer: Joseph Julian

#include <stdio.h>

int main() {

    /* Variable Definition */
    int value1, value2, value3, value4, value5, sum;
    double average;

    /* Variable Initialization */
    sum = 0;

    printf("Enter an Integer for Value 1\n");
    scanf("%d", &value1);
    printf("Enter an Integer for Value 2\n");
    scanf("%d", &value2);
    printf("Enter an Integer for Value 3\n");
    scanf("%d", &value3);
    printf("Enter an Integer for Value 4\n");
    scanf("%d", &value4);
    printf("Enter an Integer for Value 5\n");
    scanf("%d", &value5);

    sum = (value1 + value2 + value3 + value4 + value5);
    average = (sum / 5.0);

    printf("Sum is: %d\n ", sum);
    printf("Average is: %.2f\n ", average);

    if (average > 100)
        printf("Average is over 100\n");

    return 0;
}
