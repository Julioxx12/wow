#include "Crupier.h"
#include "Usuario.h"
#include "Juego.h"
#include <iostream>
#include "Mano.h"
#include <cassert>

/*
=================================================================================================================
                                 Implementacion de la clase Crupier
=================================================================================================================
Este archivo implementa la logica del crupier. Se encarga de gestionar las acciones especificas del crupier
dentro del BlackJack, como pedir cartas hasta llegar al minimo permitido, mostrar su mano y tomar decisiones
automaticas basadas en la reglas del juego
=================================================================================================================
*/

Crupier::Crupier() : Usuario() {
    // Estado inicial esperado
    assert(cartaOcultaRevelada == false);
}

void Crupier::MostrarMano() {
    std::cout << "\nMano del crupier:\n";

    // Verificación de estado interno
    assert(mano.contarCartas() >= 0);

    if (!cartaOcultaRevelada) {

        // Debe haber al menos 1 carta para mostrar algo
        if (mano.contarCartas() > 0) {
            assert(mano.contarCartas() >= 1);
            mano.obtenerCartas()[0].MostrarCarta();
        } else {
            std::cout << "  [sin cartas]\n";
        }

        std::cout << "[Carta oculta]\n";
    } 
    else {
        MostrarManoCompleta();
    }
}

void Crupier::RevelarCartaOculta() {
    assert(cartaOcultaRevelada == false);     // No se debería revelar dos veces
    cartaOcultaRevelada = true;
}

void Crupier::MostrarManoCompleta() {
    std::cout << "\nMano del crupier:\n";

    // Validar que al menos haya 1 carta para mostrar
    assert(mano.contarCartas() > 0);

    // Todas las cartas deben ser válidas
    for (const auto &c : mano.obtenerCartas()) {
        assert(c.obtenerNominal() >= 1 && c.obtenerNominal() <= 11);
        c.MostrarCarta();
    }

    int total = mano.calcularSuma();
    assert(total >= 0 && total <= 31);   // Valor lógico esperado

    std::cout << "Valor total: " << total << "\n";
}
