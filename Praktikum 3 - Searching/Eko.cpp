#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Langkah 1: Tentukan batas atas dan bawah untuk binary search
    int lo = 0, hi = *max_element(a, a + n);

    // Langkah 2: Lakukan binary search untuk mencari tinggi maksimum
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;  // Langkah 2a: hitung nilai tengah
        long long sum = 0;

        // Langkah 2b: hitung jumlah kayu yang akan dipotong
        for (int i = 0; i < n; i++) {
            if (a[i] > mid) {
                sum += a[i] - mid;
            }
        }

        // Langkah 2c: update nilai batas atas/bawah binary search
        if (sum >= m) {
            lo = mid;    // Jika jumlah kayu cukup, naikkan batas bawah
        } else {
            hi = mid - 1; // Jika jumlah kayu tidak cukup, turunkan batas atas
        }
    }

    // Langkah 3: Cetak hasil
    cout << lo << endl;

    return 0;
}
