#include<iostream>
#include<string.h>

using namespace std;

int myArrayToInt(char *str, int n){
    if(n == 0) return 0;
    return (int)(str[n-1]-'0')+10*myArrayToInt(str, n-1);
    // return result;
}
int main(){
    char str[] = "199820022023202112345";
    // cout << atoi(str);
    printf("%d", myArrayToInt(str, strlen(str)));
    return 0;
}