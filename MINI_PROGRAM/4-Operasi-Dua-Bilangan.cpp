#include <iostream>
using namespace std;

int main() {
    double a, b;
    cout<< "Masukkan angka pertama : ";
    cin >> a;
    cout<< "Masukkan angka kedua : ";
    cin >> b;

    cout<<"\n===HASIL PERHITUNGAN==="<<endl;
    cout << "Penjumlahan: " << a + b << endl;
    cout << "Pengurangan: " << a - b << endl;
    cout << "Perkalian:   " << a * b << endl;
    cout << "Pembagian:   " << a / b << endl;
    cout << "Modulo:      " << (int)a % (int)b << endl;

    return 0;
}
