#include<iostream>
#include<vector>
using namespace std;
int baseballScore(string ops){
/*TODO*/
int result = 0;
    vector<int> score;
    for(int i = 0; ops[i] != '\0'; i++){
        switch (ops[i])
        {
        case '+':
            score.push_back(score[score.size()-1]+score[score.size()-2]);
            break;
        case 'D':
            score.push_back(score[score.size()-1] *2);
            break;
        case 'C':
            score.pop_back();
            break;
        default:
            string str = "";
            str += ops[i];
            score.push_back(stoi(str, nullptr, 10));
            break;
        }
    }
    for(int i = 0; i < (int) score.size(); i++){
        result += score[i];
    }
    return result;
}
int main(){
    string input;
    cin >>input;
    cout<< "Result = "<<baseballScore(input);
    return 0;
}