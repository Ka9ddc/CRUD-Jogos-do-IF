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
#include <stdbool.h>

extern int numAtletas;
extern int numModalidades;
extern int numEquipes;
extern int numTorneios;
extern int numJogos;

typedef struct {
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
    char dataFormatada[50];
} DataHora;

typedef struct {
    int pontosTime1;
    int pontosTime2;
    char placarFormatado[50];
} Placar;

typedef struct atleta{
    char nome[50];
    char cpf[15];
    char sexo;
    char instituicaoEnsino[50];
    char dataNascimento[11];
    bool possuiEquipe;
} Atleta;

typedef struct modalidade{
    char nome[50];
    int numAtletasPorEquipe;
} Modalidade;

typedef struct equipe{
    char nome[50];
    char sigla[6];
    Modalidade *modalidade;
    int numAtletasEquipe;
    Atleta *atletas[];
} Equipe;

typedef struct torneio{
    char nome[50];
    Modalidade *modalidade;
    int quantidadeEquipesInscritas;
    int maxEquipes;
    Equipe *equipes[];
} Torneio;

typedef struct jogo{
    Torneio *torneio;
    Equipe *primeiraEquipe;
    Equipe *segundaEquipe;
    DataHora *dataHora;
    Placar *placar;
    char id[100];
} Jogo;

extern Atleta atletas[MAX_ATLETAS];
extern Modalidade modalidades[MAX_MODALIDADES];
extern Equipe equipes[MAX_EQUIPES];
extern Torneio torneios[MAX_TORNEIOS];
extern Jogo jogos[MAX_JOGOS];

//Funções Atletas

void exibirAtleta(char *cpf);
void exibirAtletas();
void atualizarAtleta(char *cpf);
void deletarAtleta(char *cpf);
Atleta criarAtleta();
Atleta * retornarAtleta(char *cpf);

//Funções Modalidades
Modalidade * criarModalidade();
void exibirModalidade(char *nome);
void exibirModalidades();
void atualizarModalidade(char *nome);
void deletarModalidade(char *nome);
Modalidade * retornarModalidade(char *nome);

//Funções Equipes
void criarEquipe();
void deletarEquipe(char *nome);
void exibirEquipe(char *nome);
void exibirEquipes();
void adicionarAtletaEquipe(char *nome);
void removerAtletaEquipe(char *nome);
void atualizarEquipe(char *nome);
Equipe * retornarEquipe(char *nome);

//Funções Torneios
void criarTorneio();
void deletarTorneio(char *nome);
void exibirTorneio(char *nome);
void exibirTorneios();
void adicionarEquipeTorneio(char *nome);
void removerEquipeTorneio(char *nome);
void atualizarTorneio(char *nome);
Torneio * retornarTorneio(char *nome);

//Funções Jogos
void criarJogo();

#endif