#include <gtest/gtest.h>
#include "npc.hpp"
#include "pegas.hpp"
#include "dragon.hpp"
#include "knight.hpp"

TEST(NPCInteractions, test1) {
    std::shared_ptr<NPC> pegas = std::make_shared<Pegas>(0, 0);
    std::shared_ptr<NPC> knight = std::make_shared<Knight>(1, 1);

    bool murder = pegas->accept(knight);
    ASSERT_FALSE(murder);
}

TEST(NPCInteractions, test2) {
    std::shared_ptr<NPC> pegas = std::make_shared<Pegas>(0, 0);
    std::shared_ptr<NPC> dragon = std::make_shared<Dragon>(1, 1);

    bool murder = pegas->accept(dragon);
    ASSERT_TRUE(murder);
}

TEST(NPCInteractions, test3) {
    std::shared_ptr<NPC> bandit1 = std::make_shared<Pegas>(0, 0);
    std::shared_ptr<NPC> bandit2 = std::make_shared<Pegas>(1, 1);

    bool murder = bandit1->accept(bandit2);
    ASSERT_FALSE(murder);
}

TEST(NPCInteractions, test4) {
    std::shared_ptr<NPC> knight1 = std::make_shared<Knight>(0, 0);
    std::shared_ptr<NPC> knight2 = std::make_shared<Knight>(1, 1);

    bool murder = knight1->accept(knight2);
    ASSERT_FALSE(murder);
}

TEST(NPCInteractions, test5) {
    std::shared_ptr<NPC> knight = std::make_shared<Knight>(0, 0);
    std::shared_ptr<NPC> dragon = std::make_shared<Dragon>(1, 1);

    bool murder = knight->accept(dragon);
    ASSERT_FALSE(murder);
}

TEST(NPCInteractions, test6) {
    std::shared_ptr<NPC> knight = std::make_shared<Knight>(0, 0);
    std::shared_ptr<NPC> pegas = std::make_shared<Pegas>(1, 1);

    bool murder = knight->accept(pegas);
    ASSERT_FALSE(murder);
}

TEST(NPCInteractions, test7) {
    std::shared_ptr<NPC> dragon = std::make_shared<Dragon>(0, 0);
    std::shared_ptr<NPC> knight = std::make_shared<Knight>(1, 1);

    bool murder = dragon->accept(knight);
    ASSERT_TRUE(murder);
}

TEST(NPCInteractions, test8) {
    std::shared_ptr<NPC> dragon1 = std::make_shared<Dragon>(0, 0);
    std::shared_ptr<NPC> dragon2 = std::make_shared<Dragon>(1, 1);

    bool murder = dragon1->accept(dragon2);
    ASSERT_FALSE(murder);
}

TEST(NPCInteractions, test9) {
    std::shared_ptr<NPC> dragon = std::make_shared<Dragon>(0, 0);
    std::shared_ptr<NPC> pegas = std::make_shared<Pegas>(1, 1);

    bool murder = dragon->accept(pegas);
    ASSERT_FALSE(murder);
}


int main(int argc, char** argv){

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}