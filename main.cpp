#include <iostream>
#include <unistd.h>
#include <ctime>
#include <vector>

//include
#include "ASCII_Engine/SpriteView.hpp"
#include "ASCII_Engine/input/Keyboard.hpp"

// Suas classes
#include "src/Raquete.hpp"
#include "src/Bola.hpp"
#include "src/Bloco.hpp"
#include "src/Fase.hpp"
#include "src/PowerUp.hpp"

int main() {
    srand(time(nullptr));

    Raquete raquete(35, 25, 10, '=');
    Bola bola(40, 24, -1, -1, 'O');

    Fase faseAtual(1);
    std::vector<Bloco> blocos = faseAtual.CriarBlocos();
    std::vector<PowerUp> powerups;

    bool Rodando = true;
    while (Rodando) {
        system("clear");

        // Entrada do usuário
        // Usa Keyboard em modo não bloqueante para ler tecla
        Keyboard::setMode(Keyboard::NONBLOCKING);
        char Tecla = Keyboard::read();
        if (Tecla != -1) {
            if (Tecla == 'a' || Tecla == 'A') raquete.MoverEsquerda();
            if (Tecla == 'd' || Tecla == 'D') raquete.MoverDireita();
            if (Tecla == 'q' || Tecla == 'Q') Rodando = false;
        }
        Keyboard::setMode(Keyboard::BLOCKING);

        bola.Mover();
        bola.ChecarColisaoRaquete(raquete);

        // Checar colisão com blocos e gerar powerups
        for (auto& bloco : blocos) {
            if (!bloco.FoiDestruido() &&
                bola.GetX() >= bloco.GetX() &&
                bola.GetX() < bloco.GetX() + bloco.GetLargura() &&
                bola.GetY() == bloco.GetY()) {

                bloco.Quebrar();
                bola.InverterVelocidadeY();

                // Chance de gerar PowerUp
                if (rand() % 4 == 0) {
                    TipoPowerUp tipo = static_cast<TipoPowerUp>(rand() % 5);
                    powerups.emplace_back(bloco.GetX(), bloco.GetY(), tipo);
                }

                break; // Evita múltiplas colisões simultâneas
            }
        }

        // Atualizar powerups
        for (auto it = powerups.begin(); it != powerups.end(); ) {
            it->Atualizar();
            if (it->ColidiuComRaquete(raquete)) {
                // Aqui você pode aplicar o efeito específico de cada tipo
                it = powerups.erase(it);
            } else {
                ++it;
            }
        }

        // Renderização
        raquete.Desenhar();
        bola.Desenhar();
        for (auto& bloco : blocos) bloco.Desenhar();
        for (auto& p : powerups) p.Desenhar();

        usleep(faseAtual.GetVelocidade());
    }

    return 0;
}