#include "estruturas.h"

void menuAtleta(){
    int opcao2;
    char cpf[20];
    printf("Entre com uma das opcoes abaixo.\n");
    printf("1  - Cadastrar atleta.\n");
    printf("2  - Exibir atleta.\n");
    printf("3  - Exibir atletas.\n");
    printf("4  - Atualizar atleta. \n");
    printf("5  - Remover atleta. \n");
    
    scanf("%d", &opcao2);
    
    switch(opcao2){
        case 1:
            criarAtleta();
          break;
        case 2:
            printf("\nDigite o CPF do atleta: ");
            scanf("%s", cpf);
            exibirAtleta(cpf);
          break;
        case 3:
            exibirAtletas();
          break;
        case 4:
            printf("\nDigite o CPF do atleta: ");
            scanf("%s", cpf);
            atualizarAtleta(cpf);
          break;
        case 5:
            printf("\nDigite o CPF do atleta: ");
            scanf("%s", cpf);
            deletarAtleta(cpf);
          break;
        default:
            printf("\nOpção inválida\n");
          break;
    }
}

void menuModalidade(){
    int opcao2;
    char nomeModalidade[50];
    
    printf("Entre com uma das opcoes abaixo.\n");
    printf("1  - Cadastrar modalidade.\n");
    printf("2  - Exibir modalidade.\n");
    printf("3  - Exibir modalidades.\n");
    printf("4  - Atualizar modalidade. \n");
    printf("5  - Deletar modalidade.\n");
    
    scanf("%d", &opcao2);
    
    switch(opcao2){
        case 1:
            criarModalidade();
          break;
        case 2:
            printf("\nDigite o nome da modalidade: ");
            scanf("%s", nomeModalidade);
            exibirModalidade(nomeModalidade);
          break;
        case 3:
            exibirModalidades();
          break;
        case 4:
            printf("\nDigite o nome da modalidade: ");
            scanf("%s", nomeModalidade);
            atualizarModalidade(nomeModalidade);
          break;
        case 5:
            printf("\nDigite o nome da modalidade: ");
            scanf("%s", nomeModalidade);
            deletarModalidade(nomeModalidade);
          break;
        default:
            printf("\nOpção inválida\n");
          break;
    }
}

void menuEquipe(){
    int opcao2;
    char nomeEquipe[50];
    
    printf("Entre com uma das opcoes abaixo.\n");
    printf("1  - Cadastrar equipe.\n");
    printf("2  - Exibir equipe.\n");
    printf("3  - Exibir equipes.\n");
    printf("4  - Atualizar equipe. \n");
    printf("5  - Deletar equipe. \n");
    printf("6  - Adicionar atleta a equipe. \n");
    printf("7  - Remover atleta da equipe. \n");
    
    scanf("%d", &opcao2);
    
    switch(opcao2){
        case 1:
            criarEquipe();
          break;
        case 2:
            printf("\nDigite o nome da equipe: ");
            scanf(" %[^\n]", nomeEquipe);
            exibirEquipe(nomeEquipe);
          break;
        case 3:
            exibirEquipes();
          break;
        case 4:
            printf("\nDigite o nome da equipe: ");
            scanf(" %[^\n]", nomeEquipe);
            atualizarEquipe(nomeEquipe);
          break;
        case 5:
            printf("\nDigite o nome da equipe: ");
            scanf(" %[^\n]", nomeEquipe);
            deletarEquipe(nomeEquipe);
          break;
        case 6:
            printf("\nDigite o nome da equipe: ");
            scanf(" %[^\n]", nomeEquipe);
            adicionarAtletaEquipe(nomeEquipe);
          break;
        case 7:
            printf("\nDigite o nome da equipe: ");
            scanf(" %[^\n]", nomeEquipe);
            removerAtletaEquipe(nomeEquipe);
          break;
        default:
            printf("\nOpção inválida\n");
          break;
    }
}

void menuTorneio(){
    int opcao2;
    char nomeTorneio[50];
    
    printf("Entre com uma das opcoes abaixo.\n");
    printf("1  - Cadastrar torneio.\n");
    printf("2  - Exibir torneio.\n");
    printf("3  - Exibir torneios.\n");
    printf("4  - Atualizar torneio. \n");
    printf("5  - Deletar torneio. \n");
    printf("6  - Adicionar equipe ao torneio. \n");
    printf("7  - Remover equipe do torneio. \n");
    
    scanf("%d", &opcao2);
    
    switch(opcao2){
        case 1:
            criarTorneio();
          break;
        case 2:
            printf("\nDigite o nome do torneio: ");
            scanf(" %[^\n]", nomeTorneio);
            exibirTorneio(nomeTorneio);
          break;
        case 3:
            exibirTorneios();
          break;
        case 4:
            printf("\nDigite o nome do torneio: ");
            scanf(" %[^\n]", nomeTorneio);
            atualizarTorneio(nomeTorneio);
          break;
        case 5:
            printf("\nDigite o nome do torneio: ");
            scanf(" %[^\n]", nomeTorneio);
            deletarTorneio(nomeTorneio);
          break;
        case 6:
            printf("\nDigite o nome do torneio: ");
            scanf(" %[^\n]", nomeTorneio);
            adicionarEquipeTorneio(nomeTorneio);
          break;
        case 7:
            printf("\nDigite o nome do torneio: ");
            scanf(" %[^\n]", nomeTorneio);
            removerEquipeTorneio(nomeTorneio);
          break;
        default:
            printf("\nOpção inválida\n");
          break;
    }
}

void menuJogo(){
    int opcao2;
    char idJogo[50];
    
    printf("Entre com uma das opcoes abaixo.\n");
    printf("1  - Cadastrar jogo.\n");
    printf("2  - Exibir jogo.\n");
    printf("3  - Exibir jogos do torneio.\n");
    printf("4  - Atualizar jogo.\n");
    printf("5  - Remover jogo. \n");
    printf("6  - Atualizar placar do jogo. \n");
    
    scanf("%d", &opcao2);
    
    switch(opcao2){
        case 1:
            criarJogo();
          break;
        case 2:
            printf("\nDigite o id do jogo: ");
            scanf(" %[^\n]", idJogo);
            exibirJogo(idJogo);
          break;
        case 3:
            exibirJogos();
          break;
        case 4:
            printf("\nDigite o id do jogo: ");
            scanf(" %[^\n]", idJogo);
            atualizarJogo(idJogo);
          break;
        case 5:
            printf("\nDigite o id do jogo: ");
            scanf(" %[^\n]", idJogo);
            deletarJogo(idJogo);
          break;
        case 6:
            printf("\nDigite o id do jogo: ");
            scanf(" %[^\n]", idJogo);
            atualizarPlacar(idJogo);
          break;
        default:
            printf("\nOpção inválida\n");
          break;
    }
}

int main()
{
  int elem, continua=1, opcao;

  while (continua) { 

    printf("Entre com uma das opcoes abaixo.\n");
    printf("1  - Sistema de cadastro de atletas.\n");
    printf("2  - Sistema de cadastro de modalidades.\n");
    printf("3  - Sistema de cadastro de equipes.\n");
    printf("4  - Sistema de cadastro de torneios.\n");
    printf("5  - Sistema de cadastro de jogos.\n");
    printf("6  - Sai do programa.\n\n");

    scanf("%d",&opcao);
    
    switch(opcao) {

    case 1:
        menuAtleta();
      break;
    case 2:
        menuModalidade();
      break;
    case 3:
        menuEquipe();
      break;
    case 4:
        menuTorneio();
      break;
    case 5:
        menuJogo();
      break;
    case 6:
        printf("Saindo do programa.");
        continua=0;
      break;
    default:
      printf("Opcao invalida\n");
    }

  }

return 0;
}