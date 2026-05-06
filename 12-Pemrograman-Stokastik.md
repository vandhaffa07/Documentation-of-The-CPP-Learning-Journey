# PEMROGRAMAN STOKASTIK
Pada dasarnya, komputer (CPU) adalah mesin logika yang kaku, dimana komponen-komponennya bekerja sesuai dengan tugasnya masing-masing dengan keteraturan yang sangat presisi. Ia memang diprogram untuk mengerjakan tugas-tugas kompleks yang hampir tidak mungkin untuk dikerjakan oleh manusia, ataupun bisa dikerjakan oleh manusai tetapi membutuhkan waktu yang sangat lama dan tenaga yang sangat besar. Lantas pertanyaannya, apakah kita bisa menghasilkan sesuatu yang acak (random) dari mesin yang sangat teratur ini?

Jawabannya bisa.... Tetapi hanya terlihat acak, bukan benar-benar acak. Hal ini dikarenakan mekanisme komputer (CPU) yang hanya bekerja sesuai dengan program/instruksi yang telah dibuatkan untuknya. Program/instruksi ini, sangat erat kaitannya dengan algoritma, serangkaian langkah logis, terurut, dan sistematis yang disusun untuk menyelesaikan masalah atau mencapai tujuan tertentu. Algoritma lah jantung sebenarnya dari proses-proses kompleks yang dapat dilakukan oleh komputer (CPU).

Untuk menghasilkan sesuatu yang acak sebenarnya juga membutuhkan algoritma, ambil contoh angka acak. Untuk menghasilkannya, dibutuhkan algoritma matematis bernama Pseudo Random Number Generator (PRNG). Ini berarti, angka yang sebenarnya dihasilkan tidak benar-benar acak secara fisik, melainkan hasil kalkulasi matematika yang sangat kompleks sehingga terlihat acak bagi manusia. Asalkan kita mengetahui persamaan matematis yang digunakan untuk algoritmanya, kita sebenarnya juga bisa menebak dan memprediksi angka yang akan dihasilkan berikutnya.

Pada file ini, kita akan membahas secara lengkap sebuah konsep pemrograman yang mengandung unsur keacakan (probabilistik) dan ketidakpastian atau yang biasa disebut sebagai pemrograman stokastik.

---

## FUNDAMENTAL LIBRARY 
Sebelum memahami lebih lanjut tentang pemrograman stokastik, kita perlu mengetahui bahwa terdapat dua library yang dapat mendukung, yakni cstdlib dan ctime. Kedua library ini dinilai ideal karena mengandung fungsi-fungsi yang memiliki unsur keacakan dan ketidakpastian.

### 1. cstdlib
cstdlib merupakan library dari bahasa pemrograman C yang diturunkan kepada bahasa pemrograman C++. Library ini merupakan utilitas umum serbaguna yang berisi fungs-fungsi untuk melakukan manajemen memori, kontrol alur program (seperti exit()), serta menyediakan algoritma-algoritma matematika kompleks termasuk PRNG yang terdapat pada fungsi rand() dan srand()

### 2. ctime
ctime merupakan Library yang digunakan untuk melakukan manipulasi pada tanggal dan waktu. 
Library ini menyediakan akses ke hardware clock pada sistem. Fungsi utamanya adalah menangkap nilai Unix Epoch Time, yaitu total akumulasi detik yang telah berlalu sejak 1 Januari 1970. Karena detik terus berjalan dan tidak pernah terulang, nilai ini merupakan sumber Entropi (ketidakpastian) yang ideal untuk digunakan sebagai benih perulangan.

---

### MEKANISME DETERMENISTIK PADA rand()
rand() merupakan salah satu fungsi yang terdapat pada library cstdlib dan digunakan untuk menghasilkan bilangan bulat pseudo-acak antara 0 hingga RAND_MAX. Fungsi ini sebenarnya menjalankan sebuah persamaan matematika rekursif di balik layar, yang biasanya menggunakan mekanisme LCG (Linear Congruential Generator) dengan rumus seperti ini :

$$
X_{n+1} = (a \cdot X_n + c) \ mod \ m
$$

Keterangan:
- $X_n$ : nilai ke- $n$ (state saat ini)
- $a$ : multiplier (pengali)
- $c$ : increment (penambah)
- $m$ : modulus (batas maksimum)

Jadi, ketika kita menggunakan rand() pada program c++ kita, kita dapat membayangkan bahwa yang sebenarnya terjadi adalah compiler seolah-olah mengambil fungsi bernama rand() dari variabel global yang berisi :
```c++
int rand() {
state = (a * state + c) % m;
return state;
}
```
Perlu diketahui bahwa nilai state awal ($X_{0}$), multiplier ($a$), increment ($c$), dan modulus ($m$) telah ditetapkan sejak awal oleh standard bahasa pemrograman C++. Ketika kita menjalankan fungsi rand(), angka random yang sebenarnya ditampilkan adalah nilai dari $X_{1}$. Itulah sebabnya ketika kita memiliki program seperti ini :
```bash
nano rand.cpp
```
```c++
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  cout << rand() << endl;
}
```
kemudian kita compile dan jalankan berulang kali :
```bash
g++ rand.cpp -o rand
```
```bash
./rand
1804289383
```
```bash
./rand
1804289383
```
```bash
./rand
1804289383
```
Maka, nilai yang dihasilkan oleh program tersebut akan selalu sama, hal ini dikarenakan sistem yang secara otomatis melakukan inisialisasi ulang nilai state saat ini menjadi nilai state awal standard pemrograman c++ saat program dimulai.

---

## srand() DAN time(0) SEBAGAI SUMBER ENTROPI
berbeda dengan rand() yang secara otomatis menetapkan nilai state awal ($X_0$) dari standard bahasa pemrograman C++, srand() justru digunakan untuk memanipulasi dan menetapkan nilai state awal ($X_0$) ke dalam algoritma LCG sesuka hati kita. Perlu diketahui bahwa srand() tidak mengembalikan nilai apapun, ia hanyalah pengubah angka state awal yang terdapat pada sistem C++. Ini berarti, ketika kita ingin mengetahui dan menampilkan hasil nilai LCG yang state awalnya telah kita rubah, kita wajib menggabungkannya dengan fungsi rand() seperti ini :
```bash
nano srand.cpp
```
```c++
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  srand(9);
  cout << rand() << endl;
}
```
```bash
g++ srand.cpp -o srand
```
```bash
./srand
444454915
```
Penting untuk dipahami pula bahwa parameter didalam srand wajib diisi dengan sesuatu yang bertipe data integer. Jika tidak, maka compiler akan menampilkan error.

Meskipun begitu, srand() tetap saja tidak bisa menghancurkan tembok deterministik yang ada, ia hanya mengubah nilai state awal. Hal ini membuat program tetap selalu menghasilkan urutan angka yang pasti sama setiap kali dijalankan seperti pada kasus rand() sebelumnya : 
```bash
./srand
444454915
```
```bash
./srand
444454915
```
```bash
./srand
444454915
```
Untuk membuatnya menghasilkan sesuatu yang selalu berubah setiap kali run, kita butuh sesuatu yang selalu berubah-ubah pula sebagai parameter dari fungsi srand() tersebut.



















