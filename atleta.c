#include "estruturas.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool validarCPF(const char* cpf) {
    int len = strlen(cpf);

    if (len != 14){
        printf("\nO cpf nao possui o tamanho correto.\n");
        return false;
        }
    
    if (cpf[3] != '.' || cpf[7] != '.' || cpf[11] != '-'){
        printf("\nO CPF nao esta no formato correto\n");
        return false;
    }
    
    for (int i = 0; i < 14; i++) {
        if (i == 3 || i == 7 || i == 11) {
            continue;
        }
        if (!isdigit(cpf[i])) {
            printf("\nO digito %d esta errado.\n", i);
            return false;
        }
    }
    
    return true;
}

bool validarData(const char* data) {
    int len = strlen(data);

    if (len != 10){
        return false;
    }
    
    if (data[2] != '/' || data[5] != '/'){
        return false;
    }
    
    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) {
            continue;
        }
        if (!isdigit(data[i])) {
            return false;
        }
    }
    
    return true;
}

void criarAtleta(){
    if(numAtletas >= MAX_ATLETAS){
        printf("\nO numero maximo de atletas cadastrado foi alcancado.\n");
    } else {
        Atleta novoAtleta;
        printf("\nEntre com o nome do atleta: ");
        scanf(" %[^\n]", novoAtleta.nome);
        printf("\nEntre com o CPF do atleta (XXX.XXX.XXX-XX): ");
        scanf("%s", novoAtleta.cpf);
        if(!validarCPF(novoAtleta.cpf)){
            printf("\nCPF invalido!\n");
            return;
        }
        printf("\nEntre com o sexo do atleta (m/f): ");
        scanf(" %c", &novoAtleta.sexo);
        printf("\nEntre com a instituicao de ensino: ");
        scanf(" %[^\n]", novoAtleta.instituicaoEnsino);
        printf("\nEntre com a data de nascimento (DD/MM/AAAA): ");
        scanf("%s", novoAtleta.dataNascimento);
        if(!validarData(novoAtleta.dataNascimento)){
            printf("\nData de nascimento invalida!\n");
            return;
        }
        novoAtleta.possuiEquipe = false;

        atletas[numAtletas++] = novoAtleta;
        printf("\nAtleta cadastrado com sucesso!\n");
    }
    
};

void exibirAtleta(char* cpf) {
    int found = 0;
    for (int i = 0; i < numAtletas; i++) {
        if (strcmp(atletas[i].cpf, cpf) == 0) {
            printf("Atleta encontrado:\n");
            printf("Nome: %s\n", atletas[i].nome);
            printf("CPF: %s\n", atletas[i].cpf);
            printf("Sexo: %c\n", atletas[i].sexo);
            printf("Instituicao de Ensino: %s\n", atletas[i].instituicaoEnsino);
            printf("Data de Nascimento: %s\n", atletas[i].dataNascimento);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Nenhum atleta encontrado com o CPF %s.\n", cpf);
    }
}

void exibirAtletas() {
    printf("\n------------ ATLETAS ------------\n");
    for (int i = 0; i < numAtletas; i++) {
        printf("Atleta %d: %s, %s, %c, %s, %s\n", i + 1, atletas[i].nome, atletas[i].cpf, atletas[i].sexo, atletas[i].instituicaoEnsino, atletas[i].dataNascimento);
    }
    printf("\n------------ FIM ATLETAS ------------\n");
}

void atualizarAtleta(char* cpf) {
    Atleta atualizarAtleta;
    int found = 0;
    for (int i = 0; i < numAtletas; i++) {
        if (strcmp(atletas[i].cpf, cpf) == 0) {
            printf("\n---FORMULARIO ATUALIZAR ATLETA---:\n");
            printf("Entre com o nome do atleta: ");
            scanf(" %[^\n]", atualizarAtleta.nome);
            printf("Entre com o CPF do atleta (XXX.XXX.XXX-XX): ");
            scanf("%s", atualizarAtleta.cpf);
            if(!validarCPF(atualizarAtleta.cpf)){
            printf("\nCPF invalido!\n");
            return;
            }
            printf("Entre com o sexo do atleta (m/f): ");
            scanf(" %c", &atualizarAtleta.sexo);
            printf("Entre com a instituicao de ensino: ");
            scanf(" %[^\n]", atualizarAtleta.instituicaoEnsino);
            printf("Entre com a data de nascimento (DD/MM/AAAA): ");
            scanf("%s", atualizarAtleta.dataNascimento);
            if(!validarData(atualizarAtleta.dataNascimento)){
            printf("\nData de nascimento invalida!\n");
            return;
            }
            found = 1;
            
            atletas[i] = atualizarAtleta;
            
            printf("Atleta atualizado com sucesso!");
            break;
        }
    }
    if (!found) {
        printf("Nenhum atleta encontrado com o CPF %s.\n", cpf);
    }
}

void deletarAtleta(char* cpf) {
    int found = 0;
    
    for (int i = 0; i < numAtletas; i++) {
        if (strcmp(atletas[i].cpf, cpf) == 0) {
            for (int j = i; j < numAtletas - 1; j++) {
                atletas[j] = atletas[j + 1];
            }
            numAtletas--;
            printf("Atleta com CPF %s deletado com sucesso.\n", cpf);
            return;
        }
    }
    
    if (!found) {
        printf("Nenhum atleta encontrado com o CPF %s.\n", cpf);
    }
}

Atleta * retornarAtleta(char* cpf) {
    int found = 0;
    Atleta * atletaRetornado = NULL;
    for (int i = 0; i < numAtletas; i++) {
        if (strcmp(atletas[i].cpf, cpf) == 0) {
            found = 1;
            atletaRetornado = &atletas[i];
            return atletaRetornado;
        }
    }
    if (!found) {
        printf("Nenhum atleta encontrado com o CPF %s.\n", cpf);
    }
    
    return NULL;
}