#include <iostream>
using namespace std;

int main(){
        int angka;

        cout << "MASUKKAN BILANGAN BULAT :";
        cin >> angka;

        if( angka %2 == 0 ){
                cout << angka  << " ADALAH BILANGAN GENAP" << endl;
        } else {
                cout << angka << " ADALAH BILANGAN GANJIL" << endl;
        }
        return 0;
}
