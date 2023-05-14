long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    long long inv_count = 0;

    i = left; // inisialisasi indeks untuk subarray kiri
    j = mid;  // inisialisasi indeks untuk subarray kanan
    k = left; // inisialisasi indeks untuk subarray hasil penggabungan

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) { // jika elemen di subarray kiri lebih kecil atau sama dengan elemen di subarray kanan
            temp[k++] = arr[i++]; // salin elemen di subarray kiri ke subarray hasil penggabungan dan tambahkan indeks subarray kiri dan indeks subarray hasil penggabungan
        } else { // jika elemen di subarray kanan lebih kecil dari elemen di subarray kiri
            temp[k++] = arr[j++]; // salin elemen di subarray kanan ke subarray hasil penggabungan dan tambahkan indeks subarray kanan dan indeks subarray hasil penggabungan

            // hitung jumlah inversi ketika sebuah elemen di subarray kanan disalin ke subarray hasil penggabungan
            inv_count += (mid - i);
        }
    }

    // salin elemen yang tersisa di subarray kiri ke subarray hasil penggabungan
    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }

    // salin elemen yang tersisa di subarray kanan ke subarray hasil penggabungan
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // salin elemen hasil penggabungan dari subarray hasil penggabungan ke subarray asal
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    // kembalikan jumlah inversi yang ditemukan
    return inv_count;
}

long long merge_sort(int arr[], int temp[], int left, int right) {
    int mid;
    long long inv_count = 0;

    if (right > left) { // jika panjang subarray lebih dari 1 elemen
        mid = (left + right) / 2; // cari indeks tengah subarray

        // hitung jumlah inversi di subarray kiri dengan menggunakan rekursi
        inv_count += merge_sort(arr, temp, left, mid);

        // hitung jumlah inversi di subarray kanan dengan menggunakan rekursi
        inv_count += merge_sort(arr, temp, mid + 1, right);

        // gabungkan dua subarray yang sudah diurutkan dan hitung jumlah inversi
        inv_count += merge(arr, temp, left, mid + 1, right);
    }

    // kembalikan jumlah inversi yang ditemukan
    return inv_count;
}

int main() {
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        int a[n], temp[n];

        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }

        // panggil fungsi merge_sort untuk menghitung jumlah inversi
        long long inv_count = merge_sort(a, temp, 0, n - 1);
 
        cout << inv_count << endl;
    }
 
    return 0;
}