#pragma once

#include <vector>
#include "Bloco.hpp"

class Fase {
private:
    int numeroFase;
    int Velocidade;
public:
    Fase(int numero);
    std::vector<Bloco> CriarBlocos() const;
    int GetVelocidade() const;
    // Adicione outros métodos e membros conforme necessário
};