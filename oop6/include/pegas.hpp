#pragma once
#include "npc.hpp"

struct Pegas : public NPC {
    Pegas(int x, int y);
    Pegas(std::istream &is);
    void print() override;
    void print(std::ostream &os) override;
    void save(std::ostream &os) override;
    // bool is_Pegas() const override;
    bool accept(std::shared_ptr<NPC> visitor) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Pegas> other) override;
    bool fight(std::shared_ptr<Dragon> other) override;
    friend std::ostream &operator<<(std::ostream &os, Pegas &pegas);
};