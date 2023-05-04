#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of the matrix: ");
    scanf("%d", &size);
    
    int mat[size][size];
    
    // Initialize the matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                mat[i][j] = 0; // Diagonal elements
            } else if (i < j) {
                mat[i][j] = 2 * (j + i); // Upper triangle
            } else {
                mat[i][j] = 2 * i - 1; // Lower triangle
            }
        }
    }
    
    // Print the matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
