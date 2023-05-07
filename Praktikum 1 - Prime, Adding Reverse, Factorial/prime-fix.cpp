#include <iostream>
using namespace std;

bool isPrime(int num) {
    // for handle 1 and 2 and minus
    if(num < 2) return false;
    // for handle 2
    if(num == 2) return true;
    // every number can % 2 == 0 except kelipatan 3 dan kelipatan 5 and prime number
    if(num % 2 == 0) return false;
    // for handle kelipatan 3 dan 5
    for(int i = 3; i*i <= num; i+=2)
        // kalo num adalah kelipatan i jelas bukan prima, karena prima hanya bisa dibagi 1 dan bil itu sendiri 
        if(num % i == 0) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long testCase, n1, n2;

    cin >> testCase;

    while(testCase--) {
        cin >> n1 >> n2;
        for(int i = n1; i <= n2; i++) {
            if(isPrime(i)) {
                cout << i << endl;
            }
        }
    }
}