#include<iostream>
#include<vector>
#include<queue>
#include<deque>
using namespace std;

int sumOfMaxSubarray(vector<int>& nums, int k) {
    // STUDENT ANSWER
    int n = nums.size();
    int sum = 0;
    vector<int> v;
    for (int i = 0; i < k; i++) {
        while (!v.empty() && nums[i] > v.back()) {
            v.pop_back();
        }
        v.push_back(nums[i]);
    }
    sum += v.front();
    for (int i = k; i < n; i++) {
        if (v.front() == nums[i - k]) {
            v.erase(v.begin());
        }
        while (!v.empty() && nums[i] > v.back()) {
            v.pop_back();
        }
        v.push_back(nums[i]);
        sum += v.front();
    }
    return sum;
}

int main(){
    vector<int> nums {1,2,4,3,6};
int k = 3;
cout << sumOfMaxSubarray(nums, k);

    return 0;
}