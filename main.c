#include "estruturas.h"

/* gcc TestaListaSimples.c ListaSimples.c -o TestaListaSimples */


int main()
{
  int elem, continua=1, opcao, opcao2, chave;
  char cpf[20], nomeModalidade[50];

  while (continua) { 

    printf("Entre com uma das opcoes abaixo.\n");
    printf("0  - Sistema de cadastro de atletas.\n");
    printf("1  - Sistema de cadastro de modalidades.\n");
    printf("2  - Sistema de cadastro de equipes.\n");
    printf("3  - Sistema de cadastro de torneios.\n");
    printf("4  - Sistema de cadastro de jogos.\n");
    printf("5  - Sai do programa.\n\n");

    scanf("%d",&opcao);
    
    switch(opcao) {

    case 0:
        printf("Entre com uma das opcoes abaixo.\n");
        printf("0  - Cadastrar atleta.\n");
        printf("1  - Exibir atleta.\n");
        printf("2  - Exibir atletas.\n");
        printf("3  - Atualizar atleta. \n");
        printf("4  - Remover atleta. \n");
        
        scanf("%d", &opcao2);
        
        switch(opcao2){
            case 0:
                criarAtleta();
              break;
            case 1:
                printf("\nDigite o CPF do atleta: ");
                scanf("%s", cpf);
                exibirAtleta(cpf);
              break;
            case 2:
                exibirAtletas();
              break;
            case 3:
                printf("\nDigite o CPF do atleta: ");
                scanf("%s", cpf);
                atualizarAtleta(cpf);
              break;
            case 4:
                printf("\nDigite o CPF do atleta: ");
                scanf("%s", cpf);
                deletarAtleta(cpf);
              break;
        }
      break;
    case 1:
        
        printf("Entre com uma das opcoes abaixo.\n");
        printf("0  - Cadastrar modalidade.\n");
        printf("1  - Exibir modalidade.\n");
        printf("2  - Exibir modalidades.\n");
        printf("3  - Atualizar modalidade. \n");
        printf("4  - Deletar modalidade.\n");
        
        scanf("%d", &opcao2);
        
        switch(opcao2){
            case 0:
                criarModalidade();
              break;
            case 1:
                printf("\nDigite o nome da modalidade: ");
                scanf("%s", nomeModalidade);
                exibirModalidade(nomeModalidade);
              break;
            case 2:
                exibirModalidades();
              break;
            case 3:
                printf("\nDigite o nome da modalidade: ");
                scanf("%s", nomeModalidade);
                atualizarModalidade(nomeModalidade);
              break;
            case 4:
                printf("\nDigite o nome da modalidade: ");
                scanf("%s", nomeModalidade);
                deletarModalidade(nomeModalidade);
              break;
        }
      break;
    case 2:
        
        printf("Entre com uma das opcoes abaixo.\n");
        printf("0  - Cadastrar atleta.\n");
        printf("1  - Exibir atleta.\n");
        printf("2  - Atualizar atleta.\n");
        printf("3  - Remover atleta. \n");
        
        scanf("%d", &opcao2);
        
        switch(opcao2){
            case 0:
              break;
            case 1:
              break;
        }
      break;
    case 3:
        
        printf("Entre com uma das opcoes abaixo.\n");
        printf("0  - Cadastrar atleta.\n");
        printf("1  - Exibir atleta.\n");
        printf("2  - Atualizar atleta.\n");
        printf("3  - Remover atleta. \n");
        
        scanf("%d", &opcao2);
        
        switch(opcao2){
            case 0:
              break;
            case 1:
              break;
        }
    case 4:
        
        printf("Entre com uma das opcoes abaixo.\n");
        printf("0  - Cadastrar atleta.\n");
        printf("1  - Exibir atleta.\n");
        printf("2  - Atualizar atleta.\n");
        printf("3  - Remover atleta. \n");
        
        scanf("%d", &opcao2);
        
        switch(opcao2){
            case 0:
              break;
            case 1:
              break;
        }
      break;
    case 5:
        printf("Saindo do programa.");
        continua=0;
      break;
    default:
      printf("Opcao invalida\n");
    }

  }

return 0;
}