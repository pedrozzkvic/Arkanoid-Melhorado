#include "Raquete.hpp"
#include "ASCII_Engine/SpriteView.hpp"
#include "ASCII_Engine/core/SpriteLinha.hpp"

Raquete::Raquete(int X, int Y, int Largura, char Caracter)
    : PosicaoX(X), PosicaoY(Y), Largura(Largura), Caracter(Caracter) {}

void Raquete::MoverEsquerda() {
    if (PosicaoX > 0) {
        PosicaoX--;
    }
}

void Raquete::MoverDireita() {
    if (PosicaoX + Largura < 80) { // Supondo largura máxima da tela
        PosicaoX++;
    }
}

void Raquete::Desenhar() {
    SpriteLinha raqueteSprite(std::string(Largura, Caracter));
    SpriteView raqueteView(raqueteSprite, 0, 0, 1, Largura);
    raqueteView.moveTo(PosicaoY, PosicaoX);
    raqueteView.draw(raqueteSprite, PosicaoY, PosicaoX);
}

int Raquete::GetPosicaoX() const {
    return PosicaoX;
}

int Raquete::GetPosicaoY() const {
    return PosicaoY;
}

int Raquete::GetLargura() const {
    return Largura;
}