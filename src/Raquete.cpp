#include "Raquete.hpp"

Raquete::Raquete(int X, int Y, int Largura, char Caracter): PosicaoX(X), PosicaoY(Y), Largura(Largura), Caracter(Caracter){}

void Raquete::MoverEsquerda(){
    if(PosicaoX > 0){
        PosicaoX--;
    }
}

void Raquete::MoverDireita(){
    if(PosicaoX + Largura < 80){
        PosicaoX++;
    }
}
//Maximo de 80 pixeis a direita.

void Raquete::Desenhar(){
    for(int i = 0; i < Largura; i++){
        SpriteView p;
        p.setChar(Caracter);
        p.setPosition(PosicaoX + i, PosicaoY);
        p.render();
    }
}

int Raquete::GetPosicaoX() {
    return PosicaoX;
}

int Raquete::GetLargura() {
    return Largura;
}

//1. Encapsulamento
//A classe Raquete encapsula seus atributos x, y largura e 
//expEe apenas os metodos pulicos necessarios MoverEsquerda, MoverDireita, Desenhar).

//2. Abstração
//A funcao main não precisa saber como a raquete eh desenhada nem como ela 
//se move internamente, so chama os métodos e pronto.
