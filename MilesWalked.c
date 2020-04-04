// C Code
// This program will calculate the total number of miles walked for a week.
// Developer: Joseph Julian

#include <stdio.h>

int main(void) {

    /* Variable Definition */
    int Days, Miles, MilesWalked;

    /* Variable Initialization */
    Days = 0;
    Miles = 0;
    MilesWalked = 0;

    while (Days < 7) {
        printf("\nHow many miles did you walk today?");
        scanf("%d", &Miles);
        MilesWalked += Miles;
        Days++;
    } // Will loop until user has input number of miles walked for 7 days

    printf("\nGood job! Your total miles walked this week is: %d", MilesWalked);

    return 0;
}
