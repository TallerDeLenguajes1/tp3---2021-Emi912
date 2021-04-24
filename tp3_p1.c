#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *TiposProductos[] = {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct Producto
{
    int ProductoID;       //Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}Producto;

typedef struct Cliente
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (alteatorio entre 1 y 5)
    Producto *Productos;          //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
}Cliente;

void cargarCliente(Cliente *cliente, int id);
void cargarProducto(Producto *producto, int cantProduct);
int costoTotal(Producto *producto);
void mostrarClientes(Cliente *cliente, int indice);
void mostrarProductos(Producto *producto, int cantProduct);

int main(){
    
    int cantClientes;
    Cliente *clientes;
    do
    {
    printf("Indique la cantidad de clientes MAX 5\n");
    scanf("%d", &cantClientes);
    } while (cantClientes > 5);
    

    clientes = (Cliente *)malloc(sizeof(Cliente) * cantClientes);
    for (int i = 0; i < cantClientes; i++)
    {
        cargarCliente(clientes, i);
    }


    for (int i = 0; i < cantClientes; i++)
    {
         mostrarClientes(clientes, i);
    }
    
       
    

    return 0;
}

void cargarCliente(Cliente *cliente, int id){
    (cliente + id)->ClienteID = id + 1;
    printf("--------------CARGANDO DATOS DEL CLIENTE[%d] -----------------\n");
    printf("Ingrese el nombre del cliente\n", id + 1);
    (cliente + id)->NombreCliente = (char *)malloc(sizeof(char)*100);
    fflush(stdin);
    gets((cliente + id)->NombreCliente);

    (cliente + id)->CantidadProductosAPedir = rand() % 4 + 1;

    (cliente + id)->Productos = (Producto *)malloc(sizeof(Producto) * (cliente + id)->CantidadProductosAPedir);

    cargarProducto((cliente + id)->Productos, (cliente + id)->CantidadProductosAPedir);
    printf("\n");

}

void cargarProducto(Producto *producto, int cantProduct){
    for (int i = 0; i < cantProduct; i++)
    {
        (producto + i)->ProductoID = i + 1;
        (producto + i)->Cantidad = rand() % 10 + 1;
        (producto + i)->TipoProducto = TiposProductos[rand() % 3 + 1];
        (producto + i)->PrecioUnitario = rand() % 91 + 10;
    }
    
}

int costoTotal(Producto *producto){

    return (producto->Cantidad * producto->PrecioUnitario);

}

void mostrarClientes(Cliente *cliente, int indice){
    printf("-----MOSTRANDO [%d] CLIENTE--------------\n", indice + 1);
    printf("ID Cliente = %d \n", indice + 1);
    printf("Nombre del cliente = %s\n", (cliente + indice)->NombreCliente);
    printf("Cantidad de productos que lleva = %d\n", (cliente + indice)->CantidadProductosAPedir);
    mostrarProductos((cliente + indice)->Productos, (cliente + indice)->CantidadProductosAPedir);
    int costoNeto;
    costoNeto = costoTotal((cliente + indice)->Productos);
    printf("COSTO TOTAL %d", costoNeto);
}

void mostrarProductos(Producto *producto, int cantProduct){
    printf("\n-----MOSTRANDO PRODUCTOS--------\n");
    for (int i = 0; i < cantProduct; i++)
    {
        printf("\nMOSTRANDO PRODUCTO [%d]\n", i + 1);
        printf("ID del producto = %d \n", (producto + i)->ProductoID);
        printf("Cantidad de productos = %d \n",(producto + i)->Cantidad);
        printf("Tipo de producto = %s \n",(producto + i)->TipoProducto);
        printf("Precio unitario del producto = %f \n",(producto + i)->PrecioUnitario);
    }
    




}