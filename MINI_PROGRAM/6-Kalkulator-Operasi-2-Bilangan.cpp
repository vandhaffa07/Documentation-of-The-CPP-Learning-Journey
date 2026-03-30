#include <iostream>
using namespace std;

int main(){
        double angka1, angka2;
        char tanda;

        cout << "===SELAMAT DATANG DI PROGRAM KALKULATOR SEDERHANA OPERASI 2 BILANGAN===" << endl;
        cout << "\nTEKAN '+' UNTUK TAMBAH\nTEKAN '-' UNTUK KURANG\nTEKAN '*' UNTUK AGI\nTEKAN '/' UNTUK BAGI\nTEKAN '%' UNTUK MODULO\n" << endl;

        cout << "Masukkan angka pertama : ";
        cin >> angka1;

        cout << "Masukkan angka kedua : ";
        cin >> angka2;

        cout << "Masukkan tanda operasi : ";
        cin >> tanda;

  if(tanda=='+'){
    cout << "Hasil dari " << angka1 << " + " << angka2 << " = " << angka1 + angka2 <<endl;
  } else if(tanda=='-'){
    cout << "Hasil dari " << angka1 << " - " << angka2 << " = " << angka1 - angka2 <<endl;
  } else if(tanda=='*'){
    cout << "Hasil dari " << angka1 << " * " << angka2 << " = " << angka1 * angka2 <<endl;
  } else if(tanda=='/'){
      if(angka2==0){
        cout << "Hasil dari " << angka1 << " / " << angka2 << " = " << "Tidak Terdefinisi" << endl;
      } else {
        cout << "Hasil dari " << angka1 << " / " << angka2 << " = " << angka1 / angka2 <<endl;
      }
  } else if(tanda=='%'){
    cout << "Hasil dari " << angka1 << " mod " << angka2 << " = " << (int)angka1 % (int)angka2 <<endl;
  } else{
    cout << "Harap masukkan tanda operasi yang valid" << endl;
  }

  return 0;
}
