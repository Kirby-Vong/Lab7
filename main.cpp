#include <iostream>

#include "factory.h"
#include "div.hpp"
#include "base.hpp"
#include "sub.hpp"
#include "add.hpp"
#include "rand.hpp"
#include "op.hpp"

using namespace std;


int main(int argv, char** argc) {
   // char* test_array[6];
    //test_array[0] = "./calculator"; test_array[1] = "1"; test_array[2] = "+"; test_array[3] = "2"; test_array[4] = "\**"; test_array[5] = "3"; 
    Factory* f = new Factory();

   // Base* test = f->parse(test_array, 6);
    Base* test = f->parse(argc, argv);
    
    if(test == nullptr) {
        cout << "Error, is nullptr" << endl;
    }
    else {
        cout << "String: " <<  test->stringify() << endl;
        cout << "Evaluated string: " <<  test->evaluate() << endl;
    }
return 0;
}

