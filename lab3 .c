#include <stdio.h>

int main() {
    float a,b,c,d,temp;

    printf("Enter four numbers:\n");
    scanf("%f %f %f %f", &a, &b, &c, &d);

    if (a > b) { temp = a; a = b; b = temp; }
    if (a > c) { temp = a; a = c; c = temp; }
    if (a > d) { temp = a; a = d; d = temp; }

    if (b > c) { temp = b; b = c; c = temp; }
    if (b > d) { temp = b; b = d; d = temp; }

    if (c > d) { temp = c; c = d; d = temp; }


    printf("\nAscending order: %.2f %.2f %.2f %.2f\n", a, b, c, d);


    printf("Descending order: %.2f %.2f %.2f %.2f\n", d, c, b, a);

    return 0;
}


