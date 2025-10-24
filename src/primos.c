#include <math.h>
#include "primos.h"

int es_primo(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int contar_primos_porcion(int *matriz, int inicio, int fin) {
    int contador = 0;
    for (int i = inicio; i < fin; i++) {
        if (es_primo(matriz[i])) {
            contador++;
        }
    }
    return contador;
}
