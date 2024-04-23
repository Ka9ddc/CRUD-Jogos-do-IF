#include "estruturas.h"

/* gcc TestaListaSimples.c ListaSimples.c -o TestaListaSimples */


int main()
{
  Atletas *inicio=NULL;
  int elem, continua=1, opcao, chave;

  while (continua) { 

    printf("Entre com uma das opcoes abaixo.\n");
    printf("0  - Sistema de cadastro de atletas.\n");
    printf("1  - Sistema de cadastro de modalidades.\n");
    printf("2  - Sistema de cadastro de equipes.\n");
    printf("3  - Sistema de cadastro de torneios. \n");
    printf("4  - Sistema de cadastro de jogos \n");
    printf("5  - Buscar o ultimo elemento na lista \n");
    printf("6  - Remove elemento do inicio da lista\n");
    printf("7  - Remove elemento do final da lista\n");
    printf("8  - Remove um dado elemento da lista\n");
    printf("9  - Destroi a lista\n");
    printf("10 - Sai do programa\n\n");

    scanf("%d",&opcao);
    
    switch(opcao) { 

    case 0:
      printf("Entre com o elemento a ser inserido\n");
      scanf("%d",&elem);
      InsereInicioListaSimples(&inicio, elem);
      break;
    case 1:
      printf("Opção a ser implementada!");
      break;
    case 2:
      printf("Opção a ser implementada!");
      break;
    case 3:
      printf("Opção a ser implementada!");
    case 4:
        printf("Opção a ser implementada!");
      break;
    default:
      printf("Opcao invalida\n");
    }

  }

return 0;
}