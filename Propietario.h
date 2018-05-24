#ifndef PROPIETARIO_H_INCLUDED
#define PROPIETARIO_H_INCLUDED
typedef struct{
    int idPropietario;
    int estado;
    char NombreApellido[50];
    char direccion[50];
    char TarjetaDeCredito[20];
}ePropietario;


#endif // PROPIETARIO_H_INCLUDED

void ePropietario_init(ePropietario listado[],int limite,int valor);
int ePropietario_buscarLugarLibre(ePropietario listado[],int limite);
void ePropietario_mostrarUno(ePropietario listado);
void ePropietario_mostrarListado(ePropietario listado[],int limite);
int BuscarID(ePropietario listado[], int tam, int numero);
int ePropietario_siguienteId(ePropietario listado[],int limite);
void Aux_ALTA(ePropietario listado[],int limite);
void ModificarAux(ePropietario listado[],int limite);
void BajaAux(ePropietario listado[], int limite);
void Hardcodeo(ePropietario listado[]);
