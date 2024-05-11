/* EP4 - parte II - 2 - Diagrama de Bifurcação */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Definindo o valor de pi */
#define PI 3.14159265

/* Função que calcula a função utilizada no método rk4. Ela recebe os mesmos 
   parâmetros da função rk4, exceto o passo, e devolve a função calculada */
double funcao (double t, double x, double v, double f)
{
    double valor;
    
    valor = 0.5*x*(1 - 4*pow(x,2)) - 0.25*v + f*cos(t);
    return valor;
}

/* Função que calcula o método Runge-Kuta de quarta ordem. Ela recebe os valores
   da posição, velocidade, tempo, força e passo, e modifica os três primeiros de 
   acordo com as regras do método */
void rk4 (double *t, double *x, double *v, double *h, double *F)
{
   double k1z, k2z, k3z, k4z, k1y, k2y, k3y, k4y;
   k1y = *h**v;
   k1z = *h*funcao(*t, *x, *v, *F);
   k2y = *h*(*v + k1z/2);
   k2z = *h*funcao(*t + *h/2, *x + k1y/2, *v + k1z/2, *F);
   k3y = *h*(*v + k2z/2);
   k3z = *h*funcao(*t + *h/2, *x + k2y/2, *v + k2z/2, *F);
   k4y = *h*(*v + k3z);
   k4z = *h*funcao(*t + *h, *x + k3y, *v + k3z, *F);
   *x = *x + (k1y + 2*k2y +2*k3y + k4y)/6;
   *v = *v + (k1z + 2*k2z +2*k3z + k4z)/6;
   *t = *t + *h;
} 

/* Início do programa principal */
int main (void)
{
    FILE*file;
    file=fopen("EP4II_2_fCORRE.txt","w");
    FILE*file2;
    file2=fopen("EP4II_2_XCORRE.txt","w");
    
    if(file);
    double h; /* Passo do método utilizado */
    double x, v, t; /* Espaço, velocidade (dx/dt), e tempo */   
    double F, dF; /* Força e a sua variação para o desenvolvimento do diagrama de fase */
    double omega; /* Frequência angular */
    int i, j; /* Variáveis contadoras */
    
    /* Definindo alguns valores iniciais */
    dF = 0.00025;
    omega = 1.0;
    
    /* Variando a força conforme o laço abaixo */
    for (F = 0; F <= 0.35; F = F + dF)
    {
        /* Inserindo as condições iniciais */
        x = -0.5;
        v = 0.5;
        t = 0.0;
        h = 0.01*2*PI/omega;
    
        /* Parte do transiente descartada */
        for (i = 0; i <= 200000; i++)
            rk4(&t, &x, &v, &h, &F);
        
        /* Parte que será impressa no diagrama */
        h = 0.001*2*PI/omega;
        for (i = 1; i <= 100; i++)
        {
            for (j = 1; j <= 1000; j++)
                rk4(&t, &x, &v, &h, &F);
            
            fprintf (file, "%.4f \n", F);
            fprintf (file2, " %.12f\n", x);
        }
    }
    fprintf (file, "Programa concluido\n");
    system ("pause");
    return 0;
}
/* Fim do programa principal */
