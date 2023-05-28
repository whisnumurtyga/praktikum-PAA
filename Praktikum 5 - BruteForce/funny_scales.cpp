#include <iostream>
#include <cstdio>
const int MAXL = 100;

int N, X;
int A[MAXL], lenA;
int B[MAXL], lenB;
int dig[MAXL];

int main()
{
    scanf("%d %d", &N, &X);

    // Konversi berat awal ke dalam sistem basis 3
    for (int i = 0; X != 0; i++)
    {
        dig[i] += X % 3;  // Menambahkan digit pada array dig
        if (dig[i] > 1)   // Jika digit lebih dari 1, dilakukan carry
        {
            dig[i + 1]++;     // Carry 1 ke digit berikutnya
            dig[i] = dig[i] - 3;  // Mengurangi 3 dari digit sekarang
        }
        X /= 3;  // Membagi berat awal dengan 3 untuk melanjutkan ke digit berikutnya
    }

    // Penempatan berat pada timbangan pertama (A) atau timbangan kedua (B)
    for (int i = MAXL - 1; i >= 0; i--)
    {
        if (dig[i] != 0)
        {
            if (dig[i] == -1)   // Jika digit = -1, berat ditempatkan pada timbangan pertama (A)
                A[lenA++] = i + 1;
            else if (dig[i] == +1)  // Jika digit = +1, berat ditempatkan pada timbangan kedua (B)
                B[lenB++] = i + 1;
        }
    }

    // Menampilkan hasil penempatan berat pada timbangan
    if (A[0] > N || B[0] > N)
        printf("-1\n");  // Jika indeks berat pertama pada timbangan melebihi jumlah berat, mencetak -1
    else
    {
        for (int i = lenA - 1; i >= 0; i--)
            printf(i ? "%d " : "%d", A[i]);  // Menampilkan indeks berat pada timbangan pertama (A)
        printf("\n");
        for (int i = lenB - 1; i >= 0; i--)
            printf(i ? "%d " : "%d", B[i]);  // Menampilkan indeks berat pada timbangan kedua (B)
        printf("\n");
    }
    return 0;
}
