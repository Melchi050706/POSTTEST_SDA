#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;     
    float ipk;   
};

int main() {
    const int n = 5;
    Mahasiswa mhs[n];

    cout << "Input data 5 mahasiswa:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Mahasiswa " << i+1 << endl;
        cout << "Nama: "; cin >> mhs[i].nama;
        cout << "NIM : "; cin >> mhs[i].nim;
        cout << "IPK : "; cin >> mhs[i].ipk;
    }

    // cari IPK tertinggi
    int idxTertinggi = 0;
    for (int i = 1; i < n; i++) {
        if (mhs[i].ipk > mhs[idxTertinggi].ipk) {
            idxTertinggi = i;
        }
    }

    cout << "\nMahasiswa dengan IPK tertinggi:" << endl;
    cout << "Nama: " << mhs[idxTertinggi].nama << endl;
    cout << "NIM : " << mhs[idxTertinggi].nim << endl;
    cout << "IPK : " << mhs[idxTertinggi].ipk << endl;

    return 0;
}
