/* 
addFrac1.C - Adds two user-input fractions
Author: Sam Johnson
Date: 9-9-13
*/

#include <stdio.h>

int main(){
        int numerator1, numerator2, denom1, denom2, finalDenom, finalNumerator;
        printf("Enter two fractions separated by a plus sign: ");
        scanf("%d/%d+%d/%d", &numerator1, &denom1, &numerator2, &denom2);

        finalDenom = denom1*denom2;
        numerator1 = numerator1 * denom2;
        numerator2 = numerator2 * denom1;
        finalNumerator = numerator1+numerator2;

        printf("The sum is %d/%d\n", finalNumerator, finalDenom);
        return 0;
}

