/******************************************************************************/
/* Fabiene Francesca Casillo Casamento nº 5977187       ***********************/
/* Exercicio-Programa EP3                          ****************************/
/* Curso Meteorologia - Turma ... - Profa. Yoshiko Wakabayashi ****************/
/* ****************************************************************************/
/* Compilador: ................... ********************************************/
/******************************************************************************/


#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define L_MAX 300
#define C_MAX 300
#define FALSE 0
#define TRUE  1

/*****primeira função******************/
/*coloca as bombas ou campo minado e mostra as dicas de onde esta a bomba*/
void  iniciojogo(int linha, int coluna, int minas,int semente ,int matriz[][C_MAX],int matrizliberado[][C_MAX],int marca[][C_MAX],int pilha[][C_MAX]);
/******terceira função*******************/
/*imprime os valores selecionados pelo usuario*/
void imprime(int linha , int coluna,int z,int w,int matriz[][C_MAX],int marca[][C_MAX],int matrizliberado[][C_MAX]);
/**************segunda função************************/
/*verifica se o jogo terminou ou não*/
int condicaojogo(int i,int j, int matriz[][C_MAX],int linha,int coluna,int marca[][C_MAX],int minas);
/*********************Quinta função***************************/
/*libera as 8 casas ao redor do campo ou matriz */
void imprimeespaco(int tlinha, int tcoluna,int matriz[][C_MAX],int matrizliberado[][C_MAX],int marca[][C_MAX], int var_col, int var_lin,int pilha[][C_MAX]);
/*************sexta função*********************************/
/*aonde ha o numero zero e sinal que não tem bomba e nem dica entao abre espaço para mostrar as dicas*/
void abreespaco (int lin,int col,int pilha[][C_MAX],int matrizliberado[][C_MAX], int matriz[][C_MAX],int marca[][C_MAX]);
/*********************quarta função**************/
/*verifica se a jogada foi boa e manda para imprime espaço  */
void  jogada(int tlinha, int tcoluna, int linha, int coluna,int matriz[][C_MAX],int matrizliberado[][C_MAX],int marca[][C_MAX],int pilha[][C_MAX]);
/******************ultima função*********************/
/*se jogador perdeu então libera todo o jogo ou a matriz*/
void liberatudo(int z,int w,int matriz[][C_MAX],int linha,int coluna,int marca[][C_MAX]);


/****************************************primeira função*******************************/
void  iniciojogo(int linha, int coluna, int minas,int semente, int matriz[][C_MAX],int matrizliberado[][C_MAX],int marca[][C_MAX],int pilha[][C_MAX])
{
   int i,j;
   int a,b,tcoluna,tlinha,cont;
   int numero;
  
  
     /* printf("funçao uma \n");*/ 
   /*inicializando todos os arrays*/
   for(i=0;i<linha;i++){
       for(j=0;j<coluna;j++)
          { 
              matriz[i][j]=0;/*matriz  inicial para o começo do jogo*/
              matrizliberado[i][j]=FALSE;/*pedido para ser impresso*/
              marca[i][j]=FALSE;/*se já foi impresso*/
              pilha[i][j]==FALSE;/*auxilia no campo ou matriz quando este é zero e ajuda a libera outros que contem dicas*/
              
          }
   }
   /*gerando as bombas*/
   srand(semente);
     
   for(cont=0;cont<minas;cont++){
      numero=rand();
      tlinha=numero%linha;
      numero=rand();
      tcoluna=numero%coluna;
     /* printf("localbomba(linha,coluna)=(%d,%d)\n",tlinha+1,tcoluna+1);*/
      /*certifica se o numero aleatorio já não foi gerado anteriormente
      caso ele já tenha gerado decremente o contador no cao o i*/
      if(matriz[tlinha][tcoluna]==-1)
         {
             cont--;
         }
       else 
          {   
             matriz[tlinha][tcoluna]=-1;/*campo minado*/
          }
    }
   for(i=0;i<linha;i++)
      {
          for(j=0;j<coluna;j++)
             {
                 if(matriz[i][j]==-1)
                    for(a=i-1;a<=1+i;a++)
                       {
                          for(b=j-1;b<=j+1;b++) 
                             {
                               if(matriz[a][b]!=-1 && a>=0&&a<linha&&b>=0&&b<coluna)
                                 {
                                       /*criando as dicas*/
                                      matriz[a][b]=matriz[a][b]+1;
                                 }  
                             }
                       }
             }   
     
    }

}
/**************************terceira função********************************************/
void imprime(int linha , int coluna,int z,int w,int matriz[][C_MAX],int marca[][C_MAX],int matrizliberado[][C_MAX])
{  
    int i, j,a,b,t,f;
    
     printf("\n");
     j=0;
     printf("    %d",j+1);
     j++;
     
    for(;j<coluna;j++)
       {
        /*imprime guia coluna*/
        printf("%2d",j+1);
       }
       printf("\n");
       printf("  +");
    for(j=0;j<coluna;j++)
       {
        /*imprime */
        printf("--");
       } 
        printf("-+");
        printf("\n");
    for(i=0;i<linha;i++)
    {
         /*imprime guia coluna*/
         printf("%2d|",i+1);
         for(j=0;j<coluna;j++)
         { 
                 if( matriz[i][j]!=-1&&i==z&&j==w )
                     {
                           printf("%2d",matriz[i][j]);  
                           marca[i][j]=TRUE;/*sinal que foi marcado*/
                           matrizliberado[i][j]=TRUE;/*liberdo para ser marcado*/
                            
                     }                                                       
                    
                  else if(matriz[i][j]==-1&&i==z&&j==w)
                    { 
                         printf("%2d",matriz[i][j]); 
                    }                    
                  else if( marca[i][j]==TRUE )
                   {
                         printf("%2d",matriz[i][j]);     
                   }
                  else if (matrizliberado[i][j]==TRUE)
                    {
                         printf("%2d",matriz[i][j]);
                         marca[i][j]=TRUE;
                    }
                  else
                    {
                            printf(" .");
                    } 
              
              
           }      
             
         printf(" |");
         printf("\n");
    }  
     printf("  +");
     for(j=0;j<coluna;j++)
       {
        /*imprime moldura*/
        printf("--");
       } 
        printf("-+");
        printf("\n"); 
  
}
/********************************segunda função************************************************/
int condicaojogo(int i,int j, int matriz[][C_MAX],int linha,int coluna,int marca[][C_MAX],int minas)
{
        int cont,auxleitura,a,b,auxdados; 
             if( matriz[i][j]==-1)/*campo minado*/
             { 
                      return TRUE;
             }
                
             cont=0;
             auxleitura=0;
             for (a=0;a<linha;a++)
             {
                for (b=0;b<coluna;b++)
                  {
                    auxleitura++;
                    if(matriz[a][b]!=-1 && marca[a][b]==TRUE)
                       cont++;
                  }                         
             }
             auxdados=auxleitura-minas;
         
             if(cont==auxdados)/*verifica se ganhou ou seja se abriu todos os valores sem bomba*/
               {
                   return (2);
               }
  
     return FALSE;
}
/*******************************Quinta função**************************************************/
void imprimeespaco(int tlinha, int tcoluna,int matriz[][C_MAX],int matrizliberado[][C_MAX],int marca[][C_MAX], int var_lin , int var_col,int pilha[][C_MAX])
{ 
      int a , b, i, j , z;
      
      
      for(a=tlinha-1;a<=tlinha + 1;a++)
         for(b= tcoluna-1; b <= tcoluna + 1; b++)
           if(matriz[a][b]!=-1 && a>=0 && b>=0 && a < var_lin && b < var_col )
             {
               matrizliberado[a][b]=TRUE;
               if(matriz[a][b]==0)
                  pilha[a][b]=TRUE;
                 
             }
}
/*********************************************sexta função****************************************/
void abreespaco (int lin,int col,int pilha[][C_MAX],int matrizliberado[][C_MAX], int matriz[][C_MAX],int marca[][C_MAX])
{ 
        

    int i,j,z,w,a,b,quantidadepilha,cont;
     quantidadepilha=0;
      for(i=0; i < lin;i++)         
              {
               for(j=0; j < col;j++)
                {
                     if (pilha[i][j]==TRUE )
                        { 
                           z=i;
                           w=j;
                           
                          for(a=i-1;a <= i + 1;a++)
                              for(b= j-1; b <= j + 1; b++)
                                  if(matriz[a][b]!=-1 && pilha[a][b]!=TRUE&& a>=0 && b>=0 && a < lin && b < col )
                                     {
                                       matrizliberado[a][b]=TRUE;
                                      if(matriz[a][b]==0)
                                          pilha[a][b]=TRUE;/*aonde esta o 0 que foi um aberto  e vai ser afonte para abrir as outras*/
                                          quantidadepilha++;
                                     } 

                         }
                 
                  }      
               }
         /***verifica***/  
       for (cont=quantidadepilha;cont>0;cont--)
           {
             for(i=0; i < lin;i++)         
              {
               for(j=0; j < col;j++)
                {
                     if (pilha[i][j]==TRUE )
                        { 
                           z=i;
                           w=j;
                           
                         
                           for(a=i-1;a <= i + 1;a++)
                              for(b= j-1; b <= j + 1; b++)
                                  if(matriz[a][b]!=-1 && pilha[a][b]!=TRUE&& a>=0 && b>=0 && a < lin && b < col )
                                     {
                                       matrizliberado[a][b]=TRUE;/*liberdo para ser imprimido*/
                                      if(matriz[a][b]==0)
                                          pilha[a][b]=TRUE;
                                          /*cont++;*/
                                     } 
                         }
                 }      
               }
           }  
}    

/********************************************quarta função*******************************************/
 void  jogada(int tlinha, int tcoluna, int linha, int coluna,int matriz[][C_MAX],int matrizliberado[][C_MAX],int marca[][C_MAX],int pilha[][C_MAX])
{
      int a,b;
      a=tlinha;
      b=tcoluna;   

         
                 
         if(a>=0 && a <=linha && b>=0 && b <=coluna && matriz[a][b]!=-1)
                 {  /*abrir espaço se for 0 necessario*/
                    /*libera um espaço para dicas */
                   matrizliberado[a][b]=TRUE;
                   if(matriz[a][b]==0)
                     {
                       /*Abre as casa adjacentes (os 8 lados que estão ao redor do campo para uma posição vazia*/ 
                       imprimeespaco(a,b,matriz,matrizliberado,marca, linha, coluna,pilha); 
                     }
                  }      
 }                     

/*************************ULTIMA FUNÇÃO**********************************************/
void liberatudo(int z,int w,int matriz[][C_MAX],int linha,int coluna,int marca[][C_MAX])
{
     int a,b; 
    
    if (matriz[z][w]==-1)
    {
       for(a=0 ;a < linha; a++)
         for(b=0;b < coluna;b++)                          
            {
               marca[a][b]=TRUE;
            } 
         
    }
}

/*********************************PRINCIPAL*****************************************************/
int main(){
   int dadocoluna,dadolinha, dadominas,jogo,a,b,matriz[L_MAX][C_MAX];
   int matrizliberado[L_MAX][C_MAX],marca[L_MAX][C_MAX],pilha[L_MAX][C_MAX];
   int semente;
              
   printf(" \t   CAMPO MINADO     \t\n");
   printf(" De o numero da linha da matriz do jogo:\n");
   scanf("%d",&dadolinha);
   printf(" De o numero da coluna da matriz do jogo:\n");
   scanf("%d",&dadocoluna);
   printf(" De o numero de minas :\n");
   scanf("%d",&dadominas);
   printf(" De o qualquer numero inteiro nao negativo sendo esta sua semente :\n");
   scanf("%d",&semente);/*semente eh a fonte para gerar um numero aleatorio*/
   
   iniciojogo(dadolinha,dadocoluna,dadominas,semente,matriz,matrizliberado,marca,pilha);
   jogo=FALSE;
   imprime(dadolinha,dadocoluna,a,b,matriz,marca,matrizliberado);
   printf("digite chute m x n\n");
   printf("digite chute m\n");
   scanf("%d",&a);
   printf("digite chute n\n");
   
   scanf("%d",&b);
   a=a-1;
   b=b-1;
   jogada(a,b,dadolinha,dadocoluna,matriz,matrizliberado,marca,pilha); 
   abreespaco(dadolinha,dadocoluna,pilha,matrizliberado,matriz,marca);
   if (matriz[a][b]!=-1)
      imprime(dadolinha,dadocoluna,a,b,matriz,marca,matrizliberado);
   while(jogo==FALSE)/*infinito jogo */  
    { 
     
     
           
            if(condicaojogo(a,b,matriz,dadolinha,dadocoluna,marca,dadominas)==TRUE)
                {
                  liberatudo(a,b,matriz,dadolinha,dadocoluna,marca);                                                                  
                  imprime(dadolinha,dadocoluna,a,b,matriz,marca,matrizliberado);
                  printf("BOOOM !! acabou de pisar em uma bomba, PERDEU!!! \n");
                  system("pause");
                  return 0;
                }
             else if(condicaojogo(a,b,matriz,dadolinha,dadocoluna,marca,dadominas)==2)
                { 
                     printf("GANHOU!!! \n");
                     system("pause");
                     return 0;
               
                }

             else 
                {
                  
                  printf("digite chute m x n\n");
                  printf("digite chute m\n");
                  scanf("%d",&a);
                  printf("digite chute n\n");
                  scanf("%d",&b);
                  printf("proximo chute (%d,%d):\n",a,b);
                  a=a-1;
                  b=b-1;
                  jogada(a,b,dadolinha,dadocoluna,matriz,matrizliberado,marca,pilha);
                  abreespaco(dadolinha,dadocoluna,pilha,matrizliberado,matriz,marca);
                  if (matriz[a][b]!=-1)
                     imprime(dadolinha,dadocoluna,a,b,matriz,marca,matrizliberado);
                } 
                  
        
    
     }           
      
    
   
   system("pause");
   return 0;
}
