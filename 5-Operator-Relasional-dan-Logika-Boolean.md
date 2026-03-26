# OPERATOR RELASIONAL DAN BOOLEAN
Setelah kita berhasil memanipulasi data menggunakan operasi aritmatika, pada pembahasan kali ini, kita akan mempelajari bagaimana cara membandingkan/mengkomparasi dua buah data dengan menggunakan operator relasional (operator perbandingan) dan konsep boolean. Operator relasional adalah simbol yang digunakan untuk membandingkan dua buah nilai atau operan guna menentukan hubungan di antara keduanya. Sedangkan boolean adalah tipe data dasar dalam pemrograman dan logika komputer yang hanya memiliki dua kemungkinan nilai yakni true(benar) atau false(salah). Operator relasional sendiri, akan mengembalikan nilai boolean ketika telah seesai melakukan komparasi pada dua buah operan. Perlu diketahui bahwa di level arsitektur memori dan saat ditampilkan ke terminal, true direpresentasikan sebagai angka 1 dan false direpresentasikan sebagai angka 0. Hal ini terjadi karena komputer hanya memahami bit angka 0 dan 1 sebagai biner.

---

## SIMBOL-SIMBOL OPERATOR RELASIONAL
### 1. `==` (Equal)
Operator ini digunakan untuk menguji apakah dua buah operan yang sedang dibandingkan memiliki nilai yang sama/identik. Perlu diperhatikan bahwa simbol `==`(Comparation) berbeda dengan simbol `=`(Assigment) walaupun secara visual mereka mirip. Operator tunggal `=`(Assigment) digunakan untuk memasukkan atau menyalin nilai dari sisi kanan ke dalam variabel yang berada di sisi kirinya. Tindakan ini merupakan salah satu bentuk dari modifikasi memori karena variabel kiri sekarang memiliki nilai yang sepenuhnya baru. Sedangkan, operator ganda `==`(Comparation) secara khusus hanya digunakan untuk membandingkan apakah nilai dari kedua sisi adalah identik. Tindakan ini secara langsung tidak memodifikasi memori karena ia hanya melakukan observasi/pengecekan.

### 2. `!=` (Not Equal)
Operator ini adalah kebalikan logis dari operator `==`. Simbol `!=` digunakan untuk menguji apakah dua buah operan memiliki nilai yang tidak sama atau berbeda. Jika nilai di sisi kiri tidak identik dengan nilai di sisi kanan, maka operasi ini akan menghasilkan nilai boolean true (1). Sebaliknya, jika kedua nilainya sama, maka hasilnya adalah false (0).

### 3. `>` (Greather Than)
Operator ini digunakan untuk mengevaluasi apakah operan di sisi kiri memiliki nilai yang secara numerik lebih tinggi daripada operan di sisi kanan. Penting untuk diingat bahwa operator ini bersifat eksklusif, artinya jika kedua nilai yang dibandingkan adalah sama (misalnya: `5 > 5`), maka hasil yang dikembalikan adalah false (0) karena 5 tidaklah lebih besar dari dirinya sendiri.

### 4. `<` (Less Than)
Kebalikan dari operator sebelumnya, operator ini digunakan untuk mengecek apakah operan di sisi kiri memiliki nilai yang lebih kecil dibandingkan operan di sisi kanan. Operator ini juga bersifat eksklusif.

### 5. `>=` (Greater Than or Equal To)
Berbeda dengan operator `>` yang bersifat eksklusif, operator ini bersifat inklusif. Operator ini akan menghasilkan nilai true (1) jika operan kiri lebih besar atau tepat sama dengan operan kanan. Secara teknis, operator ini merupakan gabungan dari dua pengujian logis (Greather Than dan Equal to). Sebagai contoh, ekspresi `5 >= 5` akan bernilai true (1), karena syarat sama dengan telah terpenuhi.

### 6. <= (Less Than or Equal To)
Operator ini akan menghasilkan nilai true (1) jika nilai di sisi kiri lebih kecil atau identik dengan nilai di sisi kanan












