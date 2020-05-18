#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMNOT 10
#define CANTHARDCODE 8

#include "datosNotbooks.h"

//3. Dada la estructura Notebook(id, procesador, marca, precio)
//generar una función que permita ordenar un array de dicha estructura por marca.
//Ante igualdad de marca deberá ordenarse por precio. Hardcodear datos
//y mostrarlos desde el main. *

typedef struct
{
    int id;
    char procesador[30];
    char marca[20];
    float precio;
    int isEmpty;

} eNotebook;

int menu();
void inicializarNotebooks(eNotebook vec[], int tam);
void ordenarNotebooksPorMarca (eNotebook vec[], int tam);
void ordenarNotebooksPorMarcaYPrecio(eNotebook vec[], int tam);
void mostrarNotebooks(eNotebook vec[], int tam);
void mostrarNotebook(eNotebook x);
void hardcodearNotebooks(eNotebook vec[], int cant);

int main()
{
    char seguir = 's';
    char confirma = 's';

    eNotebook notebooksVec[TAMNOT];

    inicializarNotebooks(notebooksVec, TAMNOT);

    hardcodearNotebooks(notebooksVec, CANTHARDCODE);

    do
    {
        switch( menu() )
        {
        case 1:
            mostrarNotebooks(notebooksVec,TAMNOT);
            break;
        case 2:
            ordenarNotebooksPorMarca(notebooksVec,TAMNOT);
            break;
        case 3:
            ordenarNotebooksPorMarcaYPrecio(notebooksVec,TAMNOT);
            break;
        case 4:
            printf("Desea continuar? S/N\n");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        }
        system("pause");
    }
    while (seguir == 's');
}

int menu()
{
    int opcion;

    system("cls");
    printf("******* PP Prog Punto3 *******\n\n");
    printf("1. Mostrar Listado Original\n");
    printf("2. Ordenar por Marca\n");
    printf("3. Ordenar por Marca y precio\n");
    printf("Ingrese Opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void inicializarNotebooks(eNotebook vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

void mostrarNotebook(eNotebook x)
{
    printf("%d\t  %25s\t  %25s\t %6.2f\t\n",x.id,x.marca,x.procesador,x.precio);
}

void mostrarNotebooks(eNotebook vec[], int tam)
{
    printf("\n  ID                          Marca                      Procesador       Precio\n");

    int flag = 0;

    for(int i = 0; i < tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarNotebook(vec[i]);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("\n\n\t\t\tNo hay Notebooks Cargados\n\n");
    }
}

void ordenarNotebooksPorMarca(eNotebook vec[], int tam)
{
    eNotebook auxNotebook;

    for(int i = 0; i < tam - 1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if(strcmp(vec[i].marca, vec[j].marca) > 0)
            {
                auxNotebook = vec[i];
                vec[i] = vec[j];
                vec[j] = auxNotebook;
            }
        }
    }
    mostrarNotebooks(vec,tam);
}

void ordenarNotebooksPorMarcaYPrecio(eNotebook vec[], int tam)
{
    eNotebook auxNotebook;

    for(int i = 0; i < tam - 1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if(vec[i].marca > vec[j].marca)
			{
			auxNotebook = vec[i];
			vec[i] = vec[j];
			vec[j] = auxNotebook;
			}
			else if(vec[i].marca == vec[j].marca && vec[i].precio < vec[i].precio)
			{
			auxNotebook = vec[i];
			vec[i] = vec[j];
			vec[j] = auxNotebook;
			}
        }
    }
    mostrarNotebooks(vec,tam);
}

void hardcodearNotebooks(eNotebook vec[], int cant)
{
    for(int i = 0; i < cant; i++)
    {
        vec[i].id = ids[i];
        strcpy(vec[i].procesador, procesadores[i]);
        strcpy(vec[i].marca, marcas[i]);
        vec[i].precio = precios[i];
        vec[i].isEmpty = 0;
    }
}
