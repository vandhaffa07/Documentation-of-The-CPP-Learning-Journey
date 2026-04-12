# IF-ELSE STATEMENT
Sebelumnya, kita telah memahami bagaimana cara komputer dapat menghasilkan nilai biner 0 (false) dan 1 (true) melalui operator-operator tertentu dan logika boolean. Berbekal pengetahuan nilai biner tersebut, kita sebenarnya dapat menyusun logika pengambilan keputusan melalui mekanisme yang disebut sebagai struktur kendali percabangan atau If-Else Statement. If-Else Statement adalah mekanisme yang memungkinkan program untuk memiliki kecerdasan dalam memilih blok kode mana yang harus dieksekusi berdasarkan kondisi tertentu. Pada tingkat yang lebih tinggi, instruksi ini dapat didefinisikan sebagai percabangan alur kerja (branching) yang hanya akan terbuka jika syarat di dalamnya menghasilkan nilai true (1).

---

## STRUKTUR DASAR INSTRUKSI IF
Secara teknis, instruksi if berfungsi sebagai gerbang logika yang mengontrol alur eksekusi program. Proses ini bekerja dalam dua tahapan utama, yakni evaluasi ekspresi dan percabangan alur. Pada tahap pertama, komputer akan mengevaluasi ekspresi di dalam tanda kurung () dimana ekspresi ini harus menghasilkan nilai boolean tertentu, baik itu 1(true) maupun 0(false). Pada tahap selanjutnya, komputer kemudian akan melakukan pengambilan keputusan. Jika hasil evaluasi adalah 1(true), maka CPU akan mengeksekusi baris kode yang berada di dalam blok kurung kurawal {}. Namun sebaliknya, Jika hasil evaluasi adalah 0(false), maka CPU akan melakukan lompatan melewati seluruh blok kode tersebut dan langsung mengeksekusi instruksi berikutnya yang terletak setelah tanda tutup kurung kurawal 

Berikut adalah sintaks utama instruksi if :
```c++
if (kondisi) {
  Intruksi //Instruksi akan dieksekusi jika kondisi bernilai 1(true)
}
```
Sebagai contoh, perhatikan program sederhana berikut :
```bash
nano if.cpp
```
```c++
#include <iostream>
using namespace std;

int main(){
  int angka = 10;
  bool kondisi = (angka>5); //variabel kondisi memiliki bernilai benar

  if(kondisi){
    cout <<"Baris ini akan ditampilkan ke layar" << endl;
  }

  kondisi = (angka>15); //sengaja dirubah agar variabel kondisi bernilai 0(false)
  if(kondisi){
    cout<<"Baris ini tidak akan ditampilkan ke layar"<<endl;
  }
  return 0;
}
```
```bash
g++ if.cpp -o if
```
```bash
./if
Baris ini akan ditampilkan ke layar
```
Dari output program diatas, kita telah membuktikan bahwa if dapat bekerja berdasarkan variabel boolean yang dihasilkan dari operator relasional. Pada blok pertama, kondisi (10 > 5) menghasilkan nilai 1 true), sehingga CPU masuk ke dalam blok kurung kurawal dan mencetak pesan yang ada didalamnya ke layar pengguna. Namun, pada blok kedua, nilai variabel kondisi diubah menjadi (10 > 15) sehingga menghasilkan 0(false). Akibatnya, CPU melakukan lompatan untuk melewati instruksi cetak yang ada didlamnya dan langsung menuju akhir dari program.

Namun, bagaimana jika kita memasukkan nilai biner(0 atau 1) secara langsung ke dalam parameter if. Mari kita coba :
```bash
nano if.cpp
```
```c++
#include <iostream>
using namespace std;

int main(){
  if(1){
    cout <<"Baris ini akan ditampilkan ke layar" << endl;
  }

  if(0){
    cout<<"Baris ini tidak akan ditampilkan ke layar"<<endl;
  }
  return 0;
}
```
```bash
g++ if.cpp -o if
```
```bash
./if
Baris ini akan ditampilkan ke layar
```
Dapat terlihat bahwa program memperlakukan angka 1 dan 0 yang kita tulis secara langsung sebagai nilai booelan yang valid. Hal ini mengartikan bahwa instruksi if tidak selalu membutuhkan variabel kompleks(seperti pada percobaan sebelumnya) untuk melakukan proses scan dan pengambilan keputusan, selama ada nilai biner di dalam parameternya, if akan tetap berfungsi secara akurat.

Menariknya, nilai di dalam parameter if juga tetap dapat dieksekusi walaupun isinya adalah hasil dari kalkulasi aritmatika. Untuk membuktikannya, mari kita bereksperimen dengan memasukkan operasi pengurangan ke dalam parameter if dan melihat bagaimana hasil kalkulasi tersebut diterjemahkan menjadi status boolean :
```bash
nano if.cpp
```
```c++
#include <iostream>
using namespace std;

int main(){
  if(6-5){
    cout <<"Baris ini akan ditampilkan ke layar" << endl;
  }

  if(6-6){
    cout<<"Baris ini tidak akan ditampilkan ke layar"<<endl;
  }
  return 0;
}
```
```bash
g++ if.cpp -o if
```
```bash
./if
Baris ini akan ditampilkan ke layar
```
Lihat! komputer tetap memperlakukan hasil dari operasi aritmatika kita sebagai nilai boolean yang valid. Hal ini menegaskan kita bahwa if mampu memproses ekspresi apa pun didalam parameternya asalkan hasil akhirnya dapat dikonversi ke status boolean.

Selain itu, ada satu hal lagi yang menarik dari intstruksi if ini, yakni perilakunya terhadap angka-angka yang berada di luar domain biner (0 dan 1). Coba perhatikan output program ini :
```bash
nano if.cpp
```
```c++
#include <iostream>
using namespace std;

int main(){
#include <iostream>
using namespace std;

int main(){
  if(389){
    cout <<"Angka 389 akan terdeteksi sebagai true" << endl;
  }

  if(-7){
    cout<<"Angka -7 juga terdeteksi sebagai true (Karena bukan 0)"<<endl;
  }
  return 0;
}
```
```bash
g++ if.cpp -o if
```
```bash
./if
Angka 389 akan terdeteksi sebagai true
Angka -7 juga terdeteksi sebagai true (Karena bukan 0)
```
Terlihat bahwa ketika kita memasukkan sembarang bilangan bulat, baik itu bilangan bulat positif seperti 389 maupun bilangan bulat negatif seperti -7, maka CPU secara otomatis akan mengkonversi nilai tersebut menjadi 1(true) dan mengizinkan eksekusi blok kode di dalamnya. Mekanisme konversi ini berakar dari pembuatan CPU yang sengaja diprogram dengan aturan bahwa 0 adalah satu-satunya nilai angka yang dianggap salah (false), sehingga secara otomatis, semua angka lainnya selain angka 0 akan dianggap benar (true)

---

## `else` ( JALUR ALTERNATIF )
`else` adalah kata kunci kondisional yang digunakan bersama instruksi if untuk mengeksekusi blok kode tertentu jika dan hanya jika kondisi if sebelumnya tidak terpenuhi (false). kata kunci ini bertindak sebagai pilihan terakhir dalam percabangan untuk memastikan program tetap memiliki tindakan alternatif jika kondisi utama tidak bernilai benar. Penting untuk dicatat bahwa else tidak memiliki parameternya sendiri karena ia hanyalah penampung dari segala kondisi yang telah ditolak oleh if.

Sebagai contoh, mari kita buat program sederhana dengan menggunakan kata kunci else seperti ini :
```bash
nano else.cpp
```
```c++
#include <iostream>
using namespace std;

int main(){
  int nilai=60;
  int kkm=75;

  if(nilai>=kkm){
    cout<<"Lulus"<<endl;
  } else{
    cout<<"Tidak Lulus"<<endl;
  }
  return 0;
}
```
Program ini berfungsi sebagai sistem sederhana untuk menentukan apakah skor dari seorang siswa berada pada KKM dan dinyatakan lulus. Secara teknis, program memeriksa apakah isi variabel nilai mencapai atau melampaui angka dalam variabel kkm melalui operator perbandingan >=. Jika kondisi tersebut terpenuhi (bernilai true), program akan mencetak kata "Lulus", namun jika nilai tersebut lebih rendah (bernilai false), alur eksekusi akan dialihkan ke blok else untuk menampilkan pesan 
"Tidak Lulus".

Selanjutnya, saya akan melakukan kompilasi dan menjalankan program tersebut :
```bash
g++ else.cpp -o else
```
```bash
./else
Tidak lulus
```
Dapat kita amati bahwa program tidak lagi diam saat syarat utama gagal terpenuhi. Setelah komputer melakukan komparasi antara variabel nilai dan variabel kkm dan kemudian mendapati bahwa 60 tidak lebih besar atau sama dengan 75, sehingga parameter if menghasilkan nilai 0(false), komputer secara otomatis mengabaikan blok kode pertama yang ada pada badan if tersebut, dan langsung melompat ke blok else untuk mengeksekusi instruksi yang ada didalamnya yakni "Tidak Lulus".

---

## `else if` ( MULTIKONDISI BERTAHAP )
`else if` adalah pernyataan kondisional dalam pemrograman yang digunakan untuk mengevaluasi beberapa kondisi secara berurutan setelah kondisi if pertama bernilai salah (false). Berbeda dengan `else` yang berfungsi sebagai pilihan terakhir tanpa syarat yang hanya dieksekusi jika semua kondisi sebelumnya salah. else if memungkinkan kita untuk menyisipkan kriteria spesifik tambahan di tengah struktur logika sebelum mencapai instruksi terakhir. Perlu dipahami bahwa `else if` hanya akan dievaluasi jika kondisi if di atasnya bernilai 0(false), dan jika `else` if tersebut bernilai 1(true), maka blok kodenya dieksekusi dan seluruh sisa percabangan di bawahnya akan diabaikan oleh CPU.

Mari kita implementasikan konsep ini pada sistem grading nilai ujian sederhana :
```Bash
nano elseif.cpp
```
```C++
#include <iostream>
using namespace std;

int main(){
    int skor = 85;
    cout << "Skor Ujian: " << skor << endl;

    if (skor >= 90) {
        cout << "Grade: A (Sangat Baik)" << endl;
    } else if (skor >= 80) {
        cout << "Grade: B (Baik)" << endl;
    } else if (skor >= 70) {
        cout << "Grade: C (Cukup)" << endl;
    } else {
        cout << "Grade: D (Perlu Perbaikan)" << endl;
    }
    return 0;
}
```
```Bash
g++ elseif.cpp -o elseif
```
```Bah
./elseif
Skor Ujian: 85
Grade: B (Baik)
```
Dapat kita amati bahwa program melakukan pengecekan secara hierarki. Mula-mula, CPU memeriksa kondisi 85 >= 90 yang kemudian menghasilkan nilai 0(false). Karena gagal, CPU turun ke kondisi berikutnya yakni 85 >= 80 yang kemudian menghasilkan nilai 1(true). Begitu kondisi ini terpenuhi, pesan "Grade: B" langsung dicetak ke layar, dan CPU langsung melompat keluar dari seluruh struktur percabangan tanpa perlu memeriksa kondisi skor >= 70 atau blok else yang ada dibawahnya.



