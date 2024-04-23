#ifndef ESTRUTURAS_H_
#define ESTRUTURAS_H_

#define MAX_ATLETAS 1000
#define MAX_MODALIDADES 10
#define MAX_EQUIPES 100
#define MAX_TORNEIOS 10
#define MAX_JOGOS 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int numAtletas;
extern int numModalidades;
extern int numEquipes;
extern int numTorneios;
extern int numJogos;

typedef struct atleta{
    char nome[50];
    char cpf[15];
    char sexo;
    char instituicaoEnsino[50];
    char dataNascimento[11];
} Atleta;

typedef struct modalidade{
    char nome[50];
    int numAtletasPorEquipe;
} Modalidade;

extern Atleta atletas[MAX_ATLETAS];
extern Modalidade modalidades[MAX_MODALIDADES];

//Funções Atletas

Atleta criarAtleta();
void exibirAtleta(char *cpf);
void exibirAtletas();
void atualizarAtleta(char *cpf);
void deletarAtleta(char *cpf);

//Funções Modalidades
Modalidade criarModalidade();
void exibirModalidade(char *cpf);
void exibirModalidades();
void atualizarModalidade(char *cpf);
void deletarModalidade(char *cpf);

#endif