#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Propietario.h"
#include "EgresoAutomovil.h"
#define OCUPADO 1
#define LIBRE -1



void Hardcodeo(ePropietario listado[])
{
    int i;

    int id[]={1,2,3,4};
    char nombre[][20]={"Juan","Luis","Maria","Jose"};
    char tarjeta[][20]= {"111-111","222-222","333-333","444-444"};
    char direccion[][20]= {"mitre","urquiza","belgrano","alsina"};

    for(i=0;i<4;i++){

        strcpy(listado[i].NombreApellido,nombre[i]);
        strcpy(listado[i].TarjetaDeCredito,tarjeta[i]);
        strcpy(listado[i].direccion,direccion[i]);
        listado[i].idPropietario=id[i];
        listado[i].estado=1;
    }
}

void BajaAux(ePropietario listado[], int limite)
{
    clean();
    int valor;
    int idEncontrado;

    int opcion;
    ePropietario_mostrarListado(listado,limite);

    printf("\nIngrese ID de Propietario a dar de Baja: ");
    scanf("%d",&valor);
    idEncontrado=BuscarID(listado,limite,valor);

            if(idEncontrado==-1)
                {
                    printf("Propietario no encontrado.");
                    mensaje();
                }
            else if(idEncontrado!=-1)
                {
                clean();
                printf("\nEsta seguro de querer borrar al Propietario: %s ", listado[idEncontrado].NombreApellido);
                printf("\n\n1)SI.");
                printf("\n\n2)NO.");
                printf("\n\nOpcion: ");
                scanf("%d",&opcion);
                switch(opcion){
                    case 1:
                        {
                            listado[idEncontrado].estado=-1;
                            clean();
                            printf("Propietario Borrado con exito!");
                            break;
                        }
                    case 2:
                        {
                            clean();
                            printf("\nBaja Cancelada.");
                            mensaje();
                            break;

                        }
                    default:
                        {
                            clean();
                            printf("Opcion incorrecta.");
                            mensaje();
                            break;
                        }
                    }

                }
}


void ModificarAux(ePropietario listado[],int limite){
    int valor;
    int idEncontrado;

    int opcion;
    clean();
    ePropietario AuxModificar;
    ePropietario_mostrarListado(listado,limite);

    printf("\n\nIngrese ID de usuario a Modificar TDC: ");
    scanf("%d",&valor);
    idEncontrado=BuscarID(listado,limite,valor);
    if(idEncontrado==-1)
                {
                    printf("Usuario no encontrado.");
                    mensaje();

                }
            else
                {
                clean();
                printf("\nEsta seguro de querer modificar la tarjeta de credito al Propietario: %s ", listado[idEncontrado].NombreApellido);
                printf("\n\n1)SI.");
                printf("\n\n2)NO.");
                printf("\n\nOpcion: ");
                scanf("%d",&opcion);
                switch(opcion)
                {
                    case 1:
                        {
                            clean();

                            printf("\nIngrese Nueva Tarjeta de Credito: ");
                            fflush(stdin);
                            gets(AuxModificar.TarjetaDeCredito);

                            strcpy(listado[idEncontrado].TarjetaDeCredito,AuxModificar.TarjetaDeCredito);

                            clean();
                            printf("\nModificacion exitosa!");
                            mensaje();

                            break;
                        }
                    case 2:
                        {
                            printf("Modificacion Cancelada.");
                            mensaje();
                            break;

                        }
                    default:
                        {
                            printf("Opcion Incorrecta.");
                            mensaje();
                            break;
                        }
                    }
                }

}


void Aux_ALTA(ePropietario listado[],int limite)
{
    clean();
    char nombreApellido[50];
    int idPropietario;
    char direccion[50];
    char tarjetaCredito[20];
    int indice;

    idPropietario=ePropietario_siguienteId(listado,limite);
    indice=ePropietario_buscarLugarLibre(listado,limite);
        if(indice == -1)
        {
            printf("No hay mas espacio para ingresar.");
            mensaje();
        }
        else{

            printf("\nIngrese su nombre: ");
            fflush(stdin);
            gets(nombreApellido);
            printf("\nIngrese su ID: ");
            fflush(stdin);
            scanf("%d",&idPropietario);
            printf("\nIngrese una Direccion: ");
            fflush(stdin);
            gets(direccion);
            printf("\nIngrese Tarjeta de Credito: ");
            fflush(stdin);
            gets(tarjetaCredito);

            clean();

            strcpy(listado[indice].NombreApellido,nombreApellido);
            strcpy(listado[indice].direccion,direccion);
            strcpy(listado[indice].TarjetaDeCredito,tarjetaCredito);
            listado[indice].idPropietario=idPropietario;
            listado[indice].estado = 1;
            }
}

int ePropietario_siguienteId(ePropietario listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].idPropietario>retorno)
                    {
                         retorno=listado[i].idPropietario;

                    }
            }
        }
    }

    return retorno+1;
}


int BuscarID(ePropietario listado[], int tam, int numero)
{
    int i;
    int retorno=-1;
    for(i=0;i<tam;i++)
    {
        if(listado[i].idPropietario==numero)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

void ePropietario_mostrarListado(ePropietario listado[],int limite)
{

    int i;
    printf(" Nombres  ID  Direccion  Tarjeta de Credito \n");

    for(i=0; i<limite; i++)
        {
        if(listado[i].estado!=-1)
            {
                ePropietario_mostrarUno(listado[i]);
            }
        }
}

void ePropietario_mostrarUno(ePropietario listado)
{
     printf("\n%s      %d      %s      %s\n",listado.NombreApellido,listado.idPropietario,listado.direccion,listado.TarjetaDeCredito);

}

void ePropietario_init(ePropietario listado[],int limite,int valor)
{
    int i;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= valor;
            listado[i].idPropietario=0;
        }

}

int ePropietario_buscarLugarLibre(ePropietario listado[],int limite)
{
    int retorno = -1;
    int i;

        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == -1)
            {
                retorno = i;
                break;
            }
        }

    return retorno;
}
//
