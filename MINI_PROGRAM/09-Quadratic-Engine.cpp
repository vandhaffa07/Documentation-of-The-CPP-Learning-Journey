#include <iostream>
#include <cmath>
using namespace std;

int main(){
char lagi;

do {
  system("clear");
  int pilihan;
  cout << "======================" << endl;
  cout << "Quadratic Engine" << endl;
  cout << "======================" << endl;
  cout << "1. Hitung akar persamaan\n2. Cek diskriminan dan jenis akar\n3. Cek sumbu simetri" << endl;
  cout << "======================\n" << endl;
  cout << "Masukkan pilihan anda (1, 2, 3) : ";

  while (!(cin >> pilihan) || pilihan > 3 || pilihan < 1 || cin.peek() != '\n') {
    cout << "Harap masukkan input yang valid : ";
    cin.clear();
    cin.ignore(1000, '\n');
  }
  cout << endl;

  switch (pilihan){
    case 1 : {
      double a, b, c, diskriminan;
      cout << "Untuk persamaan kuadrat ax^2 + bx + c," << endl;
      cout << "Masukkan nilai a : ";
	while (!(cin >> a) || a == 0 || cin.peek() != '\n') {
	  if ( a == 0 ){
    	    cout << "Untuk persamaan kudarat a tidak boleh bernilai 0, Harap masukkan input yang valid : ";
    	    cin.clear();
    	    cin.ignore(1000, '\n');
	  } else {
            cout << "Harap masukkan input yang valid : ";
            cin.clear();
            cin.ignore(1000, '\n');
          }
  	}
  	cout << endl;
      cout << "Masukkan nilai b : ";
        while (!(cin >> b) || cin.peek() != '\n') {
          cout << "Harap masukkan input yang valid : ";
          cin.clear();
          cin.ignore(1000, '\n');
        }
        cout << endl;
      cout << "Masukkan nilai c : ";
        while (!(cin >> c) || cin.peek() != '\n') {
          cout << "Harap masukkan input yang valid : ";
          cin.clear();
          cin.ignore(1000, '\n');
        }
        cout << endl;
      diskriminan = pow(b, 2) - (4*a*c);
      if ( diskriminan > 0 ){
        double akar1 = (-b + sqrt(diskriminan))/(2*a);
      	double akar2 = (-b - sqrt(diskriminan))/(2*a);
      	cout << "Akar pertama = " << akar1 << "\nAkar kedua = " << akar2 << endl;
	break;
      } else if ( diskriminan == 0 ){
        double hasil = -b / (2*a);
        cout << "Akar pertama = Akar kedua = " << hasil << endl;
 	break;
      } else if ( diskriminan < 0 ){
        double bagianreal = -b/(2*a);
	double bagianimajiner = sqrt(-diskriminan)/(2*a);
        cout << "Akar pertama : " << bagianreal << " + " << bagianimajiner << "i" << "\nAkar kedua : " << bagianreal << " - " << bagianimajiner << "i" << endl;
      	break;
      }
    break;
    }

    case 2 : {
      double a, b, c, diskriminan;
      cout << "Untuk persamaan kuadrat ax^2 + bx + c," << endl;
      cout << "Masukkan nilai a : ";
        while (!(cin >> a) || a == 0 || cin.peek() != '\n') {
          if ( a == 0 ){
            cout << "Untuk persamaan kudarat a tidak boleh bernilai 0, Harap masukkan input yang valid : ";
            cin.clear();
            cin.ignore(1000, '\n');
          } else {
            cout << "Harap masukkan input yang valid : ";
            cin.clear();
            cin.ignore(1000, '\n');
          }
        }
        cout << endl;
      cout << "Masukkan nilai b : ";
        while (!(cin >> b) || cin.peek() != '\n') {
          cout << "Harap masukkan input yang valid : ";
          cin.clear();
          cin.ignore(1000, '\n');
        }
        cout << endl;
      cout << "Masukkan nilai c : ";
        while (!(cin >> c) || cin.peek() != '\n') {
          cout << "Harap masukkan input yang valid : ";
          cin.clear();
          cin.ignore(1000, '\n');
        }
        cout << endl;
      diskriminan = pow(b, 2) - (4*a*c);
      cout << "Diskriminan = " << diskriminan << endl;
      if ( diskriminan > 0 ){
        cout << "Jenis akar = Akar real berbeda " << endl;
        break;
      } else if ( diskriminan == 0 ){
        double hasil = -b / (2*a);
        cout << "Jenis akar = Akar kembar " << endl;
        break;
      } else if ( diskriminan < 0 ){
        double bagianreal = -b/(2*a);
        double bagianimajiner = sqrt(-diskriminan)/(2*a);
        cout << "Jenis akar = Akar tidak real (Imajiner) " << endl;
        break;
      }
    break;
    }

    case 3 : {
      double a, b, c, sumbusimetri;
      cout << "Untuk persamaan kuadrat ax^2 + bx + c," << endl;
      cout << "Masukkan nilai a : ";
        while (!(cin >> a) || a == 0 || cin.peek() != '\n') {
          if ( a == 0 ){
            cout << "Untuk persamaan kudarat a tidak boleh bernilai 0, Harap masukkan input yang valid : ";
            cin.clear();
            cin.ignore(1000, '\n');
          } else {
            cout << "Harap masukkan input yang valid : ";
            cin.clear();
            cin.ignore(1000, '\n');
          }
        }
        cout << endl;
      cout << "Masukkan nilai b : ";
        while (!(cin >> b) || cin.peek() != '\n') {
          cout << "Harap masukkan input yang valid : ";
          cin.clear();
          cin.ignore(1000, '\n');
        }
        cout << endl;
      cout << "Masukkan nilai c : ";
        while (!(cin >> c) || cin.peek() != '\n') {
          cout << "Harap masukkan input yang valid : ";
          cin.clear();
          cin.ignore(1000, '\n');
        }
        cout << endl;
      sumbusimetri = -b/(2*a);
      cout << "Sumbu simetri parabola terletak pada x = " << sumbusimetri << endl;
    break;
    }
  }
cout << "\nMau Menghitung Kembali? (y/n): ";
cin >> lagi;
} while ( lagi == 'y' || lagi == 'Y' );

if ( lagi == 'n' || lagi == 'N' ){
  cout << "Program berakhir" << endl;
} else {
  cout << "Error, Input tidak valid, Program berakhir" << endl;
}
return 0;
}
