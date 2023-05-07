#include <iostream>
using namespace std;

int reversed_digit(int n) {
    // digit for save last digit from number, and reversed for result 
    int digit, reversed = 0;
    // we need to loop until digit of number clearly (n == 0)
    while(n != 0) {
        // get last digit from number so do n % 10
        digit = n % 10;
        // add reversed value with prev reversed * 10 and add digit (so after get 1 digit before add digit to reverse the prev reverse will multiply by 10 with this formula the digit will be dynamically add)
        reversed = reversed * 10 + digit;
        n /= 10;
   }
   return reversed; 
}

int main() {
  int testCase, n1, n2;
  cin >> testCase;

  while(testCase--) {
    cin >> n1 >> n2; 
    // reverse digit from result two num digit reversed 
    cout << reversed_digit(reversed_digit(n1) + reversed_digit(n2)) << endl;
  }
   return 0;
}