# Trabalho 2 - CRUD Jogos do IFB

## Participante: Ryan Micael Benício dos Santos

## Instruções de como compilar:

1. Usando o Makefile: Basta acessar o terminal e utilizar o comando ```make``` na raiz do projeto. 

2. Usando GCC: Basta acessar o terminal e utilizar o seguinte comando: ```gcc main.c atleta.c equipe.c modalidade.c jogo.c torneio.c globals.c -o jogos_do_if```


## O que faz cada módulo:

- **Módulo Principal (Main)**: É o construtor de menus do programa, ele é quem imprime os menus para o usuário e faz a chamada dos outros módulos baseado nas respostas do usuário.

- **Módulo Estruturas**: É o módulo onde são definidas as estruturas e novos tipos utilizados no projeto, também é onde são reunidas e declaradas as funções dos módulos para a utilização nos outros módulos.

- **Módulo Atleta**: É o módulo da estrutura `Atleta` que constrói as funções CRUD relacionadas a estrutura.

- **Módulo Modalidade**: É o módulo da estrutura `Modalidade` que constrói as funções CRUD relacionadas a estrutura.

- **Módulo Equipe**: É o módulo da estrutura `Equipe` que constrói as funções CRUD relacionadas a estrutura.

- **Módulo Torneio**: É o módulo da estrutura `Torneio` que constrói as funções CRUD relacionadas a estrutura.

- **Módulo Jogo**: É o módulo da estrutura `Jogo` que constrói as funções CRUD relacionadas a estrutura.

- **Módulo Globals (Variáveis globais)**: É um modulo para a declaração e compartilhamento de variáveis que são utilizadas por varios módulos do programa.
