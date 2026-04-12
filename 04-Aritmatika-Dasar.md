# ARITMATIKA DASAR
Setelah memahami mekanisme variabel dalam menyimpan data dan cara mengambil input dari pengguna. Pada pembahasan kali ini kita akan mempelajari bagaimana cara agar kita bisa mengolah data tersebut dengan menggunakan operasi aritmatika. Aritmatika adalah salah satu cabang ilmu dalam matematika yang mempelajari operasi hitung dasar dari suatu bilangan, baik bilangan bulat maupun bilangan pecahan/desimal, baik bilangan positif maupun pula bilangan negatif. Dalam konteks pemrograman, aritmatika berfungsi sebagai logika dasar yang mentransformasikan variabel-variabel statis menjadi informasi yang dinamis melalui operasi aritmatika yang meliputi penjumlahan, pengurangan, perkalian, pembagian, hingga modulus. Hubungan ini sangat krusial karena hampir setiap instruksi dalam kode, mulai dari menghitung skor dalam sebuah permainan, menentukan tata letak elemen pada layar, hingga mengatur alur perulangan algoritma, bergantung pada kalkulasi aritmatika.

---

## OPERATOR ARITMATIKA DASAR
Dalam pemrograman, operator aritmatika dasar adalah simbol yang digunakan untuk melakukan perhitungan aritmatika (penjumlahan, pengurangan, perkalian, pembagian, dan modulus) pada suatu nilai numerik atau variabel. C++ sendiri, telah menyediakan operator seperti ini yang mungkin terasa sangat familiar bagi kita. Operator ini meliputi :
- `+` : Penjumlahan

- `-` : Pengurangan

- `*` : Perkalian

- `/` : Pembagian

- `%` : Modulo (Sisa Bagi)

Mari kita lihat bagaimana operator ini bekerja dalam sebuah program sederhana:
```bash
nano aritmatika.cpp
```
```C++
#include <iostream>
using namespace std;

int main() {
    int a = 10; //Inisialisasi Variabel
    int b = 3;  //Inisialisasi Variabel  

    cout << "Penjumlahan: " << a + b << endl;
    cout << "Pengurangan: " << a - b << endl;
    cout << "Perkalian:   " << a * b << endl;
    cout << "Pembagian:   " << a / b << endl;
    cout << "Modulo:      " << a % b << endl;

    return 0;
}
```
program diatas bekerja dengan cara mengambil 2 nilai yang sudah diinisialisasi dalam variabel a dan b yakni 10 dan 3. Saat kita menuliskan perintah `cout << operasi_aritmatika`, CPU akan melakukan proses kalkulasi di dalam register (unit pemroses terkecil di CPU) yang kemudian hasilnya dikirimkan kembali ke instruksi cout untuk dicetak ke layar. Penting untuk diketauhui bahwa operasi aritmatika ini tidak mengubah nilai asli dari variabel a maupun b. Mereka hanya dipinjam nilainya untuk dikalkulasikan. 

Selanjutnya, saya akan melakukan proses kompilasi pada file program tersebut dan menjalankannya :
```Bash
g++ aritmatika.cpp -o aritmatika
```
```bash
./aritmatika
Penjumlahan: 13
Pengurangan: 7
Perkalian:   30
Pembagian:   3
Modulo:      1
```
Jika kita perhatikan kembali output di atas, ada salah satu hasil yang mungkin terlihat aneh jika dilihat dari sudut pandang matematika teoritis, yakni pada output pembagian. Secara matematis, $\frac{10}{3}$ seharusnya memiliki nilai yang sama dengan $3,33333....$ namun program malah menampilkan angka $3$. Mengapa hal ini bisa terjadi?

Untuk menjawab hal tersebut, kita dapat kembali ke konsep tipe data yang telah kita bahas pada file sebelumnya. Karena a dan b dideklarasikan sebagai integer(bilangan bulat), maka C++ secara otomatis akan melakukan pembagian dengan aturan bilangan bulat pula. Dalam kasus ini, compiler secara paksa akan membuang semua angka di belakang koma untuk menyesuaikan hasilnya ke dalam format integer. Jika kita membutuhkan hasil yang presisi dan akurat, kita harus mengubah salah satu atau kedua variabel tersebut menjadi bertipe float atau double. Karena, hal tersebut memicu C++ untuk melakukan type promotion, yakni pengkonversian tipe data yang lebih kecil menjadi tipe data yang lebih besar sebelum operasi dilakukan. Sebagai contoh, mari kita ubah tipe data variabel b menjadi double :
```bash
nano aritmatika.cpp
```
```C++
#include <iostream>
using namespace std;

int main() {
    int a = 10; //Inisialisasi Variabel
    double b = 3;  //Inisialisasi Variabel (Diubah) 

    cout << "Penjumlahan: " << a + b << endl;
    cout << "Pengurangan: " << a - b << endl;
    cout << "Perkalian:   " << a * b << endl;
    cout << "Pembagian:   " << a / b << endl;
    cout << "Modulo:      " << a % b << endl;

    return 0;
}
```
```Bash
g++ aritmatika.cpp -o aritmatika
error: invalid operands of types ‘int’ and ‘double’ to binary ‘operator%’
```
Dapat terlihat bahwa ketika kita mencoba melakukan kompilasi setelah mengubah tipe data variabel b menjadi double, compiler justru melemparkan pesan `error: invalid operands of types ‘int’ and ‘double’ to binary ‘operator%’`. Fenomena ini terjadi karena operator modulo (%) di dalam C++ secara ketat hanya menerima variabel jika keduanya bertipe bilangan bulat (Integer). Tidak seperti penjumlahan atau pembagian yang bisa mengonversi tipe data secara otomatis, modulo dirancang untuk bekerja pada tingkat pembagian Euclid yang hanya berlaku untuk bilangan bulat. Namun, sebelum membahas hal ini lebih lanjut, mari kita fokuskan tujuan simulasi awal kita yang ingin membuktikan bahwa teori Type Promotion pada pembagian tadi benar, maka kita harus melakukan troubleshoot sederhana dengan cara menghapus baris modulo tersebut sementara agar program bisa dikompilasi:
```Bash
nano aritmatika.cpp
```
```c++
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    double b = 3;

    cout << "Penjumlahan: " << a + b << endl;
    cout << "Pengurangan: " << a - b << endl;
    cout << "Perkalian:   " << a * b << endl;
    cout << "Pembagian:   " << a / b << endl;

    return 0;
}
```
```Bash
g++ aritmatika.cpp -o aritmatika
```
```bash
./aritmatika
Penjumlahan: 13
Pengurangan: 7
Perkalian:   30
Pembagian:   3.33333
```
Terbukti! terlihat bahwa setelah baris modulo dihapus, program berjalan dengan lancar dan hasil pembagian telah menjadi 3.33333 sesuai dengan sudut pandang matematika teoritis. Ini terjadi karena ketika int (a) bertemu dengan double (b), C++ akan melakukan promotion di mana a dinaikkan kastanya menjadi double sebelum dibagi, sehingga hasilnya presisi.

Selanjutnya, mari kita kembali lagi pada kasus error baris modulo sebelumnya :
```Bash
g++ aritmatika.cpp -o aritmatika
error: invalid operands of types ‘int’ and ‘double’ to binary ‘operator%’
```
Seperti yang saya katakan sebelumnya, pesan error di atas memberikan konfirmasi teknis yang sangat jelas bahwa operator modulo (%) di C++ tidak mendukung tipe data selain integer. Hal ini berakar pada prinsip dasar modulo yang memang hanya didefinisikan untuk ranah bilangan bulat. Dalam matematika formal, operasi modulo adalah proses mencari sisa hasil pembagian dari suatu bilangan bulat (dividend) oleh bilangan bulat lainnya (divisor). Karena definisi sisa hasil pembagian (remainder) secara ketat mengasumsikan bahwa pembagian berhenti ketika sisa tersebut sudah lebih kecil dari pembagi namun tetap merupakan bilangan bulat, maka keterlibatan bilangan real (seperti float atau double) akan mematahkan logika dasar tersebut.

Namun, jika kita tetap ingin program tersebut dapat berjalan dengan akurat tanpa terkena error kompilasi, maka kita bisa melakukannya dengan menggunakan teknik Type Casting. Type casting adalah proses mengubah tipe data suatu variabel secara manual menjadi tipe data lain untuk operasi saat itu saja tanpa mengubah tipe data asli variabel aslinya (bersifat sementara). Untuk melakukan type casting, kita dapat menggunakan perintah (tipe_tujuan)variabel seperti ini :
```c++
#include <iostream>
using namespace std;

int main() {
    int a = 10; 
    int b = 3;  

    cout << "Penjumlahan: " << a + b << endl;
    cout << "Pengurangan: " << a - b << endl;
    cout << "Perkalian:   " << a * b << endl;

    // Menggunakan Type Casting (double) agar pembagian menjadi presisi
    cout << "Pembagian:   " << (double)a / b << endl;

    // Modulo tetap aman karena sesi type casting untuk a telah selesai pada operasi sebelumnya
    cout << "Modulo:      " << a % b << endl;

    return 0;
}
```
Selanjutnya, saya akan melakukan proses kompilasi pada file program tersebut dan menjalankannya :
```Bash
g++ aritmatika.cpp -o aritmatika
```
```bash
./aritmatika
Penjumlahan: 13
Pengurangan: 7
Perkalian:   30
Pembagian:   3
Modulo:      1
```
Terlihat bahwa output dari seluruh operasi matematika program tersebut telah sesuai dengan standard perhitungan sudut pandang matematika teoritis. Hal ini menegaskan bahwa type casting yang telah kita lakukan pada variabel a di baris operasi pembagian berjalan dengan lancar, ini dibuktikan dengan tidak adanya error kompilasi pada baris operasi modulo, yang berarti variabel a telah kembali ke integer pada saat melakukan operasi tersebut.

---

## URUTAN OPERASI (PRECEDENCE)
Sama seperti dalam matematika formal, C++ memiliki aturan kasta atau urutan kekuatan pada saat melakukan operasi aritmatika. Jika dalam satu baris kode terdapat banyak operator, compiler tidak serta-merta mengeksekusi dari kiri ke kanan, melainkan berdasarkan prioritas tertentu agar hasil kalkulasinya logis dan konsisten. Urutan prioritas tersebut pun sama dengan aturan matematika standar yang sering disebut disebut BODMAS/PEMDAS :
- **Kurung `()`**: Segala sesuatu di dalam kurung akan dikerjakan paling awal.

- **Perkalian `*`, Pembagian `/`, dan Modulo `%`**: Ketiganya memiliki tingkat kekuatan yang setara.

- **Penjumlahan `+` dan Pengurangan `-`**: Memiliki tingkat kekuatan terendah.

Contoh kasus sederhana :
```Bash
nano precedence.cpp
```
```c++
#include <iostream>
using namespace std;

int main(){
    int hasil = 2 + 5 * 10;
    cout<< hasil << endl;

    return 0;
}
```
```Bash
g++ precedence.cpp -o precedence
```
```bash
./precedence
52
```
Pada program tersebut, nilai dari variabel hasil yang tersimpan adalah 52, bukan 70. Hal ini dikarenakan compiler melakukan operasi `5 * 10` terlebih dahulu, baru kemudian menjumlahkannya dengan 2. Namun, jika kita tetap ingin penjumlahan dilakukan terlebih dahulu, maka kita wajib membungkusnya operasi penjumlahan tersebut dengan menggunakan kurung seperti ini :
```Bash
nano precedence.cpp
```
```c++
#include <iostream>
using namespace std;

int main(){
    int hasil = (2 + 5) * 10;
    cout<< hasil << endl;

    return 0;
}
```
```Bash
g++ precedence.cpp -o precedence
```
```bash
./precedence
70
```

---

## OPERATOR PENUGASAN (COMPOUND ASSIGNMENT)
Dalam menulis kode, sering kali kita ingin memperbarui nilai sebuah variabel berdasarkan nilai variabel itu sendiri. Misalnya, kita ingin menambah nilai dari variabel skor sebanyak 5, maka penulisan standarnya adalah `skor = skor + 5;`. Namun, C++ menyediakan cara yang lebih efisien dan ringkas yang disebut dengan compound assignment. Cara ini menggabungkan operator aritmatika (+, -, *, /, %) dengan operator penugasan (=) untuk memperbarui nilai dari sebuah variabel. 

Berikut adalah tabel untuk menyederhanakan penulisan operasi kita:

| Operator | Contoh | Ekspresi Identik |
|---|---|---|
| += | a+=5 | a = a + 5 |
| -= | a-=5 | a = a - 5 |
| *= | a*=5 | a = a * 5 |
| /= | a/=5 | a = a / 5 |
| %= | a%=5 | a = a % 5 |

Untuk memahami bagaimana operator ini memanipulasi nilai di dalam memori secara bertahap, mari kita simulasikan sebuah program yang melacak perubahan nilai satu variabel tunggal:
```Bash
nano operator_penugasan.cpp
```
```c++
#include <iostream>
using namespace std;

int main(){
    int a = 10;
    cout<<"Nilai awal a : "<<a<<endl;

    a+=3;
    cout<<"Setelah a+=3 :"<<a<<endl;

    a-=6;
    cout<<"Setelah a-=6 :"<<a<<endl;

    a*=2;
    cout<<"Setelah a*=2 :"<<a<<endl;

    a/=7;
    cout<<"Setelah a/=7 :"<<a<<endl;

    a%=5;
    cout<<"Setelah a%=5 :"<<a<<endl;

    return 0;
}
```
Sebelum kita menjalankan program di atas, penting untuk memahami bahwa program ini dirancang sebagai simulasi pelacakan nilai dimana kita akan menggunakan satu variabel tunggal a yang akan terus-menerus ditimpa nilainya menggunakan berbagai operator penugasan secara berurutan. Setiap baris kode akan mengambil nilai a yang terakhir, memprosesnya dengan operator tertentu, dan menyimpan hasilnya kembali ke dalam a. 
```Bash
g++ operator_penugasan.cpp -o operator_penugasan
```
```bash
./operator_penugasan
Nilai awal a : 10
Setelah a+=3 :13
Setelah a-=6 :7
Setelah a*=2 :14
Setelah a/=7 :2
Setelah a%=5 :2
```
Melalui simulasi di atas, kita bisa melihat bahwa variabel a benar-benar terus mengalami pembaruan nilai di setiap barisnya tanpa kita perlu menuliskan kembali nama variabel tersebut di sisi kanan operator. Keunggulan utama dari metode ini adalah efisiensi penulisannya apalagi ketika nama variabel yang kita tulis sangat panjang sehingga tentu akan sangat melelahkan jika harus menulisnya dua kali dalam satu baris.

## INCREMENT DAN DECREMENT
Operasi aritmatika yang paling spesifik dan mungkin paling sering akan kita temui dalam logika pemrograman adalah menambah atau mengurangi nilai sebuah variabel tepat sebesar 1. Operasi ini sangat krusial, terutama saat kita nanti mempelajari struktur perulangan (looping) atau penghitung (counter). Maka dari itu, C++ menyediakan operator khusus yang sangat ringkas, yakni :

- `++` (Increment): Menaikkan nilai variabel sebesar 1.
- `--` (Decrement): Menurunkan nilai variabel sebesar 1.

Meskipun terlihat sederhana, terdapat perbedaan perilaku yang sangat tipis namun fundamental tergantung pada di mana kita meletakkan simbol tersebut terhadap variabelnya. Perbedaan ini sering disebut sebagai Prefix dan Postfix.

- **Prefix (++a atau --a):** Simbol diletakkan di depan variabel. Secara logis, nilai variabel akan ditambah/dikurangi terlebih dahulu, baru kemudian variabel tersebut digunakan dalam instruksi atau operasi yang sedang berjalan.

- **Postfix (a++ atau a--):** Simbol diletakkan di belakang variabel. Secara logis, nilai variabel yang sekarang (sebelum diubah) akan digunakan terlebih dahulu untuk instruksi yang sedang berjalan, baru setelah instruksi itu selesai (melewati titik koma), nilainya akan ditambah/dikurangi di memori.

Untuk membuktikan perbedaan waktu eksekusi penambahan nilai tersebut, mari kita buat sebuah program eksperimen, dimana kita akan menyiapkan dua variabel berbeda, x dan y, yang keduanya sama-sama kita inisialisasi dengan angka 5. Kita akan melihat bagaimana output di layar berbeda ketika kita menampilkannya menggunakan metode yang berbeda secara bersamaan :

```Bash
nano inc_dec.cpp
```
```C++
#include <iostream>
using namespace std;

int main() {
    int x = 5;
    int y = 5;

    cout << "Nilai awal x dan y adalah 5" << endl;
    
    // Postfix: Tampilkan nilai x dulu (5), baru setelah ini x jadi 6
    cout << "Hasil Postfix (x++): " << x++ << endl; 
    
    // Prefix: Tambah nilai y dulu jadi 6, baru tampilkan hasilnya (6)
    cout << "Hasil Prefix  (++y): " << ++y << endl; 

    // Mari kita cek nilai akhir keduanya di memori
    cout << "Nilai akhir x di memori: " << x << endl;
    cout << "Nilai akhir y di memori: " << y << endl;

    return 0;
}
```
```Bash
g++ inc_dec.cpp -o inc_dec
```
```Bash
./inc_dec
Nilai awal x dan y adalah 5
Hasil Postfix (x++): 5
Hasil Prefix  (++y): 6
Nilai akhir x di memori: 6
Nilai akhir y di memori: 6
```
Terlihat jelas perbedaannya pada baris output. Pada Postfix (x++), angka yang muncul di layar saat instruksi cout berjalan masih angka 5 (nilai lama), karena penambahan baru terjadi di balik layar setelah baris tersebut selesai. Sedangkan pada Prefix (++y), angka yang muncul sudah angka 6 karena penambahan dilakukan terlebih dahulu sebelum data dikirim ke cout.

















  
