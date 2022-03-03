//
// Created by david Scalais on 24/02/2022.
//

#include <iostream>
#include <gtest/gtest.h>

#include "Fighterplane.h"

class FighterplaneTest : public ::testing::Test{
protected:
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp() {
        fighter1 = Fighterplane("Fighter1",0,0,0);
        enemy = Fighterplane("enemy",0,0,0);

        enemypointer = &enemy;
        fighter1pointer = &fighter1;
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {

    }

    // Declares the variables your tests want to use.
    Fighterplane fighter1;
    Fighterplane enemy;
    Fighterplane* enemypointer;
    Fighterplane* fighter1pointer;
};

// Tests the default constructor.
TEST_F(FighterplaneTest, DefaultConstructor) {
    EXPECT_EQ(0, fighter1.getCoords());
    EXPECT_EQ(0, fighter1.getY());
    EXPECT_EQ(0, fighter1.getZ());
    EXPECT_EQ("Fighter1",fighter1.getCallSign());
}

TEST_F(FighterplaneTest, Movefunction)
{
    fighter1.moveTo(-4,-3,-2);
    EXPECT_EQ(-4, fighter1.getCoords());
    EXPECT_EQ(-3, fighter1.getY());
    EXPECT_EQ(-2, fighter1.getZ());
}


TEST_F(FighterplaneTest, Attackfunction)
{
    fighter1.attackPlane(enemypointer);
    EXPECT_EQ(9,fighter1.getAmmo());
    EXPECT_EQ(15,enemypointer->getHealth());
    enemy.attackPlane(fighter1pointer);
    EXPECT_EQ(9,enemy.getAmmo());
    EXPECT_EQ(15,fighter1pointer->getHealth());
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}