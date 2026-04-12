#include <iostream>
#include <cmath>
using namespace std;

int main(){
char lagi;
  do {
    system("clear");
    int pilihan;
    cout << "===SELAMAT DATANG DI PROGRAM PERHITUNGAN LUAS BANGUN DATAR===" <<endl;
    cout << "Silahkan pilih bangun datar berikut" << endl;
    cout << "1. Persegi\n2. Persegi Panjang\n3. Segitiga\n4. Lingkaran" << endl;
    cout << "Masukkan pilihan anda (1, 2, 3, 4) : ";

    while ( !(cin >> pilihan ) || pilihan < 1 || pilihan > 4 || cin.peek() != '\n' ) {
    cout << "Harap masukkan input yang valid (1, 2, 3, 4) : ";
    cin.clear();
    cin.ignore(1000, '\n');
  }
  cout << endl;

	if ( pilihan==1 ){
        int pilihan1;
          cout << "Ingin mencari luas berdasarkan apa?" << endl;
          cout << "1. Sisi\n2. Diagonal" << endl;
          cout << "Masukkan pilihan anda (1, 2) : ";
	  while ( !(cin >> pilihan1 ) || pilihan1 < 1 || pilihan1 > 2 || cin.peek() != '\n') {
	    cout << "Harap masukkan input yang valid (1, 2) : ";
            cin.clear();
    	    cin.ignore(1000, '\n');
  	  }
          cout << endl;
          if ( pilihan1==1) {
            double sisi;
              cout << "Masukkan panjang sisi : ";
               while ( !(cin >> sisi ) || sisi <= 0 || cin.peek() != '\n') {
                 cout << "Harap masukkan input yang valid ( bilangan positif ) : ";
                 cin.clear();
                 cin.ignore(1000, '\n');
               }
	  	cout << endl;
               cout << "Luas persegi tersebut adalah = " << (sisi * sisi) << endl;
          } else if ( pilihan1==2 ){
              double diagonal;
                cout << "Masukkan panjang diagonal : ";
                  while ( !(cin >> diagonal ) || diagonal <= 0 || cin.peek() != '\n') {
                    cout << "Harap masukkan input yang valid ( bilangan positif ) : ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                  }
		  cout << endl;
                cout << "Luas persegi tersebut adalah = " << ((diagonal * diagonal)/2) << endl;
          }
	} else if ( pilihan==2 ){
            double panjang, lebar;
              cout << "Masukkan panjang : ";
                while ( !(cin >> panjang ) || panjang <= 0 || cin.peek() != '\n') {
                  cout << "Harap masukkan input yang valid ( bilangan positif ) : ";
                  cin.clear();
                  cin.ignore(1000, '\n');
                }
		cout << endl;
	      cout << "Masukkan lebar : ";
                while ( !(cin >> lebar ) || lebar <= 0 || cin.peek() != '\n') {
                  cout << "Harap masukkan input yang valid ( bilangan positif ) : ";
                  cin.clear();
                  cin.ignore(1000, '\n');
                }
            	cout << endl;
              cout << "Luas persegi panjang tersebut adalah = " << (panjang * lebar) << endl;
        } else if ( pilihan==3 ){
        int pilihan3;
          cout << "Segitiga apa?" << endl;
          cout << "1. Sama sisi\n2. Sama kaki\n3. Siku-siku\n4. Sembarang" << endl;
          cout << "Masukkan pilihan anda (1, 2, 3, 4) : ";
          while ( !(cin >> pilihan3 ) || pilihan3 < 1 || pilihan3 > 4 || cin.peek() != '\n' ) {
    	    cout << "Harap masukkan input yang valid (1, 2, 3, 4) : ";
    	    cin.clear();
    	    cin.ignore(1000, '\n');
  	  }
          cout << endl;
                if ( pilihan3==1 ){
                int pilihan3_1;
                  cout << "Ingin mencari luas berdasarkan apa?" << endl;
                  cout << "1. Alas dan tinggi\n2. Panjang sisi identik" << endl;
                  cout << "Masukkan pilihan anda (1, 2) : ";
                  while ( !(cin >> pilihan3_1 ) || pilihan3_1 < 1 || pilihan3_1 > 2 || cin.peek() != '\n' ){
    		    cout << "Harap masukkan input yang valid (1, 2) : ";
    		    cin.clear();
    		    cin.ignore(1000, '\n');
  		  }
                  cout << endl;
                        if ( pilihan3_1==1 ){
                        double alas, tinggi;
                          cout << "Masukkan alas : ";
                	    while ( !(cin >> alas ) || alas <= 0 || cin.peek() != '\n') {
                  		cout << "Harap masukkan input yang valid ( bilangan positif ) : ";
                    		cin.clear();
                  		cin.ignore(1000, '\n');
                	    }
			    cout << endl;
                          cout << "Masukkan tinggi : ";
                	    while ( !(cin >> tinggi ) || tinggi <= 0 || cin.peek() != '\n') {
                  		cout << "Harap masukkan input yang valid ( bilangan positif ) : ";
                  		cin.clear();
                  		cin.ignore(1000, '\n');
                	    }
			    cout << endl;
                          cout << "Luas segitiga tersebut adalah = " << ((alas * tinggi)/2) << endl;
                        } else if ( pilihan3_1==2 ){
                        double sisi;
                          cout << "Masukkan panjang sisi identik : ";
                            while ( !(cin >> sisi ) || sisi <= 0 || cin.peek() != '\n') {
                                cout << "Harap masukkan input yang valid ( bilangan positif ) : ";
                                cin.clear();
                                cin.ignore(1000, '\n');
                            }
                            cout << endl;
                          cout << "Luas segitiga tersebut adalah = " << ((sisi*sisi)/4 * sqrt(3)) << endl;
			}
                } else if ( pilihan3==2 ){
                int pilihan3_2;
                  cout << "Ingin mencari luas berdasarkan apa?" << endl;
                  cout << "1. Alas dan tinggi\n2. Panjang sisi yang identik dan satu sisi lainnya" << endl;
                  cout << "Masukkan pilihan anda (1, 2) : ";
                  while ( !(cin >> pilihan3_2 ) || pilihan3_2 < 1 || pilihan3_2 > 2 || cin.peek() != '\n' ){
                    cout << "Harap masukkan input yang valid (1, 2) : ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                  }
                  cout << endl;
                        if ( pilihan3_2==1 ){
                        double alas, tinggi;
                          cout << "Masukkan alas : ";
                            while ( !(cin >> alas ) || alas <= 0 || cin.peek() != '\n') {
                                cout << "Harap masukkan input yang valid ( bilangan positif ) : ";
                                cin.clear();
                                cin.ignore(1000, '\n');
                            }
                            cout << endl;
                          cout << "Masukkan tinggi : ";
                            while ( !(cin >> tinggi ) || tinggi <= 0 || cin.peek() != '\n') {
                                cout << "Harap masukkan input yang valid ( bilangan positif ) : ";
                                cin.clear();
                                cin.ignore(1000, '\n');
                            }
                            cout << endl;
                          cout << "Luas segitiga tersebut adalah = " << ((alas * tinggi)/2) << endl;
                        } else if ( pilihan3_2==2 ){
                        double sisi_identik, sisi_lainnya;
			bool inputvalid;
			do {
			  inputvalid = true;
                          cout << "Masukkan panjang sisi yang identik : ";
                            while ( !(cin >> sisi_identik ) || sisi_identik <= 0 || cin.peek() != '\n') {
                                cout << "Harap masukkan input yang valid ( bilangan positif ) : ";
                                cin.clear();
                                cin.ignore(1000, '\n');
                            }
                            cout << endl;
                          cout << "Masukkan panjang sisi lainnya : ";
                            while ( !(cin >> sisi_lainnya ) || sisi_lainnya <= 0 || cin.peek() != '\n') {
                                cout << "Harap masukkan input yang valid ( bilangan positif ) : ";
                                cin.clear();
                                cin.ignore(1000, '\n');
                            }
                            cout << endl;
                                if (sisi_lainnya >= 2 * sisi_identik) {
                                  cout << "Secara matematis, segitiga ini tidak mungkin terbentuk, masukkan ulang!" << endl;
				  cout << endl;
				  inputvalid = false;
                                } else {
                                  cout << "Luas segitiga tersebut adalah = " << ((sisi_lainnya/2) * sqrt((sisi_identik * sisi_identik) - (sisi_lainnya * sisi_lainnya / 4))) << endl;
            			}
                        } while ( !inputvalid );
			}
                } else if ( pilihan3==3 ){
                int pilihan3_3;
                  cout << "Ingin mencari luas berdasarkan apa?" << endl;
                  cout << "1. Alas dan tinggi\n2. Panjang dari hipotenusa dan satu sisi lainnya" << endl;
                  cout << "Masukkan pilihan anda (1, 2) : ";
                  while ( !(cin >> pilihan3_3 ) || pilihan3_3 < 1 || pilihan3_3 > 2 || cin.peek() != '\n' ){
                    cout << "Harap masukkan input yang valid (1, 2) : ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                  }
                  cout << endl;
                        if ( pilihan3_3==1 ){
			double alas, tinggi;
                          cout << "Masukkan alas : ";
                            while ( !(cin >> alas ) || alas <= 0 || cin.peek() != '\n') {
                                cout << "Harap masukkan input yang valid ( bilangan positif ) : ";
                                cin.clear();
                                cin.ignore(1000, '\n');
                            }
                            cout << endl;
                          cout << "Masukkan tinggi : ";
                            while ( !(cin >> tinggi ) || tinggi <= 0 || cin.peek() != '\n') {
                                cout << "Harap masukkan input yang valid ( bilangan positif ) : ";
                                cin.clear();
                                cin.ignore(1000, '\n');
                            }
                            cout << endl;
                          cout << "Luas segitiga tersebut adalah = " << ((alas * tinggi)/2) << endl;
                        } else if ( pilihan3_3==2 ){
                        double hipotenusa, sisi_lainnya;
			bool inputvalid;
			do {
			  inputvalid = true;
                          cout << "Masukkan panjang hipotenusa : ";
                            while ( !(cin >> hipotenusa ) || hipotenusa <= 0 || cin.peek() != '\n') {
                                cout << "Harap masukkan input yang valid ( bilangan positif ) : ";
                                cin.clear();
                                cin.ignore(1000, '\n');
                            }
                            cout << endl;
                          cout << "Masukkan panjang sisi lainnya : ";
                            while ( !(cin >> sisi_lainnya ) || sisi_lainnya <= 0 || cin.peek() != '\n') {
                                cout << "Harap masukkan input yang valid ( bilangan positif ) : ";
                                cin.clear();
                                cin.ignore(1000, '\n');
                            }
                            cout << endl;
                                if ( sisi_lainnya >= hipotenusa ){
                                  cout << "Panjang sisi lain dari suatu segitiga siku-siku tidak mungkin melebihi atau sama dengan panjang hipotenusanya, masukkan ulang!" << endl;
				  cout << endl;
				  inputvalid = false;
                                } else {
                                  cout << "Luas segitiga tersebut adalah = " << ((sisi_lainnya/2) * sqrt((hipotenusa * hipotenusa) - (sisi_lainnya * sisi_lainnya))) << endl;
                                }
                        } while ( !inputvalid );
                        }
                } else if ( pilihan3==4 ){
                int pilihan3_4;
                  cout << "Ingin mencari luas berdasarkan apa?" << endl;
                  cout << "1. Alas dan tinggi\n2. Panjang sisi-sisi nya" << endl;
                  cout << "Masukkan pilihan anda (1, 2) : ";
                  while ( !(cin >> pilihan3_4 ) || pilihan3_4 < 1 || pilihan3_4 > 2 || cin.peek() != '\n' ){
                    cout << "Harap masukkan input yang valid (1, 2) : ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                  }
                  cout << endl;
                        if ( pilihan3_4==1 ){
                        double alas, tinggi;
                          cout << "Masukkan alas : ";
                            while ( !(cin >> alas ) || alas <= 0 || cin.peek() != '\n') {
                                cout << "Harap masukkan input yang valid ( bilangan positif ) : ";
                                cin.clear();
                                cin.ignore(1000, '\n');
                            }
                            cout << endl;
                          cout << "Masukkan tinggi : ";
                            while ( !(cin >> tinggi ) || tinggi <= 0 || cin.peek() != '\n') {
                                cout << "Harap masukkan input yang valid ( bilangan positif ) : ";
                                cin.clear();
                                cin.ignore(1000, '\n');
                            }
                            cout << endl;
                          cout << "Luas segitiga tersebut adalah = " << ((alas * tinggi)/2) << endl;
                        } else if ( pilihan3_4==2 ){
                        double sisi1, sisi2, sisi3;
			bool inputvalid;
			do {
			  inputvalid = true;
                          cout << "Masukkan panjang sisi pertama : ";
                            while ( !(cin >> sisi1) || sisi1 <= 0 || cin.peek() != '\n') {
                                cout << "Harap masukkan input yang valid ( bilangan positif ) : ";
                                cin.clear();
                                cin.ignore(1000, '\n');
                            }
                            cout << endl;
                          cout << "Masukkan panjang sisi kedua : ";
                            while ( !(cin >> sisi2 ) || sisi2 <= 0 || cin.peek() != '\n') {
                                cout << "Harap masukkan input yang valid ( bilangan positif ) : ";
                                cin.clear();
                                cin.ignore(1000, '\n');
                            }
                            cout << endl;
                          cout << "Masukkan panjang sisi ketiga : ";
                            while ( !(cin >> sisi3 ) || sisi3 <= 0 || cin.peek() != '\n') {
                                cout << "Harap masukkan input yang valid ( bilangan positif ) : ";
                                cin.clear();
                                cin.ignore(1000, '\n');
                            }
                            cout << endl;
                        double s = ((sisi1 + sisi2 + sisi3)/2);
                                if ((sisi1 + sisi2 > sisi3) && (sisi1 + sisi3 > sisi2) && (sisi2 + sisi3 > sisi1)) {
                                  cout << "Luas segitiga tersebut adalah = " << (sqrt(s * (s - sisi1) * (s - sisi2) * (s - sisi3))) << endl;
                                } else {
                                  cout << "Secara matematis, kombinasi sisi tersebut tidak bisa membentuk segitiga!" << endl;
				  cout << endl;
				  inputvalid = false;
                                }
                        } while ( !inputvalid );
                        }
                }
        } else if ( pilihan==4 ){
        int pilihan4;
          cout << "Ingin mencari luas berdasarkan apa?" << endl;
          cout << "1. Jari-jari\n2. Diameter" << endl;
          cout << "Masukkan pilihanmu(1, 2) : ";
          while ( !(cin >> pilihan4 ) || pilihan4 < 1 || pilihan4 > 2 || cin.peek() != '\n') {
            cout << "Harap masukkan input yang valid (1, 2) : ";
            cin.clear();
            cin.ignore(1000, '\n');
          }
          cout << endl;
                if ( pilihan4==1 ){
                double jarijari;
                  cout << "Masukkan panjang jari-jari : ";
                  while ( !(cin >> jarijari ) || jarijari <= 0 || cin.peek() != '\n') {
                    cout << "Harap masukkan input yang valid ( bilangan positif ) : ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                  }
		  cout << endl;
                  cout << "Luas lingkaran tersebut adalah : " << (M_PI * jarijari * jarijari) << endl;
                } else if ( pilihan4==2 ){
                double diameter;
                  cout << "Masukkan diameter : ";
                  while ( !(cin >> diameter ) || diameter <= 0 || cin.peek() != '\n') {
                    cout << "Harap masukkan input yang valid ( bilangan positif ) : ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                  }
                  cout << "Luas lingkaran tersebut adalah : " << (M_PI * (diameter/2) * (diameter/2)) << endl;
                }
	}

  cout << "\nMau Menghitung Kembali? (y/n): ";
  cin >> lagi;
  cout << endl;
  } while ( lagi == 'y' || lagi == 'Y' );

if ( lagi == 'n' || lagi == 'N' ){
  cout << "Program berakhir" << endl;
} else {
  cout << "Error, Input tidak valid, Program berakhir" << endl;
}
return 0;
}
