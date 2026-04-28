# PEMROGRAMAN STOKASTIK
Pada dasarnya, komputer (CPU) adalah mesin logika yang kaku, dimana komponen-komponennya bekerja sesuai dengan tugasnya masing-masing dengan keteraturan yang sangat presisi. Ia memang diprogram untuk mengerjakan tugas-tugas kompleks yang hampir tidak mungkin untuk dikerjakan oleh manusia, ataupun bisa dikerjakan oleh manusai tetapi membutuhkan waktu yang sangat lama dan tenaga yang sangat besar. Lantas pertanyaannya, apakah kita bisa menghasilkan sesuatu yang acak (random) dari mesin yang sangat teratur ini?

Jawabannya bisa.... Tetapi hanya terlihat acak, bukan benar-benar acak. Hal ini dikarenakan mekanisme komputer (CPU) yang hanya bekerja sesuai dengan program/instruksi yang telah dibuatkan untuknya. Program/instruksi ini, sangat erat kaitannya dengan algoritma, serangkaian langkah logis, terurut, dan sistematis yang disusun untuk menyelesaikan masalah atau mencapai tujuan tertentu. Algoritma lah jantung sebenarnya dari proses-proses kompleks yang dapat dilakukan oleh komputer (CPU).

Untuk menghasilkan sesuatu yang acak sebenarnya juga membutuhkan algoritma, ambil contoh angka acak. Untuk menghasilkannya, dibutuhkan algoritma matematis bernama Pseudo Random Number Generator (PRNG). Ini berarti, angka yang sebenarnya dihasilkan tidak benar-benar acak secara fisik, melainkan hasil kalkulasi matematika yang sangat kompleks sehingga terlihat acak bagi manusia. Asalkan kita mengetahui persamaan matematis yang digunakan untuk algoritmanya, kita sebenarnya juga bisa menebak dan memprediksi angka yang akan dihasilkan berikutnya.

Pada file ini, kita akan membahas secara lengkap sebuah konsep pemrograman yang mengandung unsur keacakan (probabilistik) dan ketidakpastian atau yang biasa disebut sebagai pemrograman stokastik.

---

## FUNDAMENTAL LIBRARY 
Sebelum memahami lebih lanjut tentang pemrograman stokastik, kita perlu mengetahui bahwa terdapat dua library yang dapat mendukung, yakni cstdlib dan ctime. Kedua library ini dinilai ideal karena mengandung fungsi-fungsi yang memiliki unsur keacakan dan ketidakpastian.




