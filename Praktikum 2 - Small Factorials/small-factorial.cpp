#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;

int main()
{
    int testCase, n;
    cin >> testCase;
    
    while(testCase--) {
        cpp_int result = 1;
        cin >> n;
        while(n > 1) {
            result *= n;
            // cout << n << endl;
            n--;
        }
        cout << result << endl;
    }
}