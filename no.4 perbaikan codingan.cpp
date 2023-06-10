/*
Judul       : No.4 Perbaikan codingan 
Nama        : Rizki Amalina Triwahyuni Nasution
NIM         : 221401123
Kom         : C
Mata Kuliah : Lab AP6
*/


#include<iostream>

using namespace std;

int tambah(int a, int b, int c);

int main() {

    cout << "Hello, world!" << endl;

    if (true) 
    {
        cout << "Ini blok if" << endl;
    }
    else
    {
        cout << "Ini blok else" << endl;
    }
    
    int hasil = tambah(3, 4, 5);
    cout << "Hasil penjumlahan: " << hasil << endl;
    
    int x = 5;
    cout << "Nilai x: " << x << endl;

    switch (x) {
        case 5: 
            cout << "Nilai x adalah 5" << endl;
            break;
        default:
            cout << "Nilai x bukan 5" << endl;
    }

    int* ptr = nullptr;
    int y = 10;
    ptr = &y;
    cout << "Nilai ptr: " << *ptr << endl;

    x = 5;
    int* nullPtr = nullptr;
    nullPtr = &x;  
    cout << "Nilai dari nullPtr: " << *nullPtr << endl;

    int* dynamicPtr = new int;
    *dynamicPtr = 7;
    cout << "Nilai dari dynamicPtr: " << *dynamicPtr << endl;
    delete dynamicPtr;

    int arr[5];
    int* arrptr = arr;
    arrptr[4] = 10;  
    cout << "Nilai dari arr[4]: " << arr[4] << endl;

    return 0;
}


int tambah(int a, int b, int c) {
    int hasil = 0; 
    hasil = a + b + c;
    return hasil;
}
