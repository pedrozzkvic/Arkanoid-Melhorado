#pragma once

    #include "Bloco.hpp"
#include <vector>

class Raquete;  // Evita include circular

class Bola {
private:
    int PosicaoX, PosicaoY;
    int VelocidadeX, VelocidadeY;
    char Caracter;

public:
    Bola(int X, int Y, int Vx, int Vy, char Caracter = 'o');
    void Mover();
    void Desenhar();
    void ChecarColisaoRaquete(Raquete& raquete);
    void ChecarColisaoBloco(std::vector<Bloco>& blocos);

    // Métodos auxiliares
    int GetX() const;
    int GetY() const;
    void InverterVelocidadeY();
};
