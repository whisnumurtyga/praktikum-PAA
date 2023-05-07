#include <iostream>
using namespace std;

int countZerosInFactorial(int n) {
    int count = 0;
    // find and count kelipatan 5 from 5 until n/i >=1 
    for (int i = 5; n / i >= 1; i *= 5) {
        count += n / i;
    }
    return count;
}

int main() {
    int testCase, n;
    cin >> testCase;
    
    while(testCase--) {
        cin >> n;
        cout << countZerosInFactorial(n) << endl;
    }
    
    return 0;
}


/*
Kelipatan 5 dipilih karena faktor 10 selalu terbentuk dari faktor 2 dan faktor 5 pada suatu bilangan. Dalam faktorial suatu bilangan, faktor 2 selalu lebih banyak daripada faktor 5, sehingga kita hanya perlu menghitung jumlah faktor 5 saja untuk mengetahui jumlah digit nol dalam faktorial tersebut.

Contohnya, jika kita ingin mencari jumlah digit nol dalam faktorial 10, maka kita perlu mencari berapa banyak faktor 5 dalam 10! (10 faktorial). Faktorial 10 dapat dinyatakan sebagai 10! = 10 x 9 x 8 x 7 x 6 x 5 x 4 x 3 x 2 x 1. Terdapat dua faktor 5 pada 10, dan satu faktor 5 pada 5. Oleh karena itu, jumlah faktor 5 dalam 10! adalah 2 + 1 = 3, sehingga terdapat tiga digit nol pada 10!.

Dalam kode yang Anda lihat sebelumnya, loop dilakukan pada setiap kelipatan 5 karena setiap kali kita melipatgandakan bilangan dengan faktor 5 (5, 10, 15, 20, 25, dan seterusnya), akan ada tambahan faktor 5 yang akan berkontribusi pada jumlah digit nol dalam faktorial bilangan tersebut. Oleh karena itu, dengan menghitung jumlah faktor 5 pada setiap kelipatan 5 dari bilangan yang ingin dicari faktorialnya, kita dapat mengetahui jumlah digit nol dalam faktorial bilangan tersebut.
*/