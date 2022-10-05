#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
namespace TF

{
	template <typename TIPO>
	struct TElementoF {
		TIPO dado;
		TElementoF* proximo;
	};

	template <typename TIPO>
	struct TFila {
		TElementoF<TIPO>* primeiro;
	};

	//inicializa
	template <typename TIPO>
	void inicializa(TFila<TIPO> &fila) {
		fila.primeiro = NULL;
	}

	//verificaVazio
	template <typename TIPO>
	bool verificaVazio(TFila<TIPO> fila) {
		if (fila.primeiro == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	//acessaInicio
	template <typename TIPO>
	TElementoF<TIPO> acessaInicio(TFila<TIPO>& fila) {
		return fila.primeiro;
	}
	//queue
	template <typename TIPO>
	void queue(TFila<TIPO> &fila, TIPO dado) {
		TElementoF<TIPO> *novo = new TElementoF<TIPO>;
		TElementoF<TIPO>* nav;
		novo->dado = dado;
		novo->proximo = NULL;
		nav = fila.primeiro;
		if(fila.primeiro != NULL){
			while(nav->proximo != NULL){
				nav = nav->proximo;
			}
			nav->proximo = novo;
		}
		else{
			fila.primeiro = novo;
		}
	}
	//dequeue
	template <typename TIPO>
	TElementoF<TIPO>* dequeue(TFila<TIPO> &fila) {
		TElementoF<TIPO> *removido = new TElementoF<TIPO>;
		removido = fila.primeiro;
		fila.primeiro = fila.primeiro->proximo;
		//delete removido;
		return removido;
	}
	//imprime
	template<typename TIPO>
	void imprimir(TFila<TIPO> fila) {
		TElementoF<TIPO>* nav = new TElementoF<TIPO>;
		nav = fila.primeiro;

		cout << "\tClientes";
		cout << "\n****************************************";
		while (nav != NULL) {
			cout << "\nCliente: " << nav->dado;
			cout << "\n--------------------------------------";
			nav = nav->proximo;
		}

		cout << "\n****************************************\n\n";
	}
}


#endif // FILA
