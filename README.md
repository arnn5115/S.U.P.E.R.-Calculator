# Selamat datang di SUPER EXTRA PLUS EXTENDED RENEWED (S.U.P.E.R.) Calculator
## Menjalankan Program
Untuk menjalankan program, masukan command ketika keluar ">".
Untuk daftar command dapat mengetikkan HELP pada input.\
Contoh input seperti berikut
```
> ADD 1 2
Result: 3.0000
> GCD 50 40
Result: 10.0000
> LCM 50 40
Result: 200.0000
```
## Penjelasan Program
Untuk menjaga keterbacaan dan kerapihan, program dibagi menjadi beberapa fungsi.
### init()
Hanya salam pembuka. Nothing special.
### main()
Pada program ini, main berfungsi untuk mengelola input argumen CLI dan mengelola status program apakah terdapat error atau tidak.
Tergantung ada tidaknya argumen CLI, main akan memanggil argInput() untuk mengelola input Argumen CLI atau manualInput() untuk membawa ke infinite loop.
### argInput()
Fungsi ini memberikan feedback text pada user lalu memanggil processor() dengan parameter yang diberikan oleh argumen CLI.
### manualInput()
Sama seperti argInput, fungsi ini hanya memberi feedback tambahan pada user berupa cara memanggil manual (HELP) dan keluar program (QUIT).
Setelah itu, fungi akan memanggil loop().
### loop()
Seperti namanya, fungsi ini adalah loop utama program. Fungsi ini memanggil fungsi inputManager() dan mengecek apabila mengembalikan 1, loop berakhir.
### inputManager()
Fungsi ini meminta input pada user dan menggunakannya untuk memanggil processor() berdasarkan command yang diterima.
### processor()
Fungsi ini hanyalah if-if yang memanggil fungsi-fungsi penghitung berdasar command yang diterima dan memasukkan hasilnya pada variabel res untuk dikeluarkan ke terminal.
Selain itu, fungsi ini juga menghandel error seperti command tak diketahui dan pembagian dengan nol. 
### Fungsi-Fungsi KaTaBaKu+Mod
Fungsi-fungsi dasar berupa add (penambahan), sub (pengurangan), mult (perkalian), div (pembagian), serta mod (sisa bagi).
### Fungsi fact(), perm(), permLoop(), dan comb()
Fungsi faktorial, kombinasi dan permutasi yang menggunakan rekursi sebagai fungsi tambahan. Faktorial menggunakan 1 sebagai basecase. Permutasi menggunakan n-r+1 yang dicari pada fungsi permLoop(). Dan kombinasi dicari dengan Permutasi dibagi fact(r)
### Fungsi gcd(), gcdLoop(), dan lcm()
Fungsi untuk menghitung GCD (Greatest Common Divider) atau FPB dan LCM (Least Common Multiplier) atau KPK. gcd() bertugas untuk menginisiasi gcdLoop() yang akan menghitung fpb dengan identitas berikut
1. gcd(2u, 2v) = 2 x gcd(u, v) berlaku jika keduanya genap
2. gcd(u, 2v) = gcd(u, v) berlaku jika salah satu genap
3. gcd(u, v) = gcd(u, v-u) dengan v > u, berlaku jika keduanya ganjil\
Ketiga identitas tersebut diulang hingga didapat u=v dan mengembalikan u sebagai basecase.\
Sedangkan KPK dapat dicari dengan membagi hasil kali kedua operand dan membaginya dengan FPB-nya.
### Fungsi Pembantu
lower() dan lowerTo() hanyalah fungsi untuk mengubah command menjadi lowercase sehingga mempermudah proses pembacaan.
