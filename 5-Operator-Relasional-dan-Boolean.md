# OPERATOR RELASIONAL DAN BOOLEAN
Setelah kita berhasil memanipulasi data menggunakan operasi aritmatika, pada pembahasan kali ini, kita akan mempelajari bagaimana cara membandingkan/mengkomparasi dua buah data dengan menggunakan operator relasional (operator perbandingan) dan konsep boolean. Operator relasional adalah simbol yang digunakan untuk membandingkan dua buah nilai atau operan guna menentukan hubungan di antara keduanya. Sedangkan boolean adalah tipe data dasar dalam pemrograman dan logika komputer yang hanya memiliki dua kemungkinan nilai yakni true(benar) atau false(salah). Operator relasional sendiri, akan mengembalikan nilai boolean ketika telah seesai melakukan komparasi pada dua buah operan. Perlu diketahui bahwa di level arsitektur memori dan saat ditampilkan ke terminal, true direpresentasikan sebagai angka 1 dan false direpresentasikan sebagai angka 0. Hal ini terjadi karena komputer hanya memahami bit angka 0 dan 1 sebagai biner.

---

## SIMBOL-SIMBOL OPERATOR RELASIONAL
### 1. `==` (Equal)
Operator ini digunakan untuk menguji apakah dua buah operan yang sedang dibandingkan memiliki nilai yang sama/identik. Perlu diperhatikan bahwa simbol `==`(Comparation) berbeda dengan simbol `=`(Assigment) walaupun secara visual mereka mirip. Operator tunggal `=`(Assigment) digunakan untuk memasukkan atau menyalin nilai dari sisi kanan ke dalam variabel yang berada di sisi kirinya. Tindakan ini merupakan salah satu bentuk dari modifikasi memori karena variabel kiri sekarang memiliki nilai yang sepenuhnya baru. Sedangkan, operator ganda `==`(Comparation) secara khusus hanya digunakan untuk membandingkan apakah nilai dari kedua sisi adalah identik. Tindakan ini secara langsung tidak memodifikasi memori karena ia hanya melakukan observasi/pengecekan.

Untuk memperjelas hal tersebut, Mari kita buat eksperimen yang menunjukkan bagaimana salah ketik satu karakter saja bisa merusak logika program yang telah kita buat.
```Bash
nano eksperimen.cpp
```
```C++
#include <iostream>
using namespace std;

int main() {
    int angka = 10;
    
    // Skenario 1: Menggunakan perbandingan yang benar (==)
    cout << "Apakah angka == 50? Hasil: " << (angka == 50) << endl;
    cout << "Nilai angka sekarang: " << angka << endl; 

    cout << "---------------------------------" << endl;

    // Skenario 2: Salah ketik menggunakan penugasan (=) di dalam cout
    cout << "Apakah angka = 50?  Hasil: " << (angka = 50) << endl;
    cout << "Nilai angka sekarang: " << angka << endl; 

    return 0;
}
```
```bash
g++ eksperimen.cpp -o eksperimen
```
```bash
./eksperimen
Apakah angka == 50? Hasil: 0
Nilai angka sekarang: 10
---------------------------------
Apakah angka = 50?  Hasil: 50
Nilai angka sekarang: 50
```
Perhatikan bahwa pada Skenario 1, komputer melakukan komparasi dengan memeriksa apakah isi variabel angka (yaitu 10) sama dengan 50? Karena jawabannya adalah tidak, maka operasi ini mengembalikan nilai 0 (false). Nilai variabel angka juga tetap terjaga di angka 10 yang berarti memori tidak berubah sedikit pun, sehingga untuk skenario 1 tidak ada yang dipermasalahkan. Sedangkan pada skenario 2, terjadi anomali yang berbahaya. Alih-alih melakukan komparasi, komputer justru melakukan instruksi penugasan di dalam perintah cetak. Angka 50 dipaksa masuk ke dalam variabel angka dengan menimpa nilai 10 yang ada sebelumnya. Akibatnya, cout tidak lagi menampilkan hasil perbandingan (0 atau 1), melainkan menampilkan nilai yang baru saja dimasukkan, yaitu 50. Lebih buruk lagi, variabel angka sekarang secara permanen berubah menjadi 50 untuk baris kode selanjutnya.

### 2. `!=` (Not Equal)
Operator ini adalah kebalikan logis dari operator `==`. Simbol `!=` digunakan untuk menguji apakah dua buah operan memiliki nilai yang tidak sama atau berbeda. Jika nilai di sisi kiri tidak identik dengan nilai di sisi kanan, maka operasi ini akan menghasilkan nilai boolean true (1). Sebaliknya, jika kedua nilainya sama, maka hasilnya adalah false (0). Karakteristik ini sangat berguna ketika kita ingin melakukan validasi, misalnya untuk memastikan bahwa sebuah input tidak kosong atau untuk mendeteksi adanya anomali data.

Untuk melihat bagaimana operator ini bekerja dalam membedakan identitas data, mari kita coba bandingkan dua buah variabel yang memiliki nilai yang sengaja kita buat berbeda :

```Bash
nano not_equal.cpp
```
```c++
#include <iostream>
using namespace std;

int main() {
    int kode_akses = 1234;
    int input_user = 5678;

    cout << "Apakah input salah? Hasil: " << (input_user != kode_akses) << endl;

    return 0;
}
```
```Bash
g++ not_equal.cpp -o not_equal
```
```bash
./not_equal
Apakah input salah? Hasil: 1
```
Hasil output 1 mengonfirmasi bahwa operan di kiri memang tidak sama dengan operan di kanan. Hal ini membuktikan bahwa operator != berhasil mendeteksi ketidaksesuaian antara 1234 dan 5678, sehingga memberikan sinyal benar (true) atas pernyataan tidak sama tersebut.

### 3. `>` (Greather Than)
Operator ini digunakan untuk mengevaluasi apakah operan di sisi kiri memiliki nilai yang secara numerik lebih tinggi daripada operan di sisi kanan. Penting untuk diingat bahwa operator ini bersifat eksklusif, artinya jika kedua nilai yang dibandingkan adalah sama (misalnya: `5 > 5`), maka hasil yang dikembalikan adalah false (0) karena 5 tidaklah lebih besar dari dirinya sendiri. Sifat eksklusif ini sering kali menjadi penentu dalam logika batas atas, di mana angka batas itu sendiri tidak boleh ikut masuk ke dalam kategori.

Mari kita simulasikan pengecekan skor dalam sebuah permainan untuk memahami sifat eksklusivitas ini lebih dalam.
```Bash
nano greater.cpp
```
```c++
#include <iostream>
using namespace std;

int main() {
    int skor_minimal = 100;
    int skor_pemain = 100;

    // Menguji apakah 100 > 100
    cout << "Apakah skor melampaui batas? Hasil: " << (skor_pemain > skor_minimal) << endl;

    return 0;
}
```
```Bash
g++ greater.cpp -o greater
```
```bash
./greater
Apakah skor melampaui batas? Hasil: 0
```
Walaupun secara visual angka yang dibandingkan tampak sama, program tetap memberikan hasil 0. Ini mempertegas teori bahwa operator > hanya akan memberikan nilai 1 jika operan kiri benar-benar memiliki nilai yang lebih tinggi. Karena 100 tidak melampaui 100, maka kondisi tersebut dianggap salah secara matematis di dalam C++.

### 4. `<` (Less Than)
Kebalikan dari operator sebelumnya, operator ini digunakan untuk mengecek apakah operan di sisi kiri memiliki nilai yang lebih kecil dibandingkan operan di sisi kanan. Sama seperti saudaranya, operator ini juga bersifat eksklusif, yang berarti ia hanya akan memvalidasi nilai yang benar-benar berada di bawah target yang ditentukan.

Penerapan operator ini bisa kita amati melalui pengecekan kapasitas penyimpanan sederhana berikut ini.

```Bash
nano less.cpp
```
```c++
#include <iostream>
using namespace std;

int main() {
    double kapasitas_maks = 50.5;
    double penggunaan_saat_ini = 49.9;

    // Menguji apakah penggunaan di bawah kapasitas
    cout << "Kapasitas aman? Hasil: " << (penggunaan_saat_ini < kapasitas_maks) << endl;

    return 0;
}
```
```Bash
g++ less.cpp -o less
```
```bash
./less
Kapasitas aman? Hasil: 1
```
Melalui output tersebut, terlihat bahwa 49.9 terdeteksi lebih kecil dari 50.5. Penggunaan tipe data double di sini juga membuktikan bahwa operator relasional tetap konsisten bekerja pada bilangan desimal selama perbandingannya dilakukan secara numerik.

### 5. `>=` (Greater Than or Equal To)
Berbeda dengan operator > yang bersifat eksklusif, operator ini bersifat inklusif. Operator ini akan menghasilkan nilai true (1) jika operan kiri lebih besar atau tepat sama dengan operan kanan. Secara teknis, operator ini merupakan gabungan dari dua pengujian logis (Greater Than dan Equal to). Sifat inklusif ini sangat krusial dalam menentukan syarat minimal, seperti syarat kelulusan atau syarat usia.

Kita bisa melihat perbedaan nyata dengan operator eksklusif sebelumnya melalui perbandingan angka yang identik pada kode berikut.
```Bash
nano greater_equal.cpp
```
```c++
#include <iostream>
using namespace std;

int main() {
    int syarat_lulus = 75;
    int nilai_akhir = 75;

    // Menguji apakah 75 >= 75
    cout << "Apakah lulus? Hasil: " << (nilai_akhir >= syarat_lulus) << endl;

    return 0;
}
```
```Bash
g++ greater_equal.cpp -o greater_equal
```
```bash
./greater_equal
Apakah lulus? Hasil: 1
```
Jika sebelumnya 100 > 100 menghasilkan 0, maka di sini 75 >= 75 menghasilkan 1. Hal ini terjadi karena operator >= menyertakan kondisi sama dengan ke dalam logikanya, sehingga selama nilai kiri tidak lebih kecil dari nilai kanan, hasilnya akan selalu benar.

### 6. <= (Less Than or Equal To)
Operator ini akan menghasilkan nilai true (1) jika nilai di sisi kiri lebih kecil atau identik dengan nilai di sisi kanan. Sama seperti operator >= sebelumnya, simbol ini bersifat inklusif dan sering digunakan sebagai batas aman maksimal dalam sebuah sistem.

Mari kita perhatikan bagaimana operator ini menangani batas maksimum pada sebuah variabel.

```Bash
nano less_equal.cpp
```
```c++
#include <iostream>
using namespace std;

int main() {
    int batas_kecepatan = 80;
    int kecepatan_sekarang = 80;

    // Menguji apakah 80 <= 80
    cout << "Masih dalam batas aman? Hasil: " << (kecepatan_sekarang <= batas_kecepatan) << endl;

    return 0;
}
```
```Bash
g++ less_equal.cpp -o less_equal
```
```bash
./less_equal
Masih dalam batas aman? Hasil: 1
```
Hasil 1 menunjukkan bahwa nilai 80 masih dianggap memenuhi syarat kurang dari atau sama dengan 80. 

---

## ATURAN PRIORITAS (OPERATOR PRECEDENCE)
Setelah kita membedah seluruh simbol relasional, ada satu detail teknis yang sangat krusial untuk dipahami agar kita tidak terjebak dalam error kompilasi saat menulis instruksi cetak (cout). Dalam C++, setiap operator memiliki tingkatan kasta atau prioritas eksekusi. Operator aritmatika (+, -, *, /) memiliki kasta yang lebih tinggi daripada operator relasional (==, !=, <, >). Namun, operator stream insertion (<<) milik cout ternyata memiliki prioritas yang tinggi pula, yang juga lebih tinggi daripada operator relasional.

Mari kita perhatikan apa yang terjadi jika kita tidak menggunakan tanda kurung saat melakukan komparasi di dalam cout:
```bash
nano testing.cpp
```
```c++
#include <iostream>
using namespace std;

int main() {
        int angka = 5;
        cout<< angka==10 << endl;

        return 0;
}
```
```bash
g++ testing.cpp -o testing
```
```bash
./testing
error: invalid operands of types ‘int’ and ‘<unresolved overloaded function type>’ to binary ‘operator<<’
```
Penyebab error di atas adalah karena komputer mencoba mengeksekusi cout << angka terlebih dahulu. Setelah nilai variabel angka dicetak, komputer kemudian mencoba membandingkan objek cout tersebut dengan angka 10. Karena cout bukanlah sebuah angka numerik, maka compiler akan bingung dan melemparkan pesan error karena tidak bisa membandingkan dua tipe data yang berbeda jauh. Itulah alasan teknis mengapa setiap kali kita melakukan operasi relasional di dalam perintah cout, kita wajib membungkusnya dengan tanda kurung agar operasi perbandingan diselesaikan terlebih dahulu sebelum hasilnya dikirim ke layar.







