#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct Node
{
    char Categoria_Producto[101];
    char Nombre_Del_Producto[51];
    char Fecha_De_Venta[41];
    char Modalidad_Venta[2];
    float Precio_De_Venta;
    char Num_Factura[11];
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
    printf("\n\t\t|(>>>>)| Opcion 9: >| Salir. |<                               |(<<<<)|");
    printf("\n\t\t|--------------------------------------------------------------------|");
    printf("\n");
    printf("\n\t\t|[*]>>>[*]| Digite la opcion que desea seleccionar.        |[*][*]>");
}

//? Funcion para validar : >| Modalidad_Venta| <, Online = 'O', Presencial = 'P'.
int Validar_Modalidad(char *Modalidad_Venta)
{
    char Online[2] = {'O'};
    char Presencial[2] = {'P'};

    //! Con >| strcmp |< comparamos las cadenas, si nos devuelve 0 es porque las cadenas son iguales por lo tanto retorna 1.
    if (strcmp(Modalidad_Venta, Online) == 0) 
    {
        return 1;
    }else if (strcmp(Modalidad_Venta, Presencial) == 0)
    {
        return 1;
    }
    

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

int Validar_Categorias(int Digitar_Categoria)
{
    if(Digitar_Categoria >=1 && Digitar_Categoria <=7)
    {
        return 1;
    }

    return 0;
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
        if (strcmp(temp->Modalidad_Venta,Tipo_Servicio) == 0)
        {
            printf("\n>----------------------------------------<");
            printf("\n");
            printf("\n|>>>| Categoria Del Producto: > %s < |<<<|",temp->Categoria_Producto);
            printf("\n");
            printf("\n|>>>| Nombre Del Producto:    > %s < |<<<|",temp->Nombre_Del_Producto);
            printf("\n|>>>| Fecha De Venta:         > %s < |<<<|",temp->Fecha_De_Venta);
            printf("\n|>>>| Modalidad De Venta:     > %s < |<<<|",temp->Modalidad_Venta);
            printf("\n|>>>| Precio de la venta:     > %.1f < |<<<|",temp->Precio_De_Venta);
            printf("\n|>>>| Numero de Facturaq:     > %s < |<<<|",temp->Num_Factura);
            printf("\n");
            printf("\n>----------------------------------------<");
            printf("\n");

           
            
        }
         //! Para pasar a los nodos siguientes
        temp = temp->next;
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
    FILE *File_Open = fopen("../archivos del programa/CategoriasPcs/Online_Register.txt","a");
    //! Si el puntero fp es nullo va a imprimir un error: no pudo abrir el archivo.
    if (File_Open == NULL)
    {
        printf("\n|>>>| ERROR AL ABRIR EL ARCHIVO |<<<|");
        exit(1);
    }
    struct Node* temp = head; 
    //! Modalidad de venta
    char Online[2] = {'O'};
    if (strcmp(head->Modalidad_Venta,Online) == 0)
    {
        fprintf(File_Open,"|[****]| NUEVO REGISTRO: : |[]>");
    }
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
            fprintf(File_Open,"\n|>>>| Precio de la venta:     > %.1f < |<<<|",temp->Precio_De_Venta);
            fprintf(File_Open,"\n|>>>| Numero de Factura:      > %s < |<<<|",temp->Num_Factura);
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
    FILE *File_Open = fopen("../archivos del programa/CategoriasPcs/Presencial_Register.txt","a");
    if (File_Open == NULL)
    {
        printf("\n|>>>| ERROR AL ABRIR EL ARCHIVO |<<<|");
        exit(2);
    }
    struct Node* temp = head; 
    //! Modalidad de venta.
    char Presencial[2] = {'P'};
    if(strcmp(head->Modalidad_Venta,Presencial) == 0){
        fprintf(File_Open,"|[****]| NUEVO REGISTRO: : |[]>");
    }
    
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
            fprintf(File_Open,"\n|>>>| Modalidad De Venta:     > %s <  |<<<|",temp->Modalidad_Venta);
            fprintf(File_Open,"\n|>>>| Precio de la venta:     > %.1f < |<<<|",temp->Precio_De_Venta);
            fprintf(File_Open,"\n|>>>| Numero de Factura:      > %s < |<<<|",temp->Num_Factura);
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
    FILE *File_Open = fopen("../archivos del programa/CategoriasPcs/Total_Ventas_Registro.txt","a");
    if (File_Open == NULL)
    {
        printf("\n|>>>| ERROR AL ABRIR EL ARCHIVO |<<<|");
        exit(3);
    }
    float Suma_Pagos;
    Suma_Pagos = Total_Ventas_Realizadas(first);
    struct Node* temp = head;
    if (head->Modalidad_Venta != NULL)
    {
        fprintf(File_Open,"|[****]| REGISTRO TOTAL DE VENTAS: |[]> %.1f <[]| |[****]|",Suma_Pagos);
    }
    
    while (temp != NULL)
    {
        fprintf(File_Open,"\n>----------------------------------------<");
        fprintf(File_Open,"\n");
        fprintf(File_Open,"\n|>>>| Categoria Del Producto: > %s < |<<<|",temp->Categoria_Producto);
        fprintf(File_Open,"\n");
        fprintf(File_Open,"\n|>>>| Nombre Del Producto:    > %s < |<<<|",temp->Nombre_Del_Producto);
        fprintf(File_Open,"\n|>>>| Fecha De Venta:         > %s < |<<<|",temp->Fecha_De_Venta);
        fprintf(File_Open,"\n|>>>| Modalidad De Venta:     > %s < |<<<|",temp->Modalidad_Venta);
        fprintf(File_Open,"\n|>>>| Precio de la venta:     > %.1f < |<<<|",temp->Precio_De_Venta);
        fprintf(File_Open,"\n|>>>| Numero de Factura:      > %s < |<<<|",temp->Num_Factura);
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
        return 0;
    }

    printf("\n>----------------------------------------<");
    printf("\n");
    printf("\n|>>>| Categoria Del Producto: > %s < |<<<|",temp->Categoria_Producto);
    printf("\n");
    printf("\n|>>>| Nombre Del Producto:    > %s < |<<<|",temp->Nombre_Del_Producto);
    printf("\n|>>>| Fecha De Venta:         > %s < |<<<|",temp->Fecha_De_Venta);
    printf("\n|>>>| Modalidad De Venta:     > %s < |<<<|",temp->Modalidad_Venta);
    printf("\n|>>>| Precio de la venta:     > %.1f < |<<<|",temp->Precio_De_Venta);
    printf("\n|>>>| Numero de Facturaq:     > %s < |<<<|",temp->Num_Factura);
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
    int Num_Nodos, Digitar_Categoria;

    printf("\n[[**]]>DIgite cuantas ventas desea registrar:       <[[**]]");
    scanf("%d",&Num_Nodos);

    for (int i = 0; i < Num_Nodos; i++)
    {
        do{    
            printf("\n|[>>>]| Digite la categoria del producto  [[**]]>");
            printf("\n|[>>>]| Categoria 1: Placa Base");
            printf("\n|[>>>]| Categoria 2: Ram");
            printf("\n|[>>>]| Categoria 3: Fuente De Poder");
            printf("\n|[>>>]| Categoria 4: Procesador");
            printf("\n|[>>>]| Categoria 5: Ssd");
            printf("\n|[>>>]| Categoria 6: Tarjeta grafica");
            printf("\n|[>>>]| Categoria 7: Disco Duro \n[[**]]>");
            scanf("%d",&Digitar_Categoria);
        }while(!Validar_Categorias(Digitar_Categoria));
        
        switch(Digitar_Categoria){
            case 1:
                strcpy(Categoria_Producto, "Placa Base");
                break;
            case 2:
                strcpy(Categoria_Producto, "Ram");
                break;
            case 3:
                strcpy(Categoria_Producto, "Fuente De Poder");
                break;
            case 4:
                strcpy(Categoria_Producto, "Procesador");
                break;
            case 5:
                strcpy(Categoria_Producto, "Ssd");
                break;
            case 6:
                strcpy(Categoria_Producto, "Tarjeta Grafica");
                break;
            case 7:
                strcpy(Categoria_Producto, "Disco Duro");
                break;
        }

        printf("|[>>>]|Ingrese el nombre del producto\n[[**]]>");
        getchar();
        gets(Nombre_Del_Producto);
        printf("\n");
        printf("|[>>>]|Ingrese la fecha de venta:");
        printf("\n");
        printf("|[>>>]|ANO\t[[**]] ");
        scanf("%s",Ano);
        printf("|[>>>]|MES\t[[**]]>");
        scanf("%s",Mes);
        printf("|[>>>]|DIA\t[[**]]>");
        scanf("%s",Dia);
        concatenar(Fecha_De_Venta, Ano, Mes, Dia);
        printf("\n");
        do
        {
            printf("|[>>>]| Ingrese modalidad de venta\t[[**]]>");
            scanf("%s",Modalidad_De_Venta);
        } while (!Validar_Modalidad(Modalidad_De_Venta));
        printf("\n");
        printf("|[>>>]| Ingrese el precio de venta\t[[**]]>");
        scanf("%f",&Precio_De_Venta);
        printf("\n");
        printf("|[>>>]| Ingrese el numero de factura\t[[**]]>");
        scanf("%s",Num_Factura);

        //! Guardar los cambios realizados guardandolos en el puntero de nodo > 'First' < 
        first = Conexion_Nodos(first, Categoria_Producto, Nombre_Del_Producto, Fecha_De_Venta, Modalidad_De_Venta,
        Precio_De_Venta, Num_Factura);
        system("cls");
    }
}

//? Procedimiento para la recomendación de PCs 
void Menu_Presupuestos(){
	int opc1, opc2;
	do{
		printf("\n\t\t|-------------------------------||");
		printf("\n\t\t|<<>>| 1. PC Gaming        |<<>>||");
		printf("\n\t\t|<<>>| 2. PC Multimedia    |<<>>||");
		printf("\n\t\t|-------------------------------||");
		printf("\n\t\t[**]--Ingrese la opcion:>> ");
		scanf("%d", &opc1);
	}while(opc1 != 1 && opc1 != 2);
	do{
		printf("\n\t\t|--------------------------|<<>>||");
		printf("\n\t\t|<<>>| 1. Gama Economica   |<<>>||");
		printf("\n\t\t|<<>>| 2. Gama Media       |<<>>||");
		printf("\n\t\t|<<>>| 3. Gama Alta        |<<>>||");
		printf("\n\t\t|--------------------------|<<>>||");
		printf("\n\t\t[**]-Ingrese la opcion:>> ");
		scanf("%d", &opc2);
	}while(opc2 < 1 || opc2 > 3);
	system("cls");
	switch(opc2){
		case 1:
			if (opc1 == 1){
				Imprimir_Registros("../archivos del programa/CategoriasPcs/gaming-economico.txt");
			}else if(opc1 == 2){
				Imprimir_Registros("../archivos del programa/CategoriasPcs/multimedia-economico.txt");
			}
			break;
		
		case 2:
			if (opc1 == 1){
				Imprimir_Registros("../archivos del programa/CategoriasPcs/gaming-equilibrado.txt");
			}else if(opc1 == 2){
				Imprimir_Registros("../archivos del programa/CategoriasPcs/multimedia-equilibrado.txt");
			}
			break;
		
		case 3:
			if (opc1 == 1){
				Imprimir_Registros("../archivos del programa/CategoriasPcs/gaming-loMejor.txt");
			}else if(opc1 == 2){
				Imprimir_Registros("../archivos del programa/CategoriasPcs/multimedia-loMejor.txt");
			}
			break;
	}

}

//? Funcion main.
int main(int argc, char const *argv[])
{   
    int opc;
    do
    {
        system("pause");
        system("cls");
        Menu();
        scanf("%d",&opc);
        system("cls");
        switch (opc)
        {
        case 1:
            system("cls");  
            Register_Informacion_Ventas();
            break;
        case 2: 
            system("cls");
            Filtrar_Modalidad(first);
            break;
        case 3:
            system("cls");
            Buscar_Num_Factura(first);
            break;
        case 4: 
            system("cls");
            Menu_Presupuestos();
            break;
        case 5:
            system("cls");
            Imprimir_Ventas_Registradas(first);
            break;
        case 6:
            system("cls");
            Imprimir_Registros("../archivos del programa/CategoriasPcs/Total_Ventas_Registro.txt");
            break;
        case 7:
            system("cls");
            Imprimir_Registros("../archivos del programa/CategoriasPcs/Online_Register.txt");
            break;
        case 8:
            system("cls");
            Imprimir_Registros("../archivos del programa/CategoriasPcs/Presencial_Register.txt");
            break;
        case 9:
            system("cls");
            printf("\t\n[|*|*|*|]          GRACIAS POR ELEGIRNOS         [|*|*|*|]\n");
            break;
        default:
            system("cls");
            printf("\n\t[|*|*|*|]      OPCION INVALIDA!     [|*|*|*|]");
            break;
        }
    } while (opc != 9 );
    
    Almacenar_Registros_Online(first);
    Almacenar_Registros_Presencial(first);
    Almacenar_Total_Ventas(first);

    return 0;
}
