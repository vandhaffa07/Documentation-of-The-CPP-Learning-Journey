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

## ANATOMI ALOKASI ARRAY DI DALAM RAM
Ketika kita menulis instruksi `int angka[5] = {1, 2, 3, 4, 5};` pada program sebelumnya, CPU tidak hanya memesan 4 tempat acak di RAM. CPU akan mencari blok memori yang benar-benar kosong sebesar $5 \times 4 \text{ byte} = 20 \text{ byte}$ secara berurutan seperti ini: 
```bash
nano test_array.cpp
```
```cpp
#include <iostream>
using namespace std;

int main(){
  int array_angka[5] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++){
    cout << "Alamat Array indeks ke-" << i << " : " << &array_angka[i] << endl;
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
Alamat Array indeks ke-0 = 0x7ffcc90ae4c0
Alamat Array indeks ke-1 = 0x7ffcc90ae4c4
Alamat Array indeks ke-2 = 0x7ffcc90ae4c8
Alamat Array indeks ke-3 = 0x7ffcc90ae4cc
Alamat Array indeks ke-4 = 0x7ffcc90ae4d0
```
Perhatikan 2 karakter terakhirnya saja! Terlihat bahwa elemen pertama array (indeks 0) menempati alamat c0, maka elemen kedua (indeks 1) pasti menempati alamat c4 (bergeser 4 byte karena bertipe int), 
elemen ketiga (indeks 2) berada di c8, dan begitu seterusnya. inilah yang sebenarnya yang dimaksud dengan alamat berurutan.

Karakteristik ini juga lah yang menjadi alasan mengapa indeks array selalu dimulai dari 0. Dimana, ketika kita menuliskan `array_angka[indeks]`, rumus internal yang dieksekusi oleh CPU untuk mencari alamat memori elemen tersebut adalah :

$$Alamay \space Elemen = Alamat \space Dasar + (\space indeks \times sizeof(Tipe Data) \space )$$

Alamat Dasar Sendiri adalah alamat memori dari elemen pertama (indeks 0) pada sebuah array. Pada indeks ke-0 Lompatan yang dilakukan adalah $0 \times 4 \text{ byte} = 0 \text{ byte}$. Artinya, CPU langsung membaca tepat di alamat dasar array itu sendiri tanpa bergeser sama sekali. Itulah mengapa elemen pertama wajib berada di indeks 0. Sedangkan pada indeks ke-1, lompatannya adalah $1 \times 4 \text{ byte} = 4 \text{ byte}$ sehingga CPU akan bergeser sejauh 4 byte dari alamat dasar untuk membaca elemen kedua, dan begitu seterusnya hingga indeks ke-4.

## HUBUNGAN ARRAY DENGAN POINTER
Nama dari sebuah Array sebenarnya adalah sebuah Pointer Konstan yang menyimpan alamat dasar Array (Alamat memori dari elemen pertamanya (indeks 0)) :
```bash
nano test_array.cpp
```
```cpp
#include <iostream>
using namespace std;

int main(){
  int array_angka[5] = {1, 2, 3, 4, 5};
  cout << "Alamat Dasar Array = " << array_angka << endl;
  for (int i = 0; i < 5; i++){
    cout << "Alamat Array indeks ke-" << i << " : " << &array_angka[i] << endl;
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
Alamat Dasar Array = 0x7ffcb9c64680
Alamat Array indeks ke-0 = 0x7ffcb9c64680
Alamat Array indeks ke-1 = 0x7ffcb9c64684
Alamat Array indeks ke-2 = 0x7ffcb9c64688
Alamat Array indeks ke-3 = 0x7ffcb9c6468c
Alamat Array indeks ke-4 = 0x7ffcb9c64690
```
Teelihat bahwa output kedua baris pertama pada program di atas mengeluarkan nilai Hexadecimal yang sama persis! Ini adalah bukti otentik bahwa nama variabel Array secara implisit bertindak sebagai pointer yang menunjuk langsung ke Alamat dasar atau koordinat awal dari elemen indeks ke-0.

Karena nama Array adalah Pointer, maka kita juga dapat melakukan operasi matematika pada pointer tersebut untuk mengubah dan memanipulasi elemen Array tanpa perlu menyentuh kurung siku sama sekali :
```bash
nano test_array.cpp
```
```cpp
#include <iostream>
using namespace std;

int main(){
  int array_angka[5] = {1, 2, 3, 4, 5};
  int *ptr = array_angka;
  cout << "Elemen 1 -> Alamat: " << ptr << " | Nilai (Dereference): " << *ptr << endl;
  cout << "Elemen 2 -> Alamat: " << (ptr + 1) << " | Nilai (Dereference): " << *(ptr + 1) << endl;
  cout << "Elemen 3 -> Alamat: " << (ptr + 2) << " | Nilai (Dereference): " << *(ptr + 2) << endl;
  cout << "Elemen 4 -> Alamat: " << (ptr + 3) << " | Nilai (Dereference): " << *(ptr + 3) << endl;
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
Elemen 1 -> Alamat: 0x7ffd51bb2a30 | Nilai (Dereference): 1
Elemen 2 -> Alamat: 0x7ffd51bb2a34 | Nilai (Dereference): 2
Elemen 3 -> Alamat: 0x7ffd51bb2a38 | Nilai (Dereference): 3
Elemen 4 -> Alamat: 0x7ffd51bb2a3c | Nilai (Dereference): 4
Elemen 5 -> Alamat: 0x7ffd51bb2a40 | Nilai (Dereference): 5
```
Pada program diatas, setelah kita menginisialisasikan pointer yang mengarah ke nama array, sebenarnya mengarah ke alamat dasar array. Sehingga, ketika kita melakukan operasi `ptr + 1`, CPU tidak menambahkan alamat yang berupa angka hexadecimal dengan nilai 1, melainkan menambahkan alamat tersebut dengan ukuran dari tipe data yang ditunjuk.



