#include <iostream>
using namespace std;

void printArray(int n){
    if(n == 0){
        cout << 0;
        return;
    }
    printArray(n-1);
    cout << ", " << n;
}
int main() {
	// your code goes here
    // int n = 5;
    printArray(5);
	return 0;
}