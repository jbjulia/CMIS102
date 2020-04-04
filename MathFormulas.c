// C Code
// This program will calculate the area of a trapezoid.
// Developer: Joseph Julian

#include <stdio.h>

int main() {

    /* Variable Definition */
    float baseA, baseB, height, area;

    /* Prompt user for baseA */
    printf("Enter the first base of the trapezoid: \n");

    // Input the base
    scanf("%f", &baseA);

    /* Prompt user for baseB */
    printf("Enter the second base of the trapezoid: \n");

    // Input the baseB
    scanf("%f", &baseB);

    /* Prompt user for height */
    printf("Enter the height of the trapezoid: \n");

    // Input the height
    scanf("%f", &height);

    // Calculate the Area
    area = 0.5 * (baseA + baseB) * height;

    // Print the result
    printf("Area is : %f\n", area);

    return 0;
}
