#ifndef ESTRUTURAS_H_
#define ESTRUTURAS_H_

#include <stdio.h>
#include <stdlib.h>

#ifndef Atleta
typedef struct atleta{
    char nome[50];
    char cpf[15]; //XXX.XXX.XXX-XX
    char sexo;
    char instituicaoEnsino[50];
    char dataNascimeto[11]; //DD/MM/AAAA
    Atleta *proximo;
} Atleta;
#endif

#ifndef Modalidade
typedef struct modalidade{
    char nome[50];
    int quantidadeAtletasEquipe;
} Modalidade;
#endif

#ifndef Equipe
typedef struct equipe{
    char nome[50];
    char sigla[6];
    int numAtletas;
    Modalidade *modalidade;
    Atleta atletas[];
} Equipe;
#endif

#ifndef Torneio
typedef struct torneio{
    char nome[50];
    Modalidade *modalidade;
    int quantidadeEquipesInscritas;
    Equipe equipes[];
} Torneio;
#endif

#ifndef Jogo
typedef struct jogo{
    char nome[50];
    Equipe *equipe1;
    Equipe *equipe2;
    char dataHora[17];
    int quantidadeEquipesInscritas;
    struct placar{
        int pontosEquipe1;
        int pontosEquipe2;
    };
    char ID[12];
} Jogo;

#endif

#ifndef Atletas
typedef struct {
        int numAtletas;
        Atleta *inicio;
    } Atletas;
#endif

Atleta *criarAtleta(Atleta **inicio);
void *editarAtleta(Atleta **inicio, char CPF[15]);

#endif