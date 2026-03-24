#include <stdio.h>

int main() {
    float num1, num2, num3, num4;

    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter second number: ");
    scanf("%f", &num2);

    printf("Enter third number: ");
    scanf("%f", &num3);

    printf("Enter fourth number: ");
    scanf("%f", &num4);

    float minimum = num1;

    // Compare and update
    if (num2 < minimum) {
        minimum = num2;
    }

    if (num3 < minimum) {
        minimum = num3;
    }

    if (num4 < minimum) {
        minimum = num4;
    }
    printf("The minimum value is: %.2f\n", minimum);
    return 0;
}


