#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Propietario.h"
#include "Automovil.h"
#include "EgresoAutomovil.h"
#define CANTIDADAUTO 20
#define CANTIDADPROPI 20



int main()
{
    ePropietario propietario[CANTIDADPROPI];
    ePropietario_init(propietario,CANTIDADPROPI,-1);

    eAutomovil automovil[CANTIDADAUTO];
    eAutomovil_init(automovil,CANTIDADAUTO,-1);

    eEgresoAutomovil egresoAutomovil[CANTIDADAUTO];

    Hardcodeo(propietario);
    eAutomovil_HardCodeo(automovil);
    Egreso_Hardcodeo(egresoAutomovil);

    char respuesta='s';
    int opcion;

    while(respuesta=='s')
    {
        printf("\n1)ALTA ");
        printf("\n2)MODIFICAR");
        printf("\n3)BAJA ");
        printf("\n4)INGRESO AUTOMOVIL.");
        printf("\n5)EGRESO AUTOMOVIL. ");
        printf("\n6)RECAUDACION TOTAL. ");
        printf("\n7)RECAUDANCION POR MARCA. ");
        printf("\n8)INFORMAR AUTOS DE CADA DUENO. ");
        printf("\n9)MOSTRAR PROPIETAIOS DE AUDI. ");
        printf("\n10)LISTADO DE AUTOS ORDENADOS POR PATENTE.");
        printf("\n\nOpcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            {
                Aux_ALTA(propietario,CANTIDADPROPI);
                break;
            }
        case 2:
            {
                ModificarAux(propietario,CANTIDADPROPI);
                break;
            }
        case 3:
            {
                BajaAux(propietario,CANTIDADPROPI);
                mensaje();
                break;
            }
        case 4:
            {
                Aux_ALTAAUTO(automovil,CANTIDADAUTO);
                break;
            }
        case 5:
            {
               EgresoAutomovil(automovil,propietario,egresoAutomovil,CANTIDADAUTO,CANTIDADPROPI);
               mensaje();
               break;
            }
        case 6:
            {
                RecaudacionTotal(egresoAutomovil,CANTIDADAUTO);
                mensaje();
                break;
            }
        case 7:
            {

                RecaudacionTotalPorMarca(egresoAutomovil,CANTIDADAUTO);
                mensaje();
                break;
            }
        case 8:
            {
                MostrarAutosPorPropietario(propietario,automovil,CANTIDADPROPI,CANTIDADAUTO);
                mensaje();
                break;
            }
        case 9:
            {
                MostrarPropietariosAudi(propietario,automovil,CANTIDADPROPI,CANTIDADAUTO);
                mensaje();
                break;
            }
        case 10:
            {

                ListadoDeAutosEstacionadosOrdenados(propietario,automovil,CANTIDADPROPI,CANTIDADAUTO);

                mensaje();
                break;
            }
        default:
            {
                clean();
                printf("\nOpcion Incorrecta.");
                mensaje();
                break;
            }

        }
        clean();
    }
    return 0;
}
