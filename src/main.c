#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include "primos.h"
#include "distribucion.h"
#include "resultados.h"
#include "matriz.h"

int main(int argc, char *argv[]) {
    int rank, size;
    int M, R;
    int *matriz = NULL;
    int *matriz_local = NULL;
    int inicio_local, fin_local;
    int elementos_locales;
    int primos_local = 0;
    int primos_total = 0;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    if (rank == 0) {
        printf("Ingrese las dimensiones de la matriz (M R): ");
        scanf("%d %d", &M, &R);
        
        if (M == 5 && R == 9) {
            printf("Usando matriz de ejemplo del problema...\n");
            crear_matriz_ejemplo(&matriz, M, R);
        } else {
            leer_matriz(&matriz, M, R);
        }
        
        mostrar_matriz(matriz, M, R);
    }
    
    MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&R, 1, MPI_INT, 0, MPI_COMM_WORLD);
    
    int total_elementos = M * R;
    
    calcular_distribucion(total_elementos, size, rank, &inicio_local, &fin_local, &elementos_locales);
    
    matriz_local = (int*)malloc(elementos_locales * sizeof(int));
    
    distribuir_matriz(matriz, matriz_local, total_elementos, size, rank, elementos_locales);
    
    primos_local = contar_primos_porcion(matriz_local, 0, elementos_locales);
    
    printf("Proceso %d: contó %d primos en elementos [%d-%d)\n", 
           rank, primos_local, inicio_local, fin_local);
    
    primos_total = recopilar_resultados(primos_local, rank);
    
    if (rank == 0) {
        mostrar_resultado_final(primos_total, matriz, M, R);
    }
    
    free(matriz_local);
    if (rank == 0) {
        free(matriz);
    }
    
    MPI_Finalize();
    return 0;
}
