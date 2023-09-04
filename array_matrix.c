// Desenvolvendo matriz a partir de um vetor estático;

/*
- Create Matrix (rows, columns)
- Inserir Value (matrix, row, column, value)
- Update Value (matrix, row, column, value)
- Delete Value (matrix, row, column)
- Serch Value (matrix, row, column)

*QUANDO SOMAR UM PONTEIRO COM UM INT, ELE CONSIDERA BYTE (4 BYTES). Ex. 1431671456 + 1 = 1431671460
*/

#include <stdio.h>
#include <stdlib.h>

const int TAMANHO = 9;


void clearMatrix(int vet[TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++){
        vet[i] = 0;
    }
}

void insertElement(int vet[TAMANHO], int row, int col, int value) {
    int posicao = (row - 1) * 3 + (col - 1);
    vet[posicao] = value;
}

int fetchMatrix(int vet[TAMANHO], int row, int col) {
    int posicao = (row - 1) * 3 + (col - 1);
    int valor = vet[posicao];
    return valor;
}

void printMatrix(int vet[TAMANHO]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%2d ", vet[i * 3 + j]);
        }
        printf("\n");
    }
}

void main() {
    int vet[TAMANHO];
    clearMatrix(&vet);

    insertElement(&vet, 1, 1, 1);
    printf("%2d\n", fetchMatrix(vet, 1, 1));
    printMatrix(vet);

}