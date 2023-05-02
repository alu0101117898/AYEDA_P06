#ifndef AB_H
#define AB_H

#include <iostream>
#include <queue>
#include "NodoB.h"

template <typename Key>
class AB {
protected:
    NodoB<Key>* raiz;

public:
    AB() : raiz(nullptr) {}
    virtual ~AB() {}

    bool esVacio() const { return raiz == nullptr; }
    NodoB<Key>* getRaiz() const { return raiz; }
    void setRaiz(NodoB<Key>* n) { raiz = n; }

    virtual bool insertar(const Key& k) = 0;
    virtual bool buscar(const Key& k) const = 0;
    virtual void inorden() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const AB<Key>& ab) {
        if (ab.esVacio()) {
            os << "Árbol vacío" << std::endl;
            return os;
        }

        std::queue<NodoB<Key>*> q;
        q.push(ab.raiz);
        int nivel = 0;
        while (!q.empty()) {
            int n = q.size();
            os << "Nivel " << nivel << ": ";
            for (int i = 0; i < n; i++) {
                NodoB<Key>* nodo = q.front();
                q.pop();
                if (nodo == nullptr) {
                    os << "[.] ";
                } else {
                    os << "[" << nodo->getDato() << "] ";
                    q.push(nodo->getIzdo());
                    q.push(nodo->getDcho());
                }
            }
            os << std::endl;
            nivel++;
        }
        return os;
    }
};

#endif /* AB_H */
