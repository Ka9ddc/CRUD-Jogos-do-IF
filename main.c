#include "estruturas.h"

/* gcc TestaListaSimples.c ListaSimples.c -o TestaListaSimples */


int main()
{
  int elem, continua=1, opcao, opcao2, chave;
  char cpf[20], nomeModalidade[50], nomeEquipe[50], nomeTorneio[50];

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
        printf("0  - Cadastrar equipe.\n");
        printf("1  - Exibir equipe.\n");
        printf("2  - Exibir equipes.\n");
        printf("3  - Atualizar equipe. \n");
        printf("4  - Deletar equipe. \n");
        printf("5  - Adicionar atleta a equipe. \n");
        printf("6  - Remover atleta da equipe. \n");
        
        scanf("%d", &opcao2);
        
        switch(opcao2){
            case 0:
                criarEquipe();
              break;
            case 1:
                printf("\nDigite o nome da equipe: ");
                scanf(" %[^\n]", nomeEquipe);
                exibirEquipe(nomeEquipe);
              break;
            case 2:
                exibirEquipes();
              break;
            case 3:
                printf("\nDigite o nome da equipe: ");
                scanf(" %[^\n]", nomeEquipe);
                atualizarEquipe(nomeEquipe);
              break;
            case 4:
                printf("\nDigite o nome da equipe: ");
                scanf(" %[^\n]", nomeEquipe);
                deletarEquipe(nomeEquipe);
              break;
            case 5:
                printf("\nDigite o nome da equipe: ");
                scanf(" %[^\n]", nomeEquipe);
                adicionarAtletaEquipe(nomeEquipe);
              break;
            case 6:
                printf("\nDigite o nome da equipe: ");
                scanf(" %[^\n]", nomeEquipe);
                removerAtletaEquipe(nomeEquipe);
              break;
        }
      break;
    case 3:
        
        printf("Entre com uma das opcoes abaixo.\n");
        printf("0  - Cadastrar torneio.\n");
        printf("1  - Exibir torneio.\n");
        printf("2  - Exibir torneios.\n");
        printf("3  - Atualizar torneio. \n");
        printf("4  - Deletar torneio. \n");
        printf("5  - Adicionar equipe ao torneio. \n");
        printf("6  - Remover equipe do torneio. \n");
        
        scanf("%d", &opcao2);
        
        switch(opcao2){
            case 0:
                criarTorneio();
              break;
            case 1:
                printf("\nDigite o nome do torneio: ");
                scanf(" %[^\n]", nomeTorneio);
                exibirTorneio(nomeTorneio);
              break;
            case 2:
                exibirTorneios();
              break;
            case 3:
                printf("\nDigite o nome do torneio: ");
                scanf(" %[^\n]", nomeTorneio);
                atualizarTorneio(nomeTorneio);
              break;
            case 4:
                printf("\nDigite o nome do torneio: ");
                scanf(" %[^\n]", nomeTorneio);
                deletarTorneio(nomeTorneio);
              break;
            case 5:
                printf("\nDigite o nome do torneio: ");
                scanf(" %[^\n]", nomeTorneio);
                adicionarEquipeTorneio(nomeTorneio);
              break;
            case 6:
                printf("\nDigite o nome do torneio: ");
                scanf(" %[^\n]", nomeTorneio);
                removerEquipeTorneio(nomeTorneio);
              break;
        }
        break;
    case 4:
        
        printf("Entre com uma das opcoes abaixo.\n");
        printf("0  - Cadastrar jogo.\n");
        printf("1  - Exibir jogo.\n");
        printf("1  - Exibir jogos do torneio.\n");
        printf("2  - Atualizar jogo.\n");
        printf("3  - Remover jogo. \n");
        
        scanf("%d", &opcao2);
        
        switch(opcao2){
            case 0:
              criarJogo();
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