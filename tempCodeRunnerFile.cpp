
    vector<int> sub;
    for(int i = 0; nums[i] <= target - nums[0]; i++){
        sub.push_back(nums[i]);
    }
    return sub[0] + sub[sub.size()-1];