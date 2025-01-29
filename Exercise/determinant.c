#include <stdio.h>

#define MAX 4

// Function to calculate the determinant of the matrix
int determinant(int matrix[MAX][MAX], int n) {
    int det = 0;
    int submatrix[MAX][MAX];

    // Base case: if matrix is 2x2
    if (n == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    } else {
        // Recursive case
        for (int x = 0; x < n; x++) {
            int subi = 0; // submatrix's row index

            // Form the submatrix
            for (int i = 1; i < n; i++) {
                int subj = 0; // submatrix's column index
                for (int j = 0; j < n; j++) {
                    if (j == x) {
                        continue;
                    }
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            // Recursively calculate the determinant and sum it up
            det += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(submatrix, n - 1);
        }
    }

    return det;
}

int main() {
    int n;
    int matrix[MAX][MAX];

    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int det = determinant(matrix, n);
    printf("The determinant of the matrix is: %d\n", det);

    return 0;
}
