#define TAMANHO 50

#include "estruturas.h"

void criarEquipe() {
    if (numEquipes >= MAX_EQUIPES) {
        printf("\nO numero maximo de equipes foi alcancado!\n");
        return;
    }

    Equipe *novaEquipe = (Equipe *)malloc(sizeof(Equipe));
    if (!novaEquipe) {
        printf("\nErro ao alocar memoria para nova equipe!\n");
        return;
    }

    printf("\nDigite o nome da equipe: ");
    scanf(" %[^\n]", novaEquipe->nome);
    printf("\nDigite a sigla da equipe: ");
    scanf(" %[^\n]", novaEquipe->sigla);

    char nomeModalidade[TAMANHO];
    printf("\nDigite a modalidade da equipe: ");
    scanf(" %[^\n]", nomeModalidade);
    novaEquipe->modalidade = retornarModalidade(nomeModalidade);

    if (!novaEquipe->modalidade) {
        printf("Essa modalidade nao existe!\n");
        free(novaEquipe);
        return;
    }

    novaEquipe->numAtletasEquipe = 0;
    int maxAtletasPorEquipe = novaEquipe->modalidade->numAtletasPorEquipe;
    novaEquipe->atletas = (Atleta **)malloc(maxAtletasPorEquipe * sizeof(Atleta *));
    if (!novaEquipe->atletas) {
        printf("\nErro ao alocar memoria para os atletas da equipe!\n");
        free(novaEquipe);
        return;
    }

    for (int i = 0; i < maxAtletasPorEquipe; i++) {
        novaEquipe->atletas[i] = NULL;
    }

    equipes[numEquipes++] = *novaEquipe;
    printf("\nEquipe criada!\n");
}

Equipe * retornarEquipe(char* sigla) {
    int found = 0;
    Equipe * equipeRetornada = NULL;
    for (int i = 0; i < numEquipes; i++) {
        if (strcmp(equipes[i].sigla, sigla) == 0) {
            found = 1;
            equipeRetornada = &equipes[i];
            return equipeRetornada;
        }
    }
    if (!found) {
        printf("Nenhuma equipe encontrado com a sigla: %s.\n", sigla);
    }
    
    return NULL;
}

void exibirEquipe(char *sigla){
    Equipe *equipe;
    equipe = retornarEquipe(sigla);
    if(equipe){
        printf("\nNome da equipe: %s\n", equipe->nome);
        printf("\nSigla da equipe: %s\n", equipe->sigla);
        printf("\nModalidade da equipe: %s\n", equipe->modalidade->nome);
        printf("\nAtletas da equipe: \n");
        for (int i = 0; i < equipe->numAtletasEquipe; i++)
        {
            printf("%s\n", equipe->atletas[i]->nome);
        }
        
    }

}


void exibirEquipes() {
    printf("\n------------ EQUIPES ------------\n");
    for (int i = 0; i < numEquipes; i++) {
        printf("\nNome da equipe: %s\n", equipes[i].nome);
        printf("Sigla da equipe: %s\n", equipes[i].sigla);
        printf("Modalidade da equipe: %s\n", equipes[i].modalidade->nome);
        printf("Atletas da Equipe:\n");
        for (int j = 0; j < equipes[i].numAtletasEquipe; j++) {
            if (equipes[i].atletas[j] != NULL) {
                printf("\t%s\n", equipes[i].atletas[j]->nome);
            }
        }
    }
    printf("\n------------ FIM EQUIPES ------------\n");
}

void atualizarEquipe(char *sigla) {
    int found = 0;
    char nomeModalidade[TAMANHO];
    for (int i = 0; i < numEquipes; i++)
    {
        if(strcmp(equipes[i].sigla, sigla) == 0){
            printf("\n---FORMULARIO PARA ATUALIZAR EQUIPE---\n");
            printf("\nDigite o nome da equipe:");
            scanf(" %[^\n]", equipes[i].nome);
            printf("\nDigite a sigla da equipe: ");
            scanf(" %[^\n]", equipes[i].sigla);
            printf("\nDigite a modalidade da equipe: ");
            scanf(" %[^\n]", nomeModalidade);
            if(!retornarModalidade(nomeModalidade)){
                printf("\nModalidade invalida!\n");
            } else {
                equipes[i].modalidade = retornarModalidade(nomeModalidade);
            }
            found = 1;
            printf("Equipe atualizada com sucesso!");
            break;
        }
    }
    if(!found){
        printf("\nNenhuma equipe com a sigla fornecida foi encontrada!\n");
    }
    
}

void liberarEquipe(Equipe *equipe) {
    if (equipe) {
        free(equipe->atletas);
        free(equipe);
    }
}

void deletarEquipe(char *sigla) {
    int found = 0;
    for (int i = 0; i < numEquipes; i++) {
        if (strcmp(equipes[i].sigla, sigla) == 0) {
            liberarEquipe(&equipes[i]);
            for (int j = i; j < numEquipes - 1; j++) {
                equipes[j] = equipes[j + 1];
            }
            numEquipes--;
            found = 1;
            printf("Equipe deletada com sucesso!\n");
            break;
        }
    }
    if (!found) {
        printf("\nNenhuma equipe com a sigla fornecida foi encontrada!\n");
    }
}

void adicionarAtletaEquipe(char *sigla) {
    Equipe *equipe = retornarEquipe(sigla); 
    if (!equipe) {
        return;
    }

    if (equipe->numAtletasEquipe >= equipe->modalidade->numAtletasPorEquipe) {
        printf("\nO número maximo de atletas nessa equipe foi alcancado!\n");
        return;
    }

    char cpf[TAMANHO];
    Atleta *adicionarAtleta;

    printf("\nDigite o CPF do atleta a ser adicionado: ");
    scanf(" %[^\n]", cpf);
    adicionarAtleta = retornarAtleta(cpf);

    if (!adicionarAtleta) {
        printf("Atleta nao encontrado!\n");
    } else if (adicionarAtleta->possuiEquipe) {
        printf("Esse atleta ja possui uma equipe!\n");
    } else {
        adicionarAtleta->possuiEquipe = true;
        equipe->atletas[equipe->numAtletasEquipe++] = adicionarAtleta;
        printf("Atleta adicionado à equipe com sucesso!\n");
    }
}

void removerAtletaEquipe(char *sigla){
    int found = 0;
    char cpf[TAMANHO];
    Equipe *equipe;
    equipe = retornarEquipe(sigla);
    if(!equipe){
        return;
    }
    printf("\nDigite o CPF do atleta a ser removido: ");
    scanf(" %[^\n]", cpf);
    for(int i = 0; i < equipe->numAtletasEquipe; i++){
        if(strcmp(cpf, equipe->atletas[i]->cpf) == 0){
            equipe->atletas[i]->possuiEquipe = false;
            printf("\nO atleta a ser removido é: %s\n", equipe->atletas[i]->nome);
            for (int j = i; j < equipe->numAtletasEquipe - 2; j++)
            {
                equipe->atletas[j] = equipe->atletas[j+1];
            }
            found = 1;
            equipe->numAtletasEquipe--;
            printf("\nAtleta removido com sucesso!\n");
            break;
        }
    }
}