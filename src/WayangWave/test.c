#include "../WayangWave/start/start.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Membuat ListPenyanyi
    ListPenyanyi Penyanyi;
    CreateListPenyanyi(&Penyanyi);

    // Memanggil fungsi start dengan file input "contoh.txt"
    start("config.txt", &Penyanyi);

    // Menampilkan hasil dari ListPenyanyi (ini hanya contoh, sesuaikan dengan struktur data Anda)
    // Misalnya, Anda memiliki fungsi PrintListPenyanyi untuk menampilkan isi ListPenyanyi.
    // PrintListPenyanyi(&Penyanyi);

    // Hapus ListPenyanyi setelah selesai digunakan
    // DeleteList(&Penyanyi);

    return 0;
}
