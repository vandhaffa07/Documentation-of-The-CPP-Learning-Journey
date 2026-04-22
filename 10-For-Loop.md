# FOR LOOP
for loop adalah salah satu struktur iterasi (seperti while loop) dalam bahasa pemrograman C++. Meskipun keduanya merupakan bentuk iterasi, for dan while memiliki perbedaan. for loop umumnya digunakan ketika jumlah pengulangan sudah diketahui secara pasti (deterministik), sedangkan while loop digunakan ketika jumlah perulangan belum pasti dan hanya bergantung pada kondisi logis di dalam parameter. Selain itu, for loop dirancang khusus untuk menangani iterasi yang melibatkan perhitungan dengan cara menyatukan proses inisialisasi, syarat kondisi, dan perubahan nilai (increment/decrement) ke dalam satu baris parameter.

## STRUKTUR DAN MEKANISME FOR LOOP
Berbeda dengan parameter while yang hanya memuat kondisi dengan mengembalikan nilai boolean. Parameter for terbagi menjadi tiga segmen utama yang dipisahkan oleh titik koma (;) seperti berikut :
```c++
for (inisialisasi; kondisi; perubahan nilai) {
  Instruksi 
}
```
**1. Inisialisasi :** Segmen ini digunakan untuk mendeklarasikan dan memberikan nilai awal pada suatu variabel pencacah (variabel yang digunakan dalam struktur pengulangan (looping) untuk menghitung jumlah iterasi). Uniknya, segmen ini hanya dieksekusi satu kali pada saat loop dimulai dan diabaikan ketika proses looping berikutnya. Hal ini tentunya berbeda dengan mekanisme looping lainnya yang akan membaca parameter dari awal lagi setelah satu proses looping selesai. 

**2. Kondisi :** Pada segmen ini, variabel pencacah akan disisipi dengan operator relasional dan nilai tertentu (biasanya jumlah looping yang ingin kita lakukan) untuk dicocokkan dan dievaluasi apakah hasilnya sesuai atau malah sebaliknya. Proses ini dilakukan di setiap siklus looping. Jika kondisi sesuai atau bernilai 1 (true), maka blok kode akan dijalankan, dan jika kondisi tidak sesuai atau bernilai 0 (false), maka loop akan dihentikan.

**3. Perubahan nilai :** Segmen ini digunakan sebagai instruksi untuk memperbarui variabel pencacah (baik menggunakan increment, decrement, maupun operator penugasan). Proses pembaruannya dilakukan tepat setelah blok kode pada siklus looping sebelumnya telah selesai dieksekusi dan tepat pula sebelum kembali ke tahap evaluasi kondisi.

Mari kita implementasikan sintaks tersebut ke dalam program sederhana untuk mencetak deret bilangan asli seperti berikut:
```bash
nano for_test.cpp
```
```c++
#include <iostream>
using namespace std;

int main(){
    for (int i = 1; i <= 5; i++) {
        cout << i << endl;
    }
    return 0;
}
```
```bash
g++ for_test.cpp -o for_test
```
```bash
./for_test
1
2
3
4
5
```
Secara teknis, ketika program di atas dijalankan, CPU akan mengalokasikan memori untuk variabel i dengan nilai awal 1. CPU kemudian memeriksa apakah 1 <= 5, dan karena hal tersebut benar, instruksi cetak didalam body pun dijalankan. Setelah satu siklus tersebut selesai, CPU akan mengeksekusi increment i++ yang membuat nilai i menjadi 2. Proses ini kemudian terus berulang hingga nilai i mencapai 6, di mana kondisi 6 <= 5 bernilai salah (false), sehingga CPU melakukan lompatan keluar dari blok iterasi. 

Namun, kita juga harus tetap berhati-hati ketika menggunakan struktur ini. Salah satu permasalahan klasik yang dapat dialami oleh for adalah infinite loop atau loop tidak terhingga. Masalah ini memang sering terjadi bahkan untuk struktur iterasi lain seperti while. Salah satu penyebabnya adalah kita yang secara tidak sengaja membuat kondisi dimana secara absolut selalu bernilai 1 (true) serta memiliki perubahan nilai yang menjauh dari batas kondisi, seperti pada program berikut :
```bash
nano for_test.cpp
```
```c++
#include <iostream>
using namespace std;

int main(){
    for (int i = 1; i > 0; i++) {
        cout << i << endl;
    }
    return 0;
}
```
```bash
g++ for_test.cpp -o for_test
```
```bash
./for_test
1
2
3
4
5
6
7
8
9
...................
..................dst
```
Karena i dimulai dari 1 dan terus bertambah melalui increment, pernyataan i > 0 secara otomatis akan selalu bernilai benar. Hal ini menyebabkan iterasi akan terus terjadi yang mengakibatkan blok body cetak pada for terus dieksekusi dan kemudian membuat terminal kita dibanjiri oleh output yang tidak akan ada habisnya.









