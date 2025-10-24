#include <stdio.h>
#include <mpi.h>
#include "resultados.h"
#include "primos.h"

int recopilar_resultados(int primos_local, int rank) {
    int primos_total = 0;
    MPI_Reduce(&primos_local, &primos_total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    return primos_total;
}

void mostrar_resultado_final(int primos_total, int *matriz, int M, int R) {
    printf("\nRESULTADO FINAL\n");
    printf("La cantidad de números primos presente es: %d\n", primos_total);
    
    printf("\nVerificación - Números primos en la matriz:\n");
    for (int i = 0; i < M * R; i++) {
        if (es_primo(matriz[i])) {
            printf("%d ", matriz[i]);
        }
    }
    printf("\n");
}
