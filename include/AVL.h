#ifndef AVL_H
#define AVL_H

#include "ABB.h"

template <typename Key>
class AVL : public ABB<Key> {
public:
    AVL() : ABB<Key>() {}
    virtual ~AVL() {}

    bool insertar(const Key& k) override {
        bool insertado = ABB<Key>::insertar(k);
        if (insertado) {
            NodoB<Key>* actual = this->getRaiz();
            while (actual != nullptr) {
                int factor = altura(actual->getIzdo()) - altura(actual->getDcho());
                if (factor == 2) {
                    if (altura(actual->getIzdo()->getIzdo()) >= altura(actual->getIzdo()->getDcho())) {
                        rotacionII(actual);
                    } else {
                        rotacionID(actual);
                    }
                    break;
                } else if (factor == -2) {
                    if (altura(actual->getDcho()->getDcho()) >= altura(actual->getDcho()->getIzdo())) {
                        rotacionDD(actual);
                    } else {
                        rotacionDI(actual);
                    }
                    break;
                }
                actual = actual->getIzdo() != nullptr ? actual->getIzdo() : actual->getDcho();
            }
        }
        return insertado;
    }

private:
    int altura(NodoB<Key>* nodo) const {
        if (nodo == nullptr) {
            return -1;
        } else {
            return 1 + std::max(altura(nodo->getIzdo()), altura(nodo->getDcho()));
        }
    }

    void rotacionII(NodoB<Key>* nodo) {
        NodoB<Key>* aux = nodo->getIzdo();
        nodo->setIzdo(aux->getDcho());
        aux->setDcho(nodo);
        if (nodo == this->getRaiz()) {
            this->setRaiz(aux);
        } else {
            NodoB<Key>* padre = buscarPadre(this->getRaiz(), nodo->getDato());
            if (nodo == padre->getIzdo()) {
                padre->setIzdo(aux);
            } else {
                padre->setDcho(aux);
            }
        }
    }

    void rotacionDD(NodoB<Key>* nodo) {
        NodoB<Key>* aux = nodo->getDcho();
        nodo->setDcho(aux->getIzdo());
        aux->setIzdo(nodo);
        if (nodo == this->getRaiz()) {
            this->setRaiz(aux);
        } else {
            NodoB<Key>* padre = buscarPadre(this->getRaiz(), nodo->getDato());
            if (nodo == padre->getIzdo()) {
                padre->setIzdo(aux);
            } else {
                padre->setDcho(aux);
            }
        }
    }

    void rotacionID(NodoB<Key>* nodo) {
        NodoB<Key>* aux = nodo->getIzdo()->getDcho();
        nodo->getIzdo()->setDcho(aux->getIzdo());
        aux->setIzdo(nodo->getIzdo());
        nodo->setIzdo(aux->getDcho());
        aux->setDcho(nodo);
        if (nodo == this->getRaiz()) {
            this->setRaiz(aux);
        } else {
            NodoB<Key>* padre = buscarPadre(this->getRaiz(), nodo->getDato());
            if (nodo == padre->getIzdo()) {
                padre->setIzdo(aux);
            } else {
                padre->setDcho(aux);
            }
        }
    }

    void rotacionDI(NodoB<Key>* nodo) {
        NodoB<Key>* aux = nodo->getDcho()->getIzdo();
        nodo->getDcho()->setIzdo(aux->getDcho());
        aux->setDcho(nodo->getDcho());
        nodo->setDcho(aux->getIzdo());
        aux->setIzdo(nodo);
        if (nodo == this->getRaiz()) {
            this->setRaiz(aux);
        } else {
            NodoB<Key>* padre = buscarPadre(this->getRaiz(), nodo->getDato());
            if (nodo == padre->getIzdo()) {
                padre->setIzdo(aux);
            } else {
                padre->setDcho(aux);
            }
        }
    }

    NodoB<Key>* buscarPadre(NodoB<Key>* nodo, const Key& k) const {
        if (nodo == nullptr || nodo->getDato() == k) {
            return nullptr;
        } else if ((nodo->getIzdo() != nullptr && nodo->getIzdo()->getDato() == k) ||
                   (nodo->getDcho() != nullptr && nodo->getDcho()->getDato() == k)) {
            return nodo;
        } else if (k < nodo->getDato()) {
            return buscarPadre(nodo->getIzdo(), k);
        } else {
            return buscarPadre(nodo->getDcho(), k);
        }
    }
};

#endif /* AVL_H */
