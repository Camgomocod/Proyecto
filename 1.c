#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct Node
{
    char Categoria_Producto[100];
    char Nombre_Del_Producto[50];
    char Fecha_De_Venta[40];
    char Modalidad_Venta[2];
    float Precio_De_Venta;
    char Num_Factura[10];
    struct Node* next;

}Node;

struct Node* head, *first = NULL, *temp2;
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

//? Procedimiento para imprimir el menu de opciones:
void Menu(void)
{
    
    printf("\n\t\t|--------------------------------------------------------------------|");
    printf("\n\t\t|      |[***********]|>          MENU          <|[***********]|      |");
    printf("\n\t\t|(>>>>)| Opcion 1: Ingresar informacion de la venta.          |(<<<<)|");
    printf("\n\t\t|(>>>>)| Opcion 2: Filtrar facturas por modalidad.            |(<<<<)|");
    printf("\n\t\t|(>>>>)| Opcion 3: Modificar valor de venta.                  |(<<<<)|");
    printf("\n\t\t|(>>>>)| Opcion 4: Recomedador de Pcs.                        |(<<<<)|");
    printf("\n\t\t|(>>>>)| Opcion 5: Imprimir las ventas ingresadas.            |(<<<<)|");
    printf("\n\t\t|(>>>>)| Opcion 6: Imprimir todos los registros de venta.     |(<<<<)|");
    printf("\n\t\t|(>>>>)| Opcion 7: Imprimir registros modalidad Online.       |(<<<<)|");
    printf("\n\t\t|(>>>>)| Opcion 8: Imprimir registros modalidad Presencial.   |(<<<<)|");
    printf("\n\t\t|(>>>>)| Opcion 8: >| Salir. |<                               |(<<<<)|");
    printf("\n\t\t|--------------------------------------------------------------------|");
    printf("\n");
    printf("\n\t\t|[*]>>>[*]| Digite la opcion que desea seleccionar.        |[*][*]>");
}

//? Funcion para validar : >| Modalidad_Venta| <, Online = 'O', Presencial = 'P'.
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
            printf("\n>----------------------------------------<");
            printf("\n");
            printf("\n|>>>| Categoria Del Producto: > %s < |<<<|",temp->Categoria_Producto);
            printf("\n");
            printf("\n|>>>| Nombre Del Producto:    > %s < |<<<|",temp->Nombre_Del_Producto);
            printf("\n|>>>| Fecha De Venta:         > %s < |<<<|",temp->Fecha_De_Venta);
            printf("\n|>>>| Modalidad De Venta:     > %s < |<<<|",temp->Modalidad_Venta);
            printf("\n|>>>| Precio de la venta:     > %s < |<<<|",temp->Precio_De_Venta);
            printf("\n");
            printf("\n>----------------------------------------<");
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

//? Procedimiento para guardar la informacion de las facturas con la modalidad : Online = '0'.
struct Node* Almacenar_Registros_Online(Node* head)
{
    //! Abrimos el txt donde vamos a guardar los registros por modalidad es este caso es : > Online <
    FILE *File_Open = fopen("Online_Register.txt","a");
    //! Si el puntero fp es nullo va a imprimir un error: no pudo abrir el archivo.
    if (File_Open == NULL)
    {
        printf("\n|>>>| ERROR AL ABRIR EL ARCHIVO |<<<|");
        exit(1);
    }
    struct Node* temp = head; 
    //! Modalidad de venta
    char Online[2] = {'0'};
    //! Guardamos el registro en: > Online_Register.txt < si cumple con la condicion de ser igual a modalidad Online.
    while (temp != NULL)
    {
        if (strcmp(temp->Modalidad_Venta,Online) == 0)
        {
            fprintf(File_Open,"\n>----------------------------------------<");
            fprintf(File_Open,"\n");
            fprintf(File_Open,"\n|>>>| Categoria Del Producto: > %s < |<<<|",temp->Categoria_Producto);
            fprintf(File_Open,"\n");
            fprintf(File_Open,"\n|>>>| Nombre Del Producto:    > %s < |<<<|",temp->Nombre_Del_Producto);
            fprintf(File_Open,"\n|>>>| Fecha De Venta:         > %s < |<<<|",temp->Fecha_De_Venta);
            fprintf(File_Open,"\n|>>>| Modalidad De Venta:     > %s < |<<<|",temp->Modalidad_Venta);
            fprintf(File_Open,"\n|>>>| Precio de la venta:     > %s < |<<<|",temp->Precio_De_Venta);
            fprintf(File_Open,"\n");
            fprintf(File_Open,"\n>-------------------------------------- <");
            fprintf(File_Open,"\n");
        }
        
        temp = temp->next;
    }
    
    fclose(File_Open);
}

//? Procedimiento para guardar la informacion de las facturas con la modalidad : Presencial = 'P'.
struct Node* Almacenar_Registros_Presencial(Node* head)
{
    FILE *File_Open = fopen("Presencial_Register.txt","a");
    if (File_Open == NULL)
    {
        printf("\n|>>>| ERROR AL ABRIR EL ARCHIVO |<<<|");
        exit(2);
    }
    struct Node* temp = head;
    //! Modalidad de venta.
    char Presencial[2] = {'P'};
    while (temp != NULL)
    {
        if (strcmp(temp->Modalidad_Venta,Presencial) == 0)
        {
            fprintf(File_Open,"\n>----------------------------------------<");
            fprintf(File_Open,"\n");
            fprintf(File_Open,"\n|>>>| Categoria Del Producto: > %s < |<<<|",temp->Categoria_Producto);
            fprintf(File_Open,"\n");
            fprintf(File_Open,"\n|>>>| Nombre Del Producto:    > %s < |<<<|",temp->Nombre_Del_Producto);
            fprintf(File_Open,"\n|>>>| Fecha De Venta:         > %s < |<<<|",temp->Fecha_De_Venta);
            fprintf(File_Open,"\n|>>>| Modalidad De Venta:     > %s < |<<<|",temp->Modalidad_Venta);
            fprintf(File_Open,"\n|>>>| Precio de la venta:     > %s < |<<<|",temp->Precio_De_Venta);
            fprintf(File_Open,"\n");
            fprintf(File_Open,"\n>-------------------------------------- <");
            fprintf(File_Open,"\n");
        }
        
        temp = temp->next;
    }
    
    fclose(File_Open);
}

//? Funcion para calcular el total de las ventas registradas
float Total_Ventas_Realizadas(struct Node* head)
{
    struct Node* temp = head;
    float Suma_Ventas;
    while (temp != NULL)
    {
        Suma_Ventas += temp->Precio_De_Venta;

        temp = temp->next;
    }
    
    return Suma_Ventas;
}

//? Procedimiento para guardar la informacion de todas las facturas generadas
struct Node* Almacenar_Total_Ventas(Node* head)
{
    FILE *File_Open = fopen("Total_Ventas_Registro.txt","a");
    if (File_Open == NULL)
    {
        printf("\n|>>>| ERROR AL ABRIR EL ARCHIVO |<<<|");
        exit(3);
    }
    float Suma_Pagos;
    Suma_Pagos = Total_Ventas_Realizadas(first);
    struct Node* temp = head;

    fprintf(File_Open,"|[****]| REGISTRO TOTAL DE VENTAS: |[]> %.1f <[]| |[****]|",Suma_Pagos);

    while (temp != NULL)
    {
        fprintf(File_Open,"\n>----------------------------------------<");
        fprintf(File_Open,"\n");
        fprintf(File_Open,"\n|>>>| Categoria Del Producto: > %s < |<<<|",temp->Categoria_Producto);
        fprintf(File_Open,"\n");
        fprintf(File_Open,"\n|>>>| Nombre Del Producto:    > %s < |<<<|",temp->Nombre_Del_Producto);
        fprintf(File_Open,"\n|>>>| Fecha De Venta:         > %s < |<<<|",temp->Fecha_De_Venta);
        fprintf(File_Open,"\n|>>>| Modalidad De Venta:     > %s < |<<<|",temp->Modalidad_Venta);
        fprintf(File_Open,"\n|>>>| Precio de la venta:     > %s < |<<<|",temp->Precio_De_Venta);
        fprintf(File_Open,"\n");
        fprintf(File_Open,"\n>-------------------------------------- <");
        fprintf(File_Open,"\n");

        temp = temp->next;
    }
    
    fclose(File_Open);
}

//? Imprimir la informacion de las ventas realizadas y guardadas mediante los nodos mediante recursividad.
struct Node* Imprimir_Ventas_Registradas(Node* temp)
{
    //! Si temp es = NULL quiere decir que llego al final de la lista
    if(temp == NULL)
    {
        return;
    }

    printf("\n>----------------------------------------<");
    printf("\n");
    printf("\n|>>>| Categoria Del Producto: > %s < |<<<|",temp->Categoria_Producto);
    printf("\n");
    printf("\n|>>>| Nombre Del Producto:    > %s < |<<<|",temp->Nombre_Del_Producto);
    printf("\n|>>>| Fecha De Venta:         > %s < |<<<|",temp->Fecha_De_Venta);
    printf("\n|>>>| Modalidad De Venta:     > %s < |<<<|",temp->Modalidad_Venta);
    printf("\n|>>>| Precio de la venta:     > %s < |<<<|",temp->Precio_De_Venta);
    printf("\n");
    printf("\n>-------------------------------------- <");
    printf("\n");

    Imprimir_Ventas_Registradas(temp->next);
}

//? Procedimiento para concatenar cadenas para mostrar la fecha.
void concatenar(char* buffer, char* Ano, char* Mes, char* Dia)
{
  strcpy(buffer, Ano);
  strcat(buffer, "/");
  strcat(buffer, Mes);
  strcat(buffer, "/");
  strcat(buffer, Dia);
}

/**
 * @brief 
 * ? Le pasamos una etiqueta al procedimento para ser utilizada para imprimir todos los registros:
 * 1. Online
 * 2. Presencial
 * 3. Todos los registros 
 * 4. Categorias del recomendador de pcs
 * @param etiqueta 
 */
void Imprimir_Registros(char *etiqueta)
{
    FILE *File_Open = fopen(etiqueta,"r");
    if (File_Open == NULL)
    {
        printf("\n|>>>| ERROR AL ABRIR EL ARCHIVO |<<<|");
        exit(6);
    }
    char Print;
    Print = fgetc(File_Open);
    //! Mientras no llegue al final del txt va a imprimir las palabras copiadas
    while (!feof(File_Open))
    {
        printf("%c",Print);
        Print = fgetc(File_Open);
    }
    
    fclose(File_Open);
}

//? Procedimiento para registrar la informacion de las ventas en los nodos > Linked List <
void Register_Informacion_Ventas(void)
{
    //! Variables que van a ser copiadas en los nodos o asignadas.
    char Categoria_Producto[100];
    char Nombre_Del_Producto[50];
    char Dia[10], Mes[20], Ano[10], Fecha_De_Venta[40];
    char Modalidad_De_Venta[2];
    float Precio_De_Venta;
    char Num_Factura[10];
    int Num_Nodos;

    printf("\n[[**]]> DIgite cuantas ventas desea registrar:       <[[**]] ");
    scanf("%d",&Num_Nodos);

    for (int i = 0; i < Num_Nodos; i++)
    {
        do
        {
            printf("|[>>>]| Ingrese la categoria del producto :   [[**]]> ");
            gets(Categoria_Producto);
        } while (!Validar_Categorias(Categoria_Producto));

        printf("|[>>>]| Ingrese el nombre del producto :    [[**]]> ");
        gets(Nombre_Del_Producto);

        printf("|[>>>]| Ingrese la fecha de venta:          [[**]]> ");
        printf("\n");
        printf("|[>>>]| AÑO:                 [[**]]>");
        scanf("%s",Ano);
        printf("|[>>>]| MES:                 [[**]]>");
        scanf("%s",Mes);
        printf("|[>>>]| DIA:                 [[**]]>");
        scanf("%s",Dia);
        concatenar(Fecha_De_Venta, Ano, Mes, Dia);
        do
        {
            printf("|[>>>]| Ingrese modalidad de venta:          [[**]]> ");
            scanf("%s",Modalidad_De_Venta);
        } while (!Validar_Categorias(Modalidad_De_Venta));
        
        printf("|[>>>]| Ingrese el precio de venta:         [[**]]> ");
        scanf("%f",&Precio_De_Venta);

        printf("|[>>>]| Ingrese el numero de factura:       [[**]]> ");
        scanf("%s",Num_Factura);

        //! Guardar los cambios realizados guardandolos en el puntero de nodo > 'First' < 
        first = Conexion_Nodos(first, Categoria_Producto, Nombre_Del_Producto, Fecha_De_Venta, Modalidad_De_Venta,
        Precio_De_Venta, Num_Factura);
        system("cls");
    }
}

int main(int argc, char const *argv[])
{   
    
    return 0;
}
