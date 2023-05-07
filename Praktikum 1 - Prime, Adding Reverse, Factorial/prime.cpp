// * Link SPOJ : https://www.spoj.com/problems/PRIME1/

/* 
* Description
Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers!

* Input
The input begins with the number t of test cases in a single line (t<=10). In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

* Output
For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.

* Example
Input:
2
1 10
3 5

Output:
2
3
5
7

3
5
*/

// ! Sieve of Eratosthenes
/* Algoritma Sieve of Eratosthenes adalah algoritma untuk mencari semua bilangan prima dalam rentang tertentu dengan cara menandai atau mengeliminasi bilangan bukan prima secara berulang-ulang. 
    1. Inisialisasi sebuah array dengan nilai boolean true untuk semua elemen dalam rentang bilangan yang akan diperiksa (misalnya, dari 2 hingga N).
    2. Loop dari 2 hingga akar dari N. Pada setiap iterasi, jika bilangan pada indeks tersebut bernilai true, maka loop lagi untuk menandai semua kelipatan dari bilangan tersebut sebagai false, karena kelipatan dari bilangan tersebut pasti bukan bilangan prima. Misalnya, jika bilangan adalah 2, maka akan menandai setiap kelipatan dari 2 sebagai false, mulai dari 4, 6, 8, dan seterusnya. Jika bilangan pada indeks tersebut sudah ditandai sebagai false sebelumnya, maka lewati langkah ini dan lanjutkan ke bilangan berikutnya.
    3. Setelah loop selesai, semua bilangan pada indeks yang masih bernilai true adalah bilangan prima.
*/

// * Lets Code 

#include <iostream>
#include <vector>
using namespace std; 

void findPrime(int n1, int n2) {
    // array init with bool type
    vector<bool> prime(n2+1, true);
    // 0 and 1 not prime number
    prime[0] = prime[1] = false;

    // Sieve of Eratosthenes Algorithm
    /* Pada baris 56, kita melakukan loop untuk mencari bilangan prima mulai dari 2 hingga akar dari bilangan b. 
    Hal ini dilakukan karena jika sebuah bilangan N bukan bilangan prima, maka N dapat dipecah menjadi faktor-faktor prima yang lebih kecil dari akar N. 
    Sebagai contoh, jika kita ingin mencari bilangan prima dari 2 hingga 100, maka kita hanya perlu mengecek faktor-faktor prima yang lebih kecil 
        atau sama dengan akar dari 100, yaitu 2, 3, 5, dan 7. 
        Jika kita memeriksa bilangan yang lebih besar dari akar 100, maka bilangan tersebut tidak akan menjadi faktor dari bilangan yang lebih kecil dari 100. 
        Dengan membatasi loop hingga akar dari b, algoritma ini menjadi lebih efisien karena kita hanya perlu memeriksa faktor-faktor prima yang lebih kecil atau sama dengan 
        akar dari b.*/
    for(int i = n1; i*i <= n2; i++)
    {   
        // cout << "prime[%i] true", i;
        if(prime[i] == true) {
            // if prime[i] true check j is i quadrat and less than n2(last interval number) untuk menandai kelipatan bilangan prima yang true menjadi false, karena bilangan kelipatan dari bilangan prima merupakan bilangan non prima
            for(int j = i*i; j <= n2; j+=i) {
                // cout << "ini dalam j : " << j;
                prime[j] = false;
            }
        }
    }

    for(int i = n1; i <= n2; i++) {
        if(prime[i] == true) {
            cout << i << endl;
        }
    }
    

}

int main()
{
    int testCase;

    cin >> testCase;
    // cout << testCase;
    int a[testCase];
    int b[testCase];

    for(int i = 0; i < testCase; i++) {
        cin >> a[i] >> b[i];
    }
    
    for(int i = 0; i < testCase; i++) {
        findPrime(a[i], b[i]);
        cout << endl;
    }


    return 0;
}