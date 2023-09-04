#include <stdio.h>
#include <stdlib.h>

/*
- Create Matrix (rows, columns)
- Inserir Value (matrix, row, column, value)
- Update Value (matrix, row, column, value)
- Delete Value (matrix, row, column)
- Serch Value (matrix, row, column)

*QUANDO SOMAR UM PONTEIRO COM UM INT, ELE CONSIDERA BYTE (4 BYTES). Ex. 1431671456 + 1 = 1431671460
*/


typedef struct {
    int rows;
    int cols;
    int *data;
    int *lastElement;
} Matrix;

Matrix createMatrix(int rows, int cols) {
    Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.data = (int *)malloc(rows * cols * sizeof(int));
    matrix.lastElement = matrix.data;
    return matrix;
}

void insertElement(Matrix *matrix, int value) {
    if (matrix->lastElement < matrix->data + matrix->rows * matrix->cols) {
        *(matrix->lastElement) = value; // Insere o valor na posição apontada pelo ponteiro
        matrix->lastElement++; // Avança o ponteiro para a próxima posição disponível
    }
}

void printMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%2d ", matrix->data[i * matrix->cols + j]);
        }
        printf("\n");
    }
}

void freeMatrix(Matrix *matrix) {
    free(matrix->data);
}
/*
1 2 3
4 5 6
7 8 9

row = 3
column = 3
setRow = 1
setColumn = 1

0 * 3 + 0 = 0
*/

void main() {
    Matrix mat = createMatrix(3, 3);

    insertElement(&mat, 1);
    insertElement(&mat, 2);
    insertElement(&mat, 3);
    insertElement(&mat, 4);
    insertElement(&mat, 5);
    insertElement(&mat, 6);
    insertElement(&mat, 7);
    insertElement(&mat, 8);
    insertElement(&mat, 9);

    printMatrix(&mat);
}