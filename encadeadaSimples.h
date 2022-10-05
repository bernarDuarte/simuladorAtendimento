#ifndef LISTA_ENCADEADA_SIMPLES_H_INCLUDED
#define LISTA_ENCADEADA_SIMPLES_H_INCLUDED
namespace TLDS
{
    template <typename TIPO>
    struct TElemento {
        TIPO dado;
        TElemento <TIPO>* proximo;
    };

    template <typename TIPO>
    struct TLista {
        TElemento <TIPO>* inicio;
    };


    //Inicia
    template <typename TIPO>
    void inicializar(TLista <TIPO> &p) {
        p.inicio = NULL;
    }


    //Cria elemento
    template <typename TIPO>
    TElemento <TIPO>* novo_elemento_lista(TIPO dado) {

        TElemento <TIPO>* novo = new TElemento<TIPO>;

        novo->dado = dado;
        novo->proximo = NULL;

        return novo;
    }


    //inserir
    template <typename TIPO>
    bool inserirInicio(TLista <TIPO>& lista, TIPO dado) {
        TElemento <TIPO>* novo = new TElemento<TIPO>;
        novo->dado = dado;
        novo->proximo = NULL;

        if (lista.inicio == NULL) {
            lista.inicio = novo;
            return true;
        }
        else {
            novo->proximo = lista.inicio;
            lista.inicio = novo;
            return true;
        }
    }
    template <typename TIPO>
    bool inserirInicio(TLista <TIPO>& lista, TIPO *dado) {
        TElemento <TIPO>* novo = new TElemento<TIPO>;
        novo->dado = dado;
        novo->proximo = NULL;

        if (lista.inicio == NULL) {
            lista.inicio = novo;
            return true;
        }
        else {
            novo->proximo = lista.inicio;
            lista.inicio = novo;
            return true;
        }
    }


    template <typename TIPO>
    bool inserePosicao(TLista <TIPO>& lista, TIPO dado, int p) {

        int contador = 0;

        TElemento<TIPO>* novo = novo_elemento_lista(dado);
        TElemento<TIPO>* nav = lista.inicio;
        if (p > 0) {
            inserirInicio(lista, dado);
            return true;
        }
        if (lista.inicio != NULL) {
            novo->dado = dado;
            while (nav->proximo != NULL) {
                if (contador + 1 == p) {
                    novo->proximo = nav->proximo;
                    nav->proximo = novo;
                    return true;
                }
                nav = nav->proximo;
                contador++;
            }
            return false;
        }
    }


    template <typename TIPO>
    bool insereFinal(TLista <TIPO>& lista, TIPO dado) {
        TElemento<TIPO>* novo = new TElemento<TIPO>;
        TElemento<TIPO>* nav = lista.inicio;
        if (lista.inicio == NULL) {
            return inserirInicio(lista, dado);
         }
        novo->dado = dado;
        novo->proximo = NULL;
        while (nav->proximo!= NULL) {
            nav = nav->proximo;
        }
        nav->proximo = novo;
        return true;
    }



    //Remover
    template <typename TIPO>
    bool removeInicio(TLista <TIPO>& lista) {

        if (lista.inicio == NULL) {
            return false;
        }
        else {
            TElemento<TIPO>* removedor = lista.inicio;
            lista.inicio = removedor->proximo;
            delete removedor;
            return true;
        }
        
    }


    template <typename TIPO>
    bool removePosicao(TLista <TIPO>& lista, int p) {

        int contador = 0;
        TElemento<TIPO>* removido = new TElemento<TIPO>;
        TElemento<TIPO>* nav = lista.inicio;

        if (lista.inicio != NULL || p > 0) {
            while (nav->proximo != NULL || contador == p) {
                if (contador+1 == p) {
                    removido = nav->proximo;
                    nav->proximo = removido->proximo;
                    delete removido;
                    return true;
                }
                nav = nav->proximo;
                contador++;
            }
            return false;
        }
    }


    template <typename TIPO>
    bool removeFinal(TLista <TIPO>& lista) {

        TElemento<TIPO>* nav = lista.inicio;
        TElemento<TIPO>* ultimo = new TElemento<TIPO>;
        if (lista.inicio != NULL) {
            while (nav->proximo != NULL) {
                ultimo = nav;
                nav = nav->proximo;
            }
            ultimo->proximo = NULL;
            delete nav;
            return true;
        }
        return false;
    }




    //quantidade
    template <typename TIPO>
    int contaLista(TLista <TIPO>& lista) {

        int qtt = 0;

        TElemento<TIPO>* nav = lista.inicio;

        if (lista.inicio == NULL) {
            cout << "Lista Vazia!" << endl;
        }
        else {

            while (nav != NULL) {
                nav = nav->proximo;
                qtt++;
            }
            return qtt;
        }


    }

    template<typename T>
    void imprimir(TLista<T> lista) {
        TElemento<T>* nav = new TElemento<T>;
        nav = lista.inicio;

        cout << "\tClientes";
        cout << "\n****************************************";
        while (nav != NULL) {
            cout << "\nCliente : " << nav->dado;
            cout << "\n--------------------------------------";
            nav = nav->proximo;
        }
      
        cout << "\n****************************************\n\n";
    }

    template<typename T>
    void imprimirAtendente(TLista<T> lista) {
        TElemento<T> *nav = new TElemento<T>;
        nav = lista.inicio;

        cout << "\tFilas De Atendimento";
        cout << "\n****************************************";
        while (nav != NULL) {
            cout << "\nAtendente: " << nav->dado;
            cout << "\n--------------------------------------";
            nav = nav->proximo;
        }

        cout << "\n****************************************\n\n";
    }


}

#endif // LISTA_ENCADEADA_SIMPLES

