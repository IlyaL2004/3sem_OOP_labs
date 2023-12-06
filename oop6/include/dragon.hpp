#pragma once
#include "npc.hpp"

struct Dragon : public NPC {
    Dragon(int x, int y);
    Dragon(std::istream &is);
    void print() override;
    void print(std::ostream &os) override;
    void save(std::ostream &os) override;
    // bool is_Dragon() const override;
    bool accept(std::shared_ptr<NPC> visitor) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Pegas> other) override;
    bool fight(std::shared_ptr<Dragon> other) override;
    friend std::ostream &operator<<(std::ostream &os, Dragon &dragon);
};