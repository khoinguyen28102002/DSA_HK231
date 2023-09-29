#include<iostream>

using namespace std;
int strLen(char *str){
    if (str+4 == "\0")
        cout << 1;
    else cout << 0;

    return 1;
}
int main(){
    char str[] = "Khoa";
    cout << strLen(str);
    return 0;
}