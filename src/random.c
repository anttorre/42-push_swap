#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para generar x números aleatorios sin repetir
void generarNumerosSinRepetir(int x, int min, int max) {
    // Verificación de límites
    if (x <= 0 || min >= max) {
        printf("Parámetros inválidos.\n");
        return;
    }

    // Inicializar la semilla aleatoria
    srand(time(NULL));

    // Verificación del rango de números posibles
    int numPosibles = max - min + 1;
    if (x > numPosibles) {
        printf("No hay suficientes números posibles en el rango [%d, %d].\n", min, max);
        return;
    }

    // Arreglo para llevar un registro de los números generados
    int *numerosGenerados = (int *)malloc(numPosibles * sizeof(int));
    if (numerosGenerados == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }

    // Inicializar el arreglo
    for (int i = 0; i < numPosibles; i++) {
        numerosGenerados[i] = min + i;
    }

    // Generar x números aleatorios sin repetir
    printf("Números aleatorios generados sin repetir:\n");
    for (int i = 0; i < x; i++) {
        // Generar un índice aleatorio en el rango restante
        int indice = rand() % (numPosibles - i);

        // Imprimir y eliminar el número seleccionado del arreglo
        printf("%d ", numerosGenerados[indice]);
        numerosGenerados[indice] = numerosGenerados[numPosibles - i - 1];
    }
    printf("\n");

    // Liberar la memoria
    free(numerosGenerados);
}

int main() {
    int cantidadNumeros = 100; // Cambia esto según la cantidad de números que desees generar
    int minimo = -1000; // Valor mínimo del rango (inclusive)
    int maximo = 1000; // Valor máximo del rango (inclusive)

    generarNumerosSinRepetir(cantidadNumeros, minimo, maximo);

    return 0;
}