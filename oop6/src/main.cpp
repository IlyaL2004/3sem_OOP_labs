#include "npc.hpp"
#include "knight.hpp"
#include "pegas.hpp"
#include "dragon.hpp"
#include "fighting.hpp"

std::string logs_file_name = "logs.txt";

// Фабрики -----------------------------------
std::shared_ptr<NPC> factory(std::istream &is) {
    std::shared_ptr<NPC> result;
    int type{0};
    if (is >> type) {
        switch (type) {
        case PegasType:
            result = std::make_shared<Pegas>(is);
            break;
        case KnightType:
            result = std::make_shared<Knight>(is);
            break;
        case DragonType:
            result = std::make_shared<Dragon>(is);
            break;
        }
    }
    else
        std::cerr << "unexpected NPC type:" << type << std::endl;

    if (result)
        result->subscribe(TextObserver::get());
        result->subscribe(FileObserver::get(logs_file_name));
    return result;
}

std::shared_ptr<NPC> factory(NpcType type, int x, int y) {
    std::shared_ptr<NPC> result;
    switch (type) {
    case PegasType:
        std::cout << "Pegas generated\n";
        result = std::make_shared<Pegas>(x, y);
        break;
    case KnightType:
        std::cout << "Knight generated\n";
        result = std::make_shared<Knight>(x, y);
        break;
    case DragonType:
        std::cout << "Dragon generated\n";
        result = std::make_shared<Dragon>(x, y);
        break;
    default:
        break;
    }
    if (result)
        result->subscribe(TextObserver::get());
        result->subscribe(FileObserver::get(logs_file_name));
    // std::cout << type << std::endl;
    return result;
}

// save array to file
void save(const set_t &array, const std::string &filename) {
    std::ofstream fs(filename);
    fs << array.size() << std::endl;
    for (auto &n : array)
        n->save(fs);
    fs.flush();
    fs.close();
}

set_t load(const std::string &filename) {
    set_t result;
    std::ifstream is(filename);
    if (is.good() && is.is_open())
    {
        int count;
        is >> count;
        for (int i = 0; i < count; ++i)
            result.insert(factory(is));
        is.close();
    }
    else
        std::cerr << "Error: " << std::strerror(errno) << std::endl;
    return result;
}

// print to screen
std::ostream &operator<<(std::ostream &os, const set_t &array) {
    for (auto &n : array)
        n->print();
    return os;
}

// ВНИМАНИЕ: метод осуществляющий сражение написан неправильно!
// Переделайте его на использование паттерна Visitor
// То есть внутри цикла вместо кучи условий должно быть:
//
// success = defender->accept(attacker);
//
// В NPC методы типа is_dragon - станут не нужны

set_t fight(const set_t &array, size_t distance) {

    set_t dead_list;

    for (const auto &attacker : array)
        for (const auto &defender : array)
            if ((attacker != defender) && (attacker->is_close(defender, distance))) {
                bool success{false};
                // if (defender->is_Pegas())
                //     success = attacker->fight(std::dynamic_pointer_cast<Pegas>(defender));
                // if (defender->is_knight())
                //     success = attacker->fight(std::dynamic_pointer_cast<Knight>(defender));
                // if (defender->is_Dragon())
                //     success = attacker->fight(std::dynamic_pointer_cast<Dragon>(defender));
                success = defender->accept(attacker);
                if (success)
                    dead_list.insert(defender);
            }

    return dead_list;
}

int main(){

    int seed;
    std::cout << "Enter seed(int) for random generate: ";
    if(!(std::cin >> seed)) {
        std::cout << "Wrong seed format!" << std::endl;
        return 1;
    }
    std::srand(seed);

    set_t array; // npc

    // Гененрируем начальное распределение монстров
    std::cout << "Generating ..." << std::endl;
    for (size_t i = 0; i < 10; ++i) {
        std::shared_ptr<NPC> cur_npc = factory(NpcType(std::rand() % 3 + 1),
                                       std::rand() % 100,
                                       std::rand() % 100);
        array.insert(cur_npc);
    }
    std::cout << "Saving ..." << std::endl;

    save(array, "npc.txt");

    std::cout << "Loading ..." << std::endl;
    array = load("npc.txt");

    std::cout << "Fighting ..." << std::endl << array;

    for (size_t distance = 20; (distance <= 100) && !array.empty(); distance += 10) {
        auto dead_list = fight(array, distance);
        for (auto &d : dead_list)
            array.erase(d);
        std::cout << "Fight stats ----------" << std::endl
                  << "distance: " << distance << std::endl
                  << "killed: " << dead_list.size() << std::endl
                  << std::endl << std::endl;
    }

    std::cout << "Survivors:"  << std::endl << array;

    return 0;
}