#include "estruturas.h"
#include <stdlib.h> // Para alocação dinâmica de memória

Modalidade *criarModalidade() {
    if (numModalidades >= MAX_MODALIDADES) {
        printf("O numero maximo de modalidades foi alcançado!");
        return NULL;
    }

    Modalidade *novaModalidade = (Modalidade *)malloc(sizeof(Modalidade)); // Aloca memória dinamicamente
    if (novaModalidade == NULL) {
        printf("Erro ao alocar memoria para a nova modalidade!");
        return NULL;
    }

    printf("\nEntre com o nome da modalidade:\n");
    scanf(" %[^\n]", novaModalidade->nome);
    printf("Entre com o numero de atletas por equipe:\n");
    scanf("%d", &novaModalidade->numAtletasPorEquipe);

    modalidades[numModalidades++] = *novaModalidade; // Copia a nova modalidade para o array
    printf("Modalidade cadastrada com sucesso!");

    return novaModalidade;
}

void exibirModalidade(char *nome) {
    int found = 0;
    for (int i = 0; i < numModalidades; i++) {
        if (strcmp(modalidades[i].nome, nome) == 0) {
            printf("\nNome da modalidade: %s", modalidades[i].nome);
            printf("\nNumero de atletas por equipe: %d\n", modalidades[i].numAtletasPorEquipe);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nNenhuma modalidade com esse nome foi encontrada!\n");
    }
}

void exibirModalidades() {
    if (numModalidades == 0) {
        printf("\nNão há modalidades cadastradas!\n");
    } else {
        for (int i = 0; i < numModalidades; i++) {
            printf("\nNome da modalidade: %s", modalidades[i].nome);
            printf("\nNumero de atletas por equipe: %d\n", modalidades[i].numAtletasPorEquipe);
        }
    }
}

// Função para atualizar uma modalidade existente
void atualizarModalidade(char *nome) {
    for (int i = 0; i < numModalidades; i++) {
        if (strcmp(modalidades[i].nome, nome) == 0) {
            printf("\n---FORMULARIO PARA ATUALIZAR MODALIDADE---\n");
            printf("\nDigite o novo nome da modalidade: ");
            scanf(" %[^\n]", modalidades[i].nome);
            printf("\nDigite o novo numero de atletas por equipe: ");
            scanf("%d", &modalidades[i].numAtletasPorEquipe);
            printf("Modalidade atualizada com sucesso!");
            return;
        }
    }
    printf("Nenhuma modalidade com esse nome foi encontrada!");
}

// Função para excluir uma modalidade existente
void deletarModalidade(char *nome) {
    int found = 0;
    for (int i = 0; i < numModalidades; i++) {
        if (strcmp(modalidades[i].nome, nome) == 0) {
            for (int j = i; j < numModalidades - 1; j++) {
                modalidades[j] = modalidades[j + 1];
            }
            numModalidades--;
            found = 1;
            printf("Modalidade deletada com sucesso!");
            break;
        }
    }
    if (!found) {
        printf("Nenhuma modalidade com esse nome foi encontrada!");
    }
}

Modalidade *retornarModalidade(char *nome) {
    for (int i = 0; i < numModalidades; i++) {
        if (strcmp(modalidades[i].nome, nome) == 0) {
            return &modalidades[i];
        }
    }
    printf("\nNenhuma modalidade com esse nome foi encontrada!\n");
    return NULL;
}
