#include <stdio.h>

int main(){
    int x1= 10, x2=20, x3;
    int *ptr1, *ptr2, *ptr3;

    printf(" Address of x1,x2,x3: %p %p %p\n\n", &x1,&x2,&x3);
    printf("press enter to continue.....");
    getchar();

    ptr1 = &x1;
    printf("ptr1 now holds the address%p\n\n", ptr1);
    printf(" Value pointed to by ptr1= &d\n\n",*ptr1);
    printf("Press enter to continue.....");
    getchar();


    ptr2 = ptr1;
    printf("Value pointed to by ptr2= %d\n\n", *ptr2);

    ptr2 = &x2;
    ptr3 = &x3;

    *ptr3 = *ptr1 + *ptr2;

    printf(" New value of x3 = %d\n\n",x3);


    return 0;
}


