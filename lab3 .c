#include <stdio.h>

int main() {
    int score;

    printf("Enter the signal strength (0-100): ");
    scanf("%d", &score);

    // First, validate the input is within the 0-100 range
    if (score < 0 || score > 100) {
        printf("Error: Input outside 0-100 range.\n");
    } else {
        // Divide by 10 to turn ranges into single digits
        switch (score / 10) {
            case 10: // Special case for exactly 100
            case 9:  // 90-99
            case 8:  // 80-89
                printf("Grade: A\n");
                break;

            case 7:  // 70-79
            case 6:  // 60-69
                printf("Grade: B\n");
                break;

            case 5:  // 50-59
            case 4:  // 40-49
                printf("Grade: C\n");
                break;

            case 3:  // 30-39
                printf("Grade: D\n");
                break;

            default: // 0-29 (Covers cases 2, 1, and 0)
                printf("Grade: F\n");
                break;
        }
    }

    return 0;
}



