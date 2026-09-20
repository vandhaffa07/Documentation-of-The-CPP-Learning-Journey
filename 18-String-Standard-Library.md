## STD STRING
Dalam C++, string dapat diartikan sebagai kumpulan karakter secara berurutan yang disimpan menggunakan array bertipe data character (char). Sedangkan `std::string` adalah sebuah objek kelas kontainer dari Standard Template Library (STL) yang membungkus array bertipe data character (char) tadi. Mekanisme pada `std::string` hampir sama seperti pada `std::array` yang berperan sebagai pembungkus array dengan tambahan-tambahan fitur yang canggih, perbedaan utamanya hanya terletak pada seberapa statis dan dinamis-nya array yang digunakan, dimana `std::string` merupakan pembungkus array yang bersifat dinamis (ukurannya dapat berubah secara otomatis saat program berjalan, meskipun di latar belakang ia menggunakan array biasa untuk menyimpan data).

---

## STRUKTUR STD STRING BEKERJA
Karena `std::string` merupakan kontainer pembungkus array, ia otomatis memiliki aturan-aturannya sendiri yang berbeda dari array biasa, khususnya pada bagian alokasi memori dan mekanisme kerjanya. 

Dalam `std::string`, compiler menyimpan setidaknya 3 variabel utama untuk dikelola:

### 1. Pointer karakter pertama
Compiler menyimpan sebuah pointer yang menunjuk langsung ke alamat memori karakter pertama pada string. Hal ini sama mirip seperti array biasa yang menyimpan informasi berupa base addres array (alamat elemen pertama). Sebelumnya perlu diketahui bahwa `std::string` menggunakan heap untuk melakukan pengolahan memori, itulah sebabnya mengapa dapat dilakukan penambahan karakter pada std 
