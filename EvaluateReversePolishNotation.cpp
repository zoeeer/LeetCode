/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another 
expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {

        vector<int> ops;

        for (vector<string>::iterator token = tokens.begin();
                token != tokens.end(); ++token) {

            if (isdigit((*token)[0]) || (*token).size() > 1 )
                ops.push_back(atoi((*token).c_str()));

            else {
                int val = ops.back();
                ops.pop_back();
                if (*token == "+")
                    ops.back() += val;
                else if (*token == "-")
                    ops.back() -= val;
                else if (*token == "*")
                    ops.back() *= val;
                else if (*token == "/")
                    ops.back() /= val;
            }
        }

        return ops.back();
    }
};
