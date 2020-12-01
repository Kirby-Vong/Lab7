#ifndef __FACTORY_H__
#define __FACTORY_H__

#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include "add.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "sub.hpp"
#include "rand.hpp"
#include "pow.hpp"
#include "op.hpp"
#include "base.hpp"

using namespace std;

class Factory {
    public:
    Factory() {};
    Base* parse(char** input, int length) {
        queue<char*> q;
        stack<char*> s;
        string str;
        //ex - input = 3+2*5
        for(int i = 1; i < length; i++) {
            str = static_cast<string>(input[i]); 
            //str.at(0) = 3
            if(isdigit(str.at(0))) {
                //q.push = {3}
                q.push(input[i]);
            }
            else if(str == "+" || str == "-" || str == "/" || str == "*" || str == "**") {
                while(!s.empty()) {
                    q.push(s.top());
                    s.pop();
                }
                s.push(input[i]);
            } else {
                cout << "Invalid input" << endl;
                return nullptr;
            }
        }
        while(!s.empty()) {
            q.push(s.top());
            s.pop();
        }
        //second queue to keep track of the array
        queue<Base*> qu;
        Base* type;
        Base* p1;
        Base* p2;
        double p3;
        while(!q.empty()) {
            str = static_cast<string>(q.front());
            if(str == "+") {
                p1 = qu.front();
                qu.pop();
                p2 = qu.front();
                qu.pop();
                type = new Add(p1, p2);
                qu.push(type);
                q.pop();
            }
            else if(str == "-") {
                p1 = qu.front();
                qu.pop();
                p2 = qu.front();
                qu.pop();
                type = new Sub(p1, p2);
                qu.push(type);
                q.pop();
            }
            else if(str == "/") {
                p1 = qu.front();
                qu.pop();
                p2 = qu.front();
                qu.pop();
                type = new Div(p1, p2);
                qu.push(type);
                q.pop();
            }
            else if(str == "*") {
                p1 = qu.front();
                qu.pop();
                p2 = qu.front();
                qu.pop();
                type = new Mult(p1, p2);
                qu.push(type);
                q.pop();
            }
            else {
                p3 = stod(str);
                type = new Op(p3);
                q.pop();
                qu.push(type);
            }

        }
        return qu.front();
    }
};
#endif


            
            
            
            
