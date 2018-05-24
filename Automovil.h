#include "Propietario.h"
#ifndef AUTOMOVIL_H_INCLUDED
#define AUTOMOVIL_H_INCLUDED
typedef struct{
    char patente[20];
    int marca;
    int id;
    int idPropietario;
    int estado;
}eAutomovil;
#endif // AUTOMOVIL_H_INCLUDED

void eAutomovil_init(eAutomovil lista[],int limite,int valor);
int eAutomovil_buscarLugarLibre(eAutomovil lista[],int limite);
int eAutomovil_siguienteId(eAutomovil lista[],int limite);
void eAutomovil_mostrarUno(eAutomovil lista);
void eAutomovil_mostrarListado(eAutomovil lista[],ePropietario listado[],int limite, int limiteAutomovil);
void eAutomovil_HardCodeo(eAutomovil lista[]);
void Aux_ALTAAUTO(eAutomovil lista[],int limiteAutomovil);
void mensaje(void);
void clean(void);

