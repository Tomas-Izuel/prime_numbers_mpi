#include <stdlib.h>
#include <mpi.h>
#include "distribucion.h"

void calcular_distribucion(int total_elementos, int size, int rank, 
                          int *inicio_local, int *fin_local, int *elementos_locales) {
    int elementos_por_proceso = total_elementos / size;
    int elementos_restantes = total_elementos % size;
    
    if (rank < elementos_restantes) {
        *inicio_local = rank * (elementos_por_proceso + 1);
        *fin_local = *inicio_local + elementos_por_proceso + 1;
    } else {
        *inicio_local = rank * elementos_por_proceso + elementos_restantes;
        *fin_local = *inicio_local + elementos_por_proceso;
    }
    
    *elementos_locales = *fin_local - *inicio_local;
}

void distribuir_matriz(int *matriz, int *matriz_local, int total_elementos, 
                      int size, int rank, int elementos_locales) {
    int *sendcounts = NULL;
    int *displs = NULL;
    
    if (rank == 0) {
        sendcounts = (int*)malloc(size * sizeof(int));
        displs = (int*)malloc(size * sizeof(int));
        
        int elementos_por_proceso = total_elementos / size;
        int elementos_restantes = total_elementos % size;
        
        for (int i = 0; i < size; i++) {
            if (i < elementos_restantes) {
                sendcounts[i] = elementos_por_proceso + 1;
            } else {
                sendcounts[i] = elementos_por_proceso;
            }
            if (i == 0) {
                displs[i] = 0;
            } else {
                displs[i] = displs[i-1] + sendcounts[i-1];
            }
        }
    }
    
    MPI_Scatterv(matriz, sendcounts, displs, MPI_INT,
                 matriz_local, elementos_locales, MPI_INT, 0, MPI_COMM_WORLD);
    
    if (rank == 0) {
        free(sendcounts);
        free(displs);
    }
}
