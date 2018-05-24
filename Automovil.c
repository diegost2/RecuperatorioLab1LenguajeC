#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Automovil.h"
#include "Propietario.h"
#define OCUPADO 1
#define LIBRE -1

#define ALPHA_ROMEO 11
#define FERRARI 22
#define AUDI 33
#define OTROS 44


void eAutomovil_HardCodeo(eAutomovil lista[])
{
    int id[]= {1,2,3,4,5,6,7,8,9,10};
    char patente[][20]={"AAA-AAA","CCC-CCC","DDD-DDD","BBB-BBB","ZZZ-ZZZ","III-III","HHH-HHH","EEE-EEE","FFF-FFF","GGG-GGG"};
    int marca[]={ALPHA_ROMEO,AUDI,AUDI,FERRARI,FERRARI,AUDI,AUDI,OTROS,AUDI,ALPHA_ROMEO};
    int idPropietario[]={2,1,2,1,3,3,4,1,4,3};
    int i;

    for(i=0;i<10;i++)
    {
        lista[i].id=id[i];
        lista[i].marca=marca[i];
        lista[i].idPropietario=idPropietario[i];
        lista[i].estado =1;
        strcpy(lista[i].patente,patente[i]);
    }
}


void Aux_ALTAAUTO(eAutomovil lista[],int limiteAutomovil)
{
    eAutomovil automovilAux;
    int indice;
    int id;

    id=eAutomovil_siguienteId(lista,limiteAutomovil);

        indice = eAutomovil_buscarLugarLibre(lista,limiteAutomovil);
        if(indice == -1)
        {
            printf("No hay mas espacio para ingresar.");
            getch();
        }
        else{
            clean();
            printf("\nIngrese pantente: ");
            fflush(stdin);
            gets(automovilAux.patente);

            printf("\nIngrese Marca: ");
            fflush(stdin);
            scanf("%d",&automovilAux.marca);

            printf("\nIngrese ID: ");
            fflush(stdin);
            scanf("%d",&id);


            strcpy(lista[indice].patente,automovilAux.patente);
            //lista[indice].idPropietario=automovilAux.idPropietario;
            lista[indice].idPropietario=id;
            lista[indice].marca=automovilAux.marca;
            lista[indice].estado=1;
            }
}


void eAutomovil_mostrarUno(eAutomovil lista)
{
     printf("        %s      %d      %s ",lista.marca,lista.idPropietario,lista.patente);

}

int eAutomovil_siguienteId(eAutomovil lista[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && lista != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(lista[i].estado == OCUPADO)
            {
                if(lista[i].idPropietario>retorno)
                {
                    retorno=lista[i].idPropietario;
                    break;
                }
            }
        }
    }

    return retorno+1;
}

int eAutomovil_buscarLugarLibre(eAutomovil lista[],int limite)
{
    int retorno = OCUPADO;
    int i;

        for(i=0;i<limite;i++)
        {
            if(lista[i].estado == OCUPADO)
            {
                retorno = i;
                break;
            }
        }

    return retorno;
}

void eAutomovil_init(eAutomovil lista[],int limite,int valor)
{
    int i;
        for(i=0; i<limite; i++)
        {
            lista[i].estado= valor;

        }

}


void mensaje(void)
{
    printf("\n\nPresione cualquier tecla para terminar...\n\n");
    getch();
}
void clean(void)
{
    system("cls");
}
//
