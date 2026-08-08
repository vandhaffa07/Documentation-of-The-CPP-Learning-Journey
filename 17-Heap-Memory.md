## STACK DAN HEAP MEMORY
Di dalam RAM komputer, sistem operasi membagi wilayah memori menjadi dua arsitektur utama untuk mengeksekusi program kita : 

- **STACK MEMORY :**
  
Stack memory adalah area memori khusus yang dikelola secara otomatis oleh compiler menggunakan prinsip Last-In, First-Out (LIFO) untuk menyimpan variabel lokal, parameter fungsi, dan alamat pengembalian saat fungsi dipanggil. Jadi, yang sebenarnya terjadi selama ini setiap kali kita mendeklarasikan atau menginisialisasikan variabel biasa seperti `int x = 10;`, `char huruf;`, atau `array<int, 5> data;`, kita sebenarnya menyerahkan manajemen lokasinya secara otomatis kepada CPU di dalam wilayah yang bernama Stack Memory ini.

Namun, Stack memiliki keterbatasan, seperti ukurannya yang kecil, sifatnya yang kaku, dan semua variabel di dalamnya akan dihancurkan otomatis begitu fungsi selesai berjalan (out of scope). Untuk membuat program berskala besar yang fleksibel dimana ukuran data baru ditentukan saat program berjalan (runtime), kita wajib bermigrasi ke wilayah memori yang lebih dinamis, yakni Heap Memory.

- **HEAP MEMORY :**

Heap memory adalah wilayah memori komputer yang dipakai untuk alokasi data secara dinamis saat program berjalan. Dengan menggunakan arsitektur ini, kita dapat mengatur bebas alokasi memori dari suatu variabel secara manual dan eksplisit (menggunakan operator `new` dan `delete` yang akan kita bahas). Heap lebih besar dan kurang terbatas dibandingkan dengan stack, sehingga cocok untuk mengelola objek dengan ukuran dinamis serta menyimpan data besar atau objek yang umurnya panjang. Namun, mengakses memori heap melibatkan dereferensi pointer yang relatif lebih lambat dibandingkan dengan memori stack.

---

## PENGGUNAAN OPERATOR `new` dan `delete` PADA HEAP MEMORY
Untuk memesan memori di Heap, C++ menyediakan operator khusus bernama `new`. Perintah ini digunakan untuk mengalokasikan memori secara dinamis pada heap saat program berjalan dengan cara meminta satu slot kosong ke sistem operasi lalu mengembalikan alamat memori (pointer) dari slot tersebut. Sedangkan `delete` adalah operator manajemen memori yang digunakan untuk membebaskan kembali memori heap yang sebelumnya dialokasikan secara dinamis menggunakan operator `new`. Hal ini penting untuk mencegah kebocoran memori (memory leak) yang bersifat merusak.

Berikut adalah beberapa sintaks dan contoh penggunaan perintah `new` dan `delete` :

### 1. ALOKASI TANPA NILAI
Untuk hanya mengalokasikan memori suatu variabel tanpa memberinya nilai terlebih dahulu (seperti deklarasi), kita cukup menggunakan sintaks `new` seperti ini :
```C++
tipe_data *nama_pointer = new tipe_data;
```
Selanjutnya mari kita langsung terapkan penggunaannya pada suatu program seperti ini :
```bash
nano heap_hanya_alokasi.cpp
```
```C++
#include <iostream>
using namespace std;

int main() {
  int* ptr = new int;

  *ptr = 777;

  cout << "Alamat pointer ptr (berada di Stack)      = " << &ptr << endl;
  cout << "Alamat yang ditunjuk ptr (berada di Heap) = " << ptr << endl;
  cout << "Nilai yang disimpan di dalam Heap         = " << *ptr << endl;

  delete ptr; 
  return 0;
}
```
```bash
g++ heap_hanya_alokasi.cpp -o heap_hanya_alokasi 
```
```bash
./heap_hanya_alokasi
```
```bash
Alamat pointer ptr (berada di Stack)      = 0x7ffeefbff568
Alamat yang ditunjuk ptr (berada di Heap) = 0x555555566c20
Nilai yang disimpan di dalam Heap         = 777
```
Secara teknis, ketika kita menuliskan perintah `new int`, komputer akan mengalokasikan 4 byte (ukuran 1 tipe data integer) ke dalam memori heap, dimana hasil dari penyimpanan tersebut adalah alamat fisik memori heap yang berupa sekumpulan angka heksadesimal sehingga wajib disimpan dalam bentuk pointer yang dalam kasus ini kita menggunakan pointer bernama `ptr`. 

Pada program tersebut, dapat terlihat pula bahwa alamat varibel yang ditunjuk pointer (yang berada di dalam heap) dan alamat pointer itu sendiri (yang berada di dalam stack), berbeda sangat jauh seperti berada di kluster memori yang berbeda. Hal ini dapat membuktikan bahwa lokasi RAM antara heap dan stack benar-benar berbeda.

Selain itu, perintah `delete` disini juga sangat penting untuk menghindari memory leak. Jika kita lupa menuliskan perintah `delete` setelah sebelumnya ada perintah `new`, maka variabel yang dialokasikan oleh `new` akan bersifat abadi didalam RAM dan tidak akan terhapus sehingga RAM atau memori kita akan terus tersedot secara misterius sampai akhirnya sistem operasi kehabisan memori dan memaksa program tersebut crash (Out of Memory).

Mari kita buat program simulasi yang sengaja membocorkan RAM untuk melihat efek berbahayanya :
```bash
nano no_delete.cpp
```
```C++
#include <iostream>
using namespace std;

int main() {
  int* ptr = new int;

  *ptr = 777;

  cout << "Alamat pointer ptr (berada di Stack)      = " << &ptr << endl;
  cout << "Alamat yang ditunjuk ptr (berada di Heap) = " << ptr << endl;
  cout << "Nilai yang disimpan di dalam Heap         = " << *ptr << endl;

  return 0;
}
```
```bash
g++ no_delete.cpp -o no_delete 
```
```bash
./no_delete
```
```bash
Alamat pointer ptr (berada di Stack)      = 0x7ffeefbff568
Alamat yang ditunjuk ptr (berada di Heap) = 0x555555566c20
Nilai yang disimpan di dalam Heap         = 777
```
Perhatikan bahwa yang lebih berbahaya adalah tidak adanya indikasi error pada saat proses compile. Hal ini membuat kita berpikir bahwa program kita baik-baik saja, padahal sebenarnya merusak secara perlahan memori atau RAM komputer kita dan mengganggu kestabilan sistem operasi. 

### 2. ALOKASI DENGAN NILAI
Untuk mengalokasikan memori yang berisi suatu nilai tertentu kita dapat menuliskan sintaks seperti ini :
```C++
tipe_data *nama_pointer = new tipe_data(nilai);
````
```bash
nano alokasi_dengan_nilai.cpp
```
```C++
#include <iostream>
using namespace std;

int main() {
  string *ptr = new string("Tes");

  cout << "Alamat pointer ptr (berada di Stack)      = " << &ptr << endl;
  cout << "Alamat yang ditunjuk ptr (berada di Heap) = " << ptr << endl;
  cout << "Nilai yang disimpan di dalam Heap         = " << *ptr << endl;

  delete ptr;
  return 0;
}
```
```bash
g++ alokasi_dengan_nilai.cpp -o alokasi_dengan_nilai 
```
```bash
./alokasi_dengan_nilai
```
```bash
Alamat pointer ptr (berada di Stack)      = 0x7ffeefbff568
Alamat yang ditunjuk ptr (berada di Heap) = 0x555555566c20
Nilai yang disimpan di dalam Heap         = Tes
```

### 3. ALOKASI ARRAY
Sintaksis pemesanannya adalah :
```C++
tipe_data *nama_pointer = new tipe_data[ukuran_array]
```
dan untuk menghapusnya, wajib menggunakan :
```C++
delete[].
```
Menariknya, dengan Heap, kita bisa membuat array dinamis yang ukurannya baru ditentukan lewat input `cin` saat program berjalan (Dynamic Array). Jika dalam array tradisional, penggunaan variabel input sebagai ukuran arraynya dalam beberapa compiler akan menyebabkan error.

Berikut adalah contoh penggunaan alokasi array menggunakan heap :
```bash
nano dynamic_array.cpp
```
```C++
#include <iostream>
using namespace std;

int main() {
  int ukuran;
  cout << "Masukkan total ukuran array : ";
  cin >> ukuran; 

  int* dynamic_arr = new int[ukuran];

  for(int i = 0; i < ukuran; i++) {
    dynamic_arr[i] = (i + 1) * 10;
  }

  for(int i = 0; i < ukuran; i++) {
    cout << "Indeks ke-" << i << " -> Nilai: " << dynamic_arr[i] << " | Alamat RAM: " << &dynamic_arr[i] << endl;
  }

  delete[] dynamic_arr; 
  return 0;
}
```
```bash
g++ dynamic_array.cpp -o dynamic_array
```
```bash
./dynamic_array
```
```bash
Masukkan total ukuran array : 3

Indeks ke-0 -> Nilai: 10 | Alamat RAM: 0x555555566c40
Indeks ke-1 -> Nilai: 20 | Alamat RAM: 0x555555566c44
Indeks ke-2 -> Nilai: 30 | Alamat RAM: 0x5555566c48
```
Mungkin ada yang bertanya-tanya mengapa manipulasi elemen array tidak menggunakan mekanisme dereferencing. Secara teknis, ketika kita mengeksekusi variabel pointer `dynamic_arr` hasil dari panggilan `new int[ukuran]`, isi nilai yang disimpan di dalam variabel pointer tersebut hanyalah Alamat Dasar (Base Address), yaitu alamat memori fisik milik elemen pertama (indeks 0 / elemen ke-1). Dan secara otomatis `dynamic_arr[i]` itu sebenarnya sudah menggunakan dereferencing di balik layar! Sintaksis kurung siku [] pada pointer hanyalah Syntactic Sugar (cara tulis ringkas) yang disediakan C++ untuk menggantikan operasi aritmatika pointer dan dereferencing manual :

$$dynamicarr[i] = (i + 1) * 10; \space\space Sama\space dengan \space\space *(dynamicarr + i) = (i + 1) * 10;$$

---

## PENGGUNAAN `delete` SECARA LEBIH EFEKTF
Salah satu cacat manajemen memori manual yang sering terjadi adalah Dangling Pointer (Pointer Berayun). Ini terjadi ketika kita sudah melakukan `delete ptr;` (memorinya di Heap sudah dikembalikan ke sistem), tapi variabel pointer ptr tersebut masih menyimpan alamat hexadecimal bekas tempat lama tersebut. Akibatnya, jika kita tidak sengaja memanggil `*ptr` lagi di bawahnya, program akan berpotensi membaca data acak yang berbahaya atau merusak alokasi aplikasi lain.

Untuk mengatasinya, kita wajib untuk selalu membuat pointer menjadi null tepat setelah perintah `delete` dituliskan :
```C++
delete ptr;
ptr = nullptr;
```








