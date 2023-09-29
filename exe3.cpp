#include<iostream>
#include<vector>

using namespace std;

int equalSumIndex(vector<int>& nums) {
    // STUDENT ANSWER
    int length = nums.size();
    if(length == 0) return -1;
    int totalSum = 0;
    for(unsigned int i = 0; i < length; i++){
        totalSum += nums[i];
    }
    int leftSum = 0;
    for(unsigned int i = 0; i < length; i++){
        int rightSum = totalSum -leftSum-nums[i];
        if(leftSum == rightSum) return i;
        leftSum += nums[i];
    }
    return -1;   
}

int main(){
    vector<int> nums {15, 1, 2, 5, 3, 5};
    cout << equalSumIndex(nums);
    return 0;
}