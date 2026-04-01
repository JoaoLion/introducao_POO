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

    double temp;

    try {
        std::cout << "Digite a temperatura inicial: ";
        std::cin >> temp;

        Termostato t(temp);

        std::cout << "Digite a nova temperatura: ";
        std::cin >> temp;

        t.definir_temperatura(temp);

        std::cout << "Temperatura atual: " << t.get_temperatura() << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Bloqueado: " << e.what() << std::endl;
    }

    return 0;
}
