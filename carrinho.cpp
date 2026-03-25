#include <iostream>
#include <stdexcept>

class Carrinho {
private:
    double total;

public:
    Carrinho() : total(0) {}

    void adicionar_item(double preco) {
        if (preco < 0) {
            throw std::invalid_argument("Preço negativo detectado!");
        }

        total += preco;

        if (total < 0) {
            throw std::logic_error("Total inválido!");
        }
    }

    double get_total() {
        return total;
    }
};

int main() {
    std::cout << "=== TESTE CARRINHO ===" << std::endl;

    try {
        Carrinho c;
        c.adicionar_item(100);
        c.adicionar_item(-50);
    } catch (const std::exception& e) {
        std::cout << "Bloqueado: " << e.what() << std::endl;
    }

    return 0;
}
