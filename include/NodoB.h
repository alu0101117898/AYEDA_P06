#ifndef NODOB_H
#define NODOB_H

template <typename Key>
class NodoB {
protected:
    Key dato;
    NodoB<Key>* izdo;
    NodoB<Key>* dcho;

public:
    NodoB(const Key& d) : dato(d), izdo(nullptr), dcho(nullptr) {}
    virtual ~NodoB() {}

    Key getDato() const { return dato; }
    NodoB<Key>* getIzdo() const { return izdo; }
    NodoB<Key>* getDcho() const { return dcho; }
    void setIzdo(NodoB<Key>* n) { izdo = n; }
    void setDcho(NodoB<Key>* n) { dcho = n; }
};

#endif /* NODOB_H */
