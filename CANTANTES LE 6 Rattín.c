#include <stdio.h>

#define CARACTERES 50
//#define CARACCHICO 4
#define CANTIDAD_CANTANTES 5

struct Cantantes{
    char nombre [CARACTERES];
    int edad;
    float salario;
};

void ingresarDatos(struct Cantantes [], int);
void procesarDatos(struct Cantantes [], int);
void mostrarDatos(struct Cantantes [], int);

int main(void){
    int cingresados = 0;
    int opcion;
    struct Cantantes cantantes[CANTIDAD_CANTANTES];
    for(int i = 0; i<CANTIDAD_CANTANTES; i++){
        cantantes[i].edad=0;
        cantantes[i].salario=0;
    }
    printf("---Menu---");
    printf("1. Ingresar datos sobre algun cantante del momento\n");
    printf("2. Procesar y dar evidencia sobre informacion relevante\n");
    printf("3. Finalizar el programa\n");
    printf("Seleccione una opcion: ");
    scanf(" %d" , &opcion);
 
 while(opcion !=3){
     while(opcion !=1 && opcion !=2){
         printf("Esta opcion no es valida, seleccione una opcion valida unicamente del 1 al 3. \n");
         printf("Puede volver a ingresar una opcion, esta vezz que sea valida por favor. \n");
         scanf(" %d", &opcion);
     }
     if(opcion==1){
         ingresarDatos(cantantes, cingresados);
         cingresados++;
         printf("Has ingresado de manera correcta el cantante. Por el momento hay %d de 5 cantantes ingresados.", cingresados);
         printf("---Menu--- \n1. Ingresar datos sobre algun cantante del momento \n2. Procesar y dar evidencia sobre informacion relevante \n3. Finalizar el programa.");
         scanf(" %d", &opcion);
     }
     if(opcion==2){
         mostrarDatos(cantantes, cingresados);
         procesarDatos(cantantes, cingresados);
         printf("---Menu--- \n1. Ingresar datos sobre algun cantante del momento \n2. Procesar y dar evidencia sobre informacion relevante \n3. Finalizar el programa.");
         scanf(" %d", &opcion);
     }
 }
 printf("Termino el programa");
}

void ingresarDatos(struct Cantantes cantantes[], int cingresados){
    printf("Ingresar nombre del cantante que busca hayar informacion: ");
    scanf(" %[^\n]s", cantantes[cingresados].nombre);
    printf("Por favor ingresar edad del cantante seleccionado: ");
    scanf(" %d", &cantantes[cingresados].edad);
    printf("Como ultimo debe ingresar el salario del cantante seleccionado: ");
    scanf("%f", &cantantes[cingresados].salario);
}

void procesarDatos(struct Cantantes cantantes [], int cingresados){
    float promedio=0;
    int max=0;
    int maxCantante;
    
    for(int i=0; i <cingresados; i++){
        if(cantantes[i].salario >max){
            max=cantantes[i].salario;
            maxCantante=i;
        }
    }
    
    for(int j=0; j <cingresados; j++){
        promedio += cantantes[j].salario;
    }
    promedio /= cingresados;
    
    printf("Promedio de salario $%f", promedio);
    printf("\n Empleado con salario mas alto: %s con un salario de %d\n", cantantes[maxCantante].nombre, max);
}



void mostrarDatos(struct Cantantes cantantes [], int cingresados){
    printf("Aca mostramos informacion sobre los cantantes");
    for (int i=0; i <cingresados; i++){
        printf("%d. Nombre del cantante: %s, Edad del cantante: %d, Salario del cantante: $%f\n", i+1, cantantes[i].nombre, cantantes[i].edad, cantantes[i].salario);
    }
}




