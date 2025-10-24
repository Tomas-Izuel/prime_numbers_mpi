#!/bin/bash

echo " Matriz 1: Original del problema (5x9)"
echo "5 9" | ./contar_primos_secuencial

echo -e "\n Matriz 2: Pequeña (3x4)"
printf "3 4\n1 2 3 4\n5 6 7 8\n9 10 11 12\n" | ./contar_primos_secuencial

echo -e "\n Matriz 3: Con muchos primos (4x5)"
printf "4 5\n2 3 5 7 11\n13 17 19 23 29\n31 37 41 43 47\n53 59 61 67 71\n" | ./contar_primos_secuencial

echo -e "\n Matriz 4: Sin primos (3x3)"
printf "3 3\n4 6 8\n9 10 12\n14 15 16\n" | ./contar_primos_secuencial

echo -e "\n Matriz 5: Mixta (2x6)"
printf "2 6\n1 2 4 5 6 8\n9 10 11 12 13 14\n" | ./contar_primos_secuencial
