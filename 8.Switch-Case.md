# SWITCH CASE
Dalam dunia pemrograman, efisiensi dan keterbacaan kode merupakan aspek krusial yang memudahkan developer dalam melacak alur logika dari sebuah program. Kode yang efisien dan mudah dibaca, akan memudahkan perbaikan bug dan penambahan fitur baru di masa depan tanpa merusak fungsi yang sudah ada sehingga developer dapat lebih cepat memahami alur kode tanpa harus bertanya-tanya mengenai apa maksud dari kode yang ditulis di masa lalu. Namun, sering kali muncul kendala yang dikenal sebagai "If-Else Hell", di mana tumpukan percabangan else if yang terlalu banyak membuat kode menjadi sulit dipahami manusia dan kurang optimal bagi kinerja CPU. 

Untuk mengatasi masalah tersebut, C++ menyediakan instruksi fundamental bernama switch-case, sebuah mekanisme percabangan (seperti if-else) yang dirancang khusus untuk menangani variabel tunggal yang memiliki banyak nilai konstan (seperti menu pilihan, kode status, atau karakter). 

## MEKANISME KERJA SWITCH-CASE
Berbeda dengan if-else yang mengevaluasi kondisi logika pada parameternya, switch bekerja dengan cara membandingkan nilai variabel terhadap daftar konstanta yang disebut case. Proses ini bekerja dalam tiga tahapan utama, yakni evaluasi ekspresi, pencocokan label, dan penghentian alur. Pada tahap awal, komputer akan mengambil nilai berupa tipe data integral (seperti int atau char) dari variabel yang ada di dalam tanda kurung switch(). Selanjutnya, komputer akan melakukan pencarian cepat dan jika ditemukan case yang nilainya identik, maka komputer akan melakukan lompatan (jump) langsung ke blok tersebut dan mengeksekusinya tanpa mempedulikan kondisi blok-blok yang ada di atasnya.

Berikut adalah sintaks dasar instruksi switch-case :
```C++
switch (variabel) {
  case nilai1:
    // Instruksi dieksekusi jika variabel == nilai1
    break; 
  case nilai2:
    // Instruksi dieksekusi jika variabel == nilai2
    break;
  default:
    // Jalur cadangan jika tidak ada case yang cocok
}
```
Dan berikut adalah contoh program sederhana menggunakan switch case :
```bash
nano switch-case.cpp
```
```c++
#include <iostream>
using namespace std;

int main(){
  int mode;
  cout << "=== SISTEM KONTROL ===\n1. Active\n2. Standby\n3. Maintenance\nPilih Mode: ";
  cin >> mode;
  cout << endl;

  switch(mode){
    case 1:
      cout << "Status: Sistem berjalan penuh (Active)." << endl;
      break;
    case 2:
      cout << "Status: Sistem dalam mode hemat daya (Standby)." << endl;
      break;
    case 3:
      cout << "Status: Sistem sedang diperbaiki (Maintenance)." << endl;
      break;
    default:
      cout << "Error: Mode tidak dikenal!" << endl;
  }
  return 0;
}
```
```bash
g++ switch-case.cpp -o switch-case
```
```bash
./switch-case
=== SISTEM KONTROL ===
1. Active
2. Standby
3. Maintenance
Pilih Mode: 3

Status: Sistem sedang diperbaiki (Maintenance).
```

## KOMPONEN DASAR SWITCH CASE
### 1. `switch(ekspresi)`
Komponen ini adalah gerbang utama bagi CPU untuk mengambil nilai dari variabel atau ekspresi yang ditulis pada parameter dan mencari label case yang cocok dengan program yang kita buat. Dalam program diatas, CPU mengambil nilai dari variabel bernama mode yang memiliki tipe data integer. Perlu dipahami bahwa sifat dari parameter switch hanya menerima tipe data Integral ( int dan char )

Mari kita lihat apa yang terjadi jika kita memaksa switch memproses tipe data non-integral :
```bash
nano switch-case.cpp
```
```c++
#include <iostream>
using namespace std;

int main(){
  float mode;
  cout << "=== SISTEM KONTROL ===\n1. Active\n2. Standby\n3. Maintenance\nPilih Mode: ";
  cin >> mode;
  cout << endl;

  switch(mode){
    case 1:
      cout << "Status: Sistem berjalan penuh (Active)." << endl;
      break;
    case 2:
      cout << "Status: Sistem dalam mode hemat daya (Standby)." << endl;
      break;
    case 3:
      cout << "Status: Sistem sedang diperbaiki (Maintenance)." << endl;
      break;
    default:
      cout << "Error: Mode tidak dikenal!" << endl;
  }
  return 0;
}
```
```bash
g++ switch-case.cpp -o switch-case
error: switch quantity not an integer
```
Saat melakukan proses kompilasi, program diatas malah menghasilkan pesan error, hal ini dkarenakan arsitektur instruksi switch pada C++ yang dirancang untuk bekerja dengan nilai biner yang pasti (Exact Value). Tipe data float atau double seringkali memiliki masalah presisi pada tingkat biner (floating-point precision), misalnya angka seperti 1.0 mungkin disimpan oleh CPU sebagai 0.9999999. Karena switch bekerja dengan sistem Direct Jump (lompatan langsung), CPU tidak bisa menoleransi ketidakpastian nilai tersebut. Sebaliknya, tipe data int dan char memiliki representasi biner yang mutlak, sehingga CPU dapat melakukan perbandingan biner dalam satu siklus instruksi dengan akurat dan presisi.

### 2. `case konstanta`
Komponen ini bertindak sebagai label alamat memori yang menjadi tujuan lompatan bagi CPU. Dalam program switch-case.cpp yang telah kita buat sebelumnya, terdapat tiga buah label yakni case 1, case 2, dan case 3. Penting untuk dipahami bahwa case bukanlah sebuah instruksi logika yang diperiksa secara berurutan, melainkan sebuah penanda titik masuk (entry point) bagi CPU untuk melakukan lompatan secara langsung. Misalnya, saat program dijalankan dan user menginput angka 3, CPU tidak akan membuang waktu untuk memeriksa case 1 atau case 2, melainkan langsung melakukan lompatan (jump) ke alamat memori yang ditandai oleh case 3.  Menariknya, nilai yang yang terdapat pada label ini haruslah konstanta tetap dan tidak boleh berupa variabel atau ekspresi yang nilainya baru bisa ditentukan saat program berjalan (runtime).

Mari kita lihat apa yang terjadi jika kita memasukkan variabel ke dalam label case, bukan nilai konstanta tetap :
```bash
nano switch-case.cpp
```
```c++
#include <iostream>
using namespace std;

int main(){
  int mode;
  int angka_satu = 1;
  cout << "=== SISTEM KONTROL ===\n1. Active\n2. Standby\n3. Maintenance\nPilih Mode: ";
  cin >> mode;
  cout << endl;

  switch(mode){
    case angka_satu:
      cout << "Status: Sistem berjalan penuh (Active)." << endl;
      break;
    case 2:
      cout << "Status: Sistem dalam mode hemat daya (Standby)." << endl;
      break;
    case 3:
      cout << "Status: Sistem sedang diperbaiki (Maintenance)." << endl;
      break;
    default:
      cout << "Error: Mode tidak dikenal!" << endl;
  }
  return 0;
}
```
```bash
g++ switch-case.cpp -o switch-case
error: the value of ‘angka_satu’ is not usable in a constant expression
note: ‘int angka_satu’ is not const
```
Error tersebut terjadi karena compiler mewajibkan nilai setelah kata kunci case adalah sebuah Literal Constant (nilai yang sudah pasti saat kode dikompilasi). Hal ini dikarenakan CPU memerlukan alamat tujuan yang statis untuk membangun Jump Table. Jika label case bersifat dinamis (berupa variabel), maka CPU tidak dapat menentukan tujuan lompatan secara instan sebelum program dijalankan.

Hal ini dapat dibuktikan ketika kita mengganti variabel angka_satu menjadi const seperti ini :
```c++
#include <iostream>
using namespace std;

int main(){
  int mode;
  const int angka_satu = 1;
  cout << "=== SISTEM KONTROL ===\n1. Active\n2. Standby\n3. Maintenance\nPilih Mode: ";
  cin >> mode;
  cout << endl;

  switch(mode){
    case angka_satu:
      cout << "Status: Sistem berjalan penuh (Active)." << endl;
      break;
    case 2:
      cout << "Status: Sistem dalam mode hemat daya (Standby)." << endl;
      break;
    case 3:
      cout << "Status: Sistem sedang diperbaiki (Maintenance)." << endl;
      break;
    default:
      cout << "Error: Mode tidak dikenal!" << endl;
  }
  return 0;
}
```
Dengan menambahkan kata kunci const, kita memberi tahu compiler bahwa nilai dari angka_satu tidak akan pernah berubah sejak program dikompilasi hingga selesai dijalankan. Karena nilainya kini bersifat read-only dan sudah diketahui di awal (compile-time), compiler dapat dengan percaya diri memasukkan angka tersebut ke dalam daftar Jump Table.
```bash
g++ switch-case.cpp -o switch-case
```
```bash
./switch-case
=== SISTEM KONTROL ===
1. Active
2. Standby
3. Maintenance
Pilih Mode: 1

Status: Sistem berjalan penuh (Active).
```

### 3. `break;`
break adalah instruksi kendali yang berfungsi untuk memerintahkan CPU agar segera keluar dari blok switch dan melompat menuju tanda tutup kurung kurawal }. Pada program sistem kontrol di atas, break memastikan bahwa setelah status sistem dicetak, program tidak melanjutkan eksekusi ke baris berikutnya.

Mari kita bereksperimen dengan menghilangkan seluruh instruksi break untuk melihat fenomena Fall-through:
```bash
nano switch-case.cpp
```
```c++
#include <iostream>
using namespace std;

int main(){
  int mode;
  cout << "=== SISTEM KONTROL ===\n1. Active\n2. Standby\n3. Maintenance\nPilih Mode: ";
  cin >> mode;
  cout << endl;

  switch(mode){
    case 1:
      cout << "Status: Sistem berjalan penuh (Active)." << endl;
    case 2:
      cout << "Status: Sistem dalam mode hemat daya (Standby)." << endl;
    case 3:
      cout << "Status: Sistem sedang diperbaiki (Maintenance)." << endl;
    default:
      cout << "Error: Mode tidak dikenal!" << endl;
  }
  return 0;
}
```
```bash
g++ switch-case.cpp -o switch-case
```
```bash
./switch-case
=== SISTEM KONTROL ===
1. Active
2. Standby
3. Maintenance
Pilih Mode: 2

Status: Sistem dalam mode hemat daya (Standby).
Status: Sistem sedang diperbaiki (Maintenance).
Error: Mode tidak dikenal!
```
Terlihat bahwa ketika kita memilih mode 2, CPU mencetak seluruh status dari case 2 hingga ke baris paling bawah. Hal ini membuktikan bahwa tanpa break, CPU akan kehilangan kendali penghenti dan terus mengeksekusi instruksi secara linear melewati label-label case lainnya. Fenomena Fall-through ini menunjukkan pula bahwa case hanyalah pintu masuk, dan break adalah satu-satunya cara untuk menemukan pintu keluar. Selain itu, hal menarik lainnya adalah respon CPU yang tidak mencetak "Status: Active" pada case pertama. Hal ini dapat terjadi karena switch menggunakan mekanisme Jump Table, dimana CPU langsung melompat ke alamat memori case 2 tanpa perlu melewati atau mengevaluasi case 1.

### 4. `default`
Komponen ini berfungsi sebagai jalur alternatif terakhir dalam sistem kontrol. Dalam program yang kita buat, komponen ini akan menangkap semua input yang tidak sesuai dengan daftar case yang tersedia (1, 2, atau 3). Posisinya identik dengan else pada struktur if-else. 
```bash
./switch-case
Pilih Mode: 99

Error: Mode tidak dikenal!
```
Selanjutnya, mari kita bereksperimen dengan menghapus seluruh blok default untuk melihat bagaimana perilaku CPU terhadap input yang tidak terdaftar:
```bash
nano switch-case.cpp
```
```c++
#include <iostream>
using namespace std;

int main(){
  int mode;
  cout << "=== SISTEM KONTROL ===\n1. Active\n2. Standby\n3. Maintenance\nPilih Mode: ";
  cin >> mode;
  cout << endl;

  switch(mode){
    case 1:
      cout << "Status: Sistem berjalan penuh (Active)." << endl;
    case 2:
      cout << "Status: Sistem dalam mode hemat daya (Standby)." << endl;
    case 3:
      cout << "Status: Sistem sedang diperbaiki (Maintenance)." << endl;
  }
  return 0;
}
```
```bash
g++ switch-case.cpp -o switch-case
```
```bash
./switch-case
=== SISTEM KONTROL ===
1. Active
2. Standby
3. Maintenance
Pilih Mode: 99

```
Perhatikan bahwa saat angka 99 dimasukkan, program tidak memberikan respons apa pun. Secara teknis, hal ini terjadi karena CPU melakukan pemindaian terhadap daftar label alamat (case 1, 2, 3) dan tidak menemukan alamat yang cocok dengan nilai 99. Karena tidak ada label default sebagai instruksi cadangan, CPU menganggap tidak ada tugas yang harus dikerjakan di dalam blok switch tersebut. Akibatnya, CPU langsung melakukan lompatan keluar menuju tanda tutup kurung kurawal } dan mengakhiri eksekusi switch
