#include<iostream>
using namespace std;

void printHailstone(int number)
{
    if(number == 1){
        cout << number;
        return;
    }
    cout << number << " ";
    if (number%2){
        printHailstone(number*3+1);
    }
    else{
        printHailstone(number/2);
    }
}

int main(){
    printHailstone(32);
    return 0;
}