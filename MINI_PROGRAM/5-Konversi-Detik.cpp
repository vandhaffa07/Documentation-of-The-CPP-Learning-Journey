#include <iostream>
using namespace std;

int main(){
        int total_detik, jam, menit, detik;
        cout<<"Masukkan Total Detik : ";
        cin >> total_detik;
        jam = total_detik/3600;
        menit = (total_detik % 3600)/60;
        detik = total_detik % 60;
        cout<<"Hasil : "<<jam<<" Jam "<<menit<<" Menit "<<detik<<" Detik"<<endl;

        return 0;
}
