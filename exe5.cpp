#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// iostream, vector and queue are included
// You can write helper methods

long long nthNiceNumber(int n) {
    queue<long long> q;
    vector<long long> niceNums;
    q.push(2);
    q.push(5);
    for(int i = 0; !q.empty() && i < n; i++){
        long long num = q.front();
        q.pop();
        niceNums.push_back(num);
        q.push(num*10+2);
        q.push(num*10+5);
    }
    return niceNums[n-1];
}

int main(){
    int n;
    cin >> n;
    cout << nthNiceNumber(n) << endl;
    return 0;
}