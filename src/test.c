#include "WayangWave/start/start.h"
#include "ADT/listmapset/listmapset.h"
#include "ADT/mapset/set.h"
#include "ADT/mesin/mesinkalimat.h"
#include "ADT/mesin/mesinkata.h"
#include "ADT/mesin/mesinkarakter.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Membuat ListPenyanyi
    printf("CEK\n");
    ListPenyanyi Penyanyi;
    CreateListPenyanyi(&Penyanyi);

    // Memanggil fungsi start dengan file input "contoh.txt"
    start("config.txt", &Penyanyi);

    // Menampilkan hasil dari ListPenyanyi (ini hanya contoh, sesuaikan dengan struktur data Anda)
    // Misalnya, Anda memiliki fungsi PrintListPenyanyi untuk menampilkan isi ListPenyanyi.
    // PrintListPenyanyi(&Penyanyi);

    // Hapus ListPenyanyi setelah selesai digunakan
    // DeleteList(&Penyanyi);
    printf("CEK\n");
    return 0;
}
