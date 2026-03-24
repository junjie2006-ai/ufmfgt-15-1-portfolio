#include <stdio.h>

int main() {
    double sensory [10];
    int i;

    for(i=0;i<10;i++){
        sensory[i]=-1.0;
    }

    printf("Sensor Array Initialized:\n");
    for (i = 0; i < 10; i++) {
        printf("Sensor %d: %.1f\n", i, sensory[i]);
    }

    return 0;
}

