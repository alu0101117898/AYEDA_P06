#ifndef ABB_H
#define ABB_H

#include "AB.h"

template <typename Key>
class ABB : public AB<Key> {
public:
    ABB() : AB<Key>() {}
    virtual ~ABB() {}

    bool insertar(const Key& k) override {
        NodoB<Key>* nuevo = new NodoB<Key>(k);
        if (this->esVacio()) {
            this->setRaiz(nuevo);
            return true;
        }

        NodoB<Key>* padre = nullptr;
        NodoB<Key>* actual = this->getRaiz();
        while (actual != nullptr) {
            if (k == actual->getDato()) {
                delete nuevo;
                return false;
            }
            padre = actual;
            if (k < actual->getDato()) {
                actual = actual->getIzdo();
            } else {
                actual = actual->getDcho();
            }
        }
        if (k < padre->getDato()) {
            padre->setIzdo(nuevo);
        } else {
            padre->setDcho(nuevo);
        }
        return true;
    }

    bool buscar(const Key& k) const override {
        NodoB<Key>* actual = this->getRaiz();
        while (actual != nullptr) {
            if (k == actual->getDato()) {
                return true;
            } else if (k < actual->getDato()) {
                actual = actual->getIzdo();
            } else {
                actual = actual->getDcho();
            }
        }
        return false;
    }

    void inorden() const override {
        inorden(this->getRaiz());
        std::cout << std::endl;
    }

private:
    void inorden(NodoB<Key>* nodo) const {
        if (nodo != nullptr) {
            inorden(nodo->getIzdo());
            std::cout << nodo->getDato() << " ";
            inorden(nodo->getDcho());
        }
    }
};

#endif /* ABB_H */
