#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

/** \brief Inicializa el parametro puntaje en -1 en el array de estructuras EMovie
 *
 * \param Array de estructura de tipo EMovie.
 * \param Largo del array de estructura
 * \return No devuelve nada
 *
 */
 void inicialiarArray(EMovie movie[], int lenght)
 {
     int i;
     for(i=0;i<lenght;i++)
     {
         movie[i].estado=0;
     }
 }
 /** \brief Busca un indice libre en el array de estructura del tipo EMovie para luego devolverlo.
  *
  * \param Recibe un array de estructuras del tipo EMovie.
  * \param Recibe el largo de array.
  * \return Devuelve el indice del array donde no se hallan cargado datos, de lo contrario -1.
  *
  */
int buscarLugar(EMovie movie[], int lenght)
{
    int indice=-1;
    int i;
    for(i=0;i<lenght;i++)
    {
        if(movie[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
/** \brief La funcion solicita datos para ingresar en el array de estructura de tipo EMovie
 *
 * \param Array de estructuras de tipoo EMovie
 * \param Tamaño del array de estructuras
 * \param Posicion en el array de persona.
 * \return No devuelve nada
 *
 */
void altaPelicula(EMovie movie[],int lenght,int indice)
{
    char bufferTitulo[50];
    char bufferGenero[50];
    char bufferDescripcion[100];
    char bufferLink[120];
    printf("\nIngrese nombre de pelicula\n");
    fflush(stdin);
    gets(bufferTitulo);
    while(strlen(bufferTitulo)>30)
    {
        printf("\nNombre demasiado largo. Reingrese: \n");
        fflush(stdin);
        gets(bufferTitulo);
    }
    strcpy(movie[indice].titulo,bufferTitulo);
    printf("\nIngrese genero de la pelicula\n");
    gets(bufferGenero);
    while(strlen(bufferGenero)>20)
    {
        printf("\nGenero demasiado largo. Reingrese");
        fflush(stdin);
        gets(bufferGenero);
    }
    strcpy(movie[indice].genero,bufferGenero);
    printf("\nIngrese duracion de la pelicula en minutos: \n");
    scanf("%d",&movie[indice].duracion);
    while(movie[indice].duracion<0 || movie[indice].duracion>300)
    {
        printf("\nDuracion de la pelicula no valida. Reingrese: \n");
        fflush(stdin);
        scanf("%d",&movie[indice].duracion);
    }
    printf("\nIngrese descripcion de la pelicula: \n");
    fflush(stdin);
    gets(bufferDescripcion);
    while(strlen(bufferDescripcion)>50)
    {
        printf("\nDescripcion muy larga. Reingrese: \n");
        fflush(stdin);
        gets(bufferDescripcion);
    }
    strcpy(movie[indice].descripcion,bufferDescripcion);
    printf("\nIngrese puntaje de la pelicula 1-10: \n");
    fflush(stdin);
    scanf("%d",&movie[indice].puntaje);
    while(movie[indice].puntaje<0 || movie[indice].puntaje>10)
    {
        printf("\nPuntaje fuera de rango. Reingrese: \n");
        fflush(stdin);
        scanf("%d",&movie[indice].puntaje);
    }
    printf("\nIngrese link de la imagen: \n");
    fflush(stdin);
    gets(bufferLink);
    while(strlen(bufferLink)>100)
    {
        printf("\nLink muy largo. Reingrese: \n");
        fflush(stdin);
        gets(bufferLink);
    }
    strcpy(movie[indice].descripcion,bufferDescripcion);
    movie[indice].estado=1;
    printf("\nPelicula ingresada con exito\n");
    system("pause");
}
/** \brief Muestra las peliculas cargads en el aray de estructura de tipo EMovie
 *
 * \param Array de estructura de tipo EMovie
 * \param Tamaño del array de estructura EMovie
 * \return No devuelve nada
 *
 */

void mostrarPelicula(EMovie movie[],int tam)
{
    int i=0;
    printf("\n INDICE TITULO  \n");
    for(i=0;i<tam;i++)
    {
        if(movie[i].estado>0)
        {
        printf("\n%d   %s     \n",i,movie[i].titulo);
        }

    }
}
/** \brief La funcion da una baja logica a los datos de una estructura en el array del tipo EMovie donde coincida el nombre del titulo a borrar
 *
 * \param Recibe un array de estructura de tipo EMovie
 * \param Recibe el tamaño del array
 * \param Recibe unba cadena de caracteres con el nombre de la pelicula a borrar
 * \return Devuelve 1 si la pelicula fue borrada con exito/-1 Si no se encontro concidencia.
 *
 */
int borraPelicula(EMovie movie[],int tam, char pelicula[])
{
    int retorno=-1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(strcmpi(movie[i].titulo,pelicula)==0)
        {
            movie[i].estado=-1;
            retorno=1;
            break;
        }
    }
    return retorno;
}
/** \brief Modifica los datos ingresados en el array de estrcuturas de tipo EMovie
 *
 * \param Array de estructura de tipo EMovie
 * \param Tamaño de array de estructura
 * \return No evuelve nada
 *
 */
 void modificarPelicula(EMovie movie[],int tam)
 {
     int indiceDePelicula;
     int opcion;
     char bufferTitulo[50];
     char bufferGenero[50];
     char bufferDescripcion[100];
     char bufferLink[120];
     mostrarPelicula(movie,tam);
     printf("\nElija el indice de la pelicula que desea modificar: \n");
     scanf("%d",&indiceDePelicula);
     while(indiceDePelicula<tam || indiceDePelicula >tam)
     {
         printf("\nIndice invalido reingrese: \n");
         scanf("%d",&indiceDePelicula);
     }
     printf("\nMODIFICAR\n");
     printf("\nElija opcion: \n");
     printf("1-Modificar titulo: \n");
     printf("2-Modificar genero: \n ");
     printf("3-Modificar duracion: \n");
     printf("4-Modificar descripcion: \n");
     printf("5-Modificar puntaje: \n");
     printf("6-Modificar link de imagen: \n");
     fflush(stdin);
     scanf("%d",&opcion);
        switch(opcion)
         {
        case 1:
             printf("\nIngrese nombre de pelicula\n");
             fflush(stdin);
             gets(bufferTitulo);
             while(strlen(bufferTitulo)>30)
                {
                    printf("\nNombre demasiado largo. Reingrese: \n");
                    fflush(stdin);
                    gets(bufferTitulo);
                }
             strcpy(movie[indiceDePelicula].titulo,bufferTitulo);
            break;
        case 2:
             printf("\nIngrese genero de la pelicula\n");
    gets(bufferGenero);
    while(strlen(bufferGenero)>20)
    {
        printf("\nGenero demasiado largo. Reingrese");
        fflush(stdin);
        gets(bufferGenero);
    }
    strcpy(movie[indiceDePelicula].genero,bufferGenero);
            break;
        case 3:
            printf("\nIngrese duracion de la pelicula en minutos: \n");
            scanf("%d",&movie[indiceDePelicula].duracion);
            while(movie[indiceDePelicula].duracion<0 || movie[indiceDePelicula].duracion>300)
                {
                    printf("\nDuracion de la pelicula no valida. Reingrese: \n");
                    fflush(stdin);
                    scanf("%d",&movie[indiceDePelicula].duracion);
                }
            break;
        case 4:
            printf("\nIngrese descripcion de la pelicula: \n");
            fflush(stdin);
            gets(bufferDescripcion);
                while(strlen(bufferDescripcion)>50)
                    {
                        printf("\nDescripcion muy larga. Reingrese: \n");
                        fflush(stdin);
                        gets(bufferDescripcion);
                    }
            strcpy(movie[indiceDePelicula].descripcion,bufferDescripcion);
            break;
        case 5:
             printf("\nIngrese puntaje de la pelicula 1-10: \n");
             fflush(stdin);
             scanf("%d",&movie[indiceDePelicula].puntaje);
             while(movie[indiceDePelicula].puntaje<0 || movie[indiceDePelicula].puntaje>10)
                {
                    printf("\nPuntaje fuera de rango. Reingrese: \n");
                    fflush(stdin);
                    scanf("%d",&movie[indiceDePelicula].puntaje);
                }
            break;
        case 6:
            printf("\nIngrese link de la imagen: \n");
            fflush(stdin);
            gets(bufferLink);
            while(strlen(bufferLink)>100)
                {
                    printf("\nLink muy largo. Reingrese: \n");
                    fflush(stdin);
                    gets(bufferLink);
                }
            strcpy(movie[indiceDePelicula].descripcion,bufferDescripcion);
            break;
        default:
                system("cls");
                printf("\nOpcion ivalida\n");
                system("pause");
            break;
         }
 }
 /**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie movie[],int tam)
{
    int i;
    FILE *archivo;
    archivo=fopen("Peliculas.html","w");
    if(archivo==NULL)
    {
        printf("\nNo se pudo crear el archivo\n");
        exit(1);
    }
    for(i=0;i<tam;i++)
    {
        if(movie[i].estado==1)
        {

     fprintf(archivo,"%s","<article class='col-md-4 article-intro'>");
     fprintf(archivo,"%s","<a href='#'>");
     fprintf(archivo,"%s","<img class='img-responsive img-rounded' src='");
     //fwrite(movie[i].linkImagen,sizeof(char),sizeof(movie[i].linkImagen),archivo);
     fprintf(archivo,"%s",movie[i].linkImagen);
     fprintf(archivo,"%s","'alt=''>");
     fprintf(archivo,"%s","</a>");
     fprintf(archivo,"%s","<h3>");
     fprintf(archivo,"%s","<a href='#'>");
     fprintf(archivo,"%s",movie[i].titulo);
     fprintf(archivo,"%s","</a>");
     fprintf(archivo,"%s","<h3>");
     fprintf(archivo,"%s","<ul>");
     fprintf(archivo,"%s","<li>Género:");
     fprintf(archivo,"%s",movie[i].genero);
     fprintf(archivo,"%s","</li>");
     fprintf(archivo,"%s","<li>Puntaje:");
     fprintf(archivo,"%d",movie[i].puntaje);
     fprintf(archivo,"%s","</li>");
     fprintf(archivo,"%s","<li>Duración:");
     fprintf(archivo,"%d",movie[i].duracion);
     fprintf(archivo,"%s","</li>");
     fprintf(archivo,"%s","<ul>");
     fprintf(archivo,"<li> Descripcion: ");
     fprintf(archivo,movie[i].descripcion);
     fprintf(archivo,"</article>");
        }
    }
     fprintf(archivo,"<script src='js/jquery-1.11.3.min.js'></script>");
     fprintf(archivo,"<script src='js/bootstrap.min.js'></script>");
	 fprintf(archivo,"<script src='js/ie10-viewport-bug-workaround.js'></script>");
	 fprintf(archivo,"<script src='js/holder.min.js'></script>");
	 fprintf(archivo,"</body></html>");
    fclose(archivo);
}
