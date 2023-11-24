<head>
  <h1>WayangWave 🎶🎧</h1>
  <small>by 8antai ASD</small>
</head>
<body>
  <h2>IF2111 - Algoritma dan Struktur Data STI</h2>
  <h3>Proyek ini dibuat sebagai pemenuhan Tugas Besar Mata Kuliah Algoritma dan Struktur Data STI</h3>
  <p><b>WayangWave</b> merupakan aplikasi yang bisa mensimulasikan service pemutaran musik yang diakses melalui CLI (<i>command-line interface</i>). Secara umum, program ini memiliki <strong>5 Main Features</strong>, yakni.</p>
  <ol>
    <li>Memutar lagu</li>
    <li>Menampilkan daftar lagu</li>
    <li>Membuat dan menghapus <i>playlist</i></li>
    <li>Mengatur urutan dimainkkannya lagu</li>
    <li>Menampilkan status dari aplikasi</li>
  </ol>
  <p> Jadi, ketika program <b>WayangWave</b> dijalankan, maka sistem program akan menampilkan <i>Welcome Page~</i> dan hanya berisikan 3 buah command yaitu <b>START</b>, <b>LOAD</b>, dan <b>HELP</b>. Untuk memulai program, pengguna harus memasukkan command <b>START</b> untuk bisa mengakses command-command lainnya yang ada di <i>main menu</i>. Terdapat beberapa command yang bisa diakses pengguna ketika menggunakan sistem WayangWave tersebut. <b>LIST</b> berisikan daftar nama penyanyi dan juga daftar playlist lagu yang dimiliki oleh pengguna. Selanjutnya, <b>PLAY</b> bertujuan untuk memutarkan lagu yang diinginkan oleh pengguna ataupun memutar playlist yang diinginkannya. <b>QUEUE</b> berisikan perintah untuk menambahkan antrian lagu atau playlist dari pengguna. Selain itu, command ini juga berguna untuk menukar urutan antrian lagu sesuai kehendak dari pengguna. Command ini juga dapat menghapus antrian lagu oleh pengguna tersebut. Command <b>SONG</b> untuk memutar lagu berikutnya ataupun sebelumnya. <b>PLAYLIST</b> berfungsi untuk membuat playlist lagu yang berisikan lagu-lagu favorit yang dimiliki oleh pengguna dan juga dapat sekaligus menghapus playlist sesuai keinginan. <b>STATUS</b> berisikan status dari sang pengguna yang menampilkan lagu yang dimainkan berserta Queue song yang ada dan dari playlist mana lagu itu diputar.</p>
<h2>📂Folder Structure</h2>
  <p>Berikut merupakan rangkaian struktur dari tugas besar kami.</p>
  <ul type = "circle">
    <li> folder <mark>bin</mark> berisikan `..` dan `makefile` untuk melakukan kompilasi terhadap program utama.</li>
    <li> folder `src` berisikan: 
        <ul type = "square">
          <li> folder `ADT` yang berisikan header yang kami butuhkan untuk program.</li>
          <li> folder `save` berisikan `dummy.txt` yang dapat kami gunakan sebagai informasi penyanyi, lagu, dan album.</li>
          <li> file `boolean.h` berisikan header tipe boolean.</li>
          <li> file `console.h` berisikan header dari berbagai fungsi dan prosedur yang kami gunakan untuk membuat program tersebut.</li>
          <li> file `console.c` berisikan hasil implementasi dari `console.h`</li>
          <li> file `main.c` berisikan program utama kami.</li>
        </ul>
        </li>
  </ul>
</body>


