#include "estruturas.h"

Atleta *criarAtleta(Atleta **inicio){
    Atleta *novoAtleta = malloc(sizeof(Atleta));
    if(novoAtleta){
        novoAtleta->proximo = NULL;
        printf("\nDigite o nome do atleta: ");
        scanf("%s", novoAtleta->nome);
        printf("\nDigite o cpf do atleta: ");
        scanf("%s", novoAtleta->cpf);
        printf("\nDigite o sexo do atleta: 'm' para masculino e 'f' para feminino: ");
        scanf("%c", novoAtleta->sexo);
        printf("\nDigite o nome da instituição do atleta: ");
        scanf("%s", novoAtleta->instituicaoEnsino);
        printf("\nDigite a data de nascimento do atleta: ");
        scanf("%s", novoAtleta->dataNascimeto);
        if(*inicio == NULL){
            *inicio = novoAtleta;
        } else {
            Atleta *aux;
            aux = *inicio;
            while(aux->proximo){
                aux = aux->proximo;
            }
            aux->proximo = novoAtleta;
        }
    } else {
        printf("\nErro ao alocar memoria!\n");
    }

    return novoAtleta;
    
};

Atleta * identificarAtletaCPF(Atleta **inicio, char CPF[15]){
    Atleta *aux;
    aux = *inicio;
    while(aux != NULL || aux->cpf != CPF){
        aux = aux->proximo;
    }

    return aux;
}

void editarAtleta(Atleta **inicio, char CPF[15]){
    Atleta *atleta = identificarAtletaCPF(&inicio, CPF);
    if(atleta == NULL){
        printf("\nO atleta com o CPF mencionado não existe.");
    } else {
        atleta = criarAtleta(&inicio);
        printf("\nAtleta criado com sucesso!\n");
        printf("\tNome: %s\n", atleta->nome);
        printf("\tNome: %s\n", atleta->cpf);
        printf("\tNome: %c\n", atleta->sexo);
        printf("\tNome: %s\n", atleta->instituicaoEnsino);
        printf("\tNome: %s\n", atleta->dataNascimeto);
    }
};