#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include <memory.h>
#include <conio.h>


//metadata

typedef char campo[20];

int ncampos;

typedef struct header
{ 
    int id; 
    campo *fname; 
    campo *lname; 
}; 


struct header registro;




int main () 
{ 
    FILE *archivo;
  int opcion=-1;
  while (opcion!=99){
    opcion =mostrarMEnu();
    switch (opcion)
      {
           
        case 1:
          crearArchivo(archivo);
        break;
       case 2:
          leerArchivo(archivo);
          break;
        case 3:
          alta(archivo);
          break;
        /*case 4:
          modifiacion(archivo);
          break;
        case 5:
          baja(archivo);
          break;*/
      }
  }
    return 0;
}

//menu
int mostrarMEnu(void){
  int opcion;
  printf("1-- Generar archivo nuevo --\n");
  printf("2-- Mostrar archivo       --\n");
  printf("3-- Alta                  --\n");
  printf("4-- Modificacion          --\n");
  printf("5-- Baja                  --\n");
  printf("99-- Salir                 --\n");
  scanf("%d", &opcion);
  while (opcion>7 || opcion<1) 
  {   
    printf("ingrese una opcion valida\n");
    scanf("%d", &opcion); 
  }
  return opcion;
}


int crearArchivo(FILE *archivo){
  archivo = fopen ( "archivo.dat", "w" );
  int fclose (FILE *archivo);
  printf("-- Archivo creado -- \n");
  ncampos=0;
  return 0;
}



void leerArchivo(FILE *archivo){
    int i;
    archivo = fopen ("archivo.dat", "rb");
    if (!archivo)
        {
            printf("Unable to open file!");
            exit(1);
        }
    else 
    {     

        for (i = 0; i < ncampos; i++)
        {
          fread(&registro,sizeof(struct header),1,archivo);
          printf("%d", registro.id, "%s",registro.lname, "%s\n",registro.fname);
        /*
        fread(registro,sizeof(struct header),1,archivo);
        //  printf("%s","ID  : ");
          printf("%d", registro.id);
         // printf("%s"," ,nombre  : ");
          printf("%s",&registro.lname);
         // printf("%s"," ,Apellido  :");
          printf("%s\n" ,&registro.fname);
        }      */
        }          
        fclose(archivo);
    }
}

void alta(FILE *archivo){
    
   archivo = fopen ("archivo.dat", "a"); 
   if (!archivo)
        {
            printf("Unable to open file!");
            exit(1);
        }
    else 
    {
     //   fseek(archivo,0,SEEK_END);
    //    int size = ftell(archivo);
     //   fseek(archivo,size,SEEK_SET);
        int id;
        campo *ln;
        campo *fn;
        struct header newregistro;
       printf("Ingrese Codigo ") ;
        scanf( "%d",&id) ; 
        printf("Ingrese Nombre ") ;
        scanf( "%s",&fn) ;
        printf("Ingrese apellido ") ;
        scanf( "%s",&ln) ; 
         
        newregistro.id=id;
        newregistro.fname=fn;
        newregistro.lname=ln;
        fwrite(&newregistro,sizeof(struct header),1,archivo);
        ncampos++;
        printf("registro insertado con exito");
        fclose(archivo);
    } 
}