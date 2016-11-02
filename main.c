#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define tam 3


int main()
{
    char seguir='s';
    int opcion=0;
    int indiceLibre;
    char pelicula[50];
    int coincidencia;
    EMovie movie[tam];
    inicialiarArray(movie,tam);



    while(seguir=='s')
    {
        system("cls");
        printf("\n              1- Agregar pelicula\n");
        printf("                2- Borrar pelicula\n");
        printf("                3- Modificar pelicula\n");
        printf("                4- Generar pagina web\n");

        printf("                5- Salir\n");
        fflush(stdin);

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                indiceLibre=buscarLugar(movie,tam);
                if(indiceLibre==-1)
                {
                    printf("\n No hay mas lugar para el ingreso\n");
                }
                else
                {
                    altaPelicula(movie,tam,indiceLibre);
                }
                break;
            case 2:
                system("cls");
                mostrarPelicula(movie,tam);
                printf("\nIngrese el nombre de la pelicula que desa borrar\n");
                fflush(stdin);
                gets(pelicula);
                coincidencia=borraPelicula(movie,tam,pelicula);
                if(coincidencia==-1)
                {
                    printf("\nNo se encontro la pelicula a borrar\n");
                }
                else
                {
                    printf("\nPelicula borrada con exito\n");
                }
                system("pause");
                break;
            case 3:
                modificarPelicula(movie,tam);
               break;
            case 4:
                generarPagina(movie,tam);
                printf("\nPagina generada con exito\n");
                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                system("cls");
                printf("\nOpcion ivalida\n");
                system("pause");
                break;
        }
    }

    return 0;
}
