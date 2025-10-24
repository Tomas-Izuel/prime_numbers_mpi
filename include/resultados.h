#ifndef RESULTADOS_H
#define RESULTADOS_H

#include <mpi.h>

int recopilar_resultados(int primos_local, int rank);
void mostrar_resultado_final(int primos_total, int *matriz, int M, int R);

#endif
