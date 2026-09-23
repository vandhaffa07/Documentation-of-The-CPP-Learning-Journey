## STD STRING
Dalam C++, string dapat diartikan sebagai kumpulan karakter secara berurutan yang disimpan menggunakan array bertipe data character (char). Sedangkan `std::string` adalah sebuah objek kelas kontainer dari Standard Template Library (STL) yang membungkus array bertipe data character (char) tadi. Mekanisme pada `std::string` hampir sama seperti pada `std::array` yang berperan sebagai pembungkus array dengan tambahan-tambahan fitur yang canggih, perbedaan utamanya hanya terletak pada seberapa statis dan dinamis-nya array yang digunakan, dimana `std::string` merupakan pembungkus array yang bersifat dinamis (ukurannya dapat berubah secara otomatis saat program berjalan, meskipun di latar belakang ia menggunakan array biasa untuk menyimpan data).

---

## CARA MENGGUNAKAN STRING
Untuk menggunakan string kita wajib memasukkan library bernama string kedalam program kita menggunakan include seperti ini (khusunya pada c++ dengan versi yang lumayan lawas) :
```c++
#include <string>
```
Namun, dalam c++ modern atau compiler modern, library string biasanya dimasukkan secara otomatis pada library iostream sehingga tidak perlu menggunakan include string untuk program kita. Tapi, dalam tingkat profesional, penulisan include string tetap menjadi pilihan terbaik yang bisa dilakukan 

Berikut adalah contoh penggunaan `std:: string` :
```bash
nano penggunaan_string.cpp
```
```c++
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string teks1 = "Halo teman-teman";
    string teks2("Selamat pagi");
    
    cout << "teks1 : " << teks1 << endl;
    cout << "teks2 : " << teks2 << endl;

    return 0;
}
```
```bash
g++ penggunaan_string.cpp -o penggunaan_string
```
```bash
./penggunaan_string
teks1 : Halo teman-teman
teks2 : Selamat pagi
```
Dapat terlihat bahwa program benar-benar menampilkan output sesuai dengan yang kita inginkan. Dari output ini pula, kita dapat mengetahui bahwa string dapat didefinisikan menggunakan "=" (inisialisasi seperti pada umumnya) atau didalam tanda kurung "()".

---

## STRUKTUR STD STRING BEKERJA
Karena `std::string` merupakan kontainer pembungkus array, ia otomatis memiliki aturan-aturannya sendiri yang berbeda dari array biasa, khususnya pada bagian alokasi memori dan mekanisme kerjanya. 

Dalam `std::string`, compiler menyimpan setidaknya 3 variabel utama untuk dikelola:

### 1. Pointer karakter pertama
Compiler menyimpan sebuah pointer yang menunjuk langsung ke alamat memori karakter pertama pada string. Hal ini mirip seperti array biasa yang menyimpan informasi berupa base addres array (alamat indeks ke-0). Sebelumnya perlu diketahui bahwa `std::string` menggunakan heap secara otomatis untuk melakukan pengolahan memori, itulah sebabnya mengapa `std::string` dapat dilakukan penambahan atau pengurangan karakter menggunakan operator aritmatika sehingga bersifat dinamis.

Namun, penggunaan heap untuk melakukan pengolahan membutuhkan waktu yang lebih lama daripada ketika menggunakan stack. Oleh karena itu, C++ menggunakan mekanisme SSO (Small String Optimization). SSO sendiri merupakan teknik optimasi memori menggunakan stack yang digunakan C++ untuk mengolah string dengan jumlah karakter yang kecil (biasanya antara 15-23 karakter atau kurang). Dengan menggunakan SSO yang menggunakan stack sebagai tempat memorinya, pengolahan string dapat dilakukan dengan performa yang lebih cepat dan ringan.

Untuk membuktikannya, kita dapat menjalankan program seperti ini :
```bash
nano test_string.cpp
```
```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string short_str = "Halo";
    cout << "Isi string pendek: " << short_str << "\n";

    short_str += " C++";
    cout << "Isi string pendek baru : " << short_str << "\n";

    string long_str = "Ini adalah teks yang sangat panjang sekali dan pasti melewati batas Small String Optimization!";
    cout << "Isi string panjang: " << long_str << "\n\n";

    cout << "Alamat objek short_str : " << (void*)&short_str << "\n";
    cout << "Alamat elemen pertama short_str : " << (void*)short_str.data() << "\n";
    cout << "Alamat objek long_str : " << (void*)&long_str << "\n";
    cout << "Alamat data long_str : " << (void*)long_str.data() << "\n";

    return 0;
}
```
```bash
g++ test_string.cpp -o test_string
```
```bash
./test_string
Isi string pendek : Halo
Isi string pendek baru : Halo C++
Isi string panjang : Ini adalah teks yang sangat panjang sekali dan pasti melewati batas Small String Optimization!

Alamat objek short_str : 0x7ffe2a6e4d50
Alamat elemen pertama short_str : 0x7ffe2a6e4d60
Alamat objek long_str : 0x7ffe2a6e4d30
Alamat elemen pertama long_str : 0x596a557707d30
```
Sebelumnya, perlu diketahui bahwa alamat objek dan alamat elemen pertama dari `std::string` merupakan dua hal yang berbeda. Alamat objek merupakan alamat yang merujuk pada objek pembungkus dari string yang dideklarasikan/diinisialisasikan, objek pembungkus ini tidak lain dan tidak bukan adalah `std::string` itu sendiri yang membungkus suatu array karakter. Alamat objek menggunakan bagian memori stack sebagai tempat alokasinya, hal ini dapat dilihat melalui output alamat dari objek bernama `short_str` dan `long_str` pada program diatas, dimana mereka berdua sama-sama memiliki alamat dengan format `0x7ff....` yang merupakan ciri khas dari alamat yang berada pada arsitektur stack. 

Sedangkan alamat dari elemen pertama merujuk pada lokasi fisik tempat karakter pertama pada suatu string disimpan (merujuk pada array karakternya, bukan objek yang membungkusnya). Alamat ini dapat menggunakan bagian memori stack maupun heap tergantung dengan panjang stringnya. Jika panjang string telah melewati batas karakter maksimal dari mekanisme SSO, maka ia akan dialokasikan di stack, sedangkan jika belum melewati batas karakter maksimal dari mekanisme SSO, maka ia akan dialokasikan di heap. Sebagai contoh, output alamat dari elemen pertama `short_str` pada program diatas memiliki format `0x7ff....`, dimana format ini merupakan format yang sama seperti pada output-output sebelumnya yang dialokasikan pada bagaian memori stack. Hal ini disebabkan karena jumlah karakter pada `short_str` hanyalah sebesar 8 karakter yang secara aturan, ia belum melewati batas karakter maksimal dari mekanisme SSO. Sedangkan pada alamat elemen pertama `long_str`, jumlah karakternya melebihi angka 23 yang secara aturan melewati batas karakter maksimal SSO. Hal inilah membuat ia dialokasikan di heap secara otomatis. Sebagai bukti konkret, dapat terlihat bahwa format alamat elemen pertama `long_str` sangat-sangat berbeda dengan alamat pada output-output sebelumnya, dimana alamat dari elemen pertama `long_str` ini memiliki format `0x59....` bukan `0x7ff`, sehingga dapat disimpulkan bahwa ia benar-benar dialokasikan di bagian memori heap.

Sebagai catatan tambahan, penggunaan `(void*)` memiliki fungsi untuk mencegah `cout` menganggap data tersebut sebagai teks. Sebab, dalam C++, `cout` mempunyai perlakuan khusus untuk pointer bertipe `char*` seperti string, dimana ketika kita memberikan variabel bertipe `char*` ke `cout` melalui operator `<<`, `cout` akan membaca isi teksnya sampai ia bertemu dengan karakter null-terminator (\0) meskipun sudah ditambahkan notasi & pada awal variabel. Penggunaan `(void*)` digunakan supaya `cout` menganggap data tersebut sebagai suatu pointer sehingga bisa menampilkan alamatnya.

### 2. Ukuran/Panjang String
Compiler menyimpan jumlah karakter yang digunakan pada saat ini. Jumlah ini memiliki sifat yang dinamis atau dapat berubah-ubah pada saat program berjalan sesuai dengan instruksi yang dapat menambah atau menguranginya. Sebagai contoh, ketika kita memiliki string "Halo", maka compiler akan menyimpan angka 4 sebagai ukuran dari string tersebut (karena kata "Halo" memiliki total sebanyak 4 karakter). Lalu, ketika kita menggunakan notasi `+= " Dunia"`, maka compiler akan memperbarui angka 4 menjadi 10 sebagai ukuran dari string tersebut (karena kata "Halo Dunia" memiliki total sebanyak 10 karakter).

### 3. Kapasitas
Tidak hanya menyimpan ukuran dari string, compiler juga menyimpan kapasitas dari string tersebut. Dalam konteks c++, kapasitas dapat diartikan total alokasi memori yang tersedia sebelum string harus merealokasi memori baru. Jadi, ketika kita memiliki string "Halo" misalnya, compiler sebenarnya tidak mengalokasikan memori dengan jumlah 4 byte (4 karakter) yang notabenenya merupakan jumlah karakter dari string "Halo" tersebut, melainkan mengalokasikan 15 byte (umumnya). Angka 15 inilah yang kemudian disimpan oleh compiler sebagai kapasitas. Menariknya, ketika kita menambahkan beberapa karakter pada string tersebut menggunakan notasi `+` atau `+=` tetapi ukurannya tidak melebihi 15 karakter (kapasitasnya), maka nilai kapasitasnya masih tetap 15. Sedangkan jika kita menambahkan beberapa karakter sehingga totalnya melebihi kapasitasnya saat itu (sampai 16 karakter misalnya), maka nilai kapasitas akan diperbarui menjadi dua kali lipat dari nilai sebelumnya, yang pada kasus ini nilai kapasitas akan diperbarui menjadi 30 (2x15). Mekanisme ini digunakan untuk mempersingkat dan mengefisienkan alokasi memori pada heap yang membutuhkan waktu lama. Dimana, jika `std::string` hanya mengalokasikan memori secara pas sesuai dengan ukurannya pada saat itu, maka setiap kali kita menambahkan beberapa karakter baru, komputer harus mencari blok memori baru yang kosong dan cukup pada heap, kemudian menyalin seluruh karakter lama ke memori baru tersebut, menambahkan karakter yang baru ke memori baru tersebut, dan menghapus lokasi memori yang lama. Langkah-langkah tersebut sangat lambat dan memerlukan waktu yang cukup lama hanya untuk melakukan penambahan karakter. Oleh karena itu, mekanisme ini digunakan agar setiap kali dilakukan penambahan karakter, komputer tidak terus-terusan melakukan langkah-langkah tadi, melainkan hanya menyesuaikan nilai kapasitasnya. 








