#define TAMANHO 50

#include "estruturas.h"

DataHora * criarDataHora() {
    DataHora *dataHora = malloc(sizeof(DataHora));
    if (dataHora == NULL) {
        printf("Erro de alocacao de memória.\n");
        exit(1);
    }

    printf("Digite a data e hora no formato AAAA-MM-DD HH:MM: ");
    scanf("%d-%d-%d %d:%d", &dataHora->ano, &dataHora->mes, &dataHora->dia, &dataHora->hora, &dataHora->minuto);
    
    sprintf(dataHora->dataFormatada, "%04d-%02d-%02d %02d:%02d",
            dataHora->ano,
            dataHora->mes,
            dataHora->dia,
            dataHora->hora,
            dataHora->minuto);

    if (dataHora->ano < 1000 || dataHora->ano > 9999 || dataHora->mes < 1 || dataHora->mes > 12 || dataHora->dia < 1 || dataHora->dia > 31 ||
        dataHora->hora < 0 || dataHora->hora > 23 || dataHora->minuto < 0 || dataHora->minuto > 59) {
        printf("Valores fornecidos fora da especificacao.\n");
        free(dataHora);
        return NULL;
    }

    return dataHora;
}

Placar * criarPlacar(Jogo *jogo){
    Placar *novoPlacar = malloc(sizeof(Placar));
    if (novoPlacar == NULL) {
        printf("Erro de alocacao de memória.\n");
        exit(1);
    }

    novoPlacar->pontosTime1 = 0;
    novoPlacar->pontosTime2 = 0;
    
    sprintf(novoPlacar->placarFormatado, "%s: %d x %s: %d",
        jogo->primeiraEquipe->sigla,
        novoPlacar->pontosTime1,
        jogo->segundaEquipe->sigla,
        novoPlacar->pontosTime2);
    
    return novoPlacar;
}

void gerarId(Jogo *jogo){
    char id[50];
    sprintf(id, "%s x %s %04d-%02d-%02d %02d:%02d",
            jogo->primeiraEquipe->sigla,
            jogo->segundaEquipe->sigla,
            jogo->dataHora->ano,
            jogo->dataHora->mes,
            jogo->dataHora->dia,
            jogo->dataHora->hora,
            jogo->dataHora->minuto);
    strncpy(jogo->id, id, sizeof(jogo->id));
}

void criarJogo() {
    if (numJogos >= MAX_JOGOS) {
        printf("\nO numero maximo de jogos foi alcancado!\n");
    } else {
        char nomeTorneio[TAMANHO];
        char siglaEquipe[TAMANHO];
        Torneio *torneio;
        Equipe *equipe1;
        Equipe *equipe2;
        DataHora *dataHora;
        Jogo novoJogo;

        printf("\nDigite o nome do torneio: ");
        scanf(" %[^\n]", nomeTorneio);
        torneio = retornarTorneio(nomeTorneio);
        if(!torneio){
            printf("\nNenhum torneio encontrado com o nome fornecido!\n");
            return;
        }
        printf("\nDigite a sigla da primeira equipe do jogo: ");
        scanf(" %[^\n]", siglaEquipe);
        equipe1 = retornarEquipe(siglaEquipe);
        if(!equipe1){
            printf("\nNenhuma equipe encontrada com a sigla fornecida!\n");
            return;
        }
        printf("\nDigite a sigla da segunda equipe do jogo: ");
        scanf(" %[^\n]", siglaEquipe);
        equipe2 = retornarEquipe(siglaEquipe);
        if(!equipe2){
            printf("\nNenhuma equipe encontrada com a sigla fornecida!\n");
            return;
        }
        dataHora = criarDataHora();
        if(!dataHora){
            return;
        }
        
        novoJogo.torneio = torneio;
        novoJogo.primeiraEquipe = equipe1;
        novoJogo.segundaEquipe = equipe2;
        novoJogo.dataHora = dataHora;
        novoJogo.placar = criarPlacar(&novoJogo);
        gerarId(&novoJogo);
        for(int i = 0; i < numJogos; i++){
            if(strcmp(novoJogo.id, jogos[i].id) == 0){
                printf("\nJa existe um jogo com esse ID\n");
                return;
            }
        }
        jogos[numJogos++] = novoJogo;
        printf("\nJogo criado!\n");
        
        printf("\nID do jogo: %s\n", novoJogo.id);
        printf("\nNome do torneio: %s\n", novoJogo.torneio->nome);
        printf("\nPrimeira Equipe: %s\n", novoJogo.primeiraEquipe->nome);
        printf("\nSegunda Equipe: %s\n", novoJogo.segundaEquipe->nome);
        printf("\nData do jogo: %s\n", novoJogo.dataHora->dataFormatada);
        printf("\nPlacar do jogo: %s\n", novoJogo.placar->placarFormatado);
    }
}

void exibirJogo(char *id){
    int found = 0;
    for(int i = 0; i < numJogos; i++){
        if(strcmp(jogos[i].id, id) == 0){
            printf("\nTorneio: %s\n", jogos[i].torneio->nome);
            printf("Data: %s\n", jogos[i].dataHora->dataFormatada);
            printf("Placar: %s\n", jogos[i].placar->placarFormatado);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("\nNao foi encontrado nenhum jogo com o id fornecido!\n");
    }
}

void exibirJogos(){
    char nomeTorneio[50];
    printf("\nDigite o nome do torneio: ");
    scanf(" %[^\n]", nomeTorneio);
    printf("\n------------ JOGOS DO TORNEIO: %s ------------\n", nomeTorneio);
    for(int i = 0; i < numJogos; i++){
            if(strcmp(jogos[i].torneio->nome, nomeTorneio) == 0){
                printf("Data: %s\n", jogos[i].dataHora->dataFormatada);
                printf("Placar: %s\n", jogos[i].placar->placarFormatado);
            }
        }
    printf("\n------------ FIM JOGOS ------------\n");
    }

void atualizarJogo(char *id){
        char nomeTorneio[TAMANHO];
        char siglaEquipe[TAMANHO];
        Torneio *torneio;
        Equipe *equipe1;
        Equipe *equipe2;
        DataHora *dataHora;
        int found = 0;
        
    for(int i = 0; i < numJogos; i++){
        if(strcmp(jogos[i].id, id) == 0){
            printf("---FORMULARIO PARA ATUALIZAR JOGO---");
            printf("\nDigite o nome do torneio: ");
            scanf(" %[^\n]", nomeTorneio);
            torneio = retornarTorneio(nomeTorneio);
            if(!torneio){
                printf("\nNenhum torneio encontrado com o nome fornecido!\n");
                return;
            }
            printf("\nDigite a sigla da primeira equipe do jogo: ");
        scanf(" %[^\n]", siglaEquipe);
        equipe1 = retornarEquipe(siglaEquipe);
        if(!equipe1){
            printf("\nNenhuma equipe encontrada com a sigla fornecida!\n");
            return;
        }
        printf("\nDigite a sigla da segunda equipe do jogo: ");
        scanf(" %[^\n]", siglaEquipe);
        equipe2 = retornarEquipe(siglaEquipe);
        if(!equipe2){
            printf("\nNenhuma equipe encontrada com a sigla fornecida!\n");
            return;
        }
        dataHora = criarDataHora();
        if(!dataHora){
            return;
        }
        
        jogos[i].torneio = torneio;
        jogos[i].primeiraEquipe = equipe1;
        jogos[i].segundaEquipe = equipe2;
        jogos[i].dataHora = dataHora;
        jogos[i].placar = criarPlacar(&jogos[i]);
        gerarId(&jogos[i]);
        printf("\nJogo atualizado!\n");
            
        }
    }
}

void deletarJogo(char *id) {
    int found = 0;
    for(int i = 0; i < numJogos; i++)
    {
        if(strcmp(jogos[i].id, id) == 0){
            for (int j = i; j < numJogos - 1; j++)
            {
                jogos[j] = jogos[j+1];
            }
            numJogos--;
            found = 1;
            printf("\nJogo deletado com sucesso!\n");
        }
    }
    if(!found){
        printf("\nNenhum jogo com o id fornecido foi encontrado!\n");
    }
}

void atualizarPlacar(char *id){
    int found = 0;
    for(int i = 0; i < numJogos; i++){
        if(strcmp(jogos[i].id, id) == 0){
            printf("\n---ATUALIZACAO DE PLACAR---\n");
            printf("\nDigite a pontuacao para %s: ", jogos[i].primeiraEquipe->sigla);
            scanf("%d", &jogos[i].placar->pontosTime1);
            printf("\nDigite a pontuacao para %s: ", jogos[i].segundaEquipe->sigla);
            scanf("%d", &jogos[i].placar->pontosTime2);
            sprintf(jogos[i].placar->placarFormatado, "%s: %d x %s: %d",
            jogos[i].primeiraEquipe->sigla,
            jogos[i].placar->pontosTime1,
            jogos[i].segundaEquipe->sigla,
            jogos[i].placar->pontosTime2);
            printf("\nPlacar atualizado com sucesso: %s\n", jogos[i].placar->placarFormatado);
        }
    }
}
