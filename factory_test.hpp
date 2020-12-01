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

TEST(SingleFactoryTest, FirstNullTest) {
    char* test[1];
    test[0] = "./calculator";
    Factory* f = new Factory();
    Base* test1 = f->parse(test, 1);
	EXPECT_TRUE(test1 == nullptr); 
	cout << "Invalid Input" << endl;
}

TEST(SingleFactoryTest, SecondNullTest) {
	char* test[2];
	test[0] = "./calculator"; test[1] = "h";
	Factory* f = new Factory();
	Base* test1 = f->parse(test, 2);
	EXPECT_TRUE(test1 == nullptr);
}

TEST(SingleFactoryTest, AddTest) {
    char* test[4];
    test[0] = "./calculator"; test[1] = "3"; test[2] = "+"; test[3] = "2";
    Factory* f = new Factory();
    Base* test1 = f->parse(test, 4);
    string st = test1->stringify();
    double val = test1->evaluate();
    EXPECT_EQ("3.000000 + 2.000000", st);
    EXPECT_EQ(5, val);
}
TEST(SingleFactoryTest, SubTest) {
    char* test[4];
    test[0] = "./calculator"; test[1] = "6"; test[2] = "-"; test[3] = "1";
    Factory* f = new Factory();
	Base* test1 = f->parse(test, 4);
	string st = test1->stringify();
	double val = test1->evaluate();
	EXPECT_EQ("6.000000 - 1.000000", st);
	EXPECT_EQ(5, val);
}

TEST(SingleFactoryTest, MultTest) {
	char* test[4];
	test[0] = "./calculator"; test[1] = "3"; test[2] = "*"; test[3] = "5";
	Factory* f = new Factory();
	Base* test1 = f->parse(test, 4);
	string st = test1->stringify();
	double val = test1->evaluate();
	EXPECT_EQ("3.000000 * 5.000000", st);
	EXPECT_EQ(15, val);
}

TEST(SingleFactoryTest, DivTest) {
	char* test[4];
	test[0] = "./calculator"; test[1] = "10"; test[2] = "/"; test[3] = "5";
	Factory* f = new Factory();
	Base* test1 = f->parse(test, 4);
	string st = test1->stringify();
	double val = test1->evaluate();
	EXPECT_EQ("10.000000 / 5.000000", st);
	EXPECT_EQ(2, val);
}

TEST(SingleFactoryTest, PowTest) {
	char* test[4];
	test[0] = "./calculator"; test[1] = "5"; test[2] = "**"; test[3] = "2";
	Factory* f = new Factory();
	Base* test1 = f->parse(test, 4);
	string st = test1->stringify();
	double val = test1->evaluate();
	EXPECT_EQ("5.000000 ** 2.000000", st);
	EXPECT_EQ(25, val);
}

TEST(DoubleFactoryTest, AddMultTest) {
    char* test[6];
    test[0] = "./calculator"; test[1] = "3"; test[2] = "+"; test[3] = "2"; test[4] = "*"; test[5] = "3";
    Factory* f = new Factory();
    Base* test1 = f->parse(test, 6);
    string st = test1->stringify();
    double val = test1->evaluate();
    EXPECT_EQ("3.000000 + 2.000000 * 3.000000", st);
    EXPECT_EQ(15, val);
}

TEST(DoubleFactoryTest, MultSubTest) {
    char* test[6];
    test[0] = "./calculator"; test[1] = "3"; test[2] = "*"; test[3] = "2"; test[4] = "-"; test[5] = "3";
    Factory* f = new Factory();
    Base* test1 = f->parse(test, 6);
    string st = test1->stringify();
    double val = test1->evaluate();
    EXPECT_EQ("3.000000 * 2.000000 - 3.000000", st);
    EXPECT_EQ(3, val);
}

TEST(DoubleFactoryTest, SubDivTest) {
    char* test[6];
    test[0] = "./calculator"; test[1] = "60"; test[2] = "-"; test[3] = "30"; test[4] = "/"; test[5] = "2";
    Factory* f = new Factory();
    Base* test1 = f->parse(test, 6);
    string st = test1->stringify();
    double val = test1->evaluate();
    EXPECT_EQ("60.000000 - 30.000000 / 2.000000", st);
    EXPECT_EQ(15, val);
}

TEST(DoubleFactoryTest, DivPowTest) {
    char* test[6];
    test[0] = "./calculator"; test[1] = "22"; test[2] = "/"; test[3] = "2"; test[4] = "**"; test[5] = "2";
    Factory* f = new Factory();
    Base* test1 = f->parse(test, 6);
    string st = test1->stringify();
    double val = test1->evaluate();
    EXPECT_EQ("22.000000 / 2.000000 ** 2.000000", st);
    EXPECT_EQ(121, val);
}

TEST(TripleFactoryTest, AddMultDivTest) {
    char* test[8];
    test[0] = "./calculator"; test[1] = "3"; test[2] = "+"; test[3] = "2"; test[4] = "*"; test[5] = "6"; test[6] = "/"; test[7] = "2";
    Factory* f = new Factory();
    Base* test1 = f->parse(test, 8);
    string st = test1->stringify();
    double val = test1->evaluate();
    EXPECT_EQ("3.000000 + 2.000000 * 6.000000 / 2.000000", st);
    EXPECT_EQ(15, val);
}

TEST(TripleFactoryTest, SubPowDivTest) {
    char* test[8];
    test[0] = "./calculator"; test[1] = "30"; test[2] = "-"; test[3] = "10"; test[4] = "**"; test[5] = "2"; test[6] = "/"; test[7] = "4";
    Factory* f = new Factory();
    Base* test1 = f->parse(test, 8);
    string st = test1->stringify();
    double val = test1->evaluate();
    EXPECT_EQ("30.000000 - 10.000000 ** 2.000000 / 4.000000", st);
    EXPECT_EQ(100, val);
}

TEST(TripleFactoryTest, PowMultAddTest) {
    char* test[8];
    test[0] = "./calculator"; test[1] = "3"; test[2] = "**"; test[3] = "2"; test[4] = "*"; test[5] = "3"; test[6] = "+"; test[7] = "3";
    Factory* f = new Factory();
    Base* test1 = f->parse(test, 8);
    string st = test1->stringify();
    double val = test1->evaluate();
    EXPECT_EQ("3.000000 ** 2.000000 * 3.000000 + 3.000000", st);
    EXPECT_EQ(30, val);
}




#endif
