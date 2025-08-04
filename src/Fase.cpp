#include "Fase.hpp"

Fase::Fase(int numero) : numeroFase(numero) {
    switch (numeroFase) {
        case 1: Velocidade = 80000; break; // Fácil
        case 2: Velocidade = 50000; break; // Médio
        case 3: Velocidade = 30000; break; // Difícil
        default: Velocidade = 60000; break; // Intermediário por padrão
    }
}

std::vector<Bloco> Fase::CriarBlocos() const {
    std::vector<Bloco> Blocos;

    int linhas = numeroFase + 1;
    int colunas = 8 + numeroFase * 2;
    int larguraBloco = 6; // Valor arbitrário razoável

    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            int posX = 5 + j * (larguraBloco + 1); // Espaçamento horizontal
            int posY = 3 + i * 2; // Espaçamento vertical
            Blocos.emplace_back(posX, posY, larguraBloco);
        }
    }

    return Blocos;
}

int Fase::GetVelocidade() const {
    return Velocidade;
}