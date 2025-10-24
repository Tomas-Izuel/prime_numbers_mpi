#ifndef DISTRIBUCION_H
#define DISTRIBUCION_H

#include <mpi.h>

void calcular_distribucion(int total_elementos, int size, int rank, 
                          int *inicio_local, int *fin_local, int *elementos_locales);
void distribuir_matriz(int *matriz, int *matriz_local, int total_elementos, 
                      int size, int rank, int elementos_locales);

#endif
