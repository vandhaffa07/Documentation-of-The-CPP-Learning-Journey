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

## SINTAKS, MEKANISME, DAN KARAKTERISTIK POINTER
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
Reference adalah sebuah fitur di C++ yang digunakan untuk membuat nama lain dari variabel yang sudah ada. Berbeda dengan pointer yang bertindak sebagai variabel mandiri untuk menyimpan alamat memori dari variabel lain sehingga membuat alokasi alamat baru untuknya, reference justru tidak memiliki alamat memorinya sendiri. Ia murni melekat dan berbagi alamat memori yang sama persis dengan variabel asli yang telah ditujukan untuknya (bukan salinan). Penggunaan reference juga tidak terlalu berbahaya seperti pointer, karena walaupun kita melakukan kesalahan dan secara tidak sengaja merubah nilainya, ia hanya berdampak pada logika program kita khususnya yang memiliki hubungan dengan program tersebut, dan tidak menimbulkan crash atau kerusakan pada hardware.

## SINTAKS, MEKANISME, DAN KARAKTERISTIK REFERENCE
Untuk menginisialisasikan reference, kita menggunakan operator ampersand (&) di antara tipe data dan nama variabel reference. Berikut adalah sintaks dasarnya :
```cpp
tipe_data_variabel_asli &nama_reference = variabel_asli;
```
Berikut adalah contoh penggunaan reference :
```bash
nano reference.cpp
```
```cpp
#include <iostream>
using namespace std;

int main(){
  int angka = 10;
  int &ref_angka = angka;

  cout << "Nilai angka      : " << angka << endl;
  cout << "Nilai ref_angka  : " << ref_angka << endl;
  cout << "Alamat angka     : " << &angka << endl;
  cout << "Alamat ref_angka : " << &ref_angka << endl;
return 0;
}
```
```bash
g++ reference.cpp -o reference
```
```bash
./reference
```
```bash
Nilai angka      : 10
Nilai ref_angka  : 10
Alamat angka     : 0x7ffdf8c99a14
Alamat ref_angka : 0x7ffdf8c99a14
```
Saat ini `ref_angka` sudah seperti layaknya sebuah variabel asli yang memiliki nilai yang sama dengan variabel `angka`. Akan tetapi, dapat terlihat secara jelas pula dari output terminal bahwa `ref_angka` juga memiliki alamat memori fisik yang sama persis (`0x7ffdf8c99a14`). Ini membuktikan bahwa reference tidak menciptakan ruang baru di RAM sebagai variabel baru, melainkan murni menempel pada slot memori variabel yang diwakilinya.

Dapat terlihat pula pada kode program diatas bahwa penggunaan reference tidak seperti pointer yang membutuhkan operator khusus untuk mengakses isi datanya. Kita cukup menggunakannya seperti variabel normal, dan CPU secara otomatis mengarahkan operasi tersebut ke alamat fisik variabel aslinya.

Jika kita melakukan perubahan data melalui `ref_angka`, maka nilai pada variabel `angka` juga akan otomatis berubah secara instan:
```bash
nano reference.cpp
```
```cpp
#include <iostream>
using namespace std;

int main(){
  int angka = 10;
  int &ref_angka = angka;

  cout << "Nilai angka      : " << angka << endl;
  cout << "Nilai ref_angka  : " << ref_angka << endl;
  cout << "Alamat angka     : " << &angka << endl;
  cout << "Alamat ref_angka : " << &ref_angka << endl;

  ref_angka = 50;

  cout << "Nilai angka sekarang      : " << angka << endl;
  cout << "Nilai ref_angka sekarang  : " << ref_angka << endl;
  cout << "Alamat angka sekarang     : " << &angka << endl;
  cout << "Alamat ref_angka sekarang : " << &ref_angka << endl;
return 0;
}
```
```bash
g++ reference.cpp -o reference
```
```bash
./reference
```
```bash
Nilai angka      : 10
Nilai ref_angka  : 10
Alamat angka     : 0x7ffdf8c99a14
Alamat ref_angka : 0x7ffdf8c99a14
Nilai angka sekarang      : 50
Nilai ref_angka sekarang  : 50
Alamat angka sekarang     : 0x7ffdf8c99a14
Alamat ref_angka sekarang : 0x7ffdf8c99a14
```

Selain itu, perlu diketahui bahwa kita tidak bisa hanya sekedar mendeklarasikan reference tanpa menunjuk variabel asli mana yang ingin diwakili dan harus melakukan inisialisasi. Jika tidak, maka compiler akan menampilkan error seperti ini :
```bash
nano deklarasi_ref.cpp
```
```cpp
#include <iostream>
using namespace std;

int main(){
  double pi = 3.14;
  double &ref_pi;
  return 0;
}
```
```bash
g++ deklarasi_ref.cpp -o deklarasi_ref
```
```bash
./deklarasi_ref
```
```bash
error: ‘ref_pi’ declared as reference but not initialized
```

Satu hal menarik lainnya dari reference adalah sifatnya yang kaku dan permanen. Begitu sebuah reference dikunci ke satu variabel saat inisialisasi, hubungan tersebut akan bersifat absolut sepanjang program berjalan, dimana kita tidak bisa mengalihkan reference tersebut untuk mewakili variabel lain. Perhatikan kode berikut :
```bash
nano ubah_variabel.cpp
```
```cpp
#include <iostream>
using namespace std;

int main(){
  int a = 2;
  int b = 3;
  int &ref = a;

  cout << "Nilai a    : " << a << endl;
  cout << "Alamat a   : " << &a << endl;
  cout << "Nilai b    : " << b << endl;
  cout << "Alamat b   : " << &b << endl;
  cout << "Nilai ref  : " << ref << endl;
  cout << "Alamat ref : " << &ref << endl;

  ref = b;

  cout << "Nilai a sekarang    : " << a << endl;
  cout << "Alamat a sekarang   : " << &a << endl;
  cout << "Nilai b sekarang    : " << b << endl;
  cout << "Alamat b sekarang   : " << &b << endl;
  cout << "Nilai ref sekarang  : " << ref << endl;
  cout << "Alamat ref sekarang : " << &ref << endl;
  return 0;
}
```
```bash
g++ ubah_variabel.cpp -o ubah_variabel
```
```bash
./ubah_variabel
```
```bash
Nilai a    : 2
Alamat a   : 0x7ffdbad2b2a4
Nilai b    : 3
Alamat b   : 0x7ffdbad2b2a0
Nilai ref  : 2
Alamat ref : 0x7ffdbad2b2a4
Nilai a sekarang    : 3
Alamat a sekarang   : 0x7ffdbad2b2a4
Nilai b sekarang    : 3
Alamat b sekarang   : 0x7ffdbad2b2a0
Nilai ref sekarang  : 3
Alamat ref sekarang : 0x7ffdbad2b2a4
```
Terlihat bahwa ketika instruksi `ref = b;` dieksekusi, C++ tidak memindahkan tautan alamat memori `ref` untuk merujuk ke variabel `b`. Alamat memori `ref` terbukti tetap setia menunjuk pada koordinat milik `a` (`0x7ffdbad2b2a4`). Yang sebenarnya terjadi adalah proses copy assignment, di mana nilai dari variabel `b` (yaitu 3) disalin dan dimasukkan ke dalam alamat memori yang diikat oleh ref (yang tidak lain adalah variabel `a`). Akibatnya, nilai `a` ikut berubah menjadi 3, menegaskan aturan mutlak bahwa ikatan referensi bersifat permanen dan tidak bisa dialihkan ke variabel lain sepanjang program berjalan.

## PARAMETER FUNGSI VIA POINTER DAN REFERENCE
Berdasarkan arsitektur manajemen memori pada C++, terdapat tiga metode utama untuk melemparkan data dari program utama (main()) ke dalam parameter sebuah fungsi yakni :

### PASSING BY VALUE
Ini adalah metode standar yang kita gunakan di File ke-13 sebelumnya. Ketika fungsi dipanggil, CPU akan membuat Stack Frame baru dan menduplikasi (menyalin) seluruh isi nilai dari variabel asli sebagai variabel lokal baru di dalam fungsi. Namun kelemahannya, metode ini menguras waktu pemrosesan CPU dan ruang RAM (overhead) serta dapat meningkatkan resiko bahwa nilai variabel tidak berubah jika kita tidak menggunakannya secara teliti seperti pada kasus berikut : 
```bash
pass_by_value.cpp
```
```cpp
#include <iostream>
using namespace std;

void ubah_nilai(int nilai){
   nilai = 100;
}

int main(){
  int nilai = 98;
  ubah_nilai(nilai);
  cout << nilai << endl;
  return 0;
}
```
```bash
g++ pass_by_value.cpp -o pass_by_balue
```
```bash
./pass_by_value
```
```bash
98
```
Dapat terlihat bahwa nilai dari variabel nilai pada main() tetap bernilai 98, karena fungsi `ubah_nilai` hanya mengubah data kloningannya pada Stack Frame internal yang terisolasi dan begitu selesai dieksekusi, nilai tersebut akan langsung dihilangkan dari memori RAM.

### PASSING BY REFERENCE
Metode kedua adalah Passing by Reference. Dengan menambahkan operator ampersand (&) pada parameter fungsi, kita tidak menduplikasi data sama sekali. Parameter fungsi tersebut secara instan menjelma menjadi nama alias yang memegang hak akses penuh atas alamat memori fisik variabel asli yang dilemparkan dari main().

Mari kita implementasikan pada skenario yang sama:

```bash
nano pass_by_reference.cpp
```
```cpp
#include <iostream>
using namespace std;

void ubah_nilai(int &nilai){ 
   nilai = 100;
}

int main(){
  int nilai = 98;
  ubah_nilai(nilai);
  cout << nilai << endl;
  return 0;
}
````
```bash
g++ pass_by_reference.cpp -o pass_by_reference
```
```bash
./pass_by_reference
```
```bash
100
```

### PASSING BY POINTER
Metode ketiga adalah Passing by Pointer. Pada metode ini, parameter fungsi dideklarasikan dengan operator asterisk (*) sehingga bertindak sebagai variabel penampung alamat memori. Saat melakukan pemanggilan fungsi, kita wajib mengekstrak alamat memori variabel asli menggunakan operator &. Di dalam tubuh fungsi, kita wajib menerapkan teknik dereferencing (*nama_pointer) untuk membongkar dan memanipulasi datanya secara fisik.

```bash
nano pass_by_pointer.cpp
```
```cpp
#include <iostream>
using namespace std;

void ubah_nilai(int *ptr_nilai){ // Menerima pointer alamat memori
   *ptr_nilai = 100;            // Melakukan dereferencing untuk mengubah data asli
}

int main(){
  int nilai = 98;
  ubah_nilai(&nilai);           // Wajib melempar alamat memori menggunakan &
  cout << nilai << endl;
  return 0;
}
```
```bash
g++ pass_by_pointer.cpp -o pass_by_pointer
```
```bash
./pass_by_pointer
```
```bash
100
```











