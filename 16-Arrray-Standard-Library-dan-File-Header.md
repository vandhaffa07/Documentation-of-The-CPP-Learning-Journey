## ARRAY STANDARD LIBRARY DAN FILE HEADER
Pada file sebelumnya, kita telah mempelajari karakteristik dan mekanisme yang terjadi di dalam array tradisional C++. Namun sebenarnya, array tradisional ini masih memiliki banyak kekurangan, seperti tidak tahu ukurannya sendiri, tidak memiliki sistem proteksi terhadap kebocoran memori (Buffer Overflow), dan kekurangan-kekurangan lainnya tetutama pada kemampuannya untuk melakukan manipulasi elemen.

Untuk mengatasi kelemahan-kelemahan tersebut tanpa mengorbankan performa kecepatan low-level dari array tradisional, C++ modern memperkenalkan pembungkus pintar bernama `std::array`. `std::array` adalah kontainer berukuran tetap yang disediakan oleh Standard Template Library (STL) C++ sebagai pembungkus di sekitar array tradisional sambil menyediakan fungsionalitas tambahan. Dengan `std::array`, kita bisa mendapatkan performa kecepatan yang sama persis dengan array tradisional, namun dipersenjatai dengan fitur-fitur canggih seperti pengecekan batas memori, pencarian ukuran otomatis, dan iterator. 

**Catatan : Untuk saat ini, kita dapat menghiraukan istilah-istilah rumit seperti STL, Kontainer, dan Sejenisnya. Karena kita akan mempelajari hal tersebut pada file yang akan datang**

## SINTAKS DAN PENGGUNAAN DASAR STD ARRAY
Untuk menggunakannya, kita wajib mengimport library-nya terlebih dahulu di bagian atas program seperti ini :
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
```bash
nano size.cpp
```
```cpp
#include <iostream>
#include <array>
using namespace std;

int main(){
  array <char, 4> huruf = {'A', 'B', 'C', 'D'};
  cout << "Banyaknya Elemen : " << huruf.size() << endl;
  return 0;
}
```
```bash
g++ size.cpp -o size
```
```bash
./size
```
```bash
Banyaknya Elemen : 4
```
Karena sifatnya yang demikian pula, perintah ini akan tetap mengambil informasi banyaknya elemen/ukuran pada angka yang dituliskan sebelum tanda "<". meskipun kita hanya menginisiasi beberapa elemen array saja :
```bash
nano size.cpp
```
```cpp
#include <iostream>
#include <array>
using namespace std;

int main(){
  array <char, 4> huruf = {'A', 'B', 'C'};
  cout << "Banyaknya Elemen : " << huruf.size() << endl;
  return 0;
}
```
```bash
g++ size.cpp -o size
```
```bash
./size
```
```bash
Banyaknya Elemen : 4
```

### AT()
`at()` adalah fitur keselamatan terpenting dalam perspektif seorang proffesional untuk menghadapi crash. Jika kita menggunakan kurung siku standar pada array tradisional (`array[indeks]`), CPU akan langsung melompat ke alamat memori tanpa peduli apakah indeks tersebut valid atau tidak, hal ini kemudian bisa memicu Buffer Overflow/Overread.

Ketika kita memanggil `.at(indeks)`, sistem  akan melakukan Bounds Checking di balik layar dengan logika sebagai berikut :

$$Jika \space Indeks >= size(), \space Maka \space Lemparkan \space Interupsi \space Sistem!$$

Jika kita melanggar batas jangkauan array, C++ akan memicu exception bernama out of range dan menghentikan jalannya program seketika sebelum data ilegal di RAM sempat terbaca atau dirusak seperti ini :
```bash
nano at.cpp
```
```cpp
#include <iostream>
#include <array>
using namespace std;

int main() {
  array<int, 4> list_id = {10, 20, 30, 40};
  cout << "Indeks ke-6 : " << list_id.at(6) << endl; 
  return 0;
}
```
```bash
g++ at.cpp -o at
```
```bash
./at
```
```bash
terminate called after throwing an instance of 'std::out_of_range'
what():  array::at: __n (which is 6) >= _Nm (which is 4)
Aborted (core dumped)
```

### FILL()
`.fill()` digunakan untuk mengisi atau mereset seluruh elemen dengan nilai yang seragam. Secara teknis, ia akan menyapu bersih seluruh alamat memori dari elemen pertama hingga terakhir dan mengisinya dengan data baru yang kita tentukan dengan sangat cepat.

Berikut adalah contoh penggunaan `.fill()` :
```bash
nano fill.cpp
```
```cpp
#include <iostream>
#include <array>
using namespace std;

int main(){
  array<int, 3> nilai = {98, 100, 87};
  
  for (int i = 0; i < nilai.size(); i++){
    cout << "Indeks ke- " << i << " : " << nilai.at(i) << endl;
  }
  cout << endl;
  
  nilai.fill(75);
  for (int i = 0; i < nilai.size(); i++){
    cout << "Indeks ke- " << i << " : " << nilai.at(i) << endl;
  }
  return 0;
}
```
```bash
g++ fill.cpp -o fill
```
```bash
./fill
```
```bash
Indeks ke-0 : 98
Indeks ke-1 : 100
Indeks ke-2 : 87

Indeks ke-0 : 75
Indeks ke-1 : 75
Indeks ke-2 : 75
```

### FRONT() DAN BACK()
Di dalam memori RAM, elemen pertama selalu berada di Alamat Dasar (Base Address), sedangkan elemen terakhir berada di koordinat batas akhir alokasi array. `.front()` dan `.back()` sendiri merupakan fitur yang berhubungan dengan hal tersebut.

`.front()` bekerja dengan cara mengembalikan referensi data langsung pada elemen pertama (indeks 0). Sedangkan `.back()` bekerja dengan cara menghitung posisi elemen terakhir berbasis data size() - 1 lalu mengembalikan referensinya.

Fitur ini membuat kode kita menjadi sangat ekspresif tanpa perlu menulis indeks manual seperti `array[0]` atau `array[array.size() - 1]`

Berikut adalah contoh penggunaannya:
```bash
nano front_back.cpp
```
```cpp
#include <iostream>
#include <array>
using namespace std;

int main(){
  array <string, 3> nama = {"andi", "budi", "cindy"};
  cout << "Elemen pertama : " << nama.front() << endl;
  cout << "Elemen terakhir : " << nama.back() << endl;
  return 0;
}
```
```bash
g++ front_back.cpp -o front_back
```
```bash
./front_back
```
```bash
Elemen pertama : andi
Elemen terakhir: cindy
```

### SWAP()
Fungsi `.swap()` digunakan untuk menukar seluruh isi data antara dua buah std::array. Syarat mutlaknya adalah kedua array tersebut harus memiliki tipe data dan ukuran kapasitas yang sama persis.

Berikutadalah contoh penggunaannya :
```bash
nano swap.cpp
```
```cpp
#include <iostream>
#include <array>
using namespace std;

int main(){
  array<char, 3> huruf1 = {'A', 'B', 'C'};
  array<char, 3> huruf2 = {'D', 'E', 'F'};
  cout << "huruf1 : ";
  for (int i = 0; i < huruf1.size(); i++){
    cout << huruf1.at(i) << "  ";
  }
  cout << "huruf2 : ";
  for (int i = 0; i < huruf2.size(); i++){
    cout << huruf2.at(i) << "  ";
  }
  
  cout << endl << endl;
  
  huruf1.swap(huruf2);
  cout << "huruf1 : ";
  for (int i = 0; i < huruf1.size(); i++){
    cout  << huruf1.at(i) << "  ";
  }
  cout << "huruf2 : ";
  for (int i = 0; i < huruf2.size(); i++){
    cout << huruf2.at(i) << "  ";
  }
  return 0;
}
```
```bash
g++ swap.cpp -o swap
```
```bash
./swap
```
```bash
huruf1 : A  B  C  huruf2 : D  E  F

huruf1 : D  E  F  huruf1 : A  B  C
```

### EMPTY()
`.empty()` merupakan fitur yang bertindak sebagai detektor untuk memeriksa apakah suatu array memiliki kapasitas elemen tau tidak. Perlu digarisbawahi secara ketat bahwa dikarenakan std array bersifat statis (ukurannya dikunci sejak awal kompilasi), fungsi `.empty()` hanya akan menghasilkan nilai true jika dan hanya jika kita mendeklarasikan array dengan ukuran 0. Jika kita mendeklarasikan array dengan ukuran/banyak elemen yang lebih besar dari 0 tetapi belum mengisi angka apa pun di dalamnya, `.empty()` akan tetap menghasilkan nilai false karena slot fisiknya sudah teralokasi di RAM.

Berikut adalah contoh penggunaannya :
```bash
nano empty.cpp
```
```cpp
#include <iostream>
#include <array>
using namespace std;

int main(){
  array<int, 4> array_biasa = {};
  array<int, 0> array_kosong;

  cout << "Apakah array_biasa kosong? : " << array_biasa.empty() << endl;
  cout << "Apakah array_kosong kosong? : " << array_kosong.empty() << endl;
  return 0;
}
```
```bash
g++ empty.cpp -o empty
```
```bash
./empty
```
```bash
Apakah array_biasa kosong? : 0
Apakah array_biasa kosong? : 1
```
### BEGIN() DAN END()
`.begin()` digunakan untuk mengembalikan pointer yang menunjuk tepat pada elemen pertama (indeks 0), sedangkan `.end()` digunakan untuk mengembalikan pointer yang menunjuk tepat pada slot memori setelah elemen terakhir (sebagai penanda batas stop/gerbang keluar).

Berikut adalah contoh penggunaanya :
```bash
begin_end.cpp
```
```cpp
#include <iostream>
#include <array>
using namespace std;

int main() {
  array<int, 3> data = {10, 20, 30};
  cout << ".begin() = " << data.begin() << endl;
  cout << ".end() = " << data.end() << endl;
  return 0;
}
```
```bash
g++ begin_end.cpp -o begin_end
```
```bash
./begin_end
```
```bash
.begin() = 0x7ffd3fa18704
.end() = 0x7ffd3fa18710
```

### DATA()
Pada array tradisional, ketika kita mengeluarkan nilai dari nama array tersebut menggunakan `cout`, maka keluarannya adalah alamat dasar dari array tersebut (indeks 0). Fungsi data sendiri digunakan untuk mengeluarkan alamat dasar dari array tanpa menggunakan `nama_array.at(0)`. Karena, ketika menggunakan std array dan ingin mengelurakan output alamat dasar dengan hanya memanggil namanya, maka compiler akan menampilkan error.

Berikut adalah contoh penggunaannya :
```bash
nano data.cpp
```
```cpp
#include <iostream>
#include <array>
using namespace std;

int main() {
  array<int, 3> data = {10, 20, 30};
  cout << "Alamat dasar via .data() : " << data.data() << endl << endl;
  for(int i = 0; i < data.size(); i++){
    cout << "Alamat indeks ke-" << i << " : " << &data.at(i) << endl;
  }
  return 0;
}
```
```bash
g++ data.cpp -o data
```
```bash
./data
```
```bash
Alamat dasar via .data() : 0x7ffe156c8710

Alamat indeks ke-0 : 0x7ffe156c8710
Alamat indeks ke-1 : 0x7ffe156c8714
Alamat indeks ke-2 : 0x7ffe156c8718
```









