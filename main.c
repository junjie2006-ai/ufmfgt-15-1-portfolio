#include <stdio.h>

struct number {
  double real;
  double imaginary;
};

int main() {
    struct number c1= {0.0,1.0};
    struct number c2= {1.0,0.0};
    struct number c3;

    c1 =c2;

    c3.real = c1.real + c2.real;
    c3.imaginary = c1.imaginary + c2.imaginary;

    printf("c1 = %lf + %lfi\n", c1.real, c1.imaginary);
    printf("c2 = %lf + %lfi\n", c2.real, c2.imaginary);
    printf("c3 = %lf + %lfi\n", c3.real, c3.imaginary);



    return 0;
}
