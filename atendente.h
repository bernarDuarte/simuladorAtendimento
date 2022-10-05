#ifndef  ATENDENTE_H
#define ATENDENTE_H


#include <stdlib.h>
#include "fila.h"
#include "encadeadaSimples.h"
#include "cliente.h"
#include <math.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <sstream>
#include <time.h> 

using namespace std;


struct Atendente {
	string nome;
	TLDS::TLista<Cliente> atendidos;
};


void criaAtendente(int numAtendentes, TLDS::TLista<Atendente> &listaA) {
	string cliente = "Atendente : ";
	if (listaA.inicio != NULL ) {
		numAtendentes--;
	}
	for (int i = 1; i <= numAtendentes; i++) {
		stringstream ss;
		string s;
		ss << i + 1;
		ss >> s;
		Atendente a;
		a.nome = cliente + s;
		TLDS::inserirInicio(listaA,a);
		TLDS::inicializar(listaA.inicio->dado.atendidos);
	}
}

// atendimentos ==1 (qustão 1 ) else 2 e 3;
void defineAtendimentoPorMinuto(int &apm) {
	srand(time(NULL));
	if (apm == 1) {
		apm = 1;
	}
	else {
		apm = rand() % 10 + 1;
		
	}
	if (apm > 1) {
		cout << endl << endl << "\t" << "E uma média de " << apm << " clientes atendidos por minuto";
	}
	else {
		cout << endl << endl << "\t" << "E uma média de " << apm << " cliente atendido por minuto";
	}
	
}

// se dia == 30 questão 3  --  else == questão 1,2 
void defineNumDia(int &dia) {
	if (dia == 30) {
		dia = 30;
	}
	else {
		dia = 3;
	}
}


template <typename TIPO>
int calculaNumAtendente(int atendimento,int dias,TF::TFila<TIPO> &fila) {
	float numClientes = verificaTotalClientes(fila);
	cout << numClientes;
	numClientes = (numClientes / dias) / (480*atendimento);
	return ceil(numClientes);
}

//dia == 1 questão 1 e 2 , elseif { dia == 30 questão 3
template <typename TIPO>
void atende(int atendimento,int dia,TF::TFila<TIPO> &fila,TLDS::TLista<Atendente> &lista) {
	int totalAtendentes = 0;
	defineAtendimentoPorMinuto(atendimento);
	
	if (dia == 1) {
		deFatoAtende(1,5,fila,lista,1);
	}

	defineNumDia(dia);
	totalAtendentes = calculaNumAtendente(atendimento, dia, fila);
	criaAtendente(totalAtendentes, lista);
	deFatoAtende(atendimento, dia, fila, lista, totalAtendentes);
}

//impressão
int calculaNumAtendidosPorAtendente(TLDS::TElemento<Atendente> *dado) {
	TLDS::TElemento<Cliente>* navC = new TLDS::TElemento<Cliente>;
	int contador = 0;
	navC = dado->dado.atendidos.inicio;
	while (navC != NULL) {
		navC = navC->proximo;
		contador++;
	}
	return contador;
}

int calculatotalAtrasados(int totalAtendentes, TF::TFila<Cliente>& fila) {
	return verificaTotalClientes(fila)/totalAtendentes;
}


void imprimirAtendenteDiario( int totalAtendentes,int dia,TLDS::TLista<Atendente> lista, TF::TFila<Cliente>& fila) {
	TLDS::TElemento<Atendente>* nav = new TLDS::TElemento<Atendente>;
	nav = lista.inicio;
	


	cout << "\tFilas De Atendimento dia "<< dia;
	cout << "\n****************************************";
	while (nav != NULL) {
		cout << "\nAtendente: " << nav->dado.nome;
		cout << "\nNúmero De Atendedimentos realizados : " << calculaNumAtendidosPorAtendente(nav)/dia;
		cout << "\nNúmero De Atendedimentos em atraso  : " << calculatotalAtrasados(totalAtendentes,fila)/dia;
		cout << "\n--------------------------------------";
		nav = nav->proximo;
	}

	cout << "\n****************************************\n\n";
}


template <typename TIPO>
void deFatoAtende(int atendimento,int dia, TF::TFila<TIPO>& fila, TLDS::TLista<Atendente>& lista, int totalAtendentes) {
	int totalCliente = 0, dias = 1, contador = 0;
	TF::TElementoF<TIPO> *cliente;
	TLDS::TElemento<Atendente> *nav;
	nav = lista.inicio;
	if (totalAtendentes == 1) {
		totalCliente = (totalAtendentes * dia) * (480 * atendimento);
	}
	else {
		totalCliente = verificaTotalClientes(fila);
		cout << endl<<"\t" << "Será Necessário : " << totalAtendentes << " Atendentes" << endl;
	}

	if (lista.inicio != NULL && fila.primeiro != NULL) {
		for (int i = 0; i < totalCliente; i++) {
			int outroDia = dias;
			cliente = TF::dequeue(fila);
			dias = ceil(1+(i / (totalAtendentes * (480 * atendimento ))));
			if (outroDia != dias || dias == 3 || dias == 5 || dias == 30) {
				imprimirAtendenteDiario(totalAtendentes ,outroDia,lista, fila);
			}
			cliente->dado.diaAtendido = dias;
			
			TLDS::inserirInicio(nav->dado.atendidos, cliente->dado);
			
			if (nav->proximo == NULL) {
				nav = lista.inicio;
			}
			else {
				nav = nav->proximo;
			}
		}
	}
	else {
		cout << "Não há Atendentes";
	}

}



ostream& operator<<(ostream& os, Atendente j) {
	TLDS::TElemento<Cliente>* nav;
	nav = j.atendidos.inicio;
	if ( nav != NULL) {
		while (nav->proximo != NULL) {
			os << "Nome: " << j.nome << " Atendidos: " << nav->dado << endl;
			nav = nav->proximo;
		}
	}
	else {
		os << "Nome: " << j.nome << endl;
	}
	return os;
}



#endif // ATENDENTE // tentando fazer a segunda parte do atendimento, função deFatoAtende.