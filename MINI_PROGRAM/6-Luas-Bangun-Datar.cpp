#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int pilihan;
    cout << "===SELAMAT DATANG DI PROGRAM PERHITUNGAN LUAS BANGUN DATAR===" <<endl;
    cout << "Silahkan pilih bangun datar berikut" << endl;
    cout << "1. Persegi\n2. Persegi Panjang\n3. Segitiga\n4. Lingkaran" << endl;
    cout << "Masukkan pilihan anda (1, 2, 3, 4) : ";
    cin >> pilihan;
    cout << endl;

        if ( pilihan==1 ){
        int pilihan1;
          cout << "Ingin mencari luas berdasarkan apa?" << endl;
          cout << "1. Sisi\n2. Diagonal" << endl;
          cout << "Masukkan pilihan anda (1, 2) : ";
          cin >> pilihan1;
          cout << endl;
                if ( pilihan1==1) {
                  double sisi;
                        cout << "Masukkan panjang sisi : ";
                        cin >> sisi;
                        cout << "Luas persegi tersebut adalah = " << (sisi * sisi) << endl;
                } else if ( pilihan1==2 ){
                  double diagonal;
                        cout << "Masukkan panjang diagonal : ";
                        cin >> diagonal;
                        cout << "Luas persegi tersebut adalah = " << ((diagonal * diagonal)/2) << endl;
                } else {
                        cout << "Harap masukkan pilihan yang valid" << endl;
                }
        } else if ( pilihan==2 ){
          double panjang, lebar;
            cout << "Masukkan panjang : ";
            cin >> panjang;
            cout << "Masukkan lebar : ";
            cin >> lebar;
            cout << "Luas persegi panjang tersebut adalah = " << (panjang * lebar) << endl;
        } else if ( pilihan==3 ){
        int pilihan3;
          cout << "Segitiga apa?" << endl;
          cout << "1. Sama sisi\n2. Sama kaki\n3. Siku-siku\n4. Sembarang" << endl;
          cout << "Masukkan pilihan anda (1, 2, 3, 4) : ";
          cin >> pilihan3;
          cout << endl;
                if ( pilihan3==1 ){
                int pilihan3_1;
                  cout << "Ingin mencari luas berdasarkan apa?" << endl;
                  cout << "1. Alas dan tinggi\n2. Panjang sisi identik" << endl;
                  cout << "Masukkan pilihan anda (1, 2) : ";
                  cin >> pilihan3_1;
                  cout << endl;
                        if ( pilihan3_1==1 ){
                        double alas, tinggi;
                          cout << "Masukkan alas : ";
                          cin >> alas;
                          cout << "Masukkan tinggi : ";
                          cin >> tinggi;
                          cout << "Luas segitiga tersebut adalah = " << ((alas * tinggi)/2) << endl;
                        } else if ( pilihan3_1==2 ){
                        double sisi;
                          cout << "Masukkan panjang sisi identik : ";
                          cin >> sisi;
                          cout << "Luas segitiga tersebut adalah = " << ((sisi*sisi)/4 * sqrt(3)) << endl;
                        } else {
                          cout << "Harap masukkan pilihan yang valid" << endl;
                        }
                } else if ( pilihan3==2 ){
                int pilihan3_2;
                  cout << "Ingin mencari luas berdasarkan apa?" << endl;
                  cout << "1. Alas dan tinggi\n2. Panjang sisi yang identik dan satu sisi lainnya" << endl;
                  cout << "Masukkan pilihan anda (1, 2) : ";
                  cin >> pilihan3_2;
                  cout << endl;
                        if ( pilihan3_2==1 ){
                        double alas, tinggi;
                          cout << "Masukkan alas : ";
                          cin >> alas;
                          cout << "Masukkan tinggi : ";
                          cin >> tinggi;
                          cout << "Luas segitiga tersebut adalah = " << ((alas * tinggi)/2) << endl;
                        } else if ( pilihan3_2==2 ){
                        double sisi_identik, sisi_lainnya;
                          cout << "Masukkan panjang sisi yang identik : ";
                          cin >> sisi_identik;
                          cout << "Masukkan panjang sisi lainnya : ";
                          cin >> sisi_lainnya;
                                if (sisi_lainnya >= 2 * sisi_identik) {
                                  cout << "Secara matematis, segitiga ini tidak mungkin terbentuk!" << endl;
                                } else {
                                  cout << "Luas segitiga tersebut adalah = " << ((sisi_lainnya/2) * sqrt((sisi_identik * sisi_identik) - (sisi_lainnya * sisi_lainnya / 4))) << endl;
                                }
                        } else {
                          cout << "Harap masukkan pilihan yang valid" << endl;
                        }
                } else if ( pilihan3==3 ){
                int pilihan3_3;
                  cout << "Ingin mencari luas berdasarkan apa?" << endl;
                  cout << "1. Alas dan tinggi\n2. Panjang dari hipotenusa dan satu sisi lainnya" << endl;
                  cout << "Masukkan pilihan anda (1, 2) : ";
                  cin >> pilihan3_3;
                  cout << endl;
                        if ( pilihan3_3==1 ){
                        double alas, tinggi;
                          cout << "Masukkan alas : ";
                          cin >> alas;
                          cout << "Masukkan tinggi : ";
                          cin >> tinggi;
                          cout << "Luas segitiga tersebut adalah = " << ((alas * tinggi)/2) << endl;
                        } else if ( pilihan3_3==2 ){
                        double hipotenusa, sisi_lainnya;
                          cout << "Masukkan panjang hipotenusa : ";
                          cin >> hipotenusa;
                          cout << "Masukkan panjang sisi lainnya : ";
                          cin >> sisi_lainnya;
                                if ( sisi_lainnya >= hipotenusa ){
                                  cout << "Panjang sisi lain dari suatu segitiga siku-siku tidak mungkin melebihi atau sama dengan panjang hipotenusanya" << endl;
                                } else {
                                  cout << "Luas segitiga tersebut adalah = " << ((sisi_lainnya/2) * sqrt((hipotenusa * hipotenusa) - (sisi_lainnya * sisi_lainnya))) << endl;
                                }
                        } else {
                          cout << "Harap masukkan pilihan yang valid" << endl;
                        }
                } else if ( pilihan3==4 ){
                int pilihan3_4;
                  cout << "Ingin mencari luas berdasarkan apa?" << endl;
                  cout << "1. Alas dan tinggi\n2. Panjang sisi-sisi nya" << endl;
                  cout << "Masukkan pilihan anda (1, 2) : ";
                  cin >> pilihan3_4;
                  cout << endl;
                        if ( pilihan3_4==1 ){
                        double alas, tinggi;
                          cout << "Masukkan alas : ";
                          cin >> alas;
                          cout << "Masukkan tinggi : ";
                          cin >> tinggi;
                          cout << "Luas segitiga tersebut adalah = " << ((alas * tinggi)/2) << endl;
                        } else if ( pilihan3_4==2 ){
                        double sisi1, sisi2, sisi3;
                          cout << "Masukkan panjang sisi pertama : ";
                          cin >> sisi1;
                          cout << "Masukkan panjang sisi kedua : ";
                          cin >> sisi2;
                          cout << "Masukkan panjang sisi ketiga : ";
                          cin >> sisi3;
                        double s = ((sisi1 + sisi2 + sisi3)/2);
                                if ((sisi1 + sisi2 > sisi3) && (sisi1 + sisi3 > sisi2) && (sisi2 + sisi3 > sisi1)) {
                                  cout << "Luas segitiga tersebut adalah = " << (sqrt(s * (s - sisi1) * (s - sisi2) * (s - sisi3))) << endl;
                                } else {
                                  cout << "Secara matematis, kombinasi sisi tersebut tidak bisa membentuk segitiga!" << endl;
                                }
                        } else {
                          cout << "Harap masukkan pilihan yang valid" << endl;
                        }
                } else {
                  cout << "Harap masukkan pilihan yang valid" << endl;
                }
        } else if ( pilihan==4 ){
        int pilihan4;
          cout << "Ingin mencari luas berdasarkan apa?" << endl;
          cout << "1. Jari-jari\n2. Diameter" << endl;
          cout << "Masukkan pilihanmu(1, 2) : ";
          cin >> pilihan4;
          cout << endl;
                if ( pilihan4==1 ){
                double jarijari;
                  cout << "Masukkan panjang jari-jari : ";
                  cin >> jarijari;
                  cout << "Luas lingkaran tersebut adalah : " << (M_PI * jarijari * jarijari) << endl;
                } else if ( pilihan4==2 ){
                double diameter;
                  cout << "Masukkan diameter : ";
                  cin >> diameter;
                  cout << "Luas lingkaran tersebut adalah : " << (M_PI * (diameter/2) * (diameter/2)) << endl;
                } else {
                  cout << "Harap masukkan pilihan yang valid" << endl;
                }

        } else {
          cout << "Harap masukkan pilihan yang valid" << endl;
        }
  return 0;
}
