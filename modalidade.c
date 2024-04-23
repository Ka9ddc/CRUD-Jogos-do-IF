#include "estruturas.h"

Modalidade criarModalidade(){
    if(numModalidades >= MAX_MODALIDADES){
        printf("O numero maximo de modalidades foi alcançado!");
    } else {
        Modalidade novaModalidade;
        printf("\nEntre com o nome da modalidade:\n");
        scanf("%s", novaModalidade.nome);
        printf("Entre com o numero de atletas por equipe:\n");
        scanf("%d", &novaModalidade.numAtletasPorEquipe);
        
        modalidades[numModalidades++] = novaModalidade;
        printf("Modalidade cadastrada com sucesso!");
        
        return novaModalidade;
    }
}

void exibirModalidade(char *nome){
    int found = 0;
    for(int i = 0; i < numModalidades; i++){
        if(strcmp(modalidades[i].nome, nome) == 0){
            printf("\nNome da modalidade: %s", modalidades[i].nome);
            printf("\nNumero de atletas por equipe: %d", modalidades[i].numAtletasPorEquipe);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("\nNenhuma modalidade com esse nome foi encontrada!\n");
    }
}

void exibirModalidades(){
    if(numModalidades == 0){
        printf("\nNão há modalidades cadastradas!\n");
    } else {
        for(int i = 0; i < numModalidades; i++){
            printf("\nNome da modalidade: %s", modalidades[i].nome);
            printf("\nNumero de atletas por equipe: %d\n", modalidades[i].numAtletasPorEquipe);
        }
    }
}

void atualizarModalidade(char *nome){
    int found = 0;
    for(int i = 0; i < numModalidades; i++){
        if(strcmp(modalidades[i].nome, nome) == 0){
            printf("\n---FORMULARIO PARA ATUALIZAR MODALIDADE---\n");
            printf("\nDigite o nome da modalidade: ");
            scanf("%s", modalidades[i].nome);
            printf("\nDigite o numero de atletas por equipe: ");
            scanf("%d", &modalidades[i].numAtletasPorEquipe);
            found = 1;
            printf("Modalidade atualizado com sucesso!");
        }
    }
    if(!found){
        printf("Nenhuma modalidade com esse nome foi encontrada!");
    }
}

void deletarModalidade(char *nome){
    int found = 0;
    for(int i = 0; i < numModalidades; i++){
        if(strcmp(modalidades[i].nome, nome) == 0){
            for(int j = i; j < numModalidades; j++){
                modalidades[j] = modalidades[j+1];
            }
        numModalidades--;
        found = 1;
        printf("Modalidade deletada com sucesso!");
        }
    }
    if(!found){
        printf("Nenhuma modalidade com esse nome foi encontrada!");
    }
}