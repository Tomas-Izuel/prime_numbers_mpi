#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

void crear_matriz_ejemplo(int **matriz, int M, int R) {
    *matriz = (int*)malloc(M * R * sizeof(int));
    int matriz_ejemplo[] = {
        98, 88, 0, 5, 7, 40, 20, 33, 22,
        14, 82, 20, 0, 17, 24, 21, 30, 12,
        10, 28, 12, 4, 71, 26, 90, 74, 8,
        44, 18, 2, 1, 10, 24, 21, 30, 12,
        65, 60, 0, 72, 84, 1, 59, 55, 13
    };
    memcpy(*matriz, matriz_ejemplo, M * R * sizeof(int));
}

void mostrar_matriz(int *matriz, int M, int R) {
    printf("\nMatriz ingresada:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < R; j++) {
            printf("%3d ", matriz[i * R + j]);
        }
        printf("\n");
    }
    printf("\n");
}

void leer_matriz(int **matriz, int M, int R) {
    *matriz = (int*)malloc(M * R * sizeof(int));
    printf("Ingrese los elementos de la matriz (%dx%d):\n", M, R);
    for (int i = 0; i < M * R; i++) {
        scanf("%d", &(*matriz)[i]);
    }
}
