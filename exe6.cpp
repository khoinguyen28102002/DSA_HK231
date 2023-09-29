#include<iostream>

using namespace std;

void RepeatString(string &str, const string repeat, int times){
    if(times > 0){
        str += repeat;
        RepeatString(str, repeat, times-1);
    }
    return;
}
string expand(const string& s, size_t& index) {
    if (index >= s.length() || s[index] == ')') return "";
    string result;
    if (isdigit(s[index])) {
        int count = s[index] - '0';  // Convert digit character to integer
        index++;
        if (s[index] == '(') {
            index++; 
            string subResult = expand(s, index);
            RepeatString(result, subResult, count);
        }
    } else if (isalpha(s[index])) 
        result += s[index];
    index++;
    result += expand(s, index);
    return result;
}

string expand(string s) {
    size_t index = 0;
    return expand(s, index);
}
int main(){
    cout << expand("2(ab3(cde)x)") << "\n";
    return 0;
}