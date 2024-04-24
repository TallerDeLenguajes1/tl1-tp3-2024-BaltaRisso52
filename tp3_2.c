#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMA 5

int main()
{
    printf("Ingrese la cantidad de nombres: ");
    int cant;
    scanf("%d", &cant);
    char **v;
    v = (char **)malloc(cant * sizeof(char *));
    char buff[100]; 
    for (int i = 0; i < cant; i++)
    {
        printf("Ingrese la palabra %d: ", i+1);
        scanf("%s",buff);
        v[i] = (char *)malloc(sizeof(char)*(strlen(buff)+1));
        strcpy(v[i], buff);

    }

    for (int i = 0; i < cant; i++)
    {
        printf("\nPalabra %d: %s", i+1,v[i]);
    }
    
    for (int i = 0; i < cant; i++)
    {
        free(v[i]);
    }

    free(v);
    

    return 0;
}
