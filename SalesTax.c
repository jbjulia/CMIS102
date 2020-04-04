// C Code
// This program will calculate the sales tax of a purchase.
// Developer: Joseph Julian

#include <stdio.h>

int main(void) {

    /* Variable Definition */
    float DollarAmount, SalesTax, Price;

    printf("\nEnter the price in Dollars: ");
    scanf("%f", &DollarAmount);

    printf("\nEnter state sales tax: ");
    scanf("%f", &SalesTax);

    Price = DollarAmount + (DollarAmount * SalesTax);

    printf("\nPrice with tax is: $ %.2f", Price);

    return 0;
}
