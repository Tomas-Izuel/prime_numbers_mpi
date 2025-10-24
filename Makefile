CC = gcc
MPICC = mpicc
CFLAGS = -Wall -Wextra -O2 -Iinclude
TARGET_MPI = contar_primos_mpi
TARGET_SEC = contar_primos_secuencial
SOURCES_MPI = src/main.c src/primos.c src/distribucion.c src/resultados.c src/matriz.c
SOURCES_SEC = src/contar_primos_secuencial.c
OBJECTS_MPI = $(SOURCES_MPI:.c=.o)

$(TARGET_MPI): $(OBJECTS_MPI)
	$(MPICC) $(CFLAGS) -o $(TARGET_MPI) $(OBJECTS_MPI) -lm

$(TARGET_SEC): $(SOURCES_SEC)
	$(CC) $(CFLAGS) -o $(TARGET_SEC) $(SOURCES_SEC) -lm

%.o: %.c
	$(MPICC) $(CFLAGS) -c $< -o $@

# Compilar versión secuencial
secuencial: $(TARGET_SEC)

# Ejecutar versión secuencial
run-sec: $(TARGET_SEC)
	./$(TARGET_SEC)

# Ejecutar con 4 procesos (requiere MPI)
run: $(TARGET_MPI)
	mpirun -np 4 ./$(TARGET_MPI)

# Ejecutar con 2 procesos (requiere MPI)
run2: $(TARGET_MPI)
	mpirun -np 2 ./$(TARGET_MPI)

# Ejecutar con 8 procesos (requiere MPI)
run8: $(TARGET_MPI)
	mpirun -np 8 ./$(TARGET_MPI)

# Limpiar archivos compilados
clean:
	rm -f $(TARGET_MPI) $(TARGET_SEC) $(OBJECTS_MPI)
	rm -f src/*.o

# Ayuda
help:
	@echo "Comandos disponibles:"
	@echo "  make secuencial  - Compilar versión secuencial"
	@echo "  make run-sec     - Ejecutar versión secuencial"
	@echo "  make run         - Ejecutar con 4 procesos (requiere MPI)"
	@echo "  make run2        - Ejecutar con 2 procesos (requiere MPI)"
	@echo "  make run8        - Ejecutar con 8 procesos (requiere MPI)"
	@echo "  make clean       - Limpiar archivos compilados"
	@echo "  make help        - Mostrar esta ayuda"

.PHONY: run run2 run8 clean help
