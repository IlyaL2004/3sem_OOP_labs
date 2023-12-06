#include "pegas.hpp"
#include "dragon.hpp"
#include "knight.hpp"

Dragon::Dragon(int x, int y) : NPC(DragonType, x, y) {}
Dragon::Dragon(std::istream &is) : NPC(DragonType, is) {}

void Dragon::print() {
    std::cout << *this;
}

void Dragon::print(std::ostream &outfs) {
    outfs << *this;
}

void Dragon::save(std::ostream &os) {
    os << DragonType << std::endl;
    NPC::save(os);
}

// bool Dragon::is_Dragon() const {
//     return true;
// }

bool Dragon::accept(std::shared_ptr<NPC> visitor) {
    std::shared_ptr<Dragon> This = std::make_shared<Dragon>(*this);
    return visitor->visit(This);
}


bool Dragon::fight(std::shared_ptr<Pegas> other) {
    fight_notify(other, true);
    return true;
}

bool Dragon::fight(std::shared_ptr<Knight> other) {
    fight_notify(other, false);
    return false;
}

bool Dragon::fight(std::shared_ptr<Dragon> other) {
    fight_notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, Dragon &dragon) {
    os << "dragon: " << *static_cast<NPC *>(&dragon) << std::endl;
    return os;
}