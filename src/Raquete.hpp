#pragma once
#include "ASCII_SpriteView.hpp"


class Raquete{
    private:
        int PosicaoX, PosicaoY, Largura;
        char Caracter;
        SpriteView SpriteRaquete

    public:
        Raquete(int X, int Y, int Largura, char Caracter);
        void MoverEsquerda();
        void MoverDireita();
        void Desenhar();
        int GetPosicaoX();
        int GetLargura();        

};