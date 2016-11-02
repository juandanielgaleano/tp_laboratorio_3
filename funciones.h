#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[120];
    int estado;
}EMovie;
void inicialiarArray(EMovie[],int);
int buscarLugar(EMovie[],int);
void mostrarPelicula(EMovie[],int);
void altaPelicula(EMovie[],int,int);
int borraPelicula(EMovie[],int,char[]);
void modificarPelicula(EMovie[],int);
void generarPagina(EMovie[],int);



#endif // FUNCIONES_H_INCLUDED
