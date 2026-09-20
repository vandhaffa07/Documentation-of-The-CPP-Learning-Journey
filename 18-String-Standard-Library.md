## STD STRING
Dalam C++, string dapat diartikan sebagai kumpulan karakter secara berurutan yang disimpan menggunakan array bertipe data character (char). Sedangkan `std::string` adalah sebuah objek kelas kontainer dari Standard Template Library (STL) yang membungkus array bertipe data character (char) tadi. Mekanisme pada `std::string` hampir sama seperti pada `std::array` yang berperan sebagai pembungkus array dengan tambahan-tambahan fitur yang canggih, perbedaan utamanya hanya terletak pada seberapa statis dan dinamis-nya array yang digunakan, dimana `std::string` merupakan pembungkus array yang bersifat dinamis (ukurannya dapat berubah secara otomatis saat program berjalan, meskipun di latar belakang ia menggunakan array biasa untuk menyimpan data).

---

## CARA MENGGUNAKAN STRING
Untuk menggunakan string kita wajib memasukkan library bernama string kedalam program kita menggunakan include seperti ini (khusunya pada c++ dengan versi yang lumayan lawas) :
```c++
#include <string>
```
Namun, dalam c++ modern atau compiler modern, library string biasanya dimasukkan secara otomatis pada iostream sehingga tidak perlu menggunakan include string untuk program kita. Tapi, dalam tingkat profesional 

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


