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

    Carrinho c;
    double preco;

    try {
        std::cout << "Digite o valor do item: ";
        std::cin >> preco;

        c.adicionar_item(preco);

        std::cout << "Total atual do carrinho: " << c.get_total() << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Bloqueado: " << e.what() << std::endl;
    }

    return 0;
}
