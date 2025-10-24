#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int es_primo(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int contar_primos_matriz(int *matriz, int total_elementos) {
    int contador = 0;
    for (int i = 0; i < total_elementos; i++) {
        if (es_primo(matriz[i])) {
            contador++;
        }
    }
    return contador;
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

int main() {
    int M, R;
    int *matriz = NULL;
    int primos_total = 0;
    
    printf("Ingrese las dimensiones de la matriz (N X M): ");
    scanf("%d %d", &M, &R);
    
    leer_matriz(&matriz, M, R);
    
    mostrar_matriz(matriz, M, R);
    
    primos_total = contar_primos_matriz(matriz, M * R);
    
    printf("RESULTADO FINAL\n");
    printf("La cantidad de números primos presente es: %d\n", primos_total);
    
    printf("\nVerificación - Números primos en la matriz:\n");
    for (int i = 0; i < M * R; i++) {
        if (es_primo(matriz[i])) {
            printf("%d ", matriz[i]);
        }
    }
    printf("\n");
    
    free(matriz);
    return 0;
}
