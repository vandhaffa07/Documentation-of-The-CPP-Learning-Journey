# STRUKTUR DASAR PROGRAM C++

Struktur dasar program C++ adalah susunan minimal komponen yang diperlukan agar sebuah program C++ dapat dikenali, dikompilasi, dan dieksekusi secara baik dan efisien. Dengan memahami struktur ini, kita tidak hanya mengetahui bagaimana cara menulis program, tetapi juga memahami bagaimana cara compiler membaca dan memproses setiap bagian dari kode yang kita tulis.

Sebagai contoh, disini saya telah menyiapkan suatu program C++ sederhana:
```cpp
#include <iostream>
using namespace std;

int main(){
  cout<<"Halo teman-teman!"<<endl;
  return 0;
}
```
Yang jika dijalankan akan menghasilkan output seperti ini :
```bash
Halo teman-teman!
```
Program tersebut adalah contoh paling dasar dari struktur bahasa C++ yang berfungsi untuk menampilkan teks ke layar. Program tersebut juga seringkali dijadikan bahan pembelajaran tingkat awal bagi sesorang yang ingin menguasai c++, karena sifatnya yang sederhana tetapi tetap komplit.

## DIRECTIVE (`#include <iostream>`)
Baris ini merupakan preprocessor directive, yakni sebuah instruksi untuk compiler yang diproses saat melakukan fase preprocessing(perluasan source code). Directive ini berfungsi untuk menyisipkan isi dari file iostream yang telah disertakan ke dalam program. Iostream sendiri adalah header file standar dalam bahasa pemrograman C++ yang merupakan singkatan dari Input/Output Stream. File ini berfungsi mendeklarasikan objek aliran standar untuk berinteraksi dengan pengguna seperti operasi input (pembacaan data) maupun operasi output (penulisan data) yang meliputi penggunaan simbol-simbol cin, cout, cerr, dan clog. Perlu diketahui bahwa deklarasi ini bukanlah implementasi langsung, melainkan semacam pemberitahuan kepada compiler bahwa simbol-simbol tersebut memang ada, sehingga ketika digunakan dalam kode dan diverifikasi saat proses compiling, compiler tidak akan menganggapnya sebagai error.

Jika directive ini tidak ditambahkan pada program, maka compiler tidak akan mengetahui keberadaan cout, cin, ataupun endl. Hal ini dikarenakan tidak ada yang mendeklarasikan/memberi tahu compiler bahwa simbol-simbol tersebut bersifat valid, sehingga akan menghasilkan error seperti:
```bash
nano program.cpp
```
```cpp
using namespace std;

int main(){
  cout<<"Halo teman-teman!"<<endl;
  return 0;
}
```
```bash
g++ program.cpp -o program
error: ‘cout’ was not declared in this scope
error: ‘endl’ was not declared in this scope
```

---

## (`using namespace std`)
Baris ini berfungsi untuk memberitahu compiler bahwa kita akan menggunakan simbol-simbol yang berada di dalam namespace std (standard) secara langsung tanpa perlu menuliskan awalan `std::` secara berulang kali. Sebelumnya, perlu diketahui bahwa terdapat beberapa cara penulisan sintaks namespace, diantarnya adalah menggunakan `using namespace nama_namespace` pada awalan program seperti pada `using namespace std` yang tengah kita pelajari saat ini, atau bisa juga dengan menuliskan sintaks `nama_namespace::` pada setiap awalan simbolnya seperti ini :
```cpp
#include <iostream>

int main(){
  std::cout<<"Halo teman-teman!"<<std::endl;
  return 0;
}
```
Program diatas memiliki logika, struktur, bahkan output yang persis sama dengan program sebelumnya, hanya saja terasa lebih rumit karena mengharuskan kita menggunakan std di setiap simbol yang menggunakan namespace miliknya. Namespace sendiri adalah mekanisme pengelompokan nama (variabel, fungsi, atau objek) untuk mencegah terjadinya konflik penamaan (name collision), misalnya ketika saya memiliki 2 fungsi yang sama bernama cout, satu buatan dari ruang lingkup/namespace saya sendiri (misalnya van) dan satu lagi dari ruang lingkup standard c++ yakni std, maka namespace memberikan peran penting untuk membantu compiler dalam menentukann apakah cout ini dari `van::cout` atau dari `std::cout`. 

Ketika kita menuliskan simbol-simbol yang ada di namespace std seperti cout dan endl tanpa awalan `std::` dan tanpa perintah `using namespace std;` pada awal program, compiler akan mencari simbol-simbol tersebut di ruang lingkup (scope) yang aktif saat ini, yaitu global scope dan local scope di dalam fungsi main(). Karena cout yang sebenarnya bersembunyi di dalam ruang lingkup std, dan sama sekali tidak ada deklarasi namespace std pada program tersebut, compiler pun tidak dapat menemukannya dan menghasilkan pesan error yang cukup cerdas :
```bash
nano program.cpp
```
```cpp
using namespace std;

int main(){
  cout<<"Halo teman-teman!"<<endl;
  return 0;
}
```
```bash
g++ program.cpp -o program
error: ‘cout’ was not declared in this scope; did you mean ‘std::cout’?
error: ‘endl’ was not declared in this scope; did you mean ‘std::endl’?
```
Pesan ini bisa muncul karena compiler menemukan kandidat simbol yang paling mendekati dan mengenali bahwa ada simbol bernama cout dan endl di dalam header yang sudah di-include sebelumnya , namun simbol tersebut tidak berada di scope yang sedang digunakan.

---

## FUNGSI (`int main(){}`)
`int main(){}` merupakan fungsi khusus dalam C++ yang berperan sebagai titik awal (entry point) dari sebuah program. Ketika sebuah program dijalankan, misalnya dengan ./program atau mengklik file .exe di windows, sistem operasi tidak langsung mengeksekusi kode yang kita tulis secara mentah, melainkan akan memanggil fungsi main sebagai titik awal dari kode program yang kita buat. Meskipun kita memiliki ribuan baris kode di luar fungsi ini, komputer hanya akan bergerak ketika ia menemukan instruksi di dalam lingkup main. Struktur `int main(){}` terdiri dari beberapa komponen krusial yang menentukan bagaimana program berinteraksi dengan sistem operasi:

- **Tipe pengembalian (`int`)** : Sintaks ini menunjukkan deklarasi return type atau tipe data kembalian pada fungsi main. Dalam standar C++ modern, fungsi main harus mengembalikan nilai bertipe integer (bilangan bulat). Nilai inilah yang nantinya akan dikirimkan kembali ke Sistem Operasi (return 0) setelah program selesai dijalankan sebagai exit status dan tanda bahwa ini adalah akhir dari program.
  
- **Nama fungsi(`main`)** : Nama ini bersifat sakral dan case-sensitive. kita tidak bisa menggantinya menjadi Main() atau MAIN(), karena linker (program khusus dalam proses linking yang bertujuan untuk menggabungkan berbagai object file dan library yang sesuai menjadi satu file yang dapat dieksekusi) secara spesifik akan mencari simbol bernama main untuk memulai eksekusi. Jika nama ini salah ketik, proses build program akan gagal dengan pesan error "undefined reference to main".
  
- **Parameter (`()`)** : Tanda kurung setelah kata main digunakan untuk menampung argumen atau parameter. Pada contoh sederhana yang saya buat, tanda kurung tersebut kosong, yang berarti program tersebut tidak menerima masukan data apapun dari luar. Namun, pada program yang lebih kompleks, bagian ini bisa diisi untuk menerima perintah tambahan saat aplikasi dipanggil, biasanya dengan int argc dan char* argv[] yang digunakan untuk menangkap argumen dari command line saat program dijalankan. Parameter ini memungkinkan program berinteraksi langsung dengan input dari sistem operasi tanpa harus menggunakan mekanisme input manual seperti cin.
  
- **Block code(`{}`)** : Tanda kurung kurawal buka { dan tutup } disebut sebagai Body of Function. Segala sesuatu yang kita tulis di antara kedua tanda ini adalah urutan instruksi yang akan dikerjakan oleh komputer satu per satu, dari atas ke bawah.

Di bagian paling bawah sebelum kurung kurawal tutup, terdapat baris return 0;. Secara teknis, baris ini adalah cara program kita melapor kepada sistem operasi bahwa tugasnya telah selesai. Menariknya, pada compiler C++ modern, jika kita lupa menuliskan return 0; khusus di dalam fungsi main, compiler akan secara otomatis menambahkannya untuk kita. Namun, menuliskannya secara eksplisit tetap dianggap sebagai praktik pemrograman yang baik dan profesional.

**Catatan :** Pembahasan main sebagai fungsi sebenarnya terlalu dini untuk memulai pembelajaran c++, kita sebenarnya dapat mengabaikan pembahasan ini terlebih dahulu

---

## STATEMENT OUTPUT (`cout<<"Halo teman-teman!"<<endl;`)
### 1. `cout` (Console Out)
`cout` (Console out) adalah sebuah objek dalam standard library iostream yang mewakili Standard Output Stream. Objek ini digunakan untuk mengirimkan/menampilkan data ke satndard output yakni layar monitor kita. 

Jika kita kembali ke contoh program sebelumnya :
```cpp
#include <iostream>
using namespace std;

int main(){
  cout<<"Halo teman-teman!"<<endl;
  return 0;
}
```
Pada baris `cout<<"Halo teman-teman!"<<endl;` string `"Halo teman-teman!"` tidak langsung muncul di layar begitu saja, melainkan terlebih dahulu dikirim ke dalam sebuah aliran(stream) bernama `cout`. Secara teknis, stream ini akan meneruskan data tersebut ke buffer output. Buffer output sendiri adalah sistem penyimpanan sementara data output di dalam memori (RAM) sebelum akhirnya ditampilkan ke layar oleh sistem.

Hal ini bisa kita pahami ketika kita mengganggu alurnya sedikit dengan hanya menuliskan :
```cpp
cat > program.cpp
#include <iostream>
using namespace std;

int main(){
"Halo teman-teman!";
return 0;
}
```
Kemudian kita jalankan :
```bash
g++ program.cpp -o program
```
```bash
./program

```
Terlihat bahwa program tetap valid dan dapat dikompilasi tetapi tidak menghasilkan output apapun. Ini menunjukkan bahwa mendeklarasikan keberadaan data saja tidak cukup untuk bisa ditampilkan di layar, data tersebut harus dikirim ke suatu mekanisme output yakni cout agar bisa terlihat oleh pengguna. 

### 2. `<<` (Insertion Operator)
Simbol dua kurung siku buka ini disebut sebagai Insertion Operator. Operator ini berfungsi untuk memasukkan atau mengarahkan data yang ada di sebelah kanannya ke objek yang ada di sebelah kirinya, Ketika kita menuliskan :
```bash
cout<<"Halo teman-teman!"<<endl;
```
Maka, secara konseptual kita sedang mengatakan "Masukkan string "Halo teman teman!" ke dalam aliran cout"

Menariknya, operator ini bekerja secara berurutan. Misalnya, pada baris kode `cout << "Halo teman-teman!" << endl;`, proses dimulai dengan eksekusi ekspresi `cout << "Halo teman-teman!"` yang mengirimkan string tersebut ke objek cout untuk ditampilkan di layar. Setelah pengiriman selesai, operasi tersebut mengembalikan (return) referensi ke objek cout itu sendiri, sehingga secara logis baris kode yang tersisa menjadi `cout << endl;`. Objek endl kemudian dikirim ke objek cout yang baru saja dikembalikan tadi untuk membuat baris baru sekaligus melakukan flushing pada buffer.

Karena mekanisme tersebut, kita juga dapat menggunakannya secara berantai(chaining), misalnya :
```cpp
#include <iostream>
using namespace std;

int main(){
  cout<<"Halo"<<"teman-teman!"<<"Semangat!"<<endl;
  return 0;
}
```
Ketika dijalankan program tersebut akan menghasilkan output seperti ini :
```bash
Haloteman-teman!Semangat!
```
Perlu diperhatikan bahwa pada output di atas, kata-kata yang ditampilkan akan tercetak rapat tanpa adanya spasi karena cout hanya menampilkan karakter apa adanya sesuai dengan string yang diberikan.

### 3. `"Halo teman-teman!"` (String)
Bagian `"Halo teman-teman!"` merupakan sebuah string literal, yakni sekumpulan karakter yang ditulis langsung di antara tanda kutip (") dan digunakan untuk menyimpan teks.

Ketika kita menulis
```cpp
cout<<"Halo teman-teman!"<<endl;
```
Yang dikirim ke cout bukanlah teks secara langsung melainkan alamat dari data string tersebut ke memori. Data ini sudah disiapkan sejak proses kompilasi dalam bentuk array karakter yang diakhiri dengan null terminator (\0) seperti ini :
```bash
'H' 'a' 'l' 'o' '' 't'............'!' '\0'
```
cout akan membaca karakter tersebut satu per satu mulai dari alamat awal hingga menemukan \0 yang menandai akhir dari string. 

Dengan sudut pandang ini, string literal dapat dipahami sebagai sebuah array karakter yang disimpan di memori dan diakses melalui alamatnya. Namun, penting untuk digarisbawahi bahwa array ini memiliki sifat khusus yakni read-only sehingga tidak dapat diubah secara langsung. Hal ini bisa terjadi dikarenakan C++ secara otomatis menginisialisasikan string literal yang kita tulis menjadi data bertipe const char[] dan biasanya ditempatkan dia area memori yang dilindungi oleh sistem. jadi, jika kita mencoba melakukan hal seperti ini:
```cpp
char* pesan = "Halo"; 
pesan[0] = 'h'; // Percobaan mengubah 'H' menjadi 'h'
```
Maka program akan mengalami Runtime Error atau segmentation fault, karena sistem operasi melindungi area instruksi dan data konstan agar tidak dimodifikasi secara tidak sengaja, yang bisa menyebabkan perilaku program tidak terprediksi.

**Catatan :** Pembahasan string untuk saat ini masih terlalu dini, kita bisa mengabaikan dan melewatinya terlebih dahulu

### 4. `endl` (Endline)
endl adalah instruksi khusus yang memiliki dua tugas utama. Ia memerintahkan komputer untuk memindahkan kursor ke baris baru (seperti menekan tombol Enter di keyboard) serta melakukan flushing pada buffer, yaitu memastikan bahwa semua data yang tertunda benar-benar segera dikirim dan ditampilkan ke layar saat itu juga.

Untuk memahami endl secara lebih mendalam, kita perlu mengetahui bahwa terdapat berbagai cara lain dalam mengakhiri sebuah baris statement output. Diantaranya adalah menggunakan karakter newline (\n):
```cpp
cout<<"Halo teman-teman!\n";
```
Secara visual, kode tersebut memiliki hasil yang sama dengan program kita sebelumnya, dimana kursor akan berpindah ke baris baru setelah teks ditampilkan. Akan tetapi, secara internal terdapat perbedaan penting. \n hanya memindahkan kursor ke baris baru tanpa melakukan flush buffer. Artinya, dalam kondisi tertentu, output masih bisa tertahan sejenak sebelum benar-benar muncul di layar.

Di sisi lain, ada juga cara lain untuk mengakhiri statement dengan cara langsung menggunakan tanda titik koma seperti ini :
```cpp
cout<<"Halo teman-teman!;
```
Secara sintaks, kode tersebut sepenuhnya valid dan tidak menghasilkan error. Teks tetap akan ditampilkan tetapi kursor tidak berpindah ke baris baru, Akibatnya, jika kita menambahkan output berikutnya, misalnya seperti ini :
```cpp
cout<<"Halo teman-teman!;
cout<<"Apa Kabar?";
```
Hasil outputnya akan menjadi :
```bash
Halo teman-teman!Apa kabar?
```
Terlihat bahwa kedua output tersebut menyambung dalam 1 baris yang sama karena tidak ada instruksi yang memerintahkan kursor untuk pindah ke baris baru yang ada di bawahnya.

### 5. `;` (Tanda titik koma)
Jika kita perhatikan kembali statement utama kita yakni `cout<<"Halo teman-teman!"<<endl;`, bagian paling akhir dari baris tersebut adalah tanda titik koma (`;`).  Tanda ini berfungsi sebagai penanda akhir sebuah statement(Instruksi lengkap yang harus dijalankan oleh program). Dengan kata lain, tanda ini memberi tahu sistem bahwa "Instruksi ini telah selesai, silahkan lanjut ke instruksi berikutnya!"

---

## CATATAN TAMBAHAN
### Comment ( `//` dan `\*...*\` )
Comment adalah bagian dari kode yang tidak akan dijalankan oleh program, karena diabaikan sepenuhnya oleh compiler. Fungsinya bukan untuk komputer, melainkan untuk manusia—baik itu diri kita sendiri di masa depan maupun orang lain yang membaca kode kita.

Dalam C++, terdapat dua jenis comment yang umum digunakan. Untuk komentar satu baris kita bisa menggunakan `//` seperti ini :
```cpp
cout<<"Halo teman-teman!"<<endl; // menampilkan teks ke layar
```
Pada kode tersebut, segala sesuatu setelah tanda `//` pada baris tersebut tidak akan diproses oleh compiler

Sedangkan untuk komentar yang lebih panjang atau mencakup beberapa baris, kita bisa menggunakan `/*...*/` seperti ini :
```cpp
#include <iostream>
using namespace std;

/*
  Program ini digunakan untuk
  menampilkan teks sederhana
  ke layar
*/

int main(){
  cout<<"Halo teman-teman!"<<endl;
  return 0;
}
```




