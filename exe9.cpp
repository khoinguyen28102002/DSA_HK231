#include<iostream>

using namespace std;

int findGCD(int a, int b) {
  if (b == 0) return a;
  return findGCD(b, a % b);
}

int findLCM(int a, int b) {
  return (a * b) / findGCD(a, b);
}
int main(){
    cout << findLCM(10,102);
    return 0;
}