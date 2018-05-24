#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "Automovil.h"
#include "EgresoAutomovil.h"
#include "Propietario.h"

#define ALPHA_ROMEO 11
#define FERRARI 22
#define AUDI 33
#define OTROS 44

void Ordenamiento(ePropietario listado[],eAutomovil lista[], int limiteAuto, int limitePro)
{
    int i,j;
    char aux[20];
    int auxInt;

    for(i=0;i<limiteAuto;i++)
    {
        for(j=i+1;j<limiteAuto;j++)
        {
            if(strcmp(lista[i].patente,lista[j].patente)>0)
            {
                strcpy(aux,lista[i].patente);
                strcpy(lista[i].patente,lista[j].patente);
                strcpy(lista[j].patente,aux);

                auxInt=lista[i].marca;
                lista[i].marca=lista[j].marca;
                lista[j].marca=auxInt;
            }
        }
    }

    for(i=0;i<limitePro;i++)
    {
        for(j=i+1;j<limitePro;j++)
        {
            if(strcmp(listado[i].NombreApellido,listado[j].NombreApellido)>0)
            {
                strcpy(aux,listado[i].NombreApellido);
                strcpy(listado[i].NombreApellido,listado[j].NombreApellido);
                strcpy(listado[j].NombreApellido,aux);
            }
        }
    }
}

void ListadoDeAutosEstacionadosOrdenados(ePropietario listado[], eAutomovil lista[],int limitePro, int limiteAuto)
{
    clean();
    int i,j;
    printf("\n\nMARCA  PATENTE   PROPIETARIO\n\n");
    for(i=0;i<limiteAuto;i++)
    {
        if(lista[i].estado!=-1)
        {
            printf("\n%d    %s",lista[i].marca,lista[i].patente);
            for(j=0;j<limitePro;j++)
            {
                if(listado[j].estado!=-1)
                {
                    if(lista[i].idPropietario==listado[j].idPropietario)
                    {
                        printf("\t   %s \n",listado[j].NombreApellido);
                        break;
                    }

                }
            }
        }

    }
    //Ordenamiento(listado,lista,limiteAuto,limitePro);
}

void MostrarPropietariosAudi(ePropietario listado[],eAutomovil lista[],int limitePro, int limiteAuto)
{
    int i,j;
    clean();
    printf("MARCA PROPIETARIO\n\n");
    for(i=0;i<limiteAuto;i++)
    {
        if(lista[i].estado!=-1)
        {
            if(lista[i].marca==AUDI)
            {
                printf(" %d ",lista[i].marca);
                {
                    for(j=0;j<limiteAuto;j++)
                    {
                        if(lista[i].idPropietario==listado[j].idPropietario)
                        {
                            if(listado[j].estado!=-1)
                            {
                                printf("     %s \n\n",listado[j].NombreApellido);
                            }

                        }

                    }
                }

            }
        }
    }


}

void MostrarAutosPorPropietario(ePropietario listado[], eAutomovil lista[], int limitePro, int limiteAuto)
{
    clean();
    int j;
    int usuario;
    int indice;
    ePropietario_mostrarListado(listado,limitePro);

    printf("\nIngrese ID de Propietario a ver informacion: ");
    scanf("%d",&usuario);

    indice=BuscarID(listado,limitePro,usuario);
    clean();

    if(listado[indice].estado!=1)
    {
        printf("\n\nID no encontrado.\n");
    }
    else
    {
        printf("\n\nPROPIETARIO  PATENTE  MARCA");
        printf("\n\n  %s ",listado[indice].NombreApellido);

        for(j=0;j<limiteAuto;j++)
        {
            if(listado[indice].idPropietario==lista[j].idPropietario)
            {
                if(lista[j].estado!=-1)
                {
                    printf("\t     %s   %d\n",lista[j].patente, lista[j].marca);

                }
            }
        }
    }
}

void EgresoAutomovil(eAutomovil lista[],ePropietario listado[] , eEgresoAutomovil egresos[], int limiteAutos, int limitePRO)
{
    clean();
    int i,j,k;

    PrecioPorEstadia(egresos,limiteAutos);
    TablaDeValores();
    printf("\n");
    printf("\n\t\t\t\tTicket De Estadia\n");
    printf("\nPropietario  Patente  Marca  Importe\n");
    for(i=0;i<limitePRO;i++)
    {
        if(listado[i].estado!=-1)
        {
            printf("\n %s ",listado[i].NombreApellido);

                for(j=0;j<limiteAutos;j++)
                {
                    if(lista[j].estado!=-1)
                    {
                        if(listado[i].idPropietario==lista[j].idPropietario)
                        {
                                printf("\t     %s    %d",lista[j].patente, lista[j].marca);

                                for(k=0;k<limiteAutos;k++)
                                    {
                                    if(lista[j].marca==egresos[k].marca)
                                      {
                                            printf("    $%.2f \n",egresos[k].importe);
                                            break;
                                      }
                                }
                        }
                    }
                }
        }
    }
}


void PrecioPorEstadia(eEgresoAutomovil egresos[],int limite)
{
    int resultado;
    int i;
    int valor=devolverHorasEstadia();

    for(i=0;i<limite;i++)
    {
        if(egresos[i].marca==11)
        {
            resultado=valor*150;
            egresos[i].importe=resultado;

        }
        else if(egresos[i].marca==22)
        {
            resultado=valor*175;
            egresos[i].importe=resultado;
        }
        else if(egresos[i].marca==33)
        {
            resultado=valor*200;
            egresos[i].importe=resultado;

        }
        else if(egresos[i].marca==44)
        {
            resultado=valor*250;
            egresos[i].importe=resultado;
        }
    }

}

int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas;

}


void Egreso_Hardcodeo(eEgresoAutomovil egresos[])
{
    int i;

    int marca[]= {ALPHA_ROMEO,ALPHA_ROMEO,FERRARI,AUDI,FERRARI,FERRARI,AUDI,OTROS,ALPHA_ROMEO,ALPHA_ROMEO};
    float importe[]= {100,200,100,300,100,100,200,200,100,100};

    for(i=0;i<10;i++)
    {

        egresos[i].marca=marca[i];
        egresos[i].importe=importe[i];
    }
}

void TablaDeValores(void){
    printf("\nMarca\t\t\tPrecio Por Hora\n");
    printf("-------------------------------------------\n");
    printf("ALPHA_ROMEO\t\t     $150\n");
    printf("FERRARI\t\t\t     $175\n");
    printf("AUDI\t\t\t     $200\n");
    printf("OTROS\t\t\t     $250\n");
}

void RecaudacionTotal(eEgresoAutomovil egresos[],int limiteAutos)
{
    int i;
    float acum=0;
    PrecioPorEstadia(egresos,limiteAutos);
    for(i=0;i<limiteAutos;i++)
    {
        acum+=egresos[i].importe;
    }
    printf("\nRecaudacion total: $%.2f",acum);
}

void RecaudacionTotalPorMarca(eEgresoAutomovil egresos[],int limiteAutos)
{
    clean();
    int i;
    float acumAR=0;
    float acumFE=0;
    float acumAU=0;
    float acumOT=0;
    PrecioPorEstadia(egresos,limiteAutos);

    for(i=0;i<limiteAutos;i++)
    {
        if(egresos[i].marca==ALPHA_ROMEO)
        {
            acumAR+=egresos[i].importe;
        }
        else if(egresos[i].marca==FERRARI)
        {
            acumFE+=egresos[i].importe;
        }
        else if(egresos[i].marca==AUDI)
        {
            acumAU+=egresos[i].importe;
        }
        else if(egresos[i].marca==OTROS)
        {
            acumOT+=egresos[i].importe;
        }

    }
    printf("\nRecaudacion total ALPHA_ROMEO: $%.2f",acumAR);
    printf("\n\nRecaudacion total FERRARI: $%.2f",acumFE);
    printf("\n\nRecaudacion total AUDI: $%.2f",acumAU);
    printf("\n\nRecaudacion total OTROS: $%.2f\n",acumOT);
}
//
