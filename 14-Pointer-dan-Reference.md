## POINTER
Pointer adalah variabel khusus yang digunakan untuk menyimpan alamat memori (lokasi data tersebut berada) dari variabel lain. Ia secara sengaja di desain supaya kita dapat melakukan manipulasi data secara efisien dan mengelola memori secara dinamis. Pointer sendiri hanya terdapat pada bahasa pemrograman C dan C++ yang merupakan bahasa pemrograman low level dan sangat dekat dengan hardware, ia menawarkan kepada kita pengalaman untuk dapat mengotak-atik memori sesuai dengan kebutuhan yang kita perlukan. Meskipun begitu, penggunaan pointer juga harus diimbangi dengan ketelitian, karena sedikit kesalahan saja pada manipulasi memori yang kita lakukan, program dapat mengalami crash dan terdapat kemungkinan kecil untuk terjadi kerusakan pada hardware yang kita miliki.

## ANATOMI DAN STRUKTUR ALAMAT MEMORI
setiap kali kita mendeklarasi atau menginisialisasikan sebuah variabel biasa (misalnya `int angka = 100`), CPU akan memesan slot kosong di RAM dengan ukuran sesuai dengan tipe data variabel tersebut. Karena variabel `angka` bertipe data integer, maka CPU akan mengalokasikan 4 byte pada slot memori RAM. Setiap slot memori di dalam RAM tersebut memiliki serangkaian nomor unik yang ditulis dalam format Hexadecimal (basis 16), dan serangkaian nomor unik inilah yang kita sebut sebagai alamat memori. Untuk melihat alamat fisik ini secara langsung di terminal kita, C++ menyediakan Address-of Operator yang disimbolkan dengan tanda ampersand (&) seperti ini :
```bash
nano cek_alamat.cpp
```
```cpp
#include <iostream>
using namespace std;

int main(){
  int angka = 100;
  cout << "Nilai dari variabel angka = " << angka << endl;
  cout << "Alamat memori (addres) dari variabel angka = " << &angka << endl; 
  return 0;
}
```
```bash
g++ cek_alamat.cpp -o cek_alamat
```
```bash
./cek_alamat
```
```bash
Nilai dari variabel angka = 100
Alamat memori (addres) dari variabel angka = 0x7ffcb7432e6c
```
Dapat terlihat bahwa ketika kita menambahkan tanda & tepat sebelum nama variabel, kita bisa mengetahui alamat fisik dari variabel tersebut di slot memori RAM. 

## SINTAKS DAN MEKANISME POINTER
Untuk membuat variabel pointer yang mampu menampung alamat dari suatu variabel, kita wajib menambahkan operator asterisk (*) di antara tipe data dan nama variabel pointer saat deklarasi maupun inisialisasi seperti ini :
```cpp
//DEKLARASI
tipe_data_variabel_target *nama_pointer;

//INISIALISASI
tipe_data_variabel_target *nama_Pointer = &nama_variabel_target
```
Berikut adalah contoh penggunaan pointer :
```bash
nano pointer_test.cpp
```
```cpp
#include <iostream>
using namespace std;

int main() {
  int target = 50;
  int *ptr = &target; 

  cout << "Nilai dari variabel target       = " << target << endl;
  cout << "Alamat memori fisik target       = " << &target << endl;
  cout << "Alamat yang disimpan di 'ptr'    = " << ptr << endl;
  return 0;
}
```
```bash
g++ pointer_test.cpp -o pointer_test
```
```bash
./pointer_test
```
```bash
Nilai dari variabel target       = 50
Alamat memori fisik target       = 0x7ffd58c3a1a4
Alamat yang disimpan di 'ptr'    = 0x7ffd58c3a1a4
```
Dapat terlihat bahwa saat ini, variabel bernama "ptr" telah mempunyai nilai berupa alamat dari variabel bernama "target". Hal ini dibuktikan dengan output pada baris kedua dan ketiga program diatas, dimana alamat fisik target sama dengan alamat yang disimpan ptr.

Namun, setelah variabel pointer berhasil menyimpan alamat memori target, bagaimana cara kita mengambil atau mengubah nilai yang ada di dalam alamat tersebut? Untuk melakukan hal tersebut, kita dapat memanfaatkan fungsi ganda dari tanda asterisk (*) yakni Dereferencing Operator. Dimana, ketika tanda * diletakkan tepat di depan nama pointer yang sudah dideklarasikan, CPU akan membaca instruksi tersebut sebagai perintah untuk melompat ke alamat memori yang disimpan oleh pointer untuk mengambil atau mengubah nilai yang ada di dalamnya seperti ini :
```bash
nano pointer_test.cpp
```
```bash
#include <iostream>
using namespace std;

int main() {
  int target = 50;
  int *ptr = &target; 

  cout << "Nilai dari variabel target       = " << target << endl;
  cout << "Alamat memori fisik target       = " << &target << endl;
  cout << "Alamat yang disimpan di 'ptr'    = " << ptr << endl;

  cout << "Nilai hasil Dereference (*ptr)   = " << *ptr << endl;

  *ptr = 100; 
  cout << "Nilai dari variabel target sekarang     = " << target << endl;
  cout << "Alamat memori fisik target sekarang     = " << &target << endl;
  cout << "Alamat yang disimpan di 'ptr' sekarang  = " << ptr << endl;
  return 0;
}
```
```bash
g++ pointer_test.cpp -o pointer_test
```
```bash
./pointer_test
```
```bash
Nilai dari variabel target       = 50
Alamat memori fisik target       = 0x7ffd58c3a1a4
Alamat yang disimpan di 'ptr'    = 0x7ffd58c3a1a4
Nilai hasil Dereference (*ptr)   = 50
Nilai dari variabel target sekarang     = 100
Alamat memori fisik target sekarang     = 0x7ffd58c3a1a4
Alamat yang disimpan di 'ptr' sekarang  = 0x7ffd58c3a1a4
```
Dapat terlihat bahwa pada output baris ke-4, kita dapat menampilkan nilai dari variabel target dengan menggunakan variabel pointer dan tanda asterisk. Sealin itu, kita juga telah berhasil merubah nilai dari variabel target menggunakan metode yang sama. 

Satu hal menarik lainnya adalah bahwa pointer sebagai variabel yang menyimpan alamat dari variabel lain ternyata juga memiliki alamat tersendiri. Kita dapat mengaksesnya dengan menggunakan Address-of Operator seperti ini :
```bash
nano alamat_pointer.cpp
```
```bash
#include <iostream>
using namespace std;

int main(){
  double pi = 3.14;
  double *ptr_pi = &pi;
  cout << "Alamat fisik dari pointer 'ptr_pi' : " << &ptr_pi << endl;
  return 0;
}
```
```bash
g++ alamat_pointer.cpp -o alamat_pointer
```
```bash
./alamat_pointer
```
```bash
Alamat fisik dari pointer 'ptr_pi' : 0x7fff72ffb640
```


## REFERENCE






