#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int **splitArr(int *num, int n, int k){
    int SubN = (n%k)? n/k+1 : n/k;
    int **Sub = new int*[SubN];
    for(int i = 0; i < SubN; i+=k){
        Sub[i] = new int[k];
        for(int j = 0; j < k; j++){
            Sub[i][j] = (i == SubN - 1 && n%k)? num[i] : 0;
        }
    }
    return Sub;
}
int findSum(int *num, int n, int k){
   for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (num[j] > num[j + 1]) {
                // Swap num[j] and num[j+1]
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
    
}
int helpfunction(int *num, int n, int k, int & size){
    int max = num[0], i = 1, idx = 0, idx_max2 = 0, max2 = 0;
    for(; i < n; i++){
        if(num[i] > max){
            max = num[i];
            idx = i;
        }else if(max2 < num[i]){
            max2 =  num[i];
            idx_max2 = i;
        }
    }
    int start = idx , end = idx;
    for(size = 0; size < k; ){
        if(start < 0)   start = 0;
        if(end >= n)    end = n - 1;
        if(start == end){
            num[start--] = -1;
            end++;
            size++;
        }
        else if(num[start] != -1 && num[end] != -1){
            if(start == idx_max2){
                num[end++] = -1;
                size++;
            }else if(end == idx_max2){
                num[start--] = -1;
                size++;
            }else{
                num[start--] = -1;
                num[end++] = -1;
                size +=2;
            }
        }else if(num[start] == -1 && num[end] != -1){
            if(end == idx_max2 && end != n-1){
                break;
            }
            num[end++] = -1;
            size ++;
        }else if(num[start] != -1 && num[end] == -1){
            if(start == idx_max2 && start != 0){
                break;
            }
            num[start--] = -1;
            size++;
        }else{
            break;
        }
    }
    return (max > 0) ? max : 0;
}
int maxSum(int *nums, int n, int k){
    int SubN = (n%k)? n/k+ n%k : n/k;
    int *numcp = nums;
    int sum = 0;
    int j = 0;
    while(j < SubN){
        int size = 0;
        int maxValue = helpfunction(numcp, n , k, size);
        sum += maxValue*size;
        j++;
    }
    return sum;
}

int sumLessThanTarget(vector<int> nums, int target){
    int maxSum = 0;
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        int currentSum = nums[left] + nums[right];
        if (currentSum < target && currentSum > maxSum) {
            maxSum = currentSum;
        }
        if (currentSum < target) {
            left++;
        } else {
            right--;
        }
    }
    return maxSum;
}
int main(){
    // vector<int> arr{-10, -1, 1,2,3,5,6,9};
    // cout << sumLessThanTarget(arr, 7);
    // int nums[] = {15,5,7,2,2,6,1};
    // cout << maxSum(nums, 7, 3)<<endl;
    int nums[] = {1,6,3,2,2,5,1};
    cout << maxSum(nums, 7, 3)<<endl;
    // nums[] = {1,6,3,2,3,2,5,1};
    // cout << maxSum(nums, 8, 3)<<endl;
    // nums[] = {15,1,2,7,2,5,6};
    // cout << maxSum(nums, 7, 3)<<endl;
    // int nums[] = {1,6,2,7,2,5,15};
    // cout << maxSum(nums, 7, 3)<<endl;
    return 0;
}