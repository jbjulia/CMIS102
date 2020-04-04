// C Code
// This code will calculate the value of ticket sales for concerts.
// Developer: Joseph Julian

#include <stdio.h>

#define MAXN 100 // max characters in a group/concert name
#define MAXG   7 // max concerts/groups
#define MAXC   3 // max categories

char group [MAXG][MAXN];
int fans [MAXG][MAXC];
float prices [MAXC];
float sales [MAXG];
int count = 0;

void printWelcome() {
    printf("Welcome!\n");
    printf("This C code will compute the values of the sales ticket sales for concerts.\n");
    printf("Developer: Joseph Julian\n");
    printf("\n");
}

void printArray() {
    printf("%15s%5s%5s%5s%10s\n",
            "Concert", "s1", "s2", "s3", "Sales");
    for (int i = 0; i < count; i++) {
        printf("%15s", group [i]);
        for (int j = 0; j < MAXC; j++) {
            printf("%5d", fans[i][j]);
        } // end for each category
        printf("%10.2f\n", sales [i]);
    } // end for each group
} // end function printArray

void computeSales() {
    for (int i = 0; i < count; i++) {
        sales [i] = 0;
        for (int j = 0; j < MAXC; j++) {
            sales [i] += prices [j] * fans [i][j];
        } // end for each category
    } // end for each group
} // end function computeSales

void switchRows(int m, int n) {
    char tc;
    int ti;
    float v;
    // printf ("Switching %d with %d\n", m, n);
    for (int i = 0; i < MAXN; i++) {
        tc = group [m][i];
        group [m][i] = group [n][i];
        group [n][i] = tc;
    } // end for each character in a group name
    for (int i = 0; i < MAXC; i++) {
        ti = fans [m][i];
        fans [m][i] = fans [n][i];
        fans [n][i] = ti;
    } // end for each fan category
    v = sales [m];
    sales [m] = sales [n];
    sales [n] = v;
} // end switch

int findMinSales(int m) {
    float min = sales [m];
    int target = m;
    for (int i = m + 1; i < count; i++)
        if (sales [i] < min) {
            min = sales [i];
            target = i;
        } // end new max found
    return target;
} // end function findMinSales

void sortBySales() {
    int target;
    for (int i = 0; i < count; i++) {
        target = findMinSales(i);
        if (target > i)
            switchRows(i, target);
    } // for each concert
} // end function sortBySales

void getData() {
    // for (int i = 0; i < MAXG; i++) sales [i] = 0;
    printf("Enter ticket prices in each of %d categories: ", MAXC);
    for (int i = 0; i < MAXC; i++)
        scanf("%f", &prices [i]);
    printf("-- Enter group and fans in %d categories\n", MAXC);
    printf("   . to finish entries:\n");
    for (int i = 0; i < MAXG; i++) {
        scanf("%s", group[i]);
        if (group [i][0] == '.')
            break;
        count++;
        for (int j = 0; j < MAXC; j++)
            scanf("%d", &fans[i][j]);
    } // end for each group
} // end function getData

int main(void) {
    printWelcome();
    getData();
    computeSales();
    printArray();
    printf("\n --- Sorted ---\n");
    sortBySales();
    printArray();
    printf("... bye ...\n");
    return 0;
}
