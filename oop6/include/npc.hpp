#pragma once

#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <random>
#include <fstream>
#include <set>
#include <math.h>

struct NPC;
struct Knight;
struct Pegas;
struct Dragon;

using set_t = std::set<std::shared_ptr<NPC>>;

enum NpcType {
    Unknown = 0,
    KnightType = 1,
    PegasType = 2,
    DragonType = 3
};
// ссылка на файт обсёрвер, то есть вызов обзёрверв, который будет там вызываться при убиении
struct IFightObserver { 
    virtual void on_fight(const std::shared_ptr<NPC> attacker,const std::shared_ptr<NPC> defender,bool win) = 0;
};

struct NPC : public std::enable_shared_from_this<NPC> {
    NpcType type;
    int x{0};
    int y{0};
    std::vector<std::shared_ptr<IFightObserver>> observers;

    NPC(NpcType t, int _x, int _y);
    NPC(NpcType t, std::istream &is);

    void subscribe(std::shared_ptr<IFightObserver>observer ); //add_observer
    void fight_notify(const std::shared_ptr<NPC> defender,bool win); // методы работы с обзёрвером
    virtual bool is_close(const std::shared_ptr<NPC> &other, size_t distance) const;

    // virtual bool is_knight() const;
    // virtual bool is_Pegas() const;
    // virtual bool is_Dragon() const ;

    // вместо
    virtual bool accept(std::shared_ptr<NPC> visitor) = 0;
    bool visit(std::shared_ptr<Knight> ref);
    bool visit(std::shared_ptr<Pegas> ref);
    bool visit(std::shared_ptr<Dragon> ref);
    //

    virtual bool fight(std::shared_ptr<Knight> other) = 0;
    virtual bool fight(std::shared_ptr<Pegas> other) = 0;
    virtual bool fight(std::shared_ptr<Dragon> other) = 0;
    virtual void print() = 0;
    virtual void print(std::ostream &os) = 0;

    virtual void save(std::ostream &os); /// сохранение в поток

    friend std::ostream &operator<<(std::ostream &os, NPC &npc);
};