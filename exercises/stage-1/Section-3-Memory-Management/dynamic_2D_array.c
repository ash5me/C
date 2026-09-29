#include <stdio.h>
#include <stdlib.h>

int **create_matrix(int rows, int cols) {
    // concept : blob:https://gemini.google.com/0e31d1fe-7641-4d93-8921-1977c693e1d0 -> so,basically **int points to the mem.add of *int
    //allocate row pointers
    int **arr = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = malloc(cols * sizeof(int));
    }
    return arr;
}

void free_matrix(int **matrix, int rows) {
    for (int i = 0; i<rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int **matrix = create_matrix(3, 4);

    matrix[0][0] = 10;
    matrix[0][1] = 20;
    matrix[0][2] = 30;
    matrix[0][3] = 40;

    matrix[1][0] = 50;
    matrix[1][1] = 60;
    matrix[1][2] = 70;
    matrix[1][3] = 80;

    matrix[2][0] = 90;
    matrix[2][1] = 100;
    matrix[2][2] = 110;
    matrix[2][3] = 120;

    printf("%d\n", matrix[1][2]);  // 70

    free_matrix(matrix,3);
    matrix = NULL;
}