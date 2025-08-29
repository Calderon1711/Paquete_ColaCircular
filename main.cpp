#include <iostream>
using namespace std;
#include "Paquete.h"
#include "ColaCircular.h"
#include "ColaEspera.h"

int main() {
    // Creamos colas
    ColaCircular circular(5);   // capacidad 5
    ColaEspera espera(3);       // capacidad 3

    // Crear paquetes de prueba
    Paquete p1("Juan", "Ana", "San José", 1.2);
    Paquete p2("Luis", "Carlos", "Alajuela", 0.8);
    Paquete p3("Pedro", "María", "Cartago", 2.1);
    Paquete p4("Mario", "Sofía", "Heredia", 1.5);
    Paquete p5("Andrés", "Lucía", "Puntarenas", 3.0);
    Paquete p6("Kevin", "Laura", "Limón", 2.8);
    Paquete p7("Esteban", "Daniela", "Guanacaste", 1.0);
    Paquete p8("José", "Fernanda", "San Carlos", 0.9);

    cout << "==== Insertando 5 paquetes en la cola circular ====" << endl;
    circular.meter(p1, espera);
    circular.meter(p2, espera);
    circular.meter(p3, espera);
    circular.meter(p4, espera);
    circular.meter(p5, espera);

    circular.mostrar();
    espera.mostrar();

    cout << "\n==== Insertando paquete 6 (circular llena, se mueve a espera) ====" << endl;
    circular.meter(p6, espera);

    circular.mostrar();
    espera.mostrar();

    cout << "\n==== Insertando paquete 7 (circular llena, se mueve otro a espera) ====" << endl;
    circular.meter(p7, espera);

    circular.mostrar();
    espera.mostrar();

    cout << "\n==== Insertando paquete 8 (circular llena, se mueve otro a espera) ====" << endl;
    circular.meter(p8, espera);

    circular.mostrar();
    espera.mostrar();

    cout << "\n==== Desencolando 2 elementos de la circular ====" << endl;
    Paquete quitado1 = circular.quitar();
    Paquete quitado2 = circular.quitar();
    cout << "Se quitaron: " << endl;
    quitado1.mostrar();
    quitado2.mostrar();

    circular.mostrar();
    espera.mostrar();

    cout << "\n==== Insertando paquete 9 después de desencolar ====" << endl;
    Paquete p9("Ricardo", "Valeria", "Perez Zeledón", 1.7);
    circular.meter(p9, espera);

    circular.mostrar();
    espera.mostrar();

    return 0;
}
