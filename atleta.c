#include "estruturas.h"

Atleta criarAtleta(){
    if(numAtletas >= MAX_ATLETAS){
        printf("\nO numero maximo de atletas cadastrado foi alcançado.\n");
    } else {
        Atleta novoAtleta;
        printf("Entre com o nome do atleta: ");
        scanf(" %[^\n]", novoAtleta.nome);
        printf("Entre com o CPF do atleta (XXX.XXX.XXX-XX): ");
        scanf("%s", novoAtleta.cpf);
        printf("Entre com o sexo do atleta (m/f): ");
        scanf(" %c", &novoAtleta.sexo);
        printf("Entre com a instituição de ensino: ");
        scanf(" %[^\n]", novoAtleta.instituicaoEnsino);
        printf("Entre com a data de nascimento (DD/MM/AAAA): ");
        scanf("%s", novoAtleta.dataNascimento);

        atletas[numAtletas++] = novoAtleta;
        printf("Atleta cadastrado com sucesso!\n");
    
        return novoAtleta;
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
            printf("Instituição de Ensino: %s\n", atletas[i].instituicaoEnsino);
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
    for (int i = 0; i < numAtletas; i++) {
        printf("Atleta %d: %s, %s, %c, %s, %s\n", i + 1, atletas[i].nome, atletas[i].cpf, atletas[i].sexo, atletas[i].instituicaoEnsino, atletas[i].dataNascimento);
    }
}

void atualizarAtleta(char* cpf) {
    int found = 0;
    for (int i = 0; i < numAtletas; i++) {
        if (strcmp(atletas[i].cpf, cpf) == 0) {
            printf("\n---FORMULARIO ATUALIZAR ATLETA---:\n");
            printf("Entre com o nome do atleta: ");
            scanf(" %[^\n]", atletas[i].nome);
            printf("Entre com o CPF do atleta (XXX.XXX.XXX-XX): ");
            scanf("%s", atletas[i].cpf);
            printf("Entre com o sexo do atleta (m/f): ");
            scanf(" %c", &atletas[i].sexo);
            printf("Entre com a instituição de ensino: ");
            scanf(" %[^\n]", atletas[i].instituicaoEnsino);
            printf("Entre com a data de nascimento (DD/MM/AAAA): ");
            scanf("%s", atletas[i].dataNascimento);
            found = 1;
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