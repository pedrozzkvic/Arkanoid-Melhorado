#pragma once

class Bloco {
private:
    int PosicaoX, PosicaoY;
    int Largura;
    bool Quebrado;

public:
    Bloco(int X, int Y, int Largura = 6);
    void Desenhar();
    void Quebrar();
    bool FoiDestruido() const;
    int GetX() const;
    int GetY() const;
    int GetLargura() const;
};