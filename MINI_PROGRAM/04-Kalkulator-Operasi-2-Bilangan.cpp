#include <iostream>
#include <cmath>
using namespace std;

int main(){
  double angka1, angka2;
  char tanda, lagi;
  bool inputvalid;
  do{
    system("clear");
    cout << "===SELAMAT DATANG DI PROGRAM KALKULATOR SEDERHANA OPERASI 2 BILANGAN===" << endl;
    cout << "\nTEKAN '+' UNTUK TAMBAH\nTEKAN '-' UNTUK KURANG\nTEKAN '*' UNTUK AGI\nTEKAN '/' UNTUK BAGI\nTEKAN '%' UNTUK MODULO\n" << endl;
    do{
      inputvalid = true;
      cout << "Masukkan angka pertama : ";
      while ( !(cin >> angka1) || cin.peek() != '\n' ){
	cout << "Harap masukkan angka yang valid : ";
	cin.clear();
	cin.ignore(1000, '\n');
      }
      cout << endl;

      cout << "Masukkan angka kedua : ";
      while ( !(cin >> angka2) || cin.peek() != '\n' ){
        cout << "Harap masukkan angka yang valid : ";
        cin.clear();
        cin.ignore(1000, '\n');
      }
      cout << endl;

      cout << "Masukkan tanda operasi : ";
      while ( !(cin >> tanda) || (tanda != '+' && tanda != '-' && tanda != '*' && tanda != '/' && tanda != '%') || cin.peek() != '\n' ){
	cout << "Harap masukkan tanda yang valid : ";
        cin.clear();
        cin.ignore(1000, '\n');
      }
      cout << endl;

      if ( tanda == '%' && ( floor(angka1) != angka1 || floor(angka2) != angka2 )){
	cout << "Operasi modulo hanya berlaku jika kedua angka adalah bilangan bulat" << endl;
	inputvalid = false;
      }
      cout << endl;
      } while ( !inputvalid );

      if ( tanda == '+' ){
	cout << "Hasil dari " << angka1 << " + " << angka2 << " = " << angka1 + angka2 <<endl;
      } else if ( tanda == '-' ){
    	cout << "Hasil dari " << angka1 << " - " << angka2 << " = " << angka1 - angka2 <<endl;
      } else if ( tanda == '*' ){
	cout << "Hasil dari " << angka1 << " * " << angka2 << " = " << angka1 * angka2 <<endl;
      } else if ( tanda == '/' ){
      	if ( angka2 == 0){
        cout << "Hasil dari " << angka1 << " / " << angka2 << " = " << "Tidak Terdefinisi" << endl;
      } else {
        cout << "Hasil dari " << angka1 << " / " << angka2 << " = " << angka1 / angka2 <<endl;
      }
      } else if ( tanda == '%'){
        if ( angka2 == 0){
        cout << "Hasil dari " << angka1 << " mod " << angka2 << " = " << "Tidak Terdefinisi" << endl;
      } else {
        cout << "Hasil dari " << angka1 << " mod " << angka2 << " = " << (int)angka1 % (int)angka2 <<endl;
      }
      }
  cout << "\nMau Menghitung Kembali? (y/n): ";
  cin >> lagi;
  cout << endl;
  } while (lagi == 'y' || lagi == 'Y' );

  if ( lagi == 'n' || lagi == 'N' ){
    cout << "Program Berakhir" << endl;
  } else {
    cout << "Error, Input Tidak Valid, Program Berakhir" << endl;
  }

  return 0;
}
