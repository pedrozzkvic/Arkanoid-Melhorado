#pragma once
#include "ASCII_Engine/SpriteView.hpp"
#include "Raquete.hpp"

enum TipoPowerUp {
    DUPLICAR_BOLA,
    ACELERAR_BOLA,
    LENTIDÃO_BOLA,
    ACELERAR_RAQUETE,
    LENTIDÃO_RAQUETE
};

class PowerUp {
private:
    int PosicaoX, PosicaoY;
    TipoPowerUp Tipo;
    char Caracter;
    bool Ativo;

public:
    PowerUp(int x, int y, TipoPowerUp tipo);

    void Atualizar();
    void Desenhar();
    bool ColidiuComRaquete(const Raquete& raquete);
    TipoPowerUp GetTipo() const;
    bool EstaAtivo() const;
};