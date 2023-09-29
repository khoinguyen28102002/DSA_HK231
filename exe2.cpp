#include <iostream>
using namespace std;

void printPattern(int n) {
    if (n > 0) {
        cout << n << " ";
        printPattern(n-5);
    }
    else{
        cout << n;
        return;
    }
    cout << " " << n;
}
int main() {
	// your code goes here
    // int n = 5;
    printPattern(14);
	return 0;
}