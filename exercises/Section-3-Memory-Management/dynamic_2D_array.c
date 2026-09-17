#include <stdio.h>
#include <stdlib.h>

int **create_matrix(int rows, int cols) {
    int **arr = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = malloc(cols * sizeof(int));
    }
    return arr;
}

void free_matrix(int **matrix, int rows);

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
}