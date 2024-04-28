all: rm jogos_do_if

jogos_do_if: globals.o equipe.o atleta.o modalidade.o
	gcc main.c globals.o equipe.o atleta.o modalidade.o -o jogos_do_if

globals.o:
	gcc -c globals.c

equipe.o:
	gcc -c equipe.c

atleta.o:
	gcc -c atleta.c

modalidade.o:
	gcc -c modalidade.c

rm:
	rm *.o
