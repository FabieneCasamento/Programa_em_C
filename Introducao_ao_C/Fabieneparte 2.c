/*************************************************************/
/* Fabiene Francesca Casillo Casamento nº 5977187       *****/
/* Exercicio-Programa EP2                          ****** *******/
/* Curso Meteorologia - Turma ... - Profa. Yoshiko Wakabayashi */
/* **************************************************************/
/* Compilador: ................... *****************************/
/**************************************************************/
/*definido valores*/
#define passado_inicial 0.5977187
#define quantidadedecartas 40

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double passado, teto;
int contvitcomp, contvitcliente; /*verifica o quanto o computador ganhou e o quanto o cliente ganhou*/

/*como fazer o sorteio das cartas*/
int sorteiogeral()
{
	double x, seno, potx, fat, sorteio, carta;
	int i;

	x = passado;
	seno=0.0;						                          
	potx=x;
	fat=1.0;
	for(i=1; i <= quantidadedecartas;i++){
		seno = seno+potx/fat;
		/*printf("%d\n",seno);*/
		potx= -potx*x*x;
		fat=fat*(2*i)*(2*i+1);
	}

	sorteio=(9821.0 * fabs(seno) + 0.211327);
	passado = sorteio - floor(sorteio);
	 
	carta = floor(passado *10+1);
    /*system ("pause");*/
	return carta;
}

int main()
{
	int apostar, contador, ncartacliente, ncartacomp, i;
	double soma_comp, soma_cliente, carta;

	

	printf("\t\t                 CASSINO ROYALE\n");
	printf("\t\t                   SEVEN&HALF\n\n");
	printf("\n\n            ###############  HISTOGRAMA DO TETO %.1f  ###############   \n",teto);
    /******inicializacao do programa abaixo ******/

    for(teto=0.5;teto<=7.5;teto=teto+0.5)
    {
          passado = passado_inicial;

    	ncartacomp = 0;
	    ncartacliente = 0;
	    contvitcliente = 0;
	    contvitcomp = 0;
/*          printf("\n\n            ###############  HISTOGRAMA DO TETO %.1f  ###############   \n",teto);  */ 
          
     for(contador = 0; contador < 100; contador++)
	   {
        soma_comp=0;
        soma_cliente = 0;
	  /****** while(1)/*apostar ==1****/
       
		 /* printf ("\tDeseja apostar (1) sim (0) nao: \n");*/
		/******  *scanf("%d", &apostar);********/
           apostar=1;
           /*printf("APOSTA %d  \n",apostar);*/
		   
		   if ( soma_cliente < teto)
		   {
               apostar=1;
           }
           else if(soma_cliente <= teto)
           {  
             if( soma_cliente +0.5 == teto || soma_cliente + 1 == teto || soma_cliente == teto)
                 apostar=0;
           }
          /*printf("TESTE     CONTADOR  %d ---   TETO%g    \n",contador,teto);*/
          /*apostar=1;*/
          

          while(apostar == 1)/*if*/
		  {
           
			/*printf("JOGAR CLIENTE\n");*/
			carta = (double)sorteiogeral();
            
			if (carta == 8)
			{
				/*printf("Carta = Q\n");*/
				carta = 0.5; 
			}
			else if (carta == 9)
			{
				/*printf("Carta = J\n");*/
				carta = 0.5; 
			}
			else if (carta == 10)
			{
				/*printf("Carta = k\n");*/
				carta = 0.5; 
			}
			else if (carta == 1)
			{
				/*printf("Carta = A\n");*/
			}
			else 
			{
			/*	printf("Carta = %g\n", carta);*/
			}
           

			
			soma_cliente += carta;
			/*printf("soma_cli: %g\n", soma_cliente);*/
			ncartacliente++;
            if(soma_cliente <=  teto  )
            {
               if( soma_cliente +0.5 == teto || soma_cliente + 1 == teto ||soma_cliente==teto)
               {
                      apostar=0;
          /*            printf ("DESISTE CLIENTE");*/
               } 
            }
			if(soma_cliente > teto)
			{
			/*	printf("Cliente Perdeu! GAME OVER\n");*/
                /*apostar=1;*/
                break;
			 	system ("pause");
				/*return 0;*/
				
			}

          }
		 
       
       /********** Jogada do computador ***********/
       if(apostar==0)
       {
       /*printf("computador jogando");*/
    
	    	soma_comp = 0;
		    ncartacomp = 0;

		    while(soma_comp <= teto && soma_comp < soma_cliente )
		    {
			        /*printf("Computador jogando...\n");*/
			
			        carta = (double)sorteiogeral();
			
		       	    if (carta == 8)
			        {
				      /*   printf("Carta = Q\n");*/
				         carta = 0.5;
                    } 
			        else if (carta == 9)
			        {
	                     /*printf("Carta = J\n");*/
				         carta = 0.5;
                    }
			        else if (carta == 10)
			        {
				         /*printf("Carta = k\n");*/
				         carta = 0.5;
			        }
			        else if (carta == 1)
      			    {
				         /*printf("Carta = A\n");*/
			        }
		            else
			        {
				       /*  printf("Carta = %g\n", carta);*/
			        }
			
			        soma_comp += carta;
			        /*printf("soma_comp: %g\n", soma_comp);*/
			        ncartacomp++;

			        if(soma_comp == soma_cliente)
			        {
                           if(ncartacomp <= ncartacliente)
				           {
					  /*         printf("+Computador ganhou!!!\n");*/
					           contvitcomp++;
					           break;
			               }

			        }
			        else if(soma_comp > soma_cliente && soma_comp <= teto)
			        {
				           /* printf("++Computador ganhou\n");*/
			                contvitcomp++;
			                break;
			        }
			        else if(soma_comp > teto )
			        {
				            /*printf("+++Computador Perdeu\n");*/
				            contvitcliente++;
			               	break;
			        }
                    else if(contvitcliente >=100)
                    {
                        contvitcliente=0;
                        contvitcomp=0;
                    }     																									
		    }
            /*printf("TESTE    COMPUTADOR JOGANDO");*/
        }
		    /*printf("\nSomacomp: %g | Soma_cliente: %g\n", soma_comp, soma_cliente);*/
	   }
    
       printf("| Teto = %.1f || Vitoria do Cliente = %d |",teto,contvitcliente);
	   
       for(i = 0; i < contvitcliente && contvitcliente <100; i++)
	   {
	        	printf("*");
	   }
               printf("\n");                               
    }
    printf("\n");                                     
	system	("pause");
	return 0;
}

















