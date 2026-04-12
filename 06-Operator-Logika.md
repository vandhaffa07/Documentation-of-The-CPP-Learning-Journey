# OPERATOR LOGIKA
Setelah kita memahami bagaimana cara membandingkan dua buah data menggunakan operator relasional pada pembahasan sebelumnya, kita menyadari bahwa hasil dari komparasi tersebut hanyalah sebuah nilai boolean tunggal (0 atau 1) yang merepresentasikan pernyataan benar(true) dan juga pernyataan salah(false). Namun, kita sering kali membutuhkan hasil yang didasarkan pada lebih dari satu syarat operator relasional sekaligus. Dari sinilah operator logika berperan sebagai gerbang yang menghubungkan berbagai ekspresi relasional tersebut untuk menghasilkan satu kesimpulan akhir yang baru. Operator logika sendiri dapat didefinisikan sebagai simbol atau kata kunci yang digunakan dalam pemrograman dan matematika untuk menghubungkan dua atau lebih kondisi guna menghasilkan nilai boolean tunggal (true atau false) yang baru. Operator ini bersifat krusial karena seringkali digunakan sebagai fondasi dalam struktur kendali alur program, seperti percabangan (if-else) dan perulangan (loops).

Secara umum, terdapat 3 operator logika utama dalam C++ :
### 1. `&&` (and)
Operator `&&`(and) adalah operator yang hanya akan menghasilkan nilai true (1) jika dan hanya jika semua operan atau kondisi yang dihubungkan bernilai benar. Jika terdapat satu saja kondisi yang bernilai false (0), maka secara otomatis seluruh hasil operasi tersebut akan menjadi false (0) tanpa terkecuali. 

Untuk membuktikannya, mari kita membuat program dimana sebuah angka dikatakan valid jika angka tersebut lebih besar dari 10 dan lebih kecil dari 20.
```bash
nano operator_and.cpp
```
```c++
#include <iostream>
using namespace std;

int main(){
  //Eksperimen 1 : Kedua syarat dibuat benar
  int angka=15;
  cout << "Apakah "<< angka << " Berada pada range 10-20?  Hasil : "<<((angka>10) && (angka<20)) << endl;

  //Eksperimen 2 : Salah satu syarat dibuat salah (30 > 10 Benar, tapi 30 < 20 Salah)
  angka=30;
  cout << "Apakah "<< angka << " Berada pada range 10-20?  Hasil : "<<((angka>10) && (angka<20)) << endl;

  //Eksperimen 3 : Salah satu syarat dibuat salah (5 < 20 Benar, tapi 5>10 Salah)
  angka=5;
  cout << "Apakah "<< angka << " Berada pada range 10-20?  Hasil : "<<((angka>10) && (angka<20)) << endl;

  return 0;
}
```
```bash
g++ operator_and.cpp -o operator.and
```
```bash
./operator_and
Apakah 15 Berada pada range 10-20?  Hasil : 1
Apakah 30 Berada pada range 10-20?  Hasil : 0
Apakah 5 Berada pada range 10-20?  Hasil : 0
```
Perhatikan pada hasil eksekusi di atas. Pada percobaan pertama, angka 15 menghasilkan 1 karena ia memenuhi kedua syarat tersebut secara bersamaan. Namun, pada percobaan kedua dan ketiga, meskipun salah satu syarat telah terpenuhi (bernilai 1), hasil akhirnya tetaplah 0 (false). Hal ini dikarenakan karakteristik dasar dari operator `&&`(and) yang menuntut seluruh kondisi bernilai benar tanpa pengecualian. Dalam logika ini, kegagalan pada satu syarat saja sudah cukup untuk membatalkan seluruh ekspresi dan mengubah kesimpulan akhir menjadi salah.

### 2. `||` (or)
Berbeda dengan operator `&&`(and), operator `||`(or) memiliki sifat yang lebih toleran. Operator ini hanya membutuhkan salah satu dari kondisi yang ada untuk bernilai true (1) agar hasil akhirnya menjadi true (1). Satu-satunya cara agar operator ini menghasilkan nilai false (0) adalah jika seluruh kondisi yang dibandingkan bernilai salah.

Untuk membuktikannya, mari kita membuat program dimana sebuah angka dikatakan valid jika angka tersebut lebih kecil dari 10 atau lebih besar dari 20.
```bash
nano operator_or.cpp
```
```c++
#include <iostream>
using namespace std;

int main(){
  // Eksperimen 1: Syarat kedua benar (25 > 20)
  int angka = 25;
  cout << "Apakah " << angka << " di luar rentang 10-20? Hasil: " << ((angka < 10) || (angka > 20)) << endl;

  // Eksperimen 2: Syarat pertama benar (5 < 10)
  angka = 5;
  cout << "Apakah " << angka << " di luar rentang 10-20? Hasil: " << ((angka < 10) || (angka > 20)) << endl;

  // Eksperimen 3: Kedua syarat salah (15 tidak < 10 dan tidak > 20)
  angka = 15;
  cout << "Apakah " << angka << " di luar rentang 10-20? Hasil: " << ((angka < 10) || (angka > 20)) << endl;

  return 0;
}
```
```bash
g++ operator_or.cpp -o operator_or
```
```bash
./operator_or
Apakah 25 di luar rentang 10-20? Hasil: 1
Apakah 5 di luar rentang 10-20? Hasil: 1
Apakah 15 di luar rentang 10-20? Hasil: 0
```
Perhatikan hasil eksekusi di atas. Pada percobaan pertama dan kedua, program menghasilkan nilai 1 (true), karena pada percobaan pertama syarat kedua terpenuhi ($25 > 20$), dan pada percobaan kedua syarat pertama terpenuhi ($5 < 10$). Hal ini dikarenakan karakteristik dasar dari operator `||`(or) yang hanya membutuhkan salah satu kondisi bernilai benar untuk menghasilkan kesimpulan akhir benar. Namun, pada percobaan ketiga, angka 15 menghasilkan nilai 0 (false) karena angka tersebut tidak memenuhi satu pun dari kedua syarat yang diberikan. Hal ini membuktikan bahwa logika or hanya akan menghasilkan nilai salah jika seluruh syarat yang dihubungkan terbukti salah secara bersamaan.


### 3. `!` (not)
Operator `!`(not) adalah satu-satunya operator logika yang bersifat unary, dimana ia hanya bekerja pada satu operan saja. Tugas utamanya adalah melakukan inversi atau membalikkan nilai logika. Jika nilai aslinya adalah true (1), maka ia akan dipaksa menjadi false (0), dan begitu pula sebaliknya.

Perhatikan bagaimana tanda seru ini membalikkan hasil perbandingan di dalam kode berikut:
```Bash
nano operator_not.cpp
```
```c++
#include <iostream>
using namespace std;

int main() {
    bool kondisi = true;

    cout << "Kondisi Awal : " << kondisi << endl;
    cout << "Kondisi Setelah (!) : " << !kondisi << endl;

    return 0;
}
```
```bash
g++ operator_not.cpp -o operator_not
```
```bash
./operator_not
Kondisi Awal : 1
Kondisi Setelah (!) : 0
```
Perhatikan hasil eksekusi di atas. Pada baris pertama, variabel kondisi menampilkan nilai 1 (true) sesuai dengan inisialisasi awalnya. Namun, pada baris kedua, ketika kita menambahkan operator `!` di depan variabel tersebut `(!kondisi)`, nilai yang muncul berubah menjadi 0 (false). Hal ini membuktikan bahwa operator not berfungsi sebagai pembalik logika (inverter) yang valid dan akurat. 

Menariknya, operator not ini dapat digunakan secara bertumpuk atau dobel. Teknik ini sering disebut dengan Double Negation. Secara logika, jika kita membalikkan sesuatu yang sudah terbalik, maka nilainya akan kembali ke bentuk asalnya.

Contoh :
```Bash
nano operator_double_not.cpp
```
```C++
#include <iostream>
using namespace std;

int main() {
    bool kondisi = true;

    cout << "Kondisi Awal (true)        : " << kondisi << endl;
    cout << "Negasi Pertama (!kondisi)  : " << !kondisi << endl;
    cout << "Negasi Kedua (!!kondisi)   : " << !!kondisi << endl;

    return 0;
}
```
```Bash
g++ operator_double_not.cpp -o double_not
```
```bash
./double_not
Bash
Kondisi Awal (true)        : 1
Negasi Pertama (!kondisi)  : 0
Negasi Kedua (!!kondisi)   : 1
```
Perhatikan alur perubahan nilai pada hasil eksekusi di atas. Pada langkah pertama, operator not tunggal `(!)` mengubah nilai 1 menjadi 0. Namun, ketika kita menambahkan operator not yang kedua `(!!)`, operator tersebut malah menghasilkan nilai yang sama seperti variabel awal. Hal tersebut dapat terjadi dikarenakan secara matematis proses dari negasi ganda ini, dapat diuraikan menjadi seperti ini :

`!!(true)` $\rightarrow$ `!( !true )` $\rightarrow$ `!( false )` $\rightarrow$ `( true )`













