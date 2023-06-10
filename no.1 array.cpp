/*
Judul       : No.1 Program yang menggunakan fungsi untuk menghitung nilai total element sebuah array
Nama        : Rizki Amalina Triwahyuni Nasution
NIM         : 221401123
Kom         : C
Mata Kuliah : Lab AP6
*/

#include <iostream>

using namespace std;

// Fungsi untuk menghitung total elemen array
int hitungTotal(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

// Fungsi utama
int main() {
    int size;

    // Input ukuran array
    cout << "Masukkan ukuran array: ";
    cin >> size;

    // Deklarasi array
    int array[size];

    // Input elemen array
    cout << "Masukkan elemen array:\n";
    for (int i = 0; i < size; i++) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> array[i];
    }

    // Hitung total elemen array
    int total = hitungTotal(array, size);
    cout << "Total elemen array: " << total << endl;

    return 0;
}