#include <iostream>
#include <cmath>
using namespace std;

int main(){
char lagi;

do {
  system("clear");
  int pilihan;
  cout << "======================" << endl;
  cout << "Math Engine (Bilangan)" << endl;
  cout << "======================" << endl;
  cout << "1. Cek bilangan prima\n2. Faktorisasi prima\n3. FPB dan KPK\n4. Cek ganjil/genap\n5. Deret  bilangan" << endl;
  cout << "======================\n" << endl;
  cout << "Masukkan pilihan anda (1, 2, 3, 4, 5) : ";

  while (!(cin >> pilihan) || pilihan > 5 || pilihan < 1 || cin.peek() == '.' || cin.peek() == ',' || cin.peek() == ' ') {
    cout << "Harap masukkan input yang valid : ";
    cin.clear();
    cin.ignore(1000, '\n');
  }
  cout << endl;

  switch (pilihan){
    case 1 : {
      int angka;
      int pembagi=2;
      bool checker = true;
      cout << "Masukkan bilangan bulat positif : ";

        while (!(cin >> angka) || angka <= 0 || cin.peek() == '.' || cin.peek() == ',' || cin.peek() == ' ') {
          cout << "Input tidak valid! Masukkan bilangan bulat positif: ";
          cin.clear();
          cin.ignore(1000, '\n');
        }

        if ( angka <= 1 ){
          checker = false;
        } else {
          while (pembagi < angka){
            int hasil = angka % pembagi;
            if ( hasil == 0 ){
                checker = false;
                break;
            }
            pembagi++;
          }
        }

        if ( checker == false ){
          cout << angka << " Bukanlah Bilangan Prima" << endl;
        } else {
          cout << angka << " Merupakan Bilangan Prima" << endl;
        }
        break;
    }
    case 2 : {
      int bilangan;
      int divider = 2;
      cout << "Masukkan bilangan bulat minimal 2 : ";

        while (!(cin >> bilangan) || bilangan < 2 || cin.peek() == '.' || cin.peek() == ',' || cin.peek() == ' ') {
          cout << "Input tidak valid! Masukkan bilangan bulat >=2 : ";
          cin.clear();
          cin.ignore(1000, '\n');
        }

        cout << "Faktorisasi prima dari " << bilangan << " adalah : ";

        while (bilangan > 1) {
          while (bilangan % divider == 0) {
            cout << divider;
            bilangan = bilangan / divider;
              if (bilangan > 1) {
                cout << " x ";
              }
           }
           divider++;
        }
        break;
    }
    case 3 : {
      int angka1, angka2;
      cout << "Masukkan bilangan bulat positif pertama : ";
        while (!(cin >> angka1) || angka1 <= 0 || cin.peek() == '.' || cin.peek() == ',' || cin.peek() == ' ') {
            cout << "Input tidak valid! Masukkan bilangan bulat positif: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
      cout << "Masukkan bilangan bulat positif kedua : ";
        while (!(cin >> angka2) || angka2 <= 0 || cin.peek() == '.' || cin.peek() == ',' || cin.peek() == ' ') {
            cout << "Input tidak valid! Masukkan bilangan bulat positif 2: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

      int a = angka1;
      int b = angka2;
        while ( b != 0 ){
          int sementara = b;
          b = a % b;
          a = sementara;
        }
        cout << "FPB(" << angka1 << ", " << angka2 << ") = " << a << endl;
        cout << "KPK(" << angka1 << ", " << angka2 << ") = " << (angka1*angka2)/a << endl;
        break;
    }
    case 4 : {
      int bilangan;
      cout << "Masukkan bilangan bulat : ";
      while (!(cin >> bilangan) || cin.peek() == '.' || cin.peek() == ',' || cin.peek() == ' '){
        cout << "Input tidak valid! Masukkan bilangan bulat : ";
        cin.clear();
        cin.ignore(1000, '\n');
      }

      if ( bilangan % 2 == 0 ){
        cout << bilangan << " Adalah bilangan genap" << endl;
      } else {
        cout << bilangan << " Adalah bilangan ganjil" << endl;
      }
    break;
    }
    case 5 : {
      int pilihan5;
      cout << "Deret apa?" << endl;
      cout << "1. Aritmatika\n2. Geometri" << endl;
      cout << "Masukkan pilihan anda(1, 2) : ";
      while (!(cin >> pilihan5) || pilihan5 > 2 || pilihan5 < 1 || cin.peek() == '.' || cin.peek() == ',' || cin.peek() == ' ') {
        cout << "Harap masukkan input yang valid : ";
        cin.clear();
        cin.ignore(1000, '\n');
      }
      cout << endl;
      switch (pilihan5){
        case 1 : {
          float u1, b;
          int n;
          cout << "Masukkan suku pertama : ";
          while (!(cin >> u1) || cin.peek() == ' ') {
            cout << "Harap masukkan input yang valid : ";
            cin.clear();
            cin.ignore(1000, '\n');
          }
          cout << "Masukkan beda setiap suku : ";
          while (!(cin >> b) || cin.peek() == ' ') {
            cout << "Harap masukkan input yang valid : ";
            cin.clear();
            cin.ignore(1000, '\n');

          }
          cout << "Masukkan banyaknya suku yang akan ditampilkan : ";
          while (!(cin >> n) || n <= 0 || cin.peek() == '.' || cin.peek() == ',' || cin.peek() == ' ') {
            cout << "Harap masukkan input yang valid : ";
            cin.clear();
            cin.ignore(1000, '\n');
          }
          cout << "Deret aritmatika : ";
          int un=1;
          while (un <= n){
            cout << u1 + (un-1)*b << " , ";
            un++;
          }
        cout << endl;
        break;
        }
        case 2 : {
          float u1, r;
          int n;
          cout << "Masukkan suku pertama : ";
          while (!(cin >> u1) || cin.peek() == ' ') {
            cout << "Harap masukkan input yang valid : ";
            cin.clear();
            cin.ignore(1000, '\n');
          }
          cout << "Masukkan rasio setiap suku : ";
          while (!(cin >> r) || cin.peek() == ' ') {
            cout << "Harap masukkan input yang valid : ";
            cin.clear();
            cin.ignore(1000, '\n');

          }
          cout << "Masukkan banyaknya suku yang akan ditampilkan : ";
          while (!(cin >> n) || n <= 0 || cin.peek() == '.' || cin.peek() == ',' || cin.peek() == ' ') {
            cout << "Harap masukkan input yang valid : ";
            cin.clear();
            cin.ignore(1000, '\n');
          }
          cout << "Deret geometri : ";
          int pangkat=0;
          while (pangkat < n){
            cout << (u1 * pow(r, pangkat)) << " , ";
            pangkat++;
          }
        cout << endl;
        break;
        }
      }
    break;
    }
  }
cout << "\nKembali ke menu? (y/n): ";
cin >> lagi;
cout << endl;
} while ( lagi == 'y' || lagi == 'Y' );

if ( lagi == 'n' || lagi == 'N' ){
    cout << "Program berakhir" << endl;
}else{
    cout << "Karakter tidak valid" << endl;
}
  return 0;
}
