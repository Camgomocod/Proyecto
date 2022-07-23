#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct Node
{
    char Categoria_Producto[100];
    char Nombre_Del_Producto[50];
    char Fecha_De_Venta[50];
    char Modalidad_Venta[2];
    float Precio_De_Venta;
    char Num_Factura[10];
    struct Node* next;

}Node;

struct Node* head, *fisrt = NULL, *temp2;
//? @brief Funcione para vincular los nodos de manera dinamica donde van a ir conectados por las direcciones de memoria de cada uno.
struct Node* Conexion_Nodos(Node* head, char *Categoria_Producto, char *Nombre_Del_Producto, char* Fecha_De_Venta,
char *Modalidad_Venta, float Precio_De_Venta, char *Num_Factura)
{
    //! Los nodos se localizan en el heap y los resivimos con un puntero.
    struct Node* temp1 = (Node*)malloc(sizeof(struct Node)); 
    //! Asignamos la informacion a cada apartado creado en la estructura.
    strcpy(temp1->Categoria_Producto, Categoria_Producto);
    strcpy(temp1->Nombre_Del_Producto, Nombre_Del_Producto);
    strcpy(temp1->Fecha_De_Venta, Fecha_De_Venta);
    strcpy(temp1->Modalidad_Venta, Modalidad_Venta);
    strcpy(temp1->Num_Factura, Num_Factura);
    temp1->Precio_De_Venta = Precio_De_Venta;
    temp1->next = NULL;

    //! Vincular los nodos: 
    if (head == NULL)
    {
        head = temp2 = temp1;
    }else{
        temp2->next = temp1;
        temp2 = temp1;
    }
    
    //! Retornamos head, para guardar los cambios realizados
    return head;
}

//? @brief Funcion para validar : >| Modalidad_Venta| <, Online = 'O', Presencial = 'P'.
int Validar_Modalidad(char *Modalidad_Venta)
{
    char Online[2] = {'0'};
    char Presencial[2] = {'P'};

    //! Con >| strcmp |< comparamos las cadenas, si nos devuelve 0 es porque las cadenas son iguales por lo tanto retorna 1.
    if (strcmp(Modalidad_Venta,Online) == 0 || strcmp(Modalidad_Venta,Presencial) == 0)
    {
        return 1;
    }else

    return 0; 
}

/**
 * @brief 
 * ? Funcion para validar: >| Categoria_Producto |< entre las categorias: 
 * 1. Placa Base
 * 2. Ram
 * 3. Ssd
 * 4. Fuente de poder 
 * 5. Procesador
 * 6. Disco Duro
 */
bool Validar_Categorias(char *Categoria_Producto)
{
    char Placa_Base[20] = {"Placa Base"};
    char Ram[10] = {"Ram"};
    char Fuente_De_Poder[20] = {"Fuente De Poder"};
    char Procesador[15] = {"Procesador"};
    char Ssd[10] = {"Ssd"};
    char Tarjeta_Grafica[20] = {"Tarjeta Grafica"};
    char Disco_Duro[20] = {"Disco Duro"};

    //! Si al comparar la cadena que le pasamos al la funcion coincide con alguna retorna true.
    if(strcmp(Categoria_Producto,Placa_Base) == 0) return true;
    if(strcmp(Categoria_Producto,Ram) == 0) return true;
    if(strcmp(Categoria_Producto,Fuente_De_Poder) == 0) return true;
    if(strcmp(Categoria_Producto,Procesador) == 0) return true;
    if(strcmp(Categoria_Producto,Ssd) == 0) return true;
    if(strcmp(Categoria_Producto,Tarjeta_Grafica) == 0) return true;
    if(strcmp(Categoria_Producto,Disco_Duro) == 0) return true;

    //! Si al comparar la cadena que le pasamos a la funcion *no* coincide con ninguna retorna false.
    return false;
}

/**
 * @brief 
 * ? Procedimiento para mostrar la informacion registrada segun las Modalidades de venta: 
 * 1. Online = '0'
 * 2. Precesial = 'P'
 */

struct Node* Filtrar_Modalidad(Node* head)
{
    struct Node* temp = head;
    char Tipo_Servicio[2];
    do
    {
        printf("\n|>>>| Ingrese el servicio para filtrar las ventas por modalidad |<<<|");
        scanf("%s",Tipo_Servicio);
    } while (!Validar_Modalidad(Tipo_Servicio));

    //! Mientrar la informacion del los nodos no sea nulo va a imprimir cada nodo.
    while(temp != NULL)
    {
        //! Segun el tipo de servicio ingresado para filtrar se mostrara los nodos con esa modalidad
        if (strcmp(temp->Modalidad_Venta,Tipo_Servicio) == 0);
        {
            printf("\n>--------------------------------------<");
            printf("\n|>>>| Categoria Del Producto: > %s < |<<<|",temp->Categoria_Producto);
            printf("\n|>>>| Nombre Del Producto: > %s <|<<<|",temp->Nombre_Del_Producto);
            printf("\n|>>>| Fecha De Venta: > %s < |<<<|",temp->Fecha_De_Venta);
            printf("\n|>>>| Modalidad De Venta: > %s < |<<<|",temp->Modalidad_Venta);
            printf("\n|>>>| Precio de la venta: > %s < |<<<|",temp->Precio_De_Venta);
            printf("\n>--------------------------------------<");
            printf("\n");

            //! Para pasar a los nodos siguientes
            temp = temp->next;
        }
    }
}

//? Funcion para buscar los registros de las ventas para modificar el valor de la venta.
struct Node* Buscar_Num_Factura(Node* head)
{
    struct Node* temp = head;
    char Num_Factura[10];
    printf("\n|>>>| Ingrese el numero de la factura de la venta: |<<<|");
    scanf("%s",Num_Factura);
    
    while (temp != NULL)
    {
        if (strcmp(temp->Num_Factura, Num_Factura) == 0)
        {
            printf("\n|>>>| Ingrese el nuevo valor del producto > %s< |<<<|",temp->Nombre_Del_Producto);
            scanf("%f",&temp->Precio_De_Venta); 
        }
        
        temp = temp->next;
    }
    
    //! Retornamos head para guardar los cambios realizados en el registro.
    return head;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
