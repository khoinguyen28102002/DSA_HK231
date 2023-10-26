#include<iostream>
#include<stack>

using namespace std;

int evaluatePostfix(string expr){
    stack<int> operands;
    for(int i = 0; i < (int) expr.size(); i++){
        if(expr[i] == ' '){
            continue;
        }else if(isdigit(expr[i])){
            int operand = 0;
            while(i < (int) expr.size() && isdigit(expr[i])){
                operand = operand*10 + (expr[i] - '0');
                i++;
            }
            i--;
            operands.push(operand);
        }else{
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            switch (expr[i]){
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    operands.push(operand1 / operand2);
                    break;
                default:
                    break;
            }
        }
    }
    return operands.top();
}
int main(){
    cout << evaluatePostfix("2 3 1 * - 9 /");
    return 0;
}