#include <iostream>

using namespace std;

string temp = "";
void minBracket(string s, int& count){
    if((int)s.find("()") == -1) return ;
    temp = ((int) s.find("(") != -1) ? s.substr(s.find("(")) : s;
    int opN = temp.find(")");
    temp = temp.substr(opN);
    int clN = ((int) temp.find("(") > 0 ) ? temp.find("(") : temp.size();
    if(opN > clN && clN > 0) {
        s.replace(s.find("(") + opN - clN, clN*2, "");
        count -= clN*2;
    }
    else {
        s.replace(s.find("("), opN*2, "");
        count -= opN*2;
    }
    minBracket(s, count);
}
int mininumBracketAdd(string s) {
    // STUDENT ANSWER
    temp = "";
    int count = s.size();
    minBracket(s, count);
    return count;
}

int main() {
    cout << mininumBracketAdd(")()))()))())())))))(") << endl;
    cout << mininumBracketAdd(")))((") << endl;
    cout << mininumBracketAdd("))()))()()") << endl;
    cout << mininumBracketAdd("") << endl;
    cout << mininumBracketAdd(")))))))") << endl;
    cout << mininumBracketAdd("(((((((") << endl;
    cout << mininumBracketAdd(")()))()))())())))))(") << endl;
    cout << mininumBracketAdd(")())(((())()())()())))()()))(()((((()(()()()))()((())((()))))))()(((()(((())(((()()(())(())))))(()))") << endl;
    cout << mininumBracketAdd(")(()())())))))(((())))))())))()))))))((())(((()(((())((()(()))())(()(()((((((())))(((()))))((())((()()))((())(()(((()())()()())(())())))(()))()))((((()()(()))()))))()()()(()))()))()())()(()())))())())()))())())((()()(())((()()(((()((()((((((((())()()())(()()()))()()()())()(()(())())((()))((((()((((((()((()))))))()))((()())))()()((((()()()(()())((((()((((((())))(()))))(()))))()())())(((())()())()(((())))(())(((()(((())))(((()()(()(((()((()(()))())))))()(()(())()())(((()(()(())()()())()(()()))(((()))()())()))))((()())(())()))(()))())(())))()))())()()(()()(((((()(()()(()()))(()(()(())()((((()((()(()(())))()())((()()(((()))(()))()(())()((()()(((((())(((())(()())()))))()((()))((()))(()())()))()())()))(()((()()()((()()))(())(())(((())()())(())()((())(((()(())(()))(())()(((())((()())((()))(((((()(())()()()()(()(()))(()()())())))))()))))()()))(())(((((((((()))(())))(()))(()))(()((()()(((()))))(()(())((((()))(()))))(()((()((()(((()))()))(()((())()))))(()))(()()))()((((()(((()()(()))()((()(((())") << endl;
    return 0;
}
