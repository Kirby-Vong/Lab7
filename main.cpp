#include <iostream>
#include "factory.h"


int main(int argv, char** argc) {
    char* test_array[6];
    test_array[0] = "./calculator"; test_array[1] = "1"; test_array[2] = "+"; test_array[3] = "2"; test_array[4] = "\**"; test_array[5] = "3"; 
    Factory* f = new Factory();

    Base* test = f->parse(test_array, 6);


    cout << test->stringify() << endl;

    cout << test->evaluate() << endl;
    return 0;
}

