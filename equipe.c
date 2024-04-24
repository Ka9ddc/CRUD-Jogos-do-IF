#define TAMANHO 50

#include "estruturas.h"

void criarEquipe() {
    if (numEquipes >= MAX_EQUIPES) {
        printf("\nO numero maximo de equipes foi alcançado!\n");
    } else {
        char nomeModalidade[TAMANHO]; // Correção: Deve ser uma string
        Modalidade *modalidade; // Correção: Deve ser um ponteiro para Modalidade
        Equipe novaEquipe;
        printf("\nDigite o nome da equipe: ");
        scanf(" %[^\n]", novaEquipe.nome);
        printf("\nDigite a sigla da equipe: ");
        scanf(" %[^\n]", novaEquipe.sigla);
        printf("\nDigite a modalidade da equipe");
        scanf(" %[^\n]", nomeModalidade);
        modalidade = retornarModalidade(nomeModalidade); // Correção: retornarModalidade retorna um ponteiro
        if (!modalidade) {
            printf("Essa modalidade não existe!");
        } else {
            novaEquipe.modalidade = modalidade; // Correção: Atribua o valor apontado pelo ponteiro
            novaEquipe.numAtletasEquipe = 0;
            equipes[numEquipes++] = novaEquipe;
            printf("\nEquipe criada!\n");
        }
    }
}

Equipe * retornarEquipe(char* nome) {
    int found = 0;
    Equipe * equipeRetornada = NULL;
    for (int i = 0; i < numEquipes; i++) {
        if (strcmp(equipes[i].nome, nome) == 0) {
            found = 1;
            equipeRetornada = &equipes[i];
            return equipeRetornada;
        }
    }
    if (!found) {
        printf("Nenhuma equipe encontrado com o nome: %s.\n", nome);
    }
    
    return NULL;
}

void adicionarAtletaEquipe() {
    char nomeEquipe[TAMANHO]; // Correção: Deve ser uma string
    Equipe *equipe; // Correção: Deve ser um ponteiro para Equipe
    printf("\nDigite o nome da equipe: ");
    scanf(" %[^\n]", nomeEquipe);
    equipe = retornarEquipe(nomeEquipe); // Correção: retornarEquipe retorna um ponteiro
    if (!equipe) {
        printf("\nNenhuma equipe com esse nome foi encontrada!\n");
        return;
    }

    if (equipe->numAtletasEquipe >= equipe->modalidade->numAtletasPorEquipe) {
        printf("\nO numero maximo de atletas nessa equipe foi alcançado!\n");
    } else {
        char nomeAtleta[TAMANHO]; // Correção: Deve ser uma string
        Atleta *adicionarAtleta; // Correção: Deve ser um ponteiro para Atleta
        printf("\nDigite o nome do atleta a ser adicionado: ");
        scanf(" %[^\n]", nomeAtleta);
        adicionarAtleta = retornarAtleta(nomeAtleta); // Correção: retornarAtleta retorna um ponteiro
        if (!adicionarAtleta) {
            printf("Atleta não encontrado!");
        } else if (adicionarAtleta->possuiEquipe) {
            printf("Esse atleta já possui uma equipe!");
        } else {
            adicionarAtleta->possuiEquipe = true;
            equipe->atletas[equipe->numAtletasEquipe++] = adicionarAtleta; // Correção: Atribua o valor apontado pelo ponteiro
            printf("Atleta adicionado a equipe com sucesso!");
        }
    }
}

void exibirEquipes() {
    for (int i = 0; i < numEquipes; i++) {
        printf("Nome da equipe: %s\n", equipes[i].nome);
        printf("Sigla da equipe: %s\n", equipes[i].sigla);
        printf("Modalidade da equipe: %s\n", equipes[i].modalidade->nome); // Correção: Acessar o campo desejado da modalidade
        printf("Atletas da Equipe:\n");
        for (int j = 0; j < equipes[i].numAtletasEquipe; j++) {
            printf("%s\n", equipes[i].atletas[j]->nome); // Correção: Acessar o campo desejado do atleta
        }
    }
}
