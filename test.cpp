#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


/*Find number k that k! = n*/
int Factorial(int n){
    if(n == 1 || n == 0) return 1;
    return n*Factorial(n-1);
}
int isFac(int n, int k){
    int Fac = Factorial(k);
    if(Fac == n){
        return k;
    }
    return (Fac > n) ? -1 : isFac(n, k+1);
}
int reverseFactorial(int n){
    int k = 0;
    // if(n == 1) return 1;
    if(n <= 0) return -1;
    return isFac(n, k);
}


// void findSum(const vector<int>& nums, unsigned int i, long long currentSum, long long& count) {
//     if (i >= nums.size()) {
//         return;
//     }
//     currentSum += nums[i];
//     if (currentSum % 2 != 0) {
//         count++;
//     }
//     findSum(nums, i + 1, currentSum, count);
// }

// void SumSublist(const vector<int>& nums, unsigned int i, long long& count) {
//     if (i >= nums.size()) {
//         return;
//     }
//     long long currentSum = 0;
//     findSum(nums, i, currentSum, count);
//     SumSublist(nums, i + 1, count);
// }

// int oddSumSublist(const vector<int>& nums, int m) {
//     long long count = 0;
//     SumSublist(nums, 0, count);
//     return count % m;
// }
void findOddSumSublist(const vector<int>& nums, size_t i, long long currentSum, long long& count, int m, bool isOdd) {
    if (i == nums.size()) {
        if (isOdd && currentSum % 2 != 0) {
            count = (count + 1) % m;
        }
        return;
    }

    // Xem xét trường hợp tiếp theo có tổng lẻ hoặc chẵn
    findOddSumSublist(nums, i + 1, currentSum + nums[i], count, m, !isOdd);
    findOddSumSublist(nums, i + 1, currentSum, count, m, isOdd);
}

int oddSumSublist(const vector<int>& nums, int m) {
    long long count = 0;
    findOddSumSublist(nums, 0, 0, count, m, false);
    return count;
}


bool isContain(char *text, char *pattern, int i1, int i2){
    if(text[0] == '\0' || pattern[0] == '\0')
        return 0;
    if(text[i2] == '\0' && i2 == 0){
        return 0;
    }
    if(pattern[i2] == '\0' && i2 > 0){
        return 1;
    }
    i2 = (text[i1] == pattern[i2] && i2 >= 0)? i2 + 1 : 0;
    return isContain(text, pattern, i1+1, i2);
}
bool containsPattern(char* text, char* pattern){
    int i1 = 0, i2 = 0;
    return isContain(text, pattern, i1, i2);
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
    vector<int> vec {7, 88, 131, 102, 191, 189, 134, 24, 46, 53, 196, 48, 112, 13, 33, 95, 36, 58, 163, 128, 197, 143, 64, 87, 114, 137, 149, 58, 8, 177, 60, 39, 47, 2, 133, 134, 82, 197, 176, 184, 99, 57, 129, 144, 94, 126, 13, 80, 140, 28, 93, 56, 91, 175, 73, 91, 68, 78, 15, 154, 150, 52, 28, 77, 9, 30, 17, 86, 37, 199, 42, 33, 28, 73, 115, 58, 93, 60, 139, 69, 18, 68, 166, 35, 149, 45, 102, 76, 150, 154, 58, 72, 32, 192, 73, 98, 77, 148, 80, 127};
// int m = 15447;
// cout << containsPattern((char*)"Truong Dai hoc Bach Khoa", (char*)"Bach Khoa");
// vector<int> vec {12, 147, 155, 73, 68, 105, 190, 173, 87, 123, 109, 63, 129, 150, 91, 161, 75, 94, 74, 192, 159, 53, 180, 167, 52, 125, 143, 51, 116, 162, 1, 104, 188, 28, 95, 58, 131, 59, 116, 61, 79, 140, 105, 145, 53, 52, 24, 120, 79, 82, 109, 74, 43, 113, 31, 68, 121, 165, 51, 44, 85, 7, 162, 64, 78, 148, 92, 55, 70, 83, 125, 151, 12, 118, 191, 89, 94, 120, 8, 115, 82, 57, 70, 28, 71, 62, 184, 141, 63, 140, 150, 150, 88, 133, 180, 151, 44, 124, 115, 120, 45, 14, 48, 138, 165, 115, 97, 32, 101, 179, 5, 32, 76, 132, 172, 199, 67, 91, 143, 100, 174, 112, 137, 19, 149, 135, 166, 117, 44, 68, 59, 21, 40, 103, 166, 47, 19, 104, 47, 60, 170, 93, 15, 97, 125, 146, 191, 81, 102, 72, 93, 15, 22, 73, 131, 177, 76, 179, 177, 18, 175, 11, 148, 47, 119, 140, 166, 68, 62, 192, 191, 143, 21, 29, 148, 93, 92, 28, 32, 51, 106, 182, 161, 64, 142, 104, 148, 66, 29, 105, 115, 6, 5, 114, 102, 196, 169, 21, 48, 90, 14, 136, 11, 31, 157, 36, 30, 171, 147, 129, 62, 70, 125, 5, 19, 86, 144, 109, 101, 181, 23, 131, 62, 33, 38, 88, 34, 22, 199, 19, 124, 137, 35, 187, 82, 158, 4, 130, 165, 85, 160, 130, 42, 144, 24, 164, 188, 49, 34, 183, 93, 193, 60, 110, 74, 116, 146, 142, 119, 155, 1, 110, 19, 129, 85, 151, 173, 75, 104, 38, 31, 18, 108, 63, 194, 67, 59, 60, 195, 161, 61, 47, 60, 64, 26, 173, 54, 5, 104, 35, 61, 77, 23, 13, 100, 187, 27, 92, 83, 78, 122, 24, 22, 18, 167, 151, 136, 141, 70, 165, 48, 189, 72, 76, 195, 129, 193, 189, 50, 13, 161, 24, 157, 186, 128, 57, 47, 197, 166, 36, 36, 47, 42, 33, 73, 101, 184, 179, 179, 24, 112, 190, 131, 103, 157, 71, 56, 12, 59, 137, 54, 125, 197, 53, 102, 196, 174, 105, 53, 177, 70, 124, 121, 46, 167, 9, 1, 179, 113, 50, 164, 187, 2, 191, 77, 70, 34, 56, 30, 49, 135, 167, 171, 83, 132, 153, 80, 2, 95, 134, 85, 141, 147, 62, 152, 19, 187, 143, 196, 132, 72, 197, 194, 182, 173, 161, 93, 91, 32, 14, 58, 160, 188, 71, 15, 169, 189, 52, 11, 180, 52, 23, 23, 11, 108, 42, 76, 62, 12, 196, 133, 72, 118, 172, 197, 176, 7, 4, 164, 164, 111, 49, 86, 113, 3, 50, 149, 126, 26, 0, 136, 89, 157, 197, 196, 130, 99, 152, 194, 183, 171, 71, 57, 175, 179, 54, 166, 123, 176, 159, 24, 18, 71, 26, 81, 60, 188, 176, 74, 98, 137, 34, 62, 75, 10, 184, 139, 114, 70, 94, 108, 6, 48, 145, 66, 18, 150, 43, 51, 22};
int m = 14242;
cout << oddSumSublist(vec, m);
    return 0;
}