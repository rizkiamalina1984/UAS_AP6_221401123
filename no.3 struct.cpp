/*
Judul       : No.3 Program Struct 
Nama        : Rizki Amalina Triwahyuni Nasution
NIM         : 221401123
Kom         : C
Mata Kuliah : Lab AP6
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Struktur data mahasiswa
struct Mahasiswa {
    string nama;
    int nim;
    int nilai;
    char mutu;
};

// Menentukan nilai mutu berdasarkan nilai mahasiswa
char hitungMutu(int nilai) {
    if (nilai >= 80)
        return 'A';
    else if (nilai >= 70)
        return 'B';
    else if (nilai >= 60)
        return 'C';
    else if (nilai >= 50)
        return 'D';
    else
        return 'E';
}

// Program utama
int main() {
    int jumlahMahasiswa;

    // Input jumlah mahasiswa
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlahMahasiswa;

    // Buat array mahasiswa
    Mahasiswa *mahasiswa = new Mahasiswa[jumlahMahasiswa];

    // Input data mahasiswa
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "Data Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama: ";
        getline(cin >> ws, mahasiswa[i].nama);
        cout << "NIM: ";
        cin >> mahasiswa[i].nim;
        cout << "Nilai: ";
        cin >> mahasiswa[i].nilai;
        cout << endl;
    }

    // Hitung dan tampilkan nilai mutu
    cout << setw(15) << "Nama" << setw(10) << "NIM" << setw(10) << "Nilai" << setw(10) << "Mutu" << endl;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        mahasiswa[i].mutu = hitungMutu(mahasiswa[i].nilai);
        cout << setw(15) << mahasiswa[i].nama << setw(10) << mahasiswa[i].nim << setw(10) << mahasiswa[i].nilai << setw(10) << mahasiswa[i].mutu << endl;
    }

    // Hapus data mahasiswa (optional)
    delete[] mahasiswa;

    return 0;
}