#define TAMANHO 50

#include "estruturas.h"

void criarJogo() {
    if (numJogos >= MAX_JOGOS) {
        printf("\nO numero maximo de jogos foi alcançado!\n");
    } else {
        char nomeModalidade[TAMANHO];
        Torneio *torneio;
        Equipe *equipe1;
        Equipe *equipe2;
        Jogo novoJogo;
        printf("\nDigite o nome do torneio: ");
        scanf(" %[^\n]", novoTorneio.nome);
        printf("\nDigite a modalidade do torneio");
        scanf(" %[^\n]", nomeModalidade);
        modalidade = retornarModalidade(nomeModalidade);
        if (!modalidade) {
            printf("Essa modalidade não existe!");
        } else {
            novoTorneio.modalidade = modalidade;
            novoTorneio.quantidadeEquipesInscritas = 0;
            novoTorneio.maxEquipes = 8;
            torneios[numTorneios++] = novoTorneio;
            printf("\nTorneio criado!\n");
        }
    }
}

Torneio * retornarTorneio(char* nome) {
    int found = 0;
    Torneio * torneioRetornado = NULL;
    for (int i = 0; i < numTorneios; i++) {
        if (strcmp(torneios[i].nome, nome) == 0) {
            found = 1;
            torneioRetornado = &torneios[i];
            return torneioRetornado;
        }
    }
    if (!found) {
        printf("Nenhum torneio encontrado com o nome: %s.\n", nome);
    }
    
    return NULL;
}

void exibirTorneio(char *nome){
    Torneio *torneio;
    torneio = retornarTorneio(nome);
    if(torneio){
        printf("\nNome da equipe: %s\n", torneio->nome);
        printf("\nModalidade da equipe: %s\n", torneio->modalidade->nome);
        printf("\nAtletas da equipe: \n");
        for (int i = 0; i < torneio->quantidadeEquipesInscritas; i++)
        {
            printf("%s\n", torneio->equipes[i]->nome);
        }
        
    }

}


void exibirTorneios() {
    for (int i = 0; i < numTorneios; i++) {
        printf("\nNome do torneio: %s\n", torneios[i].nome);
        printf("Modalidade do torneio: %s\n", torneios[i].modalidade->nome);
        printf("Equipes do torneio:\n");
        for (int j = 0; j < torneios[i].quantidadeEquipesInscritas; j++) {
            printf("%s\n", torneios[i].equipes[j]->nome); 
        }
    }
}

void atualizarTorneio(char *nome) {
    int found = 0;
    char nomeModalidade[TAMANHO];
    for (int i = 0; i < numTorneios; i++)
    {
        if(strcmp(torneios[i].nome, nome) == 0){
            printf("\n---FORMULARIO PARA ATUALIZAR TORNEIO---\n");
            printf("\nDigite o nome do torneio: ");
            scanf(" %[^\n]", torneios[i].nome);
            printf("\nDigite a modalidade do torneio: ");
            scanf(" %[^\n]", nomeModalidade);
            if(!retornarModalidade(nomeModalidade)){
                printf("\nModalidade inválida!\n");
            } else {
                torneios[i].modalidade = retornarModalidade(nomeModalidade);
            }
            found = 1;
            printf("Torneio atualizado com sucesso!");
            break;
        }
    }
    if(!found){
        printf("\nNenhum torneio com o nome fornecido foi encontrada!\n");
    }
    
}

void deletarTorneio(char *nome) {
    int found = 0;
    for (int i = 0; i < numTorneios; i++)
    {
        if(strcmp(torneios[i].nome, nome) == 0){
            for (int j = i; j < numTorneios - 1; j++)
            {
                torneios[j] = torneios[j+1];
            }
            numTorneios--;
            found = 1;
            printf("Torneio deletado com sucesso!");
        }
    }
    if(!found){
        printf("\nNenhum torneio com o nome fornecido foi encontrada!\n");
    }
    
}

void adicionarEquipeTorneio(char *nome) {
    Torneio *torneio;
    torneio = retornarTorneio(nome); 
    if (!torneio) {
        printf("\nNenhum torneio com esse nome foi encontrada!\n");
        return;
    }

    if (torneio->quantidadeEquipesInscritas >= torneio->maxEquipes) {
        printf("\nO numero maximo de equipes nesse torneio foi alcançado!\n");
    } else {
        char sigla[TAMANHO];
        Equipe *adicionarEquipe;
        printf("\nDigite a sigla da equipe a ser adicionada: ");
        scanf(" %[^\n]", sigla);
        adicionarEquipe = retornarEquipe(sigla);
        if (!adicionarEquipe) {
            printf("Equipe não encontrada!");
        } else {
            torneio->equipes[torneio->quantidadeEquipesInscritas++] = adicionarEquipe;
            printf("Equipe adicionada a equipe com sucesso!");
        }
    }
}

void removerEquipeTorneio(char *nome){
    int found = 0;
    char nomeEquipe[TAMANHO];
    Torneio *torneio;
    torneio = retornarTorneio(nome);
    if(!torneio){
        
    } else {
        printf("\nDigite o nome da equipe a ser removida: ");
        scanf(" %[^\n]", nomeEquipe);
        for(int i = 0; i < torneio->quantidadeEquipesInscritas; i++){
            if(strcmp(nomeEquipe, torneio->equipes[i]->nome) == 0){
                printf("\nA equipe a ser removida é: %s\n", torneio->equipes[i]->nome);
                for (int j = i; j < torneio->quantidadeEquipesInscritas - 2; j++)
                {
                    torneio->equipes[j] = torneio->equipes[j+1];
                }
                found = 1;
                torneio->quantidadeEquipesInscritas--;
                printf("\nEquipe removida com sucesso!\n");
                break;
            }
        }
    }
}