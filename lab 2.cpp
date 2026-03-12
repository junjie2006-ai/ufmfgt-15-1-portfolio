int main() {
    int num, ones, tens, revresed;

    printf("Please enter a teo digit number:");
     scanf("%d",&num);

      tens = num /10;
    ones = num %10;
      revresed = ones * 10 + tens;
    printf("The number revered is : %d", revresed);

      return 0;
}

// Created by j75-wang on 12/03/2026.
//

#include <stdio.h>
#include<math.h>

int main() {

      float num, height, length;

       printf("Please enter the height of the right angle triangle:");
      scanf("%f",&height);

      printf("please enter the length of the right angle triangle:");
      scanf("%f", &length);

       num = sqrt((height*height) + (length *length)) +length + height;

      printf("The perimeter is : %f", num);

    return 0;
}
