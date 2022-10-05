#ifndef  CLIENTE_H
#define CLIENTE_H


#include <stdlib.h>
#include "fila.h"
#include <iostream>
#include <sstream>
#include <time.h> 

using namespace std;


struct Cliente {
	string nome;
	int diaAtendido;
};

void defineNumDias(int& numDias) {
	if (numDias == 0) {
		numDias = 8;
	}
	else {
		numDias = 30;
	}
}

int definePessoasNaFrente() {
	srand(time(NULL));
	int i = rand() % 50 + 1;
	cout << endl << "\t" << "e aproximadamente " << i << " pessoas aguardando na frente antes da abertura diarimente"<< endl;
	return i;
	
}


void defineClientesPorMinuto(int& cpm) {
	srand(time(NULL));
	if (cpm == 0) {
		cpm = 5;
	}
	else {
		cpm = rand() % 10 + 1;
		cout <<endl<<endl<< "\t" << "Com uma média de " << cpm << " chegando por minuto";
	}
}

// cpm == 0 é para a questão 1; num dias == 0, para a questão 1 e 2;
template <typename TIPO>
void criaCliente(int cpm, int numDias, TF::TFila<TIPO> &fila) {
	defineClientesPorMinuto(cpm);
	defineNumDias(numDias);
	TF::inicializa(fila);
	int totalClientes = cpm*(numDias*480), contador = 0;
	if (numDias == 30) {
		totalClientes = totalClientes + definePessoasNaFrente()* numDias;
	}
	string cliente ="cliente : ";
	for (int i = 0; i <= totalClientes; i++){
		stringstream ss;
		string s;
		ss << contador;
		ss >> s;

		Cliente c;
		c.diaAtendido = 0;
		c.nome = cliente + s;
		TF::queue(fila, c);
		contador++;
	}
}

template <typename TIPO>
int verificaTotalClientes(TF::TFila<TIPO> fila) {
	int contador = 0;
	TF::TElementoF<TIPO>* nav;
	nav = fila.primeiro;
	while (nav->proximo != NULL) {
		nav = nav->proximo;
		contador++;
	}
	return contador;
}

ostream& operator<<(ostream& os, Cliente j) {
	os << "Dia Atendimento: " << j.diaAtendido<< " Nome: " << j.nome << endl;
	return os;
}



#endif // CLIENTE