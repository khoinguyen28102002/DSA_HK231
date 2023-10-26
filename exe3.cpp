#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> nextGreater(vector<int>& arr){
    for(int i = 0; i < (int) arr.size() - 1; i++){
        int j = i + 1;
        while(j < (int) arr.size() && arr[j] < arr[i]){
            j++;
        }
        if(j == (int) arr.size()){
            arr[i] = -1;
        }else{
            arr[i] = arr[j];
        }
    }
    arr[arr.size() - 1] = -1;
    return arr;
}
int main(){
    vector<int> nums = {15, 2, 4, 10};
    vector<int> greaterNums = nextGreater(nums);
    for(int i : greaterNums) 
        cout << i << ' ';
    cout << '\n';  
}