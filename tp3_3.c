#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct Producto
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;

struct Cliente
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos;         // El tamaño de este arreglo depende de la variable
    // "CantidadProductosAPedir"
} typedef clientes;

float CostoTotalProduc(int cliente, int producto, clientes *cl);

int main()
{
    srand(time(NULL));
    char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
    int cliente;
    do
    {
        printf("Ingresar la Cantidad de clientes a visitar (MAX 5): ");
        scanf("%d", &cliente);
    } while (cliente > 5 || cliente <= 0);
    clientes *cl;
    cl = (clientes *)malloc(cliente * sizeof(clientes));
    char buff[50];
    int cant;
    int *costoTotal = (int *)malloc(sizeof(int) * cliente);
    for (int i = 0; i < cliente; i++)
    {
        costoTotal[i] = 0;
        printf("/-----------ALTA CLIENTE-----------/\n");
        cl[i].ClienteID = i;
        printf("Ingresar nombre del cliente: ");

        scanf("%s", &buff);
        cant = strlen(buff);
        cl[i].NombreCliente = (char *)malloc(sizeof(char) * (cant + 1));
        strcpy(cl[i].NombreCliente, buff);

        cl[i].CantidadProductosAPedir = rand() % (5 - 1 + 1) + 1;
        cl[i].Productos = (Producto *)malloc(cl[i].CantidadProductosAPedir * sizeof(Producto));
        for (int j = 0; j < cl[i].CantidadProductosAPedir; j++)
        {
            cl[i].Productos[j].Cantidad = rand() % (10 - 1 + 1) + 1;
            cl[i].Productos[j].TipoProducto = TiposProductos[rand() % (4 + 1)];
            cl[i].Productos[j].PrecioUnitario = rand() % (100 - 10 + 1) + 10;
            cl[i].Productos[j].ProductoID = j;
            costoTotal[i] += cl[i].Productos[j].Cantidad * cl[i].Productos[j].PrecioUnitario;
        }
    }

    for (int i = 0; i < cliente; i++)
    {
        printf("\n/-----------MOSTRAMOS CLIENTE %d-----------/", i);
        
        printf("\nID del cliente: %d", cl[i].ClienteID);
        printf("\nNombre: %s", cl[i].NombreCliente);
        printf("\nCantidad de Productos diferentes pedidos: %d", cl[i].CantidadProductosAPedir);
        printf("\n/------PRODUCTOS------/");
        printf("\n");
        for (int j = 0; j < cl[i].CantidadProductosAPedir; j++)
        {
            printf("\nProducto ID: %d", cl[i].Productos[j].ProductoID);
            printf("\nCantidad: %d", cl[i].Productos[j].Cantidad);
            printf("\nTipo de producto: %s", cl[i].Productos[j].TipoProducto);
            printf("\nPrecio Unitario: %.2f", cl[i].Productos[j].PrecioUnitario);
            printf("\n-------");
        }
        printf("\nCosto Total: %d", costoTotal[i]);
    }

    float costo = CostoTotalProduc(0, 0, cl);
    printf("\nEl costo total es: %.2f", costo);

    for (int i = 0; i < cliente; i++)
    {
        free(cl[i].Productos);
        free(cl[i].NombreCliente);
    }
    free(cl);
    free(costoTotal);
    
    

    return 0;
}

float CostoTotalProduc(int cliente, int producto, clientes *cl)
{

    return cl[cliente].Productos[producto].PrecioUnitario * cl[cliente].Productos[producto].Cantidad;
}