#include <iostream>
using namespace std;

int main(){

char lagi;

do{
  system("clear");
  int baris;
  cout << "=====SELAMAT DATANG DI PROGRAM GENERATE POLA SEGITIGA=====" << endl;
  cout << "Masukkan jumlah baris : ";
  while(!(cin >> baris) || baris <= 0 || cin.peek() != '\n'){
    cout << "Harap masukkan input yang valid ( bilangan bulat positif ) : ";
    cin.clear();
    cin.ignore(1000, '\n');
  }
  cout << endl;
  cout << "POLA 1" << endl;
    for ( int a = 1; a <= baris; a++ ){
      for (int b = 1; b <= a; b++){
	cout << "*";
      }
      cout << endl;
    }
  cout << endl;

  cout << "POLA 2" << endl;
    for ( int a = 1; a <= baris; a++){
      for (int b = baris; b >= a; b--){
	cout << "*";
      }
      cout << endl;
    }
  cout << endl;

  cout << "POLA 3" << endl;
    for (int a = 1; a <= baris; a++){
      for (int b = baris; b >= a+1; b--){
	cout << " ";
      }
      for (int c = 1; c <= a; c++){
	cout << "*";
      }
      cout << endl;
    }
  cout << endl;

  cout << "POLA 4" << endl;
    for (int a = 1; a <= baris; a++){
      for (int c = 1; c <= a-1; c++){
        cout << " ";
      }
      for (int b = baris; b >= a; b--){
	cout << "*";
      }
      cout << endl;
    }
  cout << endl;

  cout << "POLA 5" << endl;
    for (int a = 1; a <= baris; a++){
      for (int b = baris; b >= a+1; b--){
        cout << " ";
      }
      for (int c = 1; c <= 2*a-1; c++){
        cout << "*";
      }
      cout << endl;
    }
  cout << endl;

  cout << "POLA 6" << endl;
    for (int a = 1; a <= baris; a++){
      for (int b = 1; b <= a-1; b++){
        cout << " ";
      }
      for (int c = baris; c >= 2*a-baris; c--){
        cout << "*";
      }
      cout << endl;
    }
  cout << endl;

  cout << "POLA 7" << endl;
    for (int a = 1; a <= baris; a++){
      for (int b = 1; b <= a; b++){
        if ( b == 1 || b == a || a == baris ){
	  cout << "*";
	} else {
	  cout << " ";
	}
      }
      cout << endl;
    }
  cout << endl;

  cout << "POLA 8" << endl;
    for (int a = 1; a <= baris; a++){
      for (int b = baris; b >= a; b--){
        if ( a == 1 || b == a || b == baris ){
          cout << "*";
        } else {
          cout << " ";
        }
      }
      cout << endl;
    }
  cout << endl;

  cout << "POLA 9" << endl;
    for (int a = 1; a <= baris; a++){
      for (int b = baris; b >= a+1; b--){
        cout << " ";
      }
      for (int c = 1; c <= a; c++){
        if ( c == 1 || c == a || a == baris ){
          cout << "*";
        } else {
          cout << " ";
        }
      }
      cout << endl;
    }
  cout << endl;

  cout << "POLA 10" << endl;
    for (int a = 1; a <= baris; a++){
      for (int c = 1; c <= a-1; c++){
        cout << " ";
      }
      for (int b = baris; b >= a; b--){
        if ( a == 1 || b == a || b == baris ){
          cout << "*";
        } else {
          cout << " ";
        }
      }
      cout << endl;
    }
  cout << endl;

  cout << "POLA 11" << endl;
    for (int a = 1; a <= baris; a++){
      for (int b = baris; b >= a+1; b--){
        cout << " ";
      }
      for (int c = 1; c <= 2*a-1; c++){
        if ( c == 1 || c == 2*a-1 || a == baris ){
          cout << "*";
        } else {
          cout << " ";
        }
      }
      cout << endl;
    }
  cout << endl;

  cout << "POLA 12" << endl;
    for (int a = 1; a <= baris; a++){
      for (int b = 1; b <= a-1; b++){
        cout << " ";
      }
      for (int c = baris; c >= 2*a-baris; c--){
        if ( a == 1 || c == 2*a-baris || c == baris ){
          cout << "*";
        } else{
          cout << " ";
	}
     }
     cout << endl;
     }
cout << "\nMau generate lagi? (y/n): ";
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
