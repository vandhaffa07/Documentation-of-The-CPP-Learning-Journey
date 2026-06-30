## ARRAY STANDARD LIBRARY DAN FILE HEADER
Pada file sebelumnya, kita telah mempelajari karakteristik dan mekanisme yang terjadi di dalam array tradisional C++. Namun sebenarnya, array tradisional ini masih memiliki banyak kekurangan, seperti tidak tahu ukurannya sendiri, tidak memiliki sistem proteksi terhadap kebocoran memori (Buffer Overflow), dan kekurangan-kekurangan lainnya tetutama pada kemampuannya untuk melakukan manipulasi elemen.

Untuk mengatasi kelemahan-kelemahan tersebut tanpa mengorbankan performa kecepatan low-level dari array tradisional, C++ modern memperkenalkan pembungkus pintar bernama `std::array`. 

`std::array` adalah kontainer berukuran tetap yang disediakan oleh Standard Template Library (STL) C++ sebagai pembungkus di sekitar array tradisional sambil menyediakan fungsionalitas tambahan. Dengan `std::array`, kita bisa mendapatkan performa kecepatan yang sama persis dengan array tradisional, namun dipersenjatai dengan fitur-fitur canggih seperti pengecekan batas memori, pencarian ukuran otomatis, dan iterator. 

**Catatan : Untuk saat ini, kita dapat menghiraukan STL, Kontainer, dan Sejenisnya. Kita akan mempelajari file yang akan datang**

