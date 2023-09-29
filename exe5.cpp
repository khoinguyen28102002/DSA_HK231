#include<iostream>

using namespace std;

int findGCD(int a, int b){
    if (a == 0) return b;
    else if(b == 0) return a;
    if(a > b)
        return findGCD(a%b, b);
    else if (a < b)
        return findGCD(a, b%a);
    else return a;
}

int main(){
    cout <<findGCD(715,30);
    return 0;
}