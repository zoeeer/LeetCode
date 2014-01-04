#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        string::iterator it;
        for (it = s.begin(); it != s.end(); ++it) {
            if (*it == '(' || *it == '[' || *it == '{')
                stack.push_back(*it);
            else if (*it == ')' || *it == ']' || *it == '}') {
                if (!stack.empty() 
                    && (*it == ')' && *(stack.end()-1) == '('
                     || *it == ']' && *(stack.end()-1) == '['
                     || *it == '}' && *(stack.end()-1) == '{'))
                    stack.pop_back();
                else
                    return false;
            }
        }
        return stack.empty();
    }
};
