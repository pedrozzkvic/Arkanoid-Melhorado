#include "Bloco.hpp"
#include "ASCII_Engine/SpriteView.hpp"
#include "ASCII_Engine/core/SpriteLinha.hpp"

Bloco::Bloco(int X, int Y, int Largura)
    : PosicaoX(X), PosicaoY(Y), Largura(Largura), Quebrado(false) {}

void Bloco::Desenhar() {
    if (Quebrado) return;

    // Cria um SpriteLinha com Largura caracteres '#'
    SpriteLinha blocoSprite(std::string(Largura, '#'));

    // Cria uma SpriteView com altura 1 e largura = Largura do bloco
    SpriteView blocoView(blocoSprite, 0, 0, 1, Largura);

    // Move a view para a posição desejada
    blocoView.moveTo(PosicaoY, PosicaoX); // (linha, coluna)

    // Desenha o bloco
    blocoView.draw(blocoSprite, PosicaoY, PosicaoX);
}

void Bloco::Quebrar() {
    Quebrado = true;
}

bool Bloco::FoiDestruido() const {
    return Quebrado;
}

int Bloco::GetX() const { 
    return PosicaoX; 
}

int Bloco::GetY() const { 
    return PosicaoY; 
}

int Bloco::GetLargura() const { 
    return Largura;
}