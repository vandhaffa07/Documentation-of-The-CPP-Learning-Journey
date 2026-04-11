#include <iostream>
using namespace std;

int main(){
  char lagi;
      do{
        system("clear");
        double berat_badan, tinggi_badan;
        cout << "===SELAMAT DATANG DI KALKULATOR BMI SEDERHANA===" << endl;
        cout << "<18.5        : Kurang" << endl;
        cout << "18.5 - 22.9 : Normal" << endl;
        cout << "23.0 - 24.9 : Berlebih" << endl;
        cout << "25.0 - 29.9 : Obesitas Tingkat I" << endl;
        cout << ">=30         : Obesitas Tingkat II\n" << endl;

        cout << "Masukkan Berat Badanmu(kg) : ";
        while ( !(cin >> berat_badan) || berat_badan <= 0 || cin.peek() == ' ' ){
          cout << "Harap Masukkan Berat Badan Yang Valid : ";
          cin.clear();
          cin.ignore(1000, '\n');
        }
        cout << endl;
        cout << "Masukkan Tinggi Badanmu(cm) : ";
        while ( !(cin >> tinggi_badan) || tinggi_badan <= 0 || cin.peek() == ' ' ){
          cout << "Harap Masukkan Tinggi Badan Yang Valid : ";
          cin.clear();
          cin.ignore(1000, '\n');
        }
        cout << endl;
        double hasil = berat_badan/(tinggi_badan*tinggi_badan/10000);
        cout << "BMI-mu Adalah : " << hasil << ", Kamu Berada Pada Kategori ";
        if ( hasil < 18.5 ){
          cout << "Kurang" << endl;
        } else if ( hasil >= 18.5 && hasil <= 22.9 ){
          cout << "Normal" << endl;
        } else if ( hasil >= 23 && hasil <=24.9 ){
          cout << "Berlebih" << endl;
        } else if( hasil >= 25 && hasil <= 29.9 ){
          cout << "Obesitas Tingkat I" << endl;
        } else if ( hasil >= 30 ){
          cout << "Obesitas Tingkat II" << endl;
        }
        cout << "\nMau Menghitung Kembali? (y/n): ";
        cin >> lagi;
        cout << endl;
        } while ( lagi == 'y' || lagi == 'Y' );

  if ( lagi == 'n' || lagi == 'N' ){
    cout << "Program Berakhir" << endl;
  } else {
    cout << "Error, Input Tidak Valid, Program Berakhir" << endl;
  }
return 0;
}
