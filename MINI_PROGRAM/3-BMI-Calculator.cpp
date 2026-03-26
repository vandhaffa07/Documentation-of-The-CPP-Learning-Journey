#include <iostream>
using namespace std;

int main(){

        double berat_badan, tinggi_badan;
        cout<<"===SELAMAT DATANG DI KALKULATOR BMI SEDERHANA==="<<endl;
        cout<<"<18.5        : Kurang"<<endl;
        cout<<"18.5 - 22.9 : Normal"<<endl;
        cout<<"23.0 - 24.9 : Berlebih"<<endl;
        cout<<"25.0 - 29.9 : Obesitas Tingkat I"<<endl;
        cout<<">=30         : Obesitas Tingkat II\n"<<endl;

        cout<<"Masukkan Berat Badanmu(kg) : ";
        cin >> berat_badan;
        cout<<"Masukkan Tinggi Badanmu(cm) : ";
        cin >> tinggi_badan;

        double hasil = berat_badan/(tinggi_badan*tinggi_badan/10000);
        cout<<"BMI-mu adalah : "<<hasil<<endl;
        return 0;
}
