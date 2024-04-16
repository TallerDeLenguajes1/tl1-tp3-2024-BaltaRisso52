#include <stdio.h>
#include <stdlib.h>
#define FILA 5
#define COLUMNA 12

int main()
{
    
    int matriz[FILA][COLUMNA];
    int promedio[FILA];
    int suma;
    int vMax=0;
    int vMin = 51000;
    int anioMax, anioMin;
    int mesMax, mesMin;

    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            matriz[i][j] = rand()%(10000 - 50000 + 1) + 10000;
            printf("%d ", matriz[i][j]);
            suma = matriz[i][j] + suma;
            if (matriz[i][j] > vMax)
            {
                vMax = matriz[i][j];
                anioMax = i+1;
                mesMax = j+1;

            }
            if (matriz[i][j] < vMin)
            {
                vMin = matriz[i][j];
                anioMin = i+1;
                mesMin = j+1;
            }
            
            
        }
        promedio[i] = suma / 12;
        suma = 0;
        printf("\n");
    }
    printf("\nPROMEDIOS:");
    for (int i = 0; i < FILA; i++)
    {
        printf("\nAnio %d: %d", i+1, promedio[i]);
    }
    printf("\nValor maximo y minimo:");
    printf("\nEl valor maximo es: %d, obtenido en el anio %d, mes %d", vMax, anioMax, mesMax);
    printf("\nEl valor minimo es: %d, obtenido en el anio %d, mes %d", vMin, anioMin, mesMin);
    

    
    

    return 0;
}
