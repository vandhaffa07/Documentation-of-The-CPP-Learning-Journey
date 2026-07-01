## ARRAY STANDARD LIBRARY DAN FILE HEADER
Pada file sebelumnya, kita telah mempelajari karakteristik dan mekanisme yang terjadi di dalam array tradisional C++. Namun sebenarnya, array tradisional ini masih memiliki banyak kekurangan, seperti tidak tahu ukurannya sendiri, tidak memiliki sistem proteksi terhadap kebocoran memori (Buffer Overflow), dan kekurangan-kekurangan lainnya tetutama pada kemampuannya untuk melakukan manipulasi elemen.

Untuk mengatasi kelemahan-kelemahan tersebut tanpa mengorbankan performa kecepatan low-level dari array tradisional, C++ modern memperkenalkan pembungkus pintar bernama `std::array`. 

`std::array` adalah kontainer berukuran tetap yang disediakan oleh Standard Template Library (STL) C++ sebagai pembungkus di sekitar array tradisional sambil menyediakan fungsionalitas tambahan. Dengan `std::array`, kita bisa mendapatkan performa kecepatan yang sama persis dengan array tradisional, namun dipersenjatai dengan fitur-fitur canggih seperti pengecekan batas memori, pencarian ukuran otomatis, dan iterator. 

**Catatan : Untuk saat ini, kita dapat menghiraukan STL, Kontainer, dan Sejenisnya. Kita akan mempelajari file yang akan datang**

## SINTAKS DAN PENGGUNAAN DASAR STD ARRAY
Untuk menggunakannya, kita wajib mengimpor library-nya terlebih di bagian atas program seperti ini :
```cpp
#include <array>
```
Sedangkan untuk melakukan deklarasi/inisialisasi, kita dapat menuliskan kode seperti ini :
```cpp
//DEKLARASI
array<tipe_data, jumlah_elemen> nama_array;

//INISIALISASI
array<tipe_data, jumlah_elemen> nama_array = {elemen_ke-1, elemen_ke-2, ...... elemen_ke-n}
```
Berikut adalah contoh penggunaan std array :
```bash
nano std_array.cpp
```
```cpp
#include <iostream>
#include <array>
using namespace std;

int main(){
  array<int, 5> angka = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++){
    cout << "Indeks ke-" << i << " : " << angka[i] << endl;
  }
  return 0;
}
```
```bash
g++ std_array.cpp -o std_array
```
```bash
./std_array
```
```bash
Indeks ke-0 : 1
Indeks ke-1 : 2
Indeks ke-2 : 3
Indeks ke-3 : 4
Indeks ke-4 : 5
```
Terlihat bahwa std array memberikan output yang sama dengan saat kita menggunakan array tradisional di file sebelumnya. Hal ini juga menegaskan bahwa std array benar-benar hanyalah array tradisional yang dibungkus kedalam wadah yang memiliki fitur canggih.

## FITUR-FITUR CANGGIH STD ARRAY
### SIZE() 
Pada array tradisional, array tidak menyimpan informasi ukurannya sendiri sehingga kita harus menghitung manual menggunakan operator sizeof seperti ini :
```bash
nano sizeof_array.cpp
```
```cpp
#include <iostream>
using namespace std;

int main(){
  int array_nilai[3] = {100, 98, 90};
  int banyak_elemen = sizeof(array_nilai)/sizeof(int);
  cout << banyak_elemen << endl;
  return 0;
}
```
```bash
g++ sizeof_array.cpp -o sizeof_array
```
```bash
./sizeof_array
```
```bash
3
```
Namun, di dalam naungan `std::array`, informasi jumlah elemen disimpan oleh `.size()` sebagai nilai konstan internal sejak program pertama kali dikompilasi karena sifat dari ukuran `std::array` yang bersifat statis (tetap) dan tidak bisa membesar secara dinamis saat runtime. Berikut adalah contoh penggunaanya :

### AT()

### FILL()

### FRONT() DAN BACK()

### SWAP()

### EMPTY()

### BEGIN() DAN END()

### DATA()












