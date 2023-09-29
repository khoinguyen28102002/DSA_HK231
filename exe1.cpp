#include<iostream>
#include<algorithm>

using namespace std;


int buyCar(int* nums, int length, int k) {
    sort(nums, nums + length);
    int i = 0;
    while( i < length){
        if(k >= nums[i]){
            k -= nums[i++];
        }
        else break;
    }
    return i;
}


int main(){
    int nums[] = {90,30,40,90,20};
    int length = sizeof(nums)/sizeof(nums[0]);
    cout << buyCar(nums, length, 270) << "\n";
    return 0;
}