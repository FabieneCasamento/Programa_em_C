
/********************************************************/
/* Fabiene Francesca Casillo Casamento nº 5977187       */
/* Exercicio-Programa EP1 */
/* Curso Meteorologia - Turma ... - Profa. Yoshiko Wakabayashi */
/* */
/* Compilador: ................... */
/********************************************************/

 /*O dono do Banco Aquarius que fica nas Ilhas Delta-Aquarideas deseja instalar diversos caixas
eletronicos nas magnificas praias da ilha, permitindo aos seus correntistas sacar e depositar dinheiro
durante os momentos de lazer.
Conhecendo a fama internacional dos alunos do IAG/USP, o banqueiro contratou os alunos de
MAC 115 para projetar um programa que mantivesse a contabilidade do caixa e controlasse o numero
de notas necess´arias para efetivar os saques.
Nesse local, todas as manhas a central fornece aos caixas notas de 100, 50, 10, 5 e 1 ducas. Todos os
saques devem ser processados de maneira a utilizar o menor numero possivel de notas. Por exemplo,
para um saque de 350 ducas o caixa deve entregar, se disponiveis, 3 notas de 100 e uma de 50 (em vez
de outras eventuais possibilidades como 7 notas de 50). Para que o caixa eletronico processe depositos
eh necessario que o usuario especifique a quantidade de notas (de cada tipo) que esta sendo fornecida.
*/
#include<stdio.h>   
#include<stdlib.h>

int main()
{
    int n,operacao, nota100, nota50, nota10, nota5, nota1;/*quantidades de notas  */
    int totaldinheiro,valordosaque,versaque;/*situação em que fica o dinheiro,quanto sobra de cada operação , operação de saque */
    int n100,n50,n10, n5, n1,contn;/*atualização do caixa*/
    int notadepositado100, notadepositado50, notadepositado10, notadepositado5, notadepositado1;/* quantidades de notas que eu depositei*/
    int valordodepositado;/*valor total depositado*/
    contn=1;
    printf("    Bem vindo ao Banco Aquarius !!!!!!!! \n");   
    /*Atribuir dados para as quantidades de notas */
    printf("entre com a quantidade inicial de notas de 100:");
    scanf("%d",&nota100);
    printf("\n entre com a quantidade inicial de notas de 050:");
    scanf("%d",&nota50);
    printf("\n entre com a quantidade inicial de notas de 010:");
    scanf("%d",&nota10);
    printf("\n entre com a quantidade inicial de notas de 005:");
    scanf("%d",&nota5);
    printf("\n entre com a quantidade inicial de notas de 001:");
    scanf("%d",&nota1);
    /* será necessario para atualizar o caixa por falta cedula */
    n100=nota100; n50=nota50; n10=nota10;  n5=nota5;  n1=nota1;
    
    /*verifica a quantidade de dinheiro*/
    totaldinheiro=nota100*100+nota50*50+nota10*10+nota5*5+nota1*1;
    /*valor total de ducas no caixa*/
    /*printf("quantidade de notas de 100 ducas %d\n",nota100);
    printf("quantidade de notas de 50 ducas %d\n",nota50);
    printf("quantidade de notas de 10 ducas %d\n",nota10);
    printf("quantidade de notas de 5 ducas %d\n",nota5);
    printf("quantidades de notas de 1 duca %d\n",nota1);
    printf("situação atual de %d ducas\n",totaldinheiro);*/ 
    printf("situação atual: %d %d %d %d %d           saldo: %d de ducas\n",nota100, nota50, nota10, nota5, nota1, totaldinheiro);
    /* Ler a quantidade de operacoes a serem realizadas*/
    printf("digite a quantidade de operacao que deseja fazer\n");
        scanf("%d", &n);
    
    /* dispobibilidade de saque ou deposito*/
    while (n>=contn){
          /*operacao de saque*/
          printf("Operacao %d  (Digite 0 = SAQUE ou Digite 1 = DEPOSITAR):", contn); 
          scanf("%d",&operacao);
          contn=contn+1;
          while((operacao!=0) && (operacao!=1)){
          printf(" Operacao nao pode ser realizada verifique o comando no inicio deste programa\n");
          printf(" Digite novamente (0=saque ou 1=deposito)");
           scanf("%d",&operacao);
           }
           /*saque*/
           if(operacao==0){
                           /*avaliacao do caixa se ha dinheiro neste*/
                           printf("digite o valor desejado a ser sacado\n");
                           scanf("%d",&valordosaque);
                           /*condição do saque*/
                           if(valordosaque>totaldinheiro)
                           printf("Saque de %d reais nao pode ser efetuado por falta de ducas em sua conta\n",valordosaque);
                           else{
                                versaque=valordosaque;
                                while((valordosaque>=100)&&(nota100>0)){
                                      valordosaque=valordosaque-100;
                                      nota100=nota100-1;
                                      }
                                       while((valordosaque>=50)&&(nota50>0)){
                                               valordosaque=valordosaque-50;
                                               nota50=nota50-1;
                                                }
                                                 while ((valordosaque>=10)&&(nota10>0)){
                                                           valordosaque=valordosaque-10;
                                                           nota10=nota10-1;
                                                           }
                                                           while((valordosaque>=5)&&(nota5>0)){
                                                                  valordosaque=valordosaque-5;
                                                                  nota5=nota5-1;
                                                                   }
                                                                   while((valordosaque>=1)&&(nota1>0)){
                                                                          valordosaque=valordosaque-1;
                                                                          nota1=nota1-1;
                                                                           }
                                                                          /*avalia a possibilidade de notas de ducas para o saque */
                                                                           if(valordosaque!=0){
                                                                           printf("Saque de %d ducas nao pode ser efetuado por falta de cedulas de ducas\n",versaque);
                                                                           nota100=n100;
                                                                           nota50=n50;
                                                                           nota10=n10;
                                                                           nota5=n5;
                                                                           nota1=n1;                                                                                                                                                 
                                                                                  }                                                                                                                                                 
                                                                                   else
                                                                                       printf("Saque de %d ducas\n",versaque);
                                                                                    }
                           totaldinheiro=nota100*100+nota50*50+nota10*10+nota5*5+nota1*1;                                                                                
                           printf("situacao atual: %d %d %d %d %d           saldo: %d de ducas\n",nota100, nota50, nota10, nota5, nota1, totaldinheiro);                                                                                                                      
                                                                                                                                                            
                           
                           }


          else {
               /*operacao de deposito*/
                if (operacao==1){
                                 printf("Digite a quantidade de notas de 100 ducas a ser depositado: ");
                                 scanf("%d",&notadepositado100);
                                 printf("Digite a quantidade de notas de 050 ducas a ser depositado: ");
                                 scanf("%d",&notadepositado50);
                                 printf("Digite a quantidade de notas de 010 ducas a ser depositado: ");
                                 scanf("%d",&notadepositado10);
                                 printf("Digite a quantidade de notas de 005 ducas a ser depositado: ");
                                 scanf("%d",&notadepositado5);
                                 printf("Digite a quantidade de notas de 001 ducas a ser depositado: ");
                                 scanf("%d",&notadepositado1);
                                 nota100=nota100+notadepositado100;
                                 nota50=nota50+notadepositado50;
                                 nota10=nota10+notadepositado10;
                                 nota5=nota5+notadepositado5;
                                 nota1=nota1+notadepositado1;
                                 
                                 valordodepositado=notadepositado100*100+notadepositado50*50+notadepositado10*10+notadepositado5*5+notadepositado1*1;
                                 printf("Depositado %d ducas\n", valordodepositado);
                                 /*dinheiro que sobrou do caixa*/
                                 
                                 totaldinheiro=nota100*100+nota50*50+nota10*10+nota5*5+nota1*1;                                                                                
                                 printf("situação atual: %d %d %d %d %d           saldo: %d de ducas\n",nota100, nota50, nota10, nota5, nota1, totaldinheiro);


                                 /*atualizacao dos valores*/
                                 n100=nota100;
                                 n50=nota50;
                                 n10=nota10;
                                 n5=nota5;
                                 n1=nota1;
                                 }
                                 
                        } 
                  }               
system ("pause");
return 0;
}

   








                           
           
    
     
