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
    ColaCircular(int t) : frente(nullptr), final(nullptr)
    {
        cantidad = 0;
        tam = t;
    }

    ~ColaCircular() {
        while (!estaVacia()) {
            quitar();
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
        return (contador < tam);
    }

    Paquete quitar() {
        //verifico si esta vacia, y si est amando paquete vacio
        if (estaVacia()) {
            cout << " Cola vacia, no se puede quitar" << endl;
            return Paquete(); // devuelve un paquete vacío
        }
        //asigno el valor del paquete del frente es el q moveremos a la lista de espera
        Paquete valor = frente->paquete;

        if (frente == final) {
            // si solo había un elemento
            delete frente;
            frente=nullptr;
            final = nullptr;

        } else {
            Nodo* temp = frente;
            frente = frente->siguiente;    // el frente avanza
            final->siguiente = frente;
            delete temp;
        }

        cantidad--;
        return valor;
    }


    void meter(const Paquete& p, ColaEspera& e) {
        //verifico si hay espacio
        if (verificarEspacio()) {
            // Aún hay espacio en la circular
            Nodo* nuevo = new Nodo{p, nullptr};

            if (estaVacia()) {
                // la circular estaba vacía
                frente = final = nuevo;
                final->siguiente = frente;
            } else {
                // insertar al final
                final->siguiente = nuevo;
                final = nuevo;
                final->siguiente = frente;
            }
            cantidad++;
        } else {

            if (e.verificarEspacio()) {
                // hay campo en la cola de espera
                // mover el primer elemento de circular aespera
                Paquete mover = quitar();
                e.encolar(mover);

                // ahora sí insertar el nuevo paquete al final de la circular
                Nodo* nuevo = new Nodo{p, nullptr};
                if (estaVacia()) {
                    frente = final = nuevo;
                    final->siguiente = frente;
                } else {
                    final->siguiente = nuevo;
                    final = nuevo;
                    final->siguiente = frente;
                }
                cantidad++;
            } else {
                cout << " No hay espacio ni en la circular ni en la cola de espera" << endl;
            }
        }
    }

    void mostrar() const {
        //si esta vacia
        if (estaVacia()) {
            cout << "Cola circular vacía" << endl;
            return;
        }

        cout << "Contenido de la cola circular:" << endl;

        Nodo* actual = frente;
        // recorrer hasta volver al frente
        do {
            actual->paquete.mostrar(); // reutilzao el mostrar de paquete
            actual = actual->siguiente;
        } while (actual != frente);
    }



};



#endif //COLACIRCULAR_H
