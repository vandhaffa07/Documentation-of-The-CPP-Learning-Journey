#include <iostream>
using namespace std;

int main(){

        string usn_admin = "Admin123";
        string pw_admin = "321Admin";
        string usn_admin_input, pw_admin_input;
        int identitas;

        cout << "===SELAMAT DATANG DI SISTEM LOGIN===\n\nMAU LOGIN SEBAGAI SIAPA?" << endl;
        cout << "1. ADMIN\n2. USER" << endl;
        cout << "KETIKKAN JAWABANMU ( 1 , 2 ) : ";
        cin >> identitas;
        cout<<endl;

        if ( identitas == 1 ){
                cout << "MASUKKAN USERNAME : ";
                cin >> usn_admin_input;

                cout << "MASUKKAN PASSWORD : ";
                cin >> pw_admin_input;

                if ( (usn_admin_input==usn_admin) && (pw_admin_input==pw_admin) ){
                                cout << "AKSES DITERIMA, SELAMAT DATANG KEMBALI"<< endl;
                } else {
                                cout << "AKSES DITOLAK, USERNAME ATAU PASSWORD SALAH" << endl;
                }
        } else if ( identitas == 2 ){
                string usn_daftar, pw_daftar;

                        cout << "ANDA BELUM PUNYA AKUN, SILAHKAN DAFTAR TERLEBIH DAHULU" << endl;
                        cout << "MASUKKAN USERNAME : ";
                        cin >> usn_daftar;
                        cout << "MASUKKAN PASSWORD : ";
      cin >> pw_daftar;
                        cout << "\nSELAMAT DATANG " << usn_daftar << endl;
        } else {
                cout << "HARAP MASUKKAN JAWABAN YANG VALID" << endl;
        }
        return 0;
}
