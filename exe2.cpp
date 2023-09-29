#include<iostream>
#include<vector>

using namespace std;

bool consecutiveOnes(vector<int>& nums) {
    // STUDENT ANSWER
    if(nums.size() == 0) return true;
    vector<int> one;
    for(unsigned int i = 0; i < nums.size(); i++){
        if(nums[i] == 1){
            one.push_back(i);
        }
    }
    for(unsigned int i = 0; i < one.size()-1; i++){
        //TODO
        if(one[i+1] - one[i] > 1){
            return 0;
        }
    }
    return true;
}

int main(){
    vector<int> nums {0, 1, 1, 1, 9, 8};
    cout << consecutiveOnes(nums);
    return 0;
}