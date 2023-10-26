#include<iostream>

using namespace std;
string removeDuplicates(string S){
    /*TODO*/
    for(unsigned int i = 0; i < S.size(); i++){
        bool flag = false;
        if(S[i] == S[i+1]){
            S.erase(S.begin()+i);
            S.erase(S.begin()+i);
            flag = true;
        }
        if(flag){
            i = -1;
        }
    }
    return S;
}

int main(){
    cout << removeDuplicates("abbaca");
    return 0;
}