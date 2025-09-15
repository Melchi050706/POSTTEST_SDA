#include <iostream>
using namespace std;

int main() {
    const int n = 3;
    int matriks[n][n];

    // isi matriks manual (contoh input)
    cout << "Masukkan elemen matriks 3x3:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriks[i][j];
        }
    }

    // hitung jumlah diagonal utama dan sekunder
    int jumlahDiagonal = 0;
    for (int i = 0; i < n; i++) {
        jumlahDiagonal += matriks[i][i];             // diagonal utama
        jumlahDiagonal += matriks[i][n - 1 - i];     // diagonal sekunder
    }

    cout << "\nMatriks 3x3:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Jumlah diagonal utama + sekunder = " << jumlahDiagonal << endl;

    return 0;
}
