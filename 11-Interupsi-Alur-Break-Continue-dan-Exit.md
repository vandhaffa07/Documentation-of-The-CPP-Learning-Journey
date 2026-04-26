# INTERUPSI ALUR - BREAK, CONTINUE, DAN EXIT
Dalam sistem otomasi yang kita buat menggunakan struktur perulangan (iterasi), adakalanya kita membutuhkan mekanisme untuk menginterupsi alur kerja secara mendadak, yang disebut dengan instruksi interupsi. Tanpa instruksi ini, CPU akan dipaksa menyelesaikan seluruh kontrak perulangan hingga akhir, meskipun target yang dicari telah ditemukan. Di dalam C++ sendiri, terdapat tiga instruksi utama untuk melakukan kendali alur seperti ini, yakni break, continue, dan fungsi exit().

---

## BREAK
Instruksi ini mungkin adalah instruksi yang paling familiar bagi kita, karena kita seringkali menyinggungnya pada pembahasan-pembahasan sebelumnya. Break berfungsi untuk memaksa CPU keluar dari blok perulangan (for, while, atau do-while) saat itu juga, tanpa mempedulikan apakah kondisi perulangan masih bernilai true atau tidak. Setelah break dieksekusi, alur program akan langsung melompat ke baris kode pertama setelah tanda tutup kurung kurawal } perulangan. 

Berikut adalah contohnya : 
```bash
nano break-test.cpp
```
```c++
#include <iostream>
using namespace std;

int main(){

  for (int i = 0; i <= 10; i++){
    if ( i == 5 ){
      break;
    }
    cout << i << endl;
  }
  cout << "Ini adalah akhir program" << endl;

return 0;
}
```
```bash
g++ break-test.cpp -o break-test
```
```bash
0
1
2
3
4
Ini adalah akhir program
```
Dapat terlihat bahwa program langsung keluar dari blook looping setelah iterasi ke-6 atau saat nilai dari variabel i menjadi 5. Hal ini dapat terjadi karena kita menambahkan statement khusus menggunakan if ketika nilai i menjadi 5, dimana, didalam body if tersebut, terdapat instruksi interupsi break yang memaksa CPU untuk melompat ke baris kode cetak yang berada tepat setelah tutup kurung kurawal.

Tidak hanya for, break juga bisa digunakan pada while seperti ini :
```bash
nano break-test.cpp
```
```c++
#include <iostream>
using namespace std;

int main(){

  int i = 0;
  while ( i <= 10 ){
    if ( i == 5 ){
      break;
    }
    cout << i << endl;
    i++;
  }
  cout << "Ini adalah akhir program" << endl;

return 0;
}
```
```bash
g++ break-test.cpp -o break-test
```
```bash
0
1
2
3
4
Ini adalah akhir program
```

---

## CONTINUE
Berbeda dengan break yang menghentikan seluruh iterasi ketika bertemu, continue hanya melompati sisa instruksi dalam satu putaran (iterasi) saja. Begitu CPU bertemu continue, ia akan mengabaikan semua baris kode di bawahnya dan langsung meloncat kembali ke bagian awal looping untuk melakukan update nilai (pada for) atau pengecekan kondisi (pada while).

Berikut adalah contohnya :
```bash
nano continue-test.cpp
```
```c++
#include <iostream>
using namespace std;

int main(){

  for (int i = 0; i <= 10; i++){
    if ( i == 5 ){
      continue;
    }
    cout << i << endl;
  }
  cout << "Ini adalah akhir program" << endl;

return 0;
}
```
```bash
g++ continue-test.cpp -o continue-test
```
```bash
0
1
2
3
4
6
7
8
9
10
Ini adalah akhir program
```
Dapat terlihat bahwa program tidak mengeksekusi perintah cetak pada iterasi ke-6 atau saat i bernilai 5. Hal ini disebabkan karena kita menambahkan instruksi if yang berlaku ketika nilai i menjadi 5, dimana pada body if tersebut, terdapat interupsi alur berupa continue yang memaksa program untuk melewati seluruh baris kode yang ada dibawahnya dan kembali pada bagian awal looping untuk melakukan iterasi baru. Karena perintah cetak (cout) pada program tersebut berada setelah intruksi continue, maka otomatis ia tidak akan dieksekusi dan ditampilkan ke layar sebagaiamana seperti output yang kita lihat diatas.

Meskipun continue terlihat sangat berguna, penggunaannya pada struktur while membutuhkan ketelitian ekstra dibandingkan pada for. Di dalam for loop, saat instruksi continue dipicu, CPU akan otomatis melompat ke sektor update nilai yang terdapat pada parameter for. Namun, pada while, instruksi update nilai biasanya berada di bagian bawah body loop. Hal ini berdampak secara signifikan jika instruksi continue diletakkan sebelum perubahan nilai variabel kontrol, maka variabel tersebut tidak akan pernah berubah, menyebabkan kondisi while selalu true dan terjebak dalam Infinite Loop.

Lihatlah program berikut :
```bash
nano continue-test.cpp
```
```c++
#include <iostream>
using namespace std;

int main(){

  int i = 0;
  while ( i <= 10 ){
    if ( i == 5 ){
      continue;
    }
    cout << i << endl;
    i++;
  }
  cout << "Ini adalah akhir program" << endl;

return 0;
}
```
```bash
g++ continue-test.cpp -o continue-test
```
```bash
0
1
2
3
4

```
Saat i bernilai 5, kondisi if (i == 5) terpenuhi, sehingga instruksi continue yang terdapat di dalam body if tersebut dijalankan dan memicu CPU untuk langsung meloncat kembali ke baris parameter pengecekan kondisi (i <= 10). Masalahnya, instruksi perubahan variabel i++ terlewati dan tidak dieksekusi karena letaknya yang berada di bawah instruksi continue. Hal ini menyebabkan proses evaluasi kondisi dilakukan dengan nilai i yang masih sama yakni 5. Kejadian ini kemudian akan berulang selamanya, dimana CPU terjebak mengevaluasi angka 5 tanpa henti dan tidak akan menampilkan apa-apa pada terminal kita. 

---

## EXIT
exit() merupakan fungsi yang berasal dari library <cstdlib> dan digunakan untuk menghentikan seluruh program secara total saat itu juga. Ini adalah sifat yang membedakan exit dengan break, karena break hanya menghentikan dan memaksa CPU untuk keluar dari proses looping. Sedangkan exit(), benar-benar keluar dari program. exit() tidak peduli apapun bahkan jika dalam program yang sangat kompleks, apabila dijalankan, ia akan langsung mematikan proses dan mengembalikan kendali ke sistem operasi. Parameter di dalam exit() disebut sebagai Exit Status. Kita dapat menggunakan 0 untuk menandakan program sukses (Standard Success), dan angka non-nol (seperti 1) untuk menandakan adanya error atau interupsi sistem yang tidak normal. 

Berikut adalah contohnya :
```bash
nano exit-test.cpp
```
```c++
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){

  for (int i = 0; i <= 10; i++){
    if ( i == 5 ){
      exit(0);
    }
   cout << i << endl;
  }
  cout << "Ini adalah akhir program" << endl;

return 0;
}
```
```bash
g++ exit-test.cpp -o exit-test
```
```bash
0
1
2
3
4
```
Terlihat bahwa setelah menampilkan angka 4, program langsung berhenti dan tidak menjalankan apa-apa. Ini berarti penggunaan exit() pada program kita berjalan dengan baik. Hal ini dibuktikan karena baris kode cetak "Ini adalah akhir program" tidak ditampilkan sehingga mengindikasikan bahwa setelah fungsi exit dijalankan, semua sisa program yang tersisa tidak dieksekusi.  








