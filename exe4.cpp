#include<iostream>
#include<vector>

using namespace std;

int longestSublist(vector<string>& words) {
    // STUDENT ANSWER
    if(words.size() == 0)
        return 0;
    int max_length = 1;
    vector<string> subarray;
    for(unsigned int i = 0; i < words.size()-1; i++){
            if(words[i][0] == words[i+1][0]){
                subarray.push_back(words[i]);
                if(i+1 == words.size()-1) subarray.push_back(words[i+1]);
            }else{
                subarray.push_back(words[i]);
                max_length = (max_length < (int) subarray.size())? (int) subarray.size(): max_length;
                subarray.clear();
            }
            max_length = (max_length < (int) subarray.size())? (int) subarray.size(): max_length;
    }
    return max_length;
}

int main(){
    vector<string> words {};
    cout << longestSublist(words);
    return 0;
}