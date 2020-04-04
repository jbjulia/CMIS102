// C Code
// This program will calculate the weighted average of 10 numbers.
// Developer: Joseph Julian

#include <stdio.h>

int main() {

    /* Variable Definition */
    int count;
    double avg, value, weight, sum, sumw;

    /* Variable Initialization */
    count = 0;
    sum = 0;
    sumw = 0;
    avg = 0.0;

    // Loop through to input values
    while (count < 10) {

        printf("\nEnter a value and its weight: ");
        // use %lf for double, %f for float
        scanf("%lf %lf", &value, &weight);

        if (weight >= 0) {
            sumw = sumw + weight;
            sum = sum + value * weight;
            count++;
        } else {
            printf("\nWeight must be positive\n");
        } // end if weight ok
    } // end reading input values and weights

    // Calculate avg if sumw is not 0
    avg = sum / sumw;
    printf("\nAverage is %lf", avg);

    return 0;
}
