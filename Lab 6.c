#include <stdio.h>


void foo1(int xval){
    int x;
    x =xval;

    printf(" The address of x is : %p \n", &x );
    printf("Press enter to continue.....");
    getchar();
}

void foo2(int yval){
    int y;
    y = yval;

    printf(" The address of y is : %p \n", &y);
    printf(" Press enter to continue");
    getchar();

}

void foo3(int zval){
    int z;
    z = zval;
    printf("The address of z is : %p \n",&z);
    printf("Press enter to continue");
    getchar();
}
int main(void){

    foo1(7);
    foo2(11);
    foo3(13);





    return 0;
}


