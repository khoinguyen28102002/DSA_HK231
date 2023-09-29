#include<iostream>
#include<vector>

using namespace std;


vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations) {
    // STUDENT ANSWER
    for(unsigned int i = 0; i < operations.size(); i++){
        int L = operations[i][0], R = operations[i][1], X = operations[i][2];
        for(int idx = L; idx <= R; idx++)
            nums[idx] += X;
    }
    return nums;
}
void printVector(vector<int> nums){
    cout << "{";
    for(unsigned int i = 0; i < nums.size() - 1; i++)
        cout << nums[i] << ", ";
    cout << nums[nums.size()-1] << "}";
}
int main(){
    vector<int> nums {13, 0, 6, 9, 14, 16};
    vector<vector<int>> operations {{5, 5, 16}, {3, 4, 0}, {0, 2, 8}};
    printVector(updateArrayPerRange(nums, operations));
    // cout << operations.size();
    return 0;
}