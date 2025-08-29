
#ifndef COLAESPERA_H
#define COLAESPERA_H

#include "Paquete.h"

struct NodoEspera {
    Paquete paquete;
    NodoEspera* siguiente;
};

class ColaEspera {
private:

    NodoEspera* frente;
    NodoEspera* final;
    int cantidad;
    int tam;

public:
    ColaEspera(int cap = 5) {
        frente = final = nullptr;
        cantidad = 0;
        tam = cap;
    }


    bool estaVacia() const {
        return frente == nullptr;
    }

    bool verificarEspacio() const {
        return cantidad < tam;
    }

    void encolar(const Paquete& p) {

        if (!verificarEspacio()) {
            cout << " Cola de espera llena" << endl;
            return;
        }

        NodoEspera* nuevo = new NodoEspera{p, nullptr};
        if (estaVacia()) {
            frente = final = nuevo;
        } else {
            final->siguiente = nuevo;
            final = nuevo;
        }
        cantidad++;
    }
//mostrar de espera
    void mostrar() const {
        if (estaVacia()) {
            cout << "Cola de espera vacía" << endl;
            return;
        }

        cout << "Contenido de la cola de espera:" << endl;
        NodoEspera* actual = frente;
        while (actual != nullptr) {
            actual->paquete.mostrar();
            actual = actual->siguiente;
        }
    }
};

#endif
