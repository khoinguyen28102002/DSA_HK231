#include<iostream>
#include<queue>

using namespace std;

void interleaveQueue(queue<int>& q){
    queue<int> firstHalf, secondHalf;
    int len = q.size();
    for(int i = 0; i < len; i++){
        if(i < len / 2){
            firstHalf.push(q.front());
            q.pop();
        }else{
            secondHalf.push(q.front());
            q.pop();
        }
    }
    for(int i = 0; i < len; i++){
        if(i%2 == 0){
            q.push(firstHalf.front());
            firstHalf.pop();
        }else{
            q.push(secondHalf.front());
            secondHalf.pop();
        }
    }
}

int main(){
    queue<int> q;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int element; cin >> element;
        q.push(element);
    }
    interleaveQueue(q);
    while (!q.empty()){
        cout << q.front() << ' ';
        q.pop();
    }
}