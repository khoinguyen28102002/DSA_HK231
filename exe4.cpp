#include<iostream>
#include<string.h>
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str){
    if (str[0] == ' ')
        return isPalindrome(str.substr(1, str.length()));
    else if (str[str.length()-1] == ' ')
        return isPalindrome(str.substr(0, str.length()-1));
    if (str.length() == 0 || str.length() == 1) {
        return true;
    }
    if (str[0] != str[str.length() - 1]) {
        return false;
    }
    return isPalindrome(str.substr(1, str.length() - 2));
}

 
int main(){

    cout << isPalindrome("mom");
    return 0;
}