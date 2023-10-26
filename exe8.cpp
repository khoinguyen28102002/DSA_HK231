#include<iostream>

using namespace std;

bool isValidParentheses (string s){
    /*TODO*/
    if(s.size()%2){
        return false;
    }
    else{
        int i = 0;
        while(s[i] != '\0'){
            if((s[i] == '(' &&  s[i+1] == ')') || (s[i] == '[' &&  s[i+1] == ']') || (s[i] == '{' &&  s[i+1] == '}')){
                s.erase(s.begin()+i);
                s.erase(s.begin()+i);
                i =0;
            }
            else{
                if((s[i] == '(' &&  s[s.size()-i-1] == ')') || (s[i] == '[' &&  s[s.size()-1-i] == ']') || (s[i] == '{' &&  s[s.size()-1-i] == '}')){
                    s.erase(s.begin() + (s.size()-i-1));
                    s.erase(s.begin() + i);
                    i = 0;
                }
                else{
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    cout << isValidParentheses("[]()");
    return 0;
}