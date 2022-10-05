#ifndef JOGADOR_H
#define JOGADOR_H
#include "estatica.h"
#include <iostream>
using namespace std;


struct Jogador {
	int num;
	int pontuacao;
};

void cria_jogador(TLS::TListaEstatica<Jogador, 10>& lista) {
	for (int i = 0; i < 10; i++) {
		Jogador c;
		c.num = i;
		c.pontuacao = 0;
		insere_inicio(lista, c);
	}
}

//imprime
ostream& operator<<(ostream& os, Jogador j) {
	os << "Jogador: " << j.num << " Pontuação: " << j.pontuacao << endl;
	return os;
}

#endif

