//
// Created by aleca on 8/28/2025.
//

#ifndef COLACIRCULAR_H
#define COLACIRCULAR_H

#include "ColaEspera.h"
#include "Paquete.h"

struct Nodo {
    Paquete paquete;
    Nodo* siguiente;
};


class ColaCircular {

private:
    Nodo* frente;
    Nodo* final;
    int cantidad;
    int tam=10;
public:
    ColaCircular() : frente(nullptr), final(nullptr) {}

    ~ColaCircular() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    bool estaVacia() const {
        return frente == nullptr;
    }

    bool verificarEspacio() {
        if (estaVacia()) return true; // si no hay nada, hay campo

        int contador = 1;
        Nodo* actual = frente;

        // recorremos hasta volver al frente
        while (actual->siguiente != frente) {
            contador++;
            actual = actual->siguiente;
        }

        // Si todavía no llegó al máximo → hay campo
        return (contador < MAX);
    }

    void meter(const Paquete& p, ColaEspera& e)
    {
        if (verificarEspacio())
        {
            Nodo* nuevo = new Nodo{p, nullptr};
            if (e.verificarEspacio()){

                if (estaVacia()) {
                    frente = final = nuevo;
                    final->siguiente = frente;  // circularidad
                } else {
                    final->siguiente = nuevo;
                    final = nuevo;
                    final->siguiente = frente;  // mantener circularidad
                }
                size++; // aumentamos el contador
            } else
            {
                // Si la cola está llena, mandar el paquete a la cola de espera
                e.encolar(p);
            }
        }

    }

    //if(primero verificamos si hay campo en la circular){
    //insertar

    //}else if(verificmos si en la de esper`a hay campo){



};



#endif //COLACIRCULAR_H
