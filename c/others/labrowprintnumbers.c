#include <stdio.h>

int main() {
    int rows, i, j, num;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++) {
        num = 1;

        // Print spaces
        for (j = i; j < rows; j++) {
            printf("   ");
        }

        // Print numbers in increasing order
        for (j = 1; j <= i; j++) {
            printf("%d  ", num++);
        }

        num -= 2;

        // Print numbers in decreasing order
        for (j = 1; j < i; j++) {
            printf("%d  ", num--);
        }

        printf("\n");
    }

    return 0;
}

