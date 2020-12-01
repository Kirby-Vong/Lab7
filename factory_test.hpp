#ifndef __FACTORY_TEST_H__
#define __FACTORY_TEST_H__

#include <iostream>
using namespace std;

#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "div.hpp"
#include "factory.h"

TEST(FactoryTest, AddTest) {
    char* test[4];
    test[0] = "./calculator"; test[1] = "3"; test[2] = "+"; test[3] = "2";
    Factory* f = new Factory();
    Base* test1 = f->parse(test, 4);
    string st = test1->stringify();
    double val = test1->evaluate();
    EXPECT_EQ("3.000000 + 2.000000", st);
    EXPECT_EQ(5, val);
}
TEST(FactoryTest, SubTest) {
    char* test[4];
    test[0] = "./calculator"; test[1] = "6"; test[2] = "-"; test[3] = "1";
    Factory 
#endif
