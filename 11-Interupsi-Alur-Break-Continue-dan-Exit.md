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
    cout << i << endl;
    if ( i == 5 ){
      break;
    }
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
  while ( i <= 10 )
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









