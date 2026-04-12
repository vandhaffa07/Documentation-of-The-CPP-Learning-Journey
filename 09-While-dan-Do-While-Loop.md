# WHILE & DO-WHILE LOOP
Dalam pemrograman iterasi (looping) adalah konsep dasar yang merujuk pada pengulangan satu atau serangkaian instruksi kode secara berulang-ulang sampai suatu kondisi tertentu terpenuhi. Konsep ini bertujuan untuk mengotomatisasi tugas repetitif, meningkatkan efisiensi, dan mengurangi penulisan kode yang sama berkali-kali. Tanpa adanya struktur iterasi, sebuah program akan bersifat statis dan terbatas pada eksekusi linier yang kaku. Namun, dengan memanfaatkan looping, pengembang dapat menangani pemrosesan data bervolume besar serta mengelola alur logika yang dinamis hanya dengan beberapa baris kode. Dalam bahasa pemrograman C++, struktur iterasi ini diimplementasikan melalui beberapa cara, di antaranya adalah loop while dan do-while

---

## WHILE LOOP
while loop adalah struktur kontrol perulangan yang mengeksekusi blok kode selama kondisi di dalam parameternya bernilai benar (true). Dalam prosesnya, CPU akan melakukan evaluasi terhadap parameter biner di awal sebelum mengizinkan blok kode di dalamnya dieksekusi. Jika sejak awal kondisi parameter bernilai 0 (false), maka CPU akan melakukan lompatan melewati seluruh blok kode tersebut.

Berikut adalah sintaks dasar instruksi while:
```c++
while (kondisi) {
  Instruksi // Instruksi dieksekusi selama kondisi bernilai 1 (true)
}
```
Mari kita implementasikan sintaks tersebut ke dalam program sederhana hitung mundur seperti ini :
```bash
nano while_test.cpp
```
```c++
#include <iostream>
using namespace std;

int main(){
  int angka = 5;
    while (angka>0){
        cout << "Detik ke-" << angka << endl;
        angka--;
    }
  return 0;
}
```
```bash
g++ while_test.cpp -o while_test
```
```bash
./while_test
Detik ke-5
Detik ke-4
Detik ke-3
Detik ke-2
Detik ke-1
```
Dapat terlihat bahwa program tersebut bekerja dengan melakukan evaluasi logis secara bertahap pada setiap siklusnya. Ketika program pertama kali dijalankan, variabel angka yang bernilai 5 diperiksa terhadap parameter angka > 0, dan karena kondisi terpenuhi, maka CPU pun mengeksekusi perintah cetak dan dilanjutkan dengan instruksi angka-- yang mendekrementasi nilainya menjadi 4. Proses ini berulang secara otomatis, di mana pada iterasi berikutnya nilai 4 tetap memenuhi syarat 4 > 0 sehingga teks kembali dicetak dan nilai berkurang menjadi 3, begitu pula seterusnya hingga nilai mencapai 1. Perubahan krusial terjadi saat nilai 1 dikurangi satu kali lagi menjadi 0 melalui operasi angka--, sehingga ketika CPU kembali ke atas untuk melakukan evaluasi, kondisi 0 > 0 bernilai salah (false). Pada titik inilah CPU melakukan lompatan instruksi keluar dari blok perulangan dan melanjutkan eksekusi ke baris return 0, yang menandakan berakhirnya seluruh rangkaian proses iterasi tersebut.

Hal ini menegaskan bahwa kontrol pada while sepenuhnya bergantung pada perubahan nilai di dalam bloknya. Jika kita melakukan kecerobohan dengan menghapus instruksi dekrementasi angka--, maka nilai angka akan selalu 5. Akibatnya, kondisi 5 > 0 akan selalu bernilai 1 (true) dan CPU akan terjebak dalam Infinite Loop. Dalam kondisi ini, terminal kita akan dibanjiri teks tanpa henti.
```bash
nano while_test.cpp
```
```c++
#include <iostream>
using namespace std;

int main(){
  int angka = 5;
    while (angka>0){
        cout << "Detik ke-" << angka << endl;
    }
  return 0;
}
```
```bash
g++ while_test.cpp -o while_test
```
```bash
./while_test
Detik ke-5
Detik ke-5
Detik ke-5
Detik ke-5
Detik ke-5
Detik ke-5
Detik ke-5
Detik ke-5
..........
^C
```

---

## DO-WHILE LOOP
do-while loop adalah struktur perulangan yang menjamin kode di dalam blok do dieksekusi terlebih dahulu minimal satu kali, tidak peduli apakah kondisinya benar atau salah. Baru setelah satu putaran pertama selesai, CPU akan mengevaluasi parameter biner di akhir blok. Perulangan ini kemudian akan terus berjalan selama kondisi parameter bernilai true, dan berhenti saat bernilai false. 

Berikut adalah sintaks dasar instruksi do-while:
```c++
do {
  Instruksi // Instruksi dijalankan minimal satu kali
} while (kondisi);
```
Mari kita implementasikan sintaks tersebut ke dalam program sederhana hitung mundur seperti ini :
```bash
nano do-while_test.cpp
```
```c++
#include <iostream>
using namespace std;

int main(){
  int opsi = 0;

  do {
    cout << "=== MENU SISTEM ===\n1. Loop\n0. Exit\nPilih: ";
    cin >> opsi;
  } while (opsi != 0);

  return 0;
}
```
```bash
g++ do-while_test.cpp -o do-while_test
```
```bash
./do-while_test
=== MENU SISTEM ===
1. Loop
0. Exit
Pilih: 1
=== MENU SISTEM ===
1. Loop
0. Exit
Pilih: 1
=== MENU SISTEM ===
1. Loop
0. Exit
Pilih: 0
```
Dapat terlihat bahwa program di atas memanfaatkan sifat post-condition dari do-while untuk menyajikan antarmuka menu sederhana kepada pengguna secara langsung. Ketika program dieksekusi, CPU tidak melakukan pengecekan variabel opsi terlebih dahulu, melainkan langsung masuk ke dalam blok do untuk mencetak teks menu dan menunggu input melalui perintah cin >> opsi. Alur logika teknisnya adalah ketika pengguna memasukkan angka 1, CPU akan sampai pada baris while (opsi != 0) dan melakukan evaluasi apakah 1 != 0. Karena pernyataan tersebut bernilai benar (true), CPU melakukan lompatan kembali ke atas untuk mengulang seluruh instruksi di dalam blok do. Proses pengulangan ini akan terus terjadi selama input yang diberikan bukan angka 0. Begitu pengguna memasukkan angka 0, evaluasi pada parameter di akhir blok akan menghasilkan nilai salah (false) karena 0 != 0 adalah pernyataan yang keliru, sehingga CPU menghentikan iterasi dan melanjutkan ke instruksi berikutnya di luar struktur loop.

Karakteristik ini membuat do-while menjadi banyak digemari oleh pengembang untuk pembuatan menu interaktif. Namun, ia juga menyimpan risiko logika yang berbeda. Jika pada while kita bisa menghindari error dengan menutup gerbang logika di awal, pada do-while kita tidak bisa menghindar. Meskipun kita memasukkan kondisi yang salah secara absolut seperti while(false), pesan di dalam blok do akan tetap muncul satu kali ke layar sebelum CPU menyadari kesalahannya dan keluar dari loop.

