/*Realiza la practica en equipo de máximo 3 integrantes.
• Objetivo general: Elaborar un programa que resuelva el problema de asignación de tareas con el método
codicioso con la intención de minimizar el costo asociado
• El programa tendrá las siguientes funcionalidades
1. Aplicar el método codicioso simple por filas
2. Aplicar dos veces el método codicioso. La primera vez para ordenar las etapas (columnas) comenzando por el precio más alto global. La segunda vez para elegir al trabajador que cobre menos por el trabajo
3. Aplicar un criterio de ordenamiento y después el método voraz. El criterio de ordenamiento ordenará las etapas (filas) comenzando por la fila cuya sumatoria de precios sea la mayor. Después se aplicará el método voraz para asignar a cada trabajador el trabajo por el que cobre menos.
• Especificaciones:
• El programa leerá los datos del archivo datosP3_2.txt. Cada fila del archivo corresponderá a cada trabajador y cada columna
a los costos por cada trabajo.
• El programa deberá validar que el número de trabajos sea el mismo que el número de trabajadores
• La salida del programa se deberá escribir en el archivo salidaP3_2.txt. Para mayor referencia del formato que debe tener el archivo salidaP3_2.txt revisar del archivo ejemploSalidaP3_2.txt. En el archivo ejemploSalidaP3_2.txt se muestra el resultado de las tres funcionalidades, donde 𝐹𝑊 se refiere a la funcionalidad 𝑊 para 𝑊 = 1,2,3, 𝑃𝐾 se refiere al trabajador 𝐾 y 𝑇𝐾 se refiere al trabajo 𝐾 para K = 1,2,3, ... , 𝑛. Dado que para la funcionalidad de 𝐹1 tiene dos posibilidades, se presentan dos filas una para posibilidad
• Si existen varias posibilidades deberá presentar todas en el archivo de salida*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define filas 5
#define cols 5
int sumaCol[cols][2];
int sumaFil[filas][2];
int aux[filas][cols];
int numero=0;


void imprimirMatriz(int[filas][cols][4]);
void cargarMatriz(char*,int[filas][cols][4]);
void guardarMatriz(int[filas][cols][4]);
void sumaColumnas(int[filas][cols][4]);
void sumaFilas(int[filas][cols][4]);
void ordenarSumas(int [cols][2]);
void mayor(int [filas][2]);
void menor(int [filas][2]);
void MCFilas(int[filas][cols][4]);
void PersonaOcupada(int [filas][cols][4],int);
void TrabajoOcupado(int [filas][cols][4],int);

int main(){
    //La matriz Z es de 3 dimensiones donde en la 3ra dimension tenemos
    //en la posición [0] el valor en la matriz
    //en la posición [1] el numero de Trabajo (T1, T2,etc)
    //en la posición [2] el número de Persona/Trabajador (P1, P2,etc)
    int Z[filas][cols][4];

    cargarMatriz("datosP3_2.txt",Z);
    imprimirMatriz(Z);
    guardarMatriz(Z);
    sumaColumnas(Z);
    printf("\n\n");
 /*  for(int i=0;i<cols;i++){
        printf("%d|T%d \t\t\t",sumaCol[i][0],sumaCol[i][1]);
    }
    printf("\n");
    mayor(sumaCol);
    for(int i=0;i<cols;i++){
        printf("%d|T%d \t\t\t",sumaCol[i][0],sumaCol[i][1]);
    }
    printf("\n\n");
    sumaFilas(Z);
    for(int i=0;i<filas;i++){
        printf("%d|P%d \t\t\t",sumaFil[i][0],sumaFil[i][1]);
    }
    printf("\n");
    mayor(sumaFil);
    for(int i=0;i<filas;i++){
        printf("%d|P%d \t\t\t",sumaFil[i][0],sumaFil[i][1]);
    }
    printf("\n");
    menor(sumaFil);
    for(int i=0;i<filas;i++){
        printf("%d|P%d \t\t\t",sumaFil[i][0],sumaFil[i][1]);
    }*/
    MCFilas(Z);
    printf("\n\n");
    imprimirMatriz(Z);

    return 0;
}

void imprimirMatriz(int matriz[filas][cols][4]){
    for(int i=0;i<filas;i++){
        for(int j=0;j<cols;j++){
            printf("%d | T%d,P%d|%d\t\t\t",matriz[i][j][0],matriz[i][j][1],matriz[i][j][2],matriz[i][j][3]);
        }
        printf("\n");
    }
}

void cargarMatriz(char *fileName, int matriz[filas][cols][4]){
    FILE *fp = fopen(fileName, "rb");
	if (fp == NULL) {
		printf("Error al cargar el archivo.");
	}
	while(numero<25){
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < cols; j++) {
                fscanf(fp,"%d",&numero);
                matriz[i][j][0]=numero;
                matriz[i][j][1]=j+1;
                matriz[i][j][2]=i+1;
                matriz[i][j][3]=0;
		    }
	    }
    }
	fclose(fp);
}

void guardarMatriz(int matriz[filas][cols][4]){
    FILE *asientos=NULL;
    asientos=fopen("asientos.txt","w");
    if(asientos == NULL ) {
        printf("No fue posible abrir el archivo\n");
    }
    char linea[80];
	for (int i = 0; i < filas; i++) {
        linea[0] = '\0';
		for (int j = 0; j < cols; j++) {
			char buffer[10];
			sprintf(buffer, "%d\t", matriz[i][j][0]);
			strcat(linea, buffer);
		}
		int len = strlen(linea);
		linea[len - 1] = '\n';
		fputs(linea, asientos);
	}
	fclose(asientos);
}


void sumaColumnas(int matriz[filas][cols][4]){

    for(int j=0;j<cols;j++){
        int suma=0;
        
        for(int i=0;i<filas;i++){
            suma=suma+matriz[i][j][0];
        }
        sumaCol[j][0]=suma;

    }    
    for (int i = 0; i < filas; i++)
    {
        sumaCol[i][1]=i+1;
    }
    
}


void sumaFilas(int matriz[filas][cols][4]){
    int suma=0;
    for(int i=0;i<filas;i++){
        sumaFil[i][1]=i+1;
        for(int j=0;j<cols;j++){
            suma=suma+matriz[i][j][0];
        }
        sumaFil[i][0]=suma;
        suma=0;
    } 
    
}
void mayor(int mm[filas][2]){
    int temp,temp2;
    for (int i = 0; i < (filas - 1); i++) { 
        for (int j = i + 1; j < filas; j++){ 
            if (mm[j][0] > mm[i][0]) { 
                    temp = mm[j][0];
                    temp2 = mm[j][1];
                    mm[j][0] = mm[i][0]; 
                    mm[j][1] = mm[i][1];
                    mm[i][0] = temp;
                    mm[i][1] = temp2;  
                } 
        } 
  } 
}

void menor(int mm[filas][2]){
    int temp,temp2;
    for (int i = 0; i < (filas - 1); i++) { 
        for (int j = i + 1; j < filas; j++){ 
            if (mm[j][0] < mm[i][0]) { 
                    temp = mm[j][0];
                    temp2 = mm[j][1];
                    mm[j][0] = mm[i][0]; 
                    mm[j][1] = mm[i][1];
                    mm[i][0] = temp;
                    mm[i][1] = temp2;  
                } 
        } 
  } 
}


void MCFilas(int mm[filas][cols][4]){    
    int x,y;
    int barato;
    
    for(int j=0;j<cols;j++){
        barato=mm[j][0][0];
        x=j;
        y=0;
        printf("\n");
        for(int i=0;i<filas;i++){
            printf("%d\t",mm[j][i][0]);
            if (barato>=mm[j][i][0] && mm[j][i][3]==0){
                barato=mm[j][i][0];
                x=j;
                y=i;
            }
            
        }
        printf("\tP%d|T%d",x+1,y+1);
        PersonaOcupada(mm,x);
        TrabajoOcupado(mm,y);
    }
}




void PersonaOcupada(int mm[filas][cols][4],int t){
    for (int i = 0; i < cols; i++){
        mm[t][i][3]=1;
    }
    

}

void TrabajoOcupado(int mm[filas][cols][4],int t){
    for (int i = 0; i < filas; i++){
        mm[i][t][3]=1;
    }
    
}
