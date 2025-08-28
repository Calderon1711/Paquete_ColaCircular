#ifndef PAQUETE_H
#define PAQUETE_H

#include <iostream>
#include <string>
using namespace std;

struct Paquete {
    string remitente;
    string destinatario;
    string localidad;
    float peso;

    void mostrar() const {
        cout << "Remitente: " << remitente
             << ", Destinatario: " << destinatario
             << ", Localidad: " << localidad
             << ", Peso: " << peso << " kg" << endl;
    }
};

#endif
