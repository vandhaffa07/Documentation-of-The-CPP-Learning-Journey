## FUNGSI DAN SCOPE VARIABLE
Dalam pemrograman, fungsi (atau function) adalah blok kode terpisah yang dirancang untuk menyelesaikan tugas tertentu. Ia menerima input (parameter), kemudian memprosesnya, dan menghasilkan atau mengembalikan suatu output. Penggunaan fungsi membuat kode lebih modular dan mudah dikelola.

Jika kita tarik pada program-program yang telah kita buat sebelumnya, dapat diketahui bahwa seluruh program atau instruksi yang kita tulis, ditumpuk secara monolitik di dalam satu skop global entry point, yaitu `int main()`. Model penulisan ini sebenarnya tidak efisien untuk sistem berskala besar. Karena, ketika basis kode meluas, penumpukan instruksi akan menciptakan kode yang terlihat kompleks, meningkatkan risiko efek samping, serta menyulitkan proses pelacakan bug.

Fungsi sendiri, digunakan untuk memecah kode program rumit yang menumpuk di dalam `int main()` tersebut, menjadi bagian-bagian yang lebih kecil sehingga lebih mudah dibaca dan diperbaiki. Selain itu, penggunaan fungsi dapat menghemat waktu dan tenaga kita, karena kita cukup menulis kode satu kali dan dapat memanggilnya berulang kali di berbagai bagian program.


## STRUKTUR DASAR FUNGSI PADA C++
Pada C++, fungsi dapat dituliskan sebagai berikut :
```c++
tipe_data_fungsi nama_fungsi( parameter ){
  instruksi
  return (kembalian)
}
```
### TIPE DATA FUNGSI (RETURN TYPE)
Bagian ini merupakan spesifikasi kategori data yang akan dikirimkan kembali oleh fungsi ke alur program utama (pemanggil) setelah seluruh instruksi internal selesai dieksekusi. Secara teknis, kompiler menggunakan tipe data ini untuk menentukan alokasi ruang memori (byte size) yang akan digunakan. Misalnya, jika kita menetapkan int, maka sistem menyiapkan 4 byte dan jika kita mentepakan double maka sistem menyiapkan 8 byte.

### NAMA FUNGSI
Bagian ini hanya digunakan untuk memberikan identitas resmi dari suatu blok fungsi agar bisa dipanggil di bagian program lain. Di tingkat low-level, nama fungsi sebenarnya merepresentasikan alamat memori awal di mana seluruh rangkaian instruksi mesin fungsi tersebut disimpan di dalam segmen kode. Saat kita memanggilnya, CPU akan membaca label tersebut sebagai perintah untuk melakukan jump (lompatan) ke alamat memori yang dituju.

### PARAMETER (INPUT ARGUMENTS)
Kita dapat meletakkan 1 atau lebih variabel di dalam tanda kurung sebagai pintu masuk bagi data eksternal yang dikirim dari program utama untuk diolah di dalam fungsi. Jadi, ketika fungsi tersebut dipanggil, setiap data yang kita masukkan ke dalam parameter akan disalin dan dialokasikan secara instan ke dalam Stack Frame fungsi tersebut sebagai variabel lokal baru. Parameter ini bersifat opsional sesuai dengan kebutuhan program yang ingin kita buat. Jika fungsi tidak membutuhkan data luar sama sekali, kita boleh mengosongkan bagian parameter ini.

### INSTRUKSI (FUNCTION BODY)
Blok kode yang diapit oleh tanda kurung kurawal ini adalah inti dari fungsi itu sendiri. Ia digunakan untuk menuliskan logika dan algoritma untuk menyelesaikan suatu tugas spesifik. Perlu diketahui bahwa seluruh variabel yang dideklarasikan di dalam blok ini bersifat lokal. Mereka terisolasi dari dunia luar dan memiliki ruang lingkup (scope) yang terbatas, dan akan langsung dihancurkan oleh CPU begitu eksekusi menyentuh kurung kurawal tutup.

### RETURN (KEMBALIAN)
Bagian ini menandakan titik terminasi akhir dari eksekusi sebuah fungsi, sekaligus instruksi untuk melempar nilai hasil komputasi keluar dari fungsi. Saat CPU mengeksekusi perintah return, nilai di dalam di sebelah kata return akan dievaluasi, lalu disalin ke register output CPU. Sedangkan Stack Frame fungsi tersebut langsung dihancurkan (deallocated) dari RAM. Inilah alasan mengapa kode apa pun yang ditulis di bawah perintah return di dalam blok fungsi yang sama tidak akan pernah dieksekusi oleh CPU (unreachable code), karena alur kendali sudah terlanjur keluar dari fungsi tersebut.


## CONTOH DAN PEMANGGILAN FUNGSI
Perlu diketahui bahwa fungsi adalah blok kode yang hanya berjalan ketika dipanggil. Jadi, ketika kita membuat fungsi seperti ini misalnya :
```bash
nano fungsi.cpp
```
```cpp
#include <iostream>
using namespace std;

int tambah(){
  int a = 2;
  int b = 3;
  return a+b;
}
```
Kemudian kita langsung mengcompile-nya dengan maksud ingin menampilkan hasil penjumlahan tersebut, maka ini yang akan terjadi :
```bash
g++ fungsi.cpp -o fungsi
```
```bash
./fungsi
```
```bash

```
Dapat terlihat bahwa meskipun tidak ada error pada proses kompilasi, hasil dari fungsi tersebut tetap tidak terlihat/ditampilkan oleh sistem. Hal ini dikarenakan kita tidak memanggil fungsi tersebut di dalam main. Karena pada dasarnya fungsi hanya melakukan komputasi. Dan untuk menampilkan hasil dari komputasi tersebut, fungsi harus dipanggil ke alur program utama yakni main seperti ini :
```bash
nano fungsi.cpp
```
```cpp
#include <iostream>
using namespace std;

int tambah(){
  int a = 2;
  int b = 3;
  return a+b;
}

int main(){
  cout << tambah();
  return 0;
}
```
```bash
g++ fungsi.cpp -o fungsi
```
```bash
./fungsi
```
```bash
5
```
Selanjutnya kita ingin mencoba pemanggilan fungsi yang memiliki parameter :
```bash
nano fungsi_dengan_parameter.cpp
```
```cpp
#include <iostream>
using namespace std;

int kali(int a, int b){
  return a*b;
}

int main(){
  cout << kali(2, 5);
  return 0;
}
```
Pada program ini, kita melempar dua buah nilai konstan, yaitu 2 dan 5 ke dalam parameter int a dan int b pada fungsi bernama kali. Ketika program dieksekusi, data 2 akan disalin ke variabel lokal a, dan data 5 akan disalin ke variabel lokal b di dalam Stack Frame fungsi kali. Fungsi tersebut akan kemudian memproses operasi aritmatika perkalian yang ada didalam body-nya dan mengembalikan hasilnya yakni 10 ke main :
```bash
g++ fungsi_dengan_parameter.cpp -o fungsi_dengan_parameter
```
```bash
./fungsi_dengan_parameter
```
```bash
10
```
Tidak hanya melempar nilai konstan (literal) secara langsung, kita juga dapat melempar variabel yang telah dideklarasikan di dalam main() sebagai argumen ke dalam parameter fungsi. Perhatikan program berikut :
```bash
nano fungsi_dengan_parameter.cpp
```
```cpp
#include <iostream>
using namespace std;

int kurang(int x, int y){
  return x-y;
}

int main(){
int a = 8;
int b = 3;
  cout << kurang(a, b);
  return 0;
}
```
Pada program di atas, kita menginisialisasikan variabel `int a = 8;` dan `int b = 3;` di dalam ruang lingkup main. Ketika instruksi kurang(a, b) dipanggil, C++ secara otomatis menerapkan mekanisme yang disebut Passing by Value (pengiriman berdasarkan nilai). Dimana, CPU tidak memberikan variabel asli a dan b milik main kepada fungsi kurang melainkan hanya mengambil salinan nilai dari variabel a (yaitu 8) untuk disuntikkan ke dalam variabel int x dan variabel b (yaitu 3) untuk disuntikkan ke dalam variabel int y. Fungsi tersebut akan kemudian memproses operasi pengurangan dan mengembalikan hasilnya ke main :
```bash
g++ fungsi_dengan_parameter.cpp -o fungsi_dengan_parameter
```
```bash
./fungsi_dengan_parameter
```
```bash
5
```


## MAIN() SEBAGAI FUNGSI UTAMA (ENTRY POINT)
Setelah kita memahami anatomi dan mekanisme pengiriman data pada suatu fungsi, sekarang mari kita arahkan sudut pandang kita ke fungsi yang selalu kita tulis di setiap program, yakni `int main()`


