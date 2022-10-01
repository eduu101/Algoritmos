/*Realiza la practica en equipo de máximo 3 integrantes.
• Objetivo: Elaborar un programa que resuelva el problema del cambio por el método codicioso con la intención de minimizar el número de billetes y monedas que se dan de cambio
• Especificaciones:
• El programa deberá recibir la cantidad de la cuál dará cambio, así como el número de billetes de $500,$200,$100,$50, $20 y monedas de $10,$5,$2 y 1 con las que se cuenta.
• La salida del programa indicará cuantas monedas o billetes y su denominación se entregarán de cambio
• Condición
• Existe un número limitado de billetes y monedas de cada valor*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int b500,b200,b100,b50,b20;
int b500cam,b200cam,b100cam,b50cam,b20cam;
int m10,m5,m2,m1;
int m10cam,m5cam,m2cam,m1cam;
int cambio;
bool falta;

void preguntar();
void calcular(int);
void imprimir();


int main(){
    char res;
    do{
        b500cam=0,b200cam=0,b100cam=0,b50cam=0,b20cam=0;
        m10cam=0,m5cam=0,m2cam=0,m1cam=0;

        preguntar();
        calcular(cambio);
        if (falta==false)
        {
            imprimir();
        }
        printf("\nCalcular otro cambio?(s/n):");
        fflush(stdin);
        scanf("%c",&res);
    }while(res=='s'||res=='S');
    
    return 0;
}

void preguntar(){
    printf("\nCual es el cambio a devolver?:");
    scanf("%i",&cambio);

    printf("\nCuantos billetes de 500 hay?:");
    scanf("%i",&b500);
    printf("\nCuantos billetes de 200 hay?:");
    scanf("%i",&b200);
    printf("\nCuantos billetes de 100 hay?:");
    scanf("%i",&b100);
    printf("\nCuantos billetes de 50 hay?:");
    scanf("%i",&b50);
    printf("\nCuantos billetes de 20 hay?:");
    scanf("%i",&b20);
    printf("\nCuantas monedas de 10 hay?:");
    scanf("%i",&m10);
    printf("\nCuantas monedas de 5 hay?:");
    scanf("%i",&m5);
    printf("\nCuantas monedas de 2 hay?:");
    scanf("%i",&m2);
    printf("\nCuantas monedas de 1 hay?:");
    scanf("%i",&m1);
}
void calcular(int cam){
    while (cam>=500 && b500>0)
    {   
        cam-=500;
        b500cam++;
        b500--;
    
    }
    while (cam>=200 && b200>0)
    {
        cam-=200;
        b200cam++;
        b200--;
    }while (cam>=100 && b100>0)
    {   
        cam-=100;
        b100cam++;
        b100--;
    
    }
    while (cam>=50 && b50>0)
    {
        cam-=50;
        b50cam++;
        b50--;
    }while (cam>=20 && b20>0)
    {   
        cam-=20;
        b20cam++;
        b20--;
    
    }
    while (cam>=10 && m10>0)
    {
        cam-=10;
        m10cam++;
        m10--;
    }
    while (cam>=5 && m5>0)
    {
        cam-=5;
        m5cam++;
        m5--;
    }
    while (cam>=2 && m2>0)
    {
        cam-=2;
        m2cam++;
        m2--;
    }
    while (cam>=1 && m1>0)
    {
        cam-=1;
        m1cam++;
        m1--;
    }
    if (cam>0)
    {
        printf("\n\n*****No es posible devolver el cambio*****");
        falta=true;
        if (cam>1)
            printf("\n\nFaltan %d pesos",cam);
        else        
            printf("\n\nFalta %d peso",cam);
    }
    else
        falta=false;
    
        
}

void imprimir(){

    printf("\nEl cambio de %d se devuelve en:",cambio);
    if (b500cam>0)
    {
        if (b500cam>1)
        {
            printf("\n%d billetes de 500",b500cam);
        }
        else
            printf("\n%d billete de 500",b500cam);
    }
    if (b200cam>0)
    {
        if (b200cam>1)
        {
            printf("\n%d billetes de 200",b200cam);
        }
        else
            printf("\n%d billete de 200",b200cam);
    }
    if (b100cam>0)
    {
        if (b100cam>1)
        {
            printf("\n%d billetes de 100",b100cam);
        }
        else
            printf("\n%d billete de 100",b100cam);
    }
    if (b50cam>0)
    {
        if (b50cam>1)
        {
            printf("\n%d billetes de 50",b50cam);
        }
        else
            printf("\n%d billete de 50",b50cam);
    }
    if (b20cam>0)
    {
        if (b20cam>1)
        {
            printf("\n%d billetes de 20",b20cam);
        }
        else
            printf("\n%d billete de 20",b20cam);
    }
    if (m10cam>0)
    {
        if (m10cam>1)
        {
            printf("\n%d monedas de 10",m10cam);
        }
        else
            printf("\n%d moneda de 10",m10cam);
    }
    if (m5cam>0)
    {
        if (m5cam>1)
        {
            printf("\n%d monedas de 5",m5cam);
        }
        else
            printf("\n%d moneda de 5",m5cam);
    }
    if (m2cam>0)
    {
        if (m2cam>1)
        {
            printf("\n%d monedas de 2",m2cam);
        }
        else
            printf("\n%d moneda de 2",m2cam);
    }
    if (m1cam>0)
    {
        if (m1cam>1)
        {
            printf("\n%d monedas de 1",m1cam);
        }
        else
            printf("\n%d moneda de 1",m1cam);
    }
}
