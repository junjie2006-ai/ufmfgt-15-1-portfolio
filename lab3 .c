#include <stdio.h>

int main() {
    int num;

    printf("Enter a control value (-10 to 10): ");
    scanf("%d", &num);

    // 1. Validation Range Check
    if (num >= -10 && num <= 10) {

        // 2a. Check if positive, negative, or zero
        if (num > 0) {
            printf("The value is positive.\n");
        } else if (num < 0) {
            printf("The value is negative.\n");
        } else {
            printf("The value is zero.\n");
        }

        // 2b. Check if odd or even using the modulo operator (%)
        // We use the absolute value logic or check remainder != 0 for odd
        if (num % 2 == 0) {
            printf("The value is even.\n");
        } else {
            printf("The value is odd.\n");
        }

    } else {
        // Error for inputs outside the range
        printf("Error: Input %d is outside the valid range (-10 to 10).\n", num);
    }

    return 0;
}