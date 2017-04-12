#include<string>
#include<stack>
#include<iostream>
#include<assert.h>
#include <map>

bool valid_parentheses(std::string s){
    std::stack<char> stk;
    std::map<char, char> bkts = {
            {'{','}'},
            {'[',']'},
            {'(',')'}
    };

    for(auto ch : s){
        if(bkts.find(ch) != bkts.end()) stk.push(ch);
        else {
            if(stk.size()>0 && bkts[stk.top()] == ch)
                stk.pop();
            else {
                return false;
            }
        }
    }

    return stk.empty();
}

int vmain() {
    assert(valid_parentheses("{{}}") == 1);
    assert(valid_parentheses("{}{}{}") == 1);

    assert(valid_parentheses("{{}") == 0);
    assert(valid_parentheses("{}{}{{}}}{}") == 0);
    assert(valid_parentheses("{}{}}{") == 0);
    assert(valid_parentheses("{}{}{{") == 0);

    assert(valid_parentheses("{}[]()") == 1);
    assert(valid_parentheses("{}[()") == 0);

    assert(valid_parentheses("{[{](})}") == 0);
    std::cout << "All tests passed";
}
