#include <iostream>
#include <stdexcept>

class Personagem {
private:
    int hp;

public:
    Personagem(int vida) {
        if (vida <= 0) {
            throw std::invalid_argument("HP inicial inválido!");
        }
        hp = vida;
    }

    void receber_dano(int dano) {
        if (dano < 0) {
            throw std::invalid_argument("Dano inválido!");
        }

        hp -= dano;

        if (hp < 0) {
            hp = 0; // trava
        }
    }

    int get_hp() {
        return hp;
    }
};

int main() {
    std::cout << "=== TESTE PERSONAGEM ===" << std::endl;

    try {
        Personagem p(100);
        p.receber_dano(9999); // 🧟 ataque

        std::cout << "HP após dano: " << p.get_hp() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    return 0;
}
