//@Autores : Luis Felipe Velasco Chilito , Alejandro Velez , Julio Cesar , Jeronimo Imbachi , Leonardo Rosero
//@fecha: 16/11/2025

#ifndef CRUPIER_H
#define CRUPIER_H

#include "Usuario.h"
#include <cassert>

/*
=================================================================================================================
                                            TARJETA CRC
=================================================================================================================
CLASE:
     Crupier

RESPONSABILIDADES:
     - Administrar la mano del crupier
     - Robar cartas del mazo
     - Mostrar su mano
     - Seguir las reglas del crupier (pedir hasta valor 17)
COLABORADORES:
     - Mazo
     - Mano
     - Carta
*/
class Crupier : public Usuario {
private:
    bool cartaOcultaRevelada = false;

public:

    // Constructor con verificación de estado inicial
    Crupier() : Usuario() {
    }

    void RevelarCartaOculta();
    void MostrarManoCompleta();
    void MostrarMano();
};

#endif // CRUPIER_H
