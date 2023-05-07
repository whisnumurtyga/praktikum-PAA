#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 1e5;
int N, C;
int x[MAX_N];

bool check(int d) {
    int cnt = 1; // inisialisasi jumlah kandang awal dengan 1
    int last = x[0]; // inisialisasi posisi kandang terakhir dengan kandang pertama
    for (int i = 1; i < N; i++) { // looping untuk semua kandang
        if (x[i] - last >= d) { // jika jarak antara kandang saat ini dengan kandang terakhir lebih besar atau sama dengan d
            cnt++; // tambahkan jumlah kandang
            last = x[i]; // posisi kandang terakhir diupdate menjadi kandang saat ini
        }
    }
    return cnt >= C; // return true jika jumlah kandang yang diperoleh setelah pemotongan kayu cukup untuk menampung semua sapi
}

int main() {
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    sort(x, x + N); // urutkan kandang secara ascending

    int lb = 0, ub = x[N - 1] - x[0]; // inisialisasi nilai lowerbound dan upperbound
    while (ub - lb > 1) { // looping selama nilai upperbound dan lowerbound masih berbeda lebih dari 1
        int mid = (lb + ub) / 2; // hitung nilai mid sebagai rata-rata dari lowerbound dan upperbound
        if (check(mid)) { // jika pemotongan kayu dengan jarak mid dapat memuat semua sapi
            lb = mid; // update nilai lowerbound menjadi mid
        } else {
            ub = mid; // update nilai upperbound menjadi mid
        }
    }

    cout << lb << endl; // cetak nilai lowerbound sebagai hasil akhir
    return 0;
}
