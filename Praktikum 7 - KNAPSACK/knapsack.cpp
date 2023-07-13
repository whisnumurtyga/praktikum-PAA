#include<iostream>
#include<vector>
using namespace std;

// Fungsi untuk mencari nilai maksimum antara dua bilangan
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Fungsi untuk memecahkan Knapsack Problem
int knapSack(int S, vector<int>& sizes, vector<int>& values, int N) {
    vector<vector<int>> dp(N + 1, vector<int>(S + 1, 0));

    // Mengisi tabel dp[][] secara bottom-up
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= S; j++) {
            if (sizes[i - 1] <= j) {
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - sizes[i - 1]], dp[i - 1][j]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Mengembalikan nilai maksimum yang dapat diperoleh
    return dp[N][S];
}

int main() {
    int S, N;
    cin >> S >> N;

    vector<int> sizes(N);
    vector<int> values(N);

    for (int i = 0; i < N; i++) {
        cin >> sizes[i] >> values[i];
    }

    int maxTotalValue = knapSack(S, sizes, values, N);
    cout << maxTotalValue << endl;

    return 0;
}
```