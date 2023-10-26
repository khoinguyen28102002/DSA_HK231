#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> stock_span(const vector<int>& ns) {
        // STUDENT ANSWER
    vector<int> result;
    result.push_back(1);
    for(int i = 1; i < (int) ns.size(); i++){
        int count = 1;
        for(int j = i-1, k = 0; j >= 0; j--, k++){
            if(ns[j] < ns[i] && count == k + 1){
                count++;
            }else{
                break;
            }
        }
        result.push_back(count);
    }
    return result;
}

int main(){
    vector<int> ns = {10, 4, 5, 90, 120, 80};
    vector<int> rs = stock_span(ns);
    for(int i ; i < rs.size(); i++){
        cout << rs[i] << " ";
    }
    return 0;
}