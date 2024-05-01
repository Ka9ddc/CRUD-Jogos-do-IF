#define TAMANHO 50

#include "estruturas.h"

void criarEquipe() {
    if (numEquipes >= MAX_EQUIPES) {
        printf("\nO numero maximo de equipes foi alcançado!\n");
    } else {
        char nomeModalidade[TAMANHO];
        Modalidade *modalidade;
        Equipe novaEquipe;
        printf("\nDigite o nome da equipe: ");
        scanf(" %[^\n]", novaEquipe.nome);
        printf("\nDigite a sigla da equipe: ");
        scanf(" %[^\n]", novaEquipe.sigla);
        printf("\nDigite a modalidade da equipe");
        scanf(" %[^\n]", nomeModalidade);
        modalidade = retornarModalidade(nomeModalidade);
        if (!modalidade) {
            printf("Essa modalidade não existe!");
        } else {
            novaEquipe.modalidade = modalidade;
            novaEquipe.numAtletasEquipe = 0;
            equipes[numEquipes++] = novaEquipe;
            printf("\nEquipe criada!\n");
        }
    }
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
    for (int i = 0; i < numEquipes; i++) {
        printf("\nNome da equipe: %s\n", equipes[i].nome);
        printf("Sigla da equipe: %s\n", equipes[i].sigla);
        printf("Modalidade da equipe: %s\n", equipes[i].modalidade->nome);
        printf("Atletas da Equipe:\n");
        for (int j = 0; j < equipes[i].numAtletasEquipe; j++) {
            printf("%s\n", equipes[i].atletas[j]->nome); 
        }
    }
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
                printf("\nModalidade inválida!\n");
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

void deletarEquipe(char *sigla) {
    int found = 0;
    char nomeModalidade[TAMANHO];
    for (int i = 0; i < numEquipes; i++)
    {
        if(strcmp(equipes[i].sigla, sigla) == 0){
            for (int j = i; j < numEquipes - 1; j++)
            {
                equipes[j] = equipes[j+1];
            }
            numEquipes--;
            found = 1;
            printf("Equipe deletada com sucesso!");
        }
    }
    if(!found){
        printf("\nNenhuma equipe com a sigla fornecida foi encontrada!\n");
    }
    
}

void adicionarAtletaEquipe(char *sigla) {
    Equipe *equipe;
    equipe = retornarEquipe(sigla); 
    if (!equipe) {
        return;
    }

    if (equipe->numAtletasEquipe >= equipe->modalidade->numAtletasPorEquipe) {
        printf("\nO numero maximo de atletas nessa equipe foi alcançado!\n");
    } else {
        char cpf[TAMANHO];
        Atleta *adicionarAtleta;
        printf("\nDigite o CPF do atleta a ser adicionado: ");
        scanf(" %[^\n]", cpf);
        adicionarAtleta = retornarAtleta(cpf);
        if (!adicionarAtleta) {
            printf("Atleta não encontrado!");
        } else if (adicionarAtleta->possuiEquipe) {
            printf("Esse atleta já possui uma equipe!");
        } else {
            adicionarAtleta->possuiEquipe = true;
            equipe->atletas[equipe->numAtletasEquipe++] = adicionarAtleta;
            printf("Atleta adicionado a equipe com sucesso!");
        }
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