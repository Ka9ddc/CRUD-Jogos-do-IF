all: jogos_do_if

jogos_do_if: globals.o equipe.o atleta.o modalidade.o jogo.o torneio.o
	gcc main.c globals.o equipe.o atleta.o modalidade.o jogo.o torneio.o -o jogos_do_if

globals.o:
	gcc -c globals.c -o globals.o

equipe.o:
	gcc -c equipe.c -o equipe.o

atleta.o:
	gcc -c atleta.c -o atleta.o

modalidade.o:
	gcc -c modalidade.c -o modalidade.o

torneio.o:
	gcc -c torneio.c -o torneio.o

jogo.o:
	gcc -c jogo.c -o jogo.o

clean:
	rm -f *.o jogos_do_if
