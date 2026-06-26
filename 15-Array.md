## ARRAY
Secara definisi, Array adalah kumpulan dari variabel-variabel bertipe data sama yang disimpan pada slot memori dengan lokasi/alamat yang berurutan tanpa terputus (Contiguous Memory Allocation). Setiap elemen yang ada didalam array dapat diakses melalui indeks angka yang dimulai dari nol (0). Fitur ini sangatlah efisien untuk menyimpan banyak nilai sekaligus dalam satu nama variabel. 

Untuk melakukan deklarasi/inisialisai variabel dengan tipe data array, kita dapat menuliskan perintah sebagai berikut :
```cpp
\\DEKLARASI
tipe_data nama_array[banyak_elemen];

\\INISIALISASI
\\Cara 1 : tipe_data nama_array[banyak_elemen] = {elemen1, elemen2, ...--, elemen_ke-N}; //(dengan N adalah total banyaknya elemen)
\\Cara 2 : tipe_data nama_array[] = {elemen1, elemen2, ...--, elemen_ke-N}; //(dengan N adalah total banyaknya elemen)
```
Berikut adalah contoh penggunaannya :
```bash
nano test_array.cpp
```
```cpp
#include <iostream>
using namespace std;

int main(){
  int array_angka[5] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++){
    cout << "Array indeks ke-" << i << " : " << array_angka[i] << endl;
  }
  return 0;
}
```
```bash
g++ test_array.cpp -o test_array
```
```bash
./test_array
```
```bash
Array indeks ke-0 = 1
Array indeks ke-1 = 2
Array indeks ke-2 = 3
Array indeks ke-3 = 4
Array indeks ke-4 = 5
```
Terlihat bahwa indeks pada array selalu dimulai dari 0 bukan 1. Hal ini mungkin akan terasa membingungkan dan terkesan rumit bagi orang-orang yang baru mulai belajar. Namun, secara arsitektur komputer, indeks pada array memang bukanlah nomor urut elemen, melainkan nilai Offset (jarak lompatan) dari alamat memori dasar (base address) milik elemen pertama. Kita akan membahas hal tersebut sebentar lagi!



