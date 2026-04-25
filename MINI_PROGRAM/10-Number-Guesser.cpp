#include <iostream>
using namespace std;

int main(){

char lagi;

do {
  system("clear");
  long batas_bawah, batas_atas, tengah;
  cout << "Halo, nama saya adalah 'V'. Saya adalah program penebak angka\n" << endl;
  cout << "Masukkan batas bawah dari rentang angka yang harus saya tebak : ";
  while (!(cin >> batas_bawah) || cin.peek() != '\n') {
    cout << "Harap masukkan input yang valid (bilangan bulat) : ";
    cin.clear();
    cin.ignore(1000, '\n');
  }
  cout << endl;
  cout << "Masukkan batas atas dari rentang angka yang harus saya tebak : ";
  while (!(cin >> batas_atas) || batas_atas <= batas_bawah || cin.peek() != '\n') {
    if (batas_atas <= batas_bawah){
      cout << "Batas atas tidak mungkin sama atau lebih kecil dari batas bawah, Harap masukkan input yang valid : ";
      cin.clear();
      cin.ignore(1000, '\n');
    } else {
      cout << "Harap masukkan input yang valid (bilangan bulat) : ";
      cin.clear();
      cin.ignore(1000, '\n');
    }
  }
  cout << "\nSekarang, pikirkan angka dengan rentang " << batas_bawah << "-" << batas_atas << ", Saya akan menebaknya" << endl;
  cout<<"==RULE=="<<endl;
  cout<<"1. Jika angka tebakan saya terlalu besar ketik 'B'"<<endl;
  cout<<"2. Jika angka tebakan saya terlalu kecil ketik 'K'"<<endl;
  cout<<"3. Jika angka tebakan saya sesuai dengan yang kamu pikirkan ketik 'S'"<<endl;
  char pilihan;
  do{
    cout << endl;
    tengah = (batas_bawah + batas_atas)/2;
    cout << "Angka yang kamu pikirkan adalah  : " << tengah << endl;
    cout << "B, K, atau S : ";
    while (!(cin >> pilihan) || (pilihan != 'B' && pilihan != 'b' && pilihan != 'K' && pilihan != 'k' && pilihan != 'S' && pilihan != 's') || cin.peek() != '\n') {
      cout << "Harap masukkan input yang valid (B, K, S) : ";
      cin.clear();
      cin.ignore(1000, '\n');
    }
    cout << endl;
    if ( pilihan == 'B' || pilihan == 'b' ){
      batas_atas = tengah - 1;
    } else if ( pilihan == 'K' || pilihan == 'k' ){
      batas_bawah = tengah + 1;
    }
  } while ( pilihan != 'S' && pilihan != 's' );

cout << "\nAkhir yang menyenangkan" << endl;
cout << "Mau mencoba kembali (y/n) : ";
cin >> lagi;
} while ( lagi == 'y' || lagi == 'Y' );

if ( lagi == 'n' || lagi == 'N' ){
  cout << "Program berakhir" << endl;
}else{
  cout << "Karakter tidak valid" << endl;
}
return 0;
}
