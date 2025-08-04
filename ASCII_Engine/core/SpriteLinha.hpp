#pragma once
#include "SpriteBase.hpp"
#include <string>

class SpriteLinha : public SpriteBase {
public:
    SpriteLinha(const std::string& linha) {
        sprt.push_back(linha);
        limits.emplace_back(0, linha.size() - 1, linha.size());
    }

    SpriteBase* copia() const override {
        return new SpriteLinha(*this);
    }

    std::string getLinha(unsigned l) const override {
        return sprt.at(l);
    }

    void init() override {}
    void update() override {}
};