#include <iostream>
using namespace std;

#include "estatica.h"
#include "jogador.h"
#include "encadeadaSimples.h"
#include "encadeadaDupla.h"
#include "fila.h"
#include "cliente.h"
#include "atendente.h"

int main()
{
    TLS::TListaEstatica<Jogador, 10> jogadores;
    TF::TFila<Cliente> playerFila;
    TLDS::TLista<Atendente> atendentes;
    TLDD::TLista<Jogador> playersDupla;
    
    
    //TLDS::imprimirAtendente(atendentes);
    TLDS::inicializar(atendentes);
    criaAtendente(1, atendentes);
    criaCliente(2, 1, playerFila);
    atende(30,1, playerFila, atendentes);  
    //TLDS::imprimirAtendente(atendentes);


    //TF::imprimir(playerFila);
    //cout << verificaTotalClientes(playerFila)<<endl;
    //Cliente a;
    //TF::TElementoF<Cliente> *cliente = TF::dequeue(playerFila);
    //a.nome = cliente->dado.nome;
    //cout << a.nome;
    //a.diaAtendido = cliente->dado.diaAtendido;
    //TLDS::inserirInicio(atendentes.inicio->dado.atendidos, a);
    //TLDS::imprimirAtendente(atendentes);
    
    
    
    
    /*
    Jogador c;
    c.num = 1;
    c.pontuacao = 1;
    Jogador d;
    d.num = 2;
    d.pontuacao = 2;
    Jogador a;
    a.num = 3;
    a.pontuacao = 3;

    Jogador b;
    b.num = 4;
    b.pontuacao = 4;

    Jogador e;
    e.num = 5;
    e.pontuacao = 5;
   
    
    * dinaminca simples
    
    TLDS::inicializar(players);
    TLDS::inserirInicio(players, a);
    TLDS::inserirInicio(players, d);
    TLDS::inserirInicio(players, c);
    TLDS::inserirInicio(players, a);
    TLDS::inserirInicio(players, a);
    TLDS::inserePosicao(players, b, 3);
    TLDS::insereFinal(players, e);
    
    TLDS::removePosicao(players, 5);
    TLDS::removeFinal(players);
    TLDS::imprimir(players);
    

    TF::inicializa(playerFila);
    TF::queue(playerFila, a);
    TF::queue(playerFila, b);
    TF::queue(playerFila, c);
    TF::queue(playerFila, d);
    TF::queue(playerFila, e);
    TF::imprimir(playerFila);
    TF::dequeue(playerFila);
    TF::imprimir(playerFila);
    */
    /*
      dinaminca dupla
    TLDD::inicializar(playersDupla);
    TLDD::inserirInicio(playersDupla, b);
    TLDD::inserirInicio(playersDupla, b);
    TLDD::inserirInicio(playersDupla, b);
    TLDD::inserirInicio(playersDupla, b);
    TLDD::imprimir(playersDupla);
    
    
    TLS::inicializa(jogadores);

    cria_jogador(jogadores);
    cout << jogadores;
    */

    

}