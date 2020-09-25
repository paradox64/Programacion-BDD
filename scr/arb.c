#include <stdio.h>
#include <stdlib.h>


struct record_a
{
    long clave;
    char RazonSocial[50];
    char Domicilio[50];
    char Localidad[30];
    long TE;
    long Celular;
    char Mail[100];

} record_a;

int crearArchivo(FILE *archivo);
int mostrarMEnu(void);

int main (){
  FILE *archivo;
  int opcion=-1;
  while (opcion!=7){
    opcion =mostrarMEnu();
    switch (opcion)
      {
        case 1:
          crearArchivo(archivo);
        break;
       /* case 2:
          mostrarArchivo(archivo);
          break;
        case 3:
          alta(archivo);
          break;
        case 4:
          modifiacion(archivo);
          break;
        case 5:
          baja(archivo);
          break;
        case 6:
          compactar(archivo);
          break;*/
        default:printf("El programa finalizo");
      }
  }
  return 0;
}

int crearArchivo(FILE *archivo){
  archivo = fopen ( "archivito.in", "w" );
  int fclose (FILE *stream);
  printf("-- Archivo creado -- \n");
  return 0;
}

int mostrarMEnu(void){
  int opcion;
  printf("1-- Generar archivo nuevo --\n");
  printf("2-- Mostrar archivo       --\n");
  printf("3-- Alta                  --\n");
  printf("4-- Modificacion          --\n");
  printf("5-- Baja                  --\n");
  printf("6-- Compactar             --\n");
  printf("7-- Salir                 --\n");
  scanf("%d", &opcion);
  while (opcion>7 || opcion<1) 
  {   
    printf("ingrese una opcion valida\n");
    scanf("%d", &opcion); 
  }
  return opcion;
}