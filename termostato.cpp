#include <iostream>
#include <stdexcept>

class Termostato {
private:
    double temperatura;

    void validar(double t) {
        if (t < 15 || t > 35) {
            throw std::out_of_range("Temperatura fora do intervalo seguro!");
        }
    }

public:
    Termostato(double t) {
        validar(t);
        temperatura = t;
    }

    void definir_temperatura(double t) {
        validar(t);
        temperatura = t;
    }

    double get_temperatura() {
        return temperatura;
    }
};

int main() {
    std::cout << "=== TESTE TERMOSTATO ===" << std::endl;

    try {
        Termostato t(20);
        t.definir_temperatura(900); // 🔥 ataque
    } catch (const std::exception& e) {
        std::cout << "Bloqueado: " << e.what() << std::endl;
    }

    return 0;
}
