#include "pegas.hpp"
#include "dragon.hpp"
#include "knight.hpp"

Pegas::Pegas(int x, int y) : NPC(PegasType, x, y) {}
Pegas::Pegas(std::istream &is) : NPC(PegasType, is) {}

void Pegas::print() {
    std::cout << *this;
}

void Pegas::print(std::ostream &outfs) {
    outfs << *this;
}

void Pegas::save(std::ostream &os) {
    os << PegasType << std::endl;
    NPC::save(os);
}
// bool Pegas::is_Pegas() const {
//     return true;
// }

bool Pegas::accept(std::shared_ptr<NPC> visitor) {
    std::shared_ptr<Pegas> This = std::make_shared<Pegas>(*this);
    return visitor->visit(This);
}

bool Pegas::fight(std::shared_ptr<Knight> other) {
    fight_notify(other, false);
    return false;
}

bool Pegas::fight(std::shared_ptr<Pegas> other) {
    fight_notify(other, false);
    return false;
}

bool Pegas::fight(std::shared_ptr<Dragon> other) {
    fight_notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, Pegas &pegas) {
    os << "pegas: " << *static_cast<NPC *>(&pegas) << std::endl;
    return os;
}