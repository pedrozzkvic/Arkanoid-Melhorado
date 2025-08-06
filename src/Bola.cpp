#include "Bola.hpp"

#include "ASCII_Engine/SpriteView.hpp"
#include "ASCII_Engine/core/SpriteLinha.hpp"

Bola::Bola(int X, int Y, int Vx, int Vy, char Caracter)
    : PosicaoX(X), PosicaoY(Y), VelocidadeX(Vx), VelocidadeY(Vy), Caracter(Caracter) {}

void Bola::Mover() {
    PosicaoX += VelocidadeX;
    PosicaoY += VelocidadeY;

    if (PosicaoX <= 0 || PosicaoX >= 79)
        VelocidadeX *= -1;

    if (PosicaoY <= 0)
        VelocidadeY *= -1;

    // Se quiser detectar a parte inferior (como "game over"):
    // if (PosicaoY >= 23) VelocidadeY *= -1;  // ou reset*
}

void Bola::Desenhar() {
    SpriteLinha bolaSprite(std::string(1, Caracter));
    SpriteView bolaView(bolaSprite, 0, 0, 1, 1);
    bolaView.moveTo(PosicaoY, PosicaoX);
    bolaView.draw(bolaSprite, PosicaoY, PosicaoX);
}

void Bola::ChecarColisaoRaquete(Raquete& raquete) {
    if (PosicaoY == raquete.GetPosicaoY() - 1) {
        if (PosicaoX >= raquete.GetPosicaoX() &&
            PosicaoX < raquete.GetPosicaoX() + raquete.GetLargura()) {
            VelocidadeY *= -1;
        }
    }
}

void Bola::ChecarColisaoBloco(std::vector<Bloco>& blocos) {
    for (auto& bloco : blocos) {
        if (!bloco.FoiDestruido() &&
            PosicaoX >= bloco.GetX() &&
            PosicaoX < bloco.GetX() + bloco.GetLargura() &&
            PosicaoY == bloco.GetY()) {
            VelocidadeY *= -1;
            bloco.Quebrar();
            break;
        }
    }
}

int Bola::GetX() const {
    return PosicaoX;
}

int Bola::GetY() const {
    return PosicaoY;
}

void Bola::InverterVelocidadeY() {
    VelocidadeY *= -1;
}