#include "PowerUp.hpp"
#include "ASCII_Engine/SpriteView.hpp"
#include "ASCII_Engine/core/SpriteLinha.hpp"

PowerUp::PowerUp(int x, int y, TipoPowerUp tipo)
    : PosicaoX(x), PosicaoY(y), Tipo(tipo), Ativo(true) {
    switch (tipo) {
        case DUPLICAR_BOLA:     Caracter = 'D'; break;
        case ACELERAR_BOLA:     Caracter = 'V'; break;
        case LENTIDÃO_BOLA:     Caracter = 'L'; break;
        case ACELERAR_RAQUETE:  Caracter = '>'; break;
        case LENTIDÃO_RAQUETE:  Caracter = '<'; break;
    }
}

void PowerUp::Atualizar() {
    PosicaoY++;
    if (PosicaoY >= 24) Ativo = false; // Fora da tela
}

void PowerUp::Desenhar() {
    if (!Ativo) return;

    SpriteLinha powerupSprite(std::string(1, Caracter));
    SpriteView powerupView(powerupSprite, 0, 0, 1, 1);
    powerupView.moveTo(PosicaoY, PosicaoX);
    powerupView.draw(powerupSprite, PosicaoY, PosicaoX);
}

bool PowerUp::ColidiuComRaquete(const Raquete& raquete) {
    if (PosicaoY == raquete.GetPosicaoY()) {
        if (PosicaoX >= raquete.GetPosicaoX() &&
            PosicaoX < raquete.GetPosicaoX() + raquete.GetLargura()) {
            Ativo = false;
            return true;
        }
    }
    return false;
}

TipoPowerUp PowerUp::GetTipo() const {
    return Tipo;
}

bool PowerUp::EstaAtivo() const {
        return Ativo;
}