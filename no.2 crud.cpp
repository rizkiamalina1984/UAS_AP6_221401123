/*
Judul       : No.2 Program CRUD
Nama        : Rizki Amalina Triwahyuni Nasution
NIM         : 221401123
Kom         : C
Mata Kuliah : Lab AP6
*/

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>

#ifdef _WIN32
#include <cstdlib>
#else
#include <unistd.h>
#endif

using namespace std;

// Fungsi untuk membersihkan layar
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    cout << "\033[2J\033[1;1H";
#endif
}

// Fungsi untuk membersihkan input buffer
void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.clear();
}

// Struktur data untuk menyimpan data mahasiswa
struct Mahasiswa {
    string nim;
    string nama;
    int usia;
};

// vector untuk menyimpan daftar mahasiswa
vector<Mahasiswa> daftarMahasiswa;

// Fungsi untuk menambahkan mahasiswa ke dalam daftar mahasiswa
void tambahMahasiswa() {
    Mahasiswa mhs;
    cout << "Masukkan NIM mahasiswa: ";
    cin >> mhs.nim;
    cin.ignore();

    // Periksa keberadaan NIM
    for (const auto& existingMhs : daftarMahasiswa) {
        if (existingMhs.nim == mhs.nim) {
            cout << "Mahasiswa dengan NIM tersebut sudah ada." << endl;
            return;
        }
    }

    cout << "Masukkan nama mahasiswa: ";
    getline(cin >> ws, mhs.nama);
    cout << "Masukkan usia mahasiswa: ";
    cin >> mhs.usia;
    daftarMahasiswa.push_back(mhs);
    cout << "Mahasiswa berhasil ditambahkan!" << endl;
}

// Fungsi untuk menampilkan daftar mahasiswa
void tampilkanMahasiswa() {
    // Membersihkan layar sebelum menampilkan daftar mahasiswa
    clearScreen();

    // Cek apakah daftar mahasiswa kosong
    if (daftarMahasiswa.empty()) {
        cout << "=============================================================" << endl;
        cout << "|                 Daftar mahasiswa kosong.                  |" << endl;
        cout << "=============================================================" << endl;
        return;
    }

    // Tampilkan header tabel
    cout << "=============================================================" << endl;
    cout << setw(10) << "NIM" << setw(20) << "Nama" << setw(10) << "Usia" << endl;
    cout << "=============================================================" << endl;

    // Tampilkan daftar mahasiswa
    for (const auto& mhs : daftarMahasiswa) {
        cout << setw(10) << mhs.nim << setw(20) << mhs.nama << setw(10) << mhs.usia << endl;
    }

    cout << "=============================================================" << endl;
}

// Fungsi untuk mengupdate mahasiswa
void updateMahasiswa() {
    // Cek apakah daftar mahasiswa kosong
    if (daftarMahasiswa.empty()) {
        cout << "Daftar mahasiswa kosong." << endl;
        return;
    }

    string nim;
    cout << "Masukkan NIM mahasiswa yang akan diupdate: ";
    getline(cin >> ws, nim);

    Mahasiswa* mhs = nullptr;
    for (auto& mahasiswa : daftarMahasiswa) {
        if (mahasiswa.nim == nim) {
            mhs = &mahasiswa;
            break;
        }
    }

    if (mhs == nullptr) {
        cout << "Mahasiswa dengan NIM tersebut tidak ditemukan." << endl;
        return;
    }

    cout << "Masukkan nama baru: ";
    getline(cin >> ws, mhs->nama);
    cout << "Masukkan usia baru: ";
    cin >> mhs->usia;
    cout << "Mahasiswa berhasil diupdate!" << endl;
}

// Fungsi untuk menghapus mahasiswa
void hapusMahasiswa() {
    if (daftarMahasiswa.empty()) {
        cout << "Daftar mahasiswa kosong." << endl;
        return;
    }

    string nim;
    cout << "Masukkan NIM mahasiswa yang akan dihapus: ";
    getline(cin >> ws, nim);

    for (auto it = daftarMahasiswa.begin(); it != daftarMahasiswa.end(); ++it) {
        if (it->nim == nim) {
            daftarMahasiswa.erase(it);
            cout << "Mahasiswa berhasil dihapus!" << endl;
            return;
        }
    }

    cout << "Mahasiswa dengan NIM tersebut tidak ditemukan." << endl;
}

// Fungsi utama
int main() {
    int pilihan;

    while (true) {
        cout << "Menu: " << endl;
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Tampilkan Mahasiswa" << endl;
        cout << "3. Update Mahasiswa" << endl;
        cout << "4. Hapus Mahasiswa" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        clearScreen();

        switch (pilihan) {
            case 1:
                tambahMahasiswa();
                break;
            case 2:
                tampilkanMahasiswa();
                break;
            case 3:
                updateMahasiswa();
                break;
            case 4:
                hapusMahasiswa();
                break;
            case 5:
                cout << "Terima kasih!" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid." << endl;
        }

        cout << "Tekan Enter untuk melanjutkan...";
        clearInputBuffer();
        clearScreen();

        cout << endl;
    }
}