#pragma once
#include "ASCII_Engine/SpriteView.hpp"


class Raquete{
    private:
        int PosicaoX, PosicaoY, Largura;
        char Caracter;
        
    public:
        Raquete(int X, int Y, int Largura, char Caracter);
        void MoverEsquerda();
        void MoverDireita();
        void Desenhar();
        int GetPosicaoY() const;
        int GetPosicaoX() const;
        int GetLargura() const ;        

};