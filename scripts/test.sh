#!/bin/bash

echo "=== Test de rendimiento con matrices de diferentes tamaños ==="

# Función para medir tiempo
medir_tiempo() {
    local descripcion="$1"
    local comando="$2"
    
    echo "=== $descripcion ==="
    echo "Ejecutando: $comando"
    
    # Medir tiempo con time
    time eval "$comando"
    echo ""
}

# Matriz pequeña (10x10) - 100 elementos
echo "Creando matriz pequeña (10x10)..."
printf "10 10\n" > /tmp/matriz_pequena.txt
for i in {1..100}; do
    printf "%d " $((RANDOM % 100 + 1))
    if [ $((i % 10)) -eq 0 ]; then
        printf "\n"
    fi
done >> /tmp/matriz_pequena.txt

# Matriz mediana (100x100) - 10,000 elementos  
echo "Creando matriz mediana (100x100)..."
printf "100 100\n" > /tmp/matriz_mediana.txt
for i in {1..10000}; do
    printf "%d " $((RANDOM % 1000 + 1))
    if [ $((i % 100)) -eq 0 ]; then
        printf "\n"
    fi
done >> /tmp/matriz_mediana.txt

# Matriz gigante (1000x1000) - 250,000 elementos
echo "Creando matriz gigante (1000x1000)..."
printf "1000 1000\n" > /tmp/matriz_gigante.txt
for i in {1..1000000}; do
    printf "%d " $((RANDOM % 10000 + 1))
    if [ $((i % 1000)) -eq 0 ]; then
        printf "\n"
    fi
done >> /tmp/matriz_gigante.txt

echo "Matrices creadas. Iniciando pruebas de rendimiento..."
echo ""

# Test 1: Matriz pequeña
medir_tiempo "Matriz Pequeña (10x10) - 100 elementos" "cat /tmp/matriz_pequena.txt | ./contar_primos_secuencial"

# Test 2: Matriz mediana  
medir_tiempo "Matriz Mediana (100x100) - 10,000 elementos" "cat /tmp/matriz_mediana.txt | ./contar_primos_secuencial"

# Test 3: Matriz gigante
medir_tiempo "Matriz Gigante (1000x1000) - 1000,000 elementos" "cat /tmp/matriz_gigante.txt | ./contar_primos_secuencial"

# Limpiar archivos temporales
echo "Limpiando archivos temporales..."
rm -f /tmp/matriz_pequena.txt /tmp/matriz_mediana.txt /tmp/matriz_gigante.txt

echo "=== Test completado ==="