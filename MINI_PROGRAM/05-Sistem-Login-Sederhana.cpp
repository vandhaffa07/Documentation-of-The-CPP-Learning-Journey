#include <iostream>
using namespace std;

int main(){
  char lagi;

  string usn_admin = "Admin123";
  string pw_admin = "321Admin";
  string usn_akun_user, pw_akun_user;
  bool akun = false;

  do {
  int pilihan;

        cout << "===SELAMAT DATANG DI SISTEM LOGIN===\n\nMAU LOGIN SEBAGAI SIAPA?" << endl;
        cout << "1. ADMIN\n2. LOGIN USER\n3. DAFTAR USER" << endl;
        cout << "KETIKKAN JAWABANMU ( 1, 2, 3 ) : ";
        while ( !(cin >> pilihan) || pilihan < 1 || pilihan > 3 || cin.peek() != '\n' ){
          cout <<"MASUKKAN JAWABAN YANG VALID (1, 2, 3) : ";
          cin.clear();
          cin.ignore(1000, '\n');
        }
        cout<<endl;

	switch ( pilihan ){
        case 1 : {
	cin.ignore(1000, '\n');
        string usn_admin_input, pw_admin_input;
          cout << "MASUKKAN USERNAME : ";
           getline(cin, usn_admin_input);

          cout << "MASUKKAN PASSWORD : ";
           getline(cin, pw_admin_input);

          if ( (usn_admin_input==usn_admin) && (pw_admin_input==pw_admin) ){
            cout << "AKSES DITERIMA, LOGIN SEBAGAI ADMIN BERHASIL, SELAMAT DATANG"<< endl;
          } else {
            cout << "AKSES DITOLAK, LOGIN ADMIN GAGAL, USERNAME ATAU PASSWORD SALAH" << endl;
          }
	break;
        }

	case 2 : {
	cin.ignore(1000, '\n');
        string usn_login_user, pw_login_user;
	  if ( !akun ){
	    cout << "ANDA BELUM PUNYA AKUN, SILAHKAN DAFTAR TERLEBIH DAHULU" << endl;
	    break;
	  }
	  cout << "MASUKKAN USERNAME : ";
	    getline(cin, usn_login_user);
	  cout << "MASUKKAN PASSWORD : ";
	    getline(cin, pw_login_user);
	    if ( (usn_login_user == usn_akun_user) && (pw_login_user == pw_akun_user) ){
	      cout << "LOGIN SEBAGAI USER BERHASIL, SELAMAT DATANG " << usn_akun_user << endl;
	    } else {
	      cout << "LOGIN USER GAGAL, USERNAME ATAU PASSWORD SALAH" << endl;
	    }
	break;
	}

	case 3 : {
	cin.ignore(1000, '\n');
	string usn_daftar_user, pw_daftar_user;
	  cout << "MASUKKAN USERNAME : ";
	    getline(cin, usn_daftar_user);
	  cout << "MASUKKAN PASSWORD : ";
	    getline(cin, pw_daftar_user);
	  akun = true;
	  usn_akun_user = usn_daftar_user;
	  pw_akun_user = pw_daftar_user;
	  cout << "PENDAFTARAN BERHASIL" << endl;
	break;
	}
	}

  cout << "\nKembali ke menu? (y/n): ";
  cin >> lagi;
} while (lagi == 'y' || lagi == 'Y');

return 0;
}
