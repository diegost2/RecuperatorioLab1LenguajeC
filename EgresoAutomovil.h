#include "Propietario.h"
#include "Automovil.h"

#ifndef EGRESOAUTOMOVIL_H_INCLUDED
#define EGRESOAUTOMOVIL_H_INCLUDED

typedef struct{
    int marca;
    float importe;
}eEgresoAutomovil;

#endif // EGRESOAUTOMOVIL_H_INCLUDED

void Egreso_Hardcodeo(eEgresoAutomovil egresos[]);
void TablaDeValores(void);
void EgresoAutomovil(eAutomovil lista[],ePropietario listado[] , eEgresoAutomovil egresos[], int limiteAutos, int limitePRO);
void PrecioPorEstadia(eEgresoAutomovil egresos[],int limite);
int devolverHorasEstadia();
void RecaudacionTotal(eEgresoAutomovil egresos[],int limiteAutos);
void RecaudacionTotalPorMarca(eEgresoAutomovil egresos[],int limiteAutos);
void MostrarAutosPorPropietario(ePropietario listado[], eAutomovil lista[], int limitePro, int limiteAuto);
void MostrarPropietariosAudi(ePropietario listado[],eAutomovil lista[],int limitePro, int limiteAuto);
void ListadoDeAutosEstacionadosOrdenados(ePropietario listado[], eAutomovil lista[],int limitePro, int limiteAuto);
void Ordenamiento(ePropietario listado[],eAutomovil lista[], int limiteAuto, int limitePro);
