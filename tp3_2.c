#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMA 5

int main()
{
    
    char **v;
    v = (char **)malloc(TAMA * sizeof(char *));
    char buff[100]; 
    for (int i = 0; i < TAMA; i++)
    {
        printf("Ingrese la palabra %d: ", i+1);
        gets(buff);
        v[i] = (char *)malloc(sizeof(char)*(strlen(buff)+1));
        strcpy(v[i], buff);

    }

    for (int i = 0; i < TAMA; i++)
    {
        printf("\nPalabra %d: %s", i+1,v[i]);
    }
    
    for (int i = 0; i < TAMA; i++)
    {
        free(v[i]);
    }

    free(v);
    

    return 0;
}
