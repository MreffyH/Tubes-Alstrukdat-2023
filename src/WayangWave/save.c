#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void saveFile(const char *filename) {
    // Tentukan folder penyimpanan
    const char *folder = "save";

    // Gabungkan folder dan nama file untuk mendapatkan path lengkap
    char filepath[100]; // Atur ukuran yang sesuai dengan kebutuhan
    snprintf(filepath, sizeof(filepath), "%s/%s", folder, filename);

    // Buka file untuk penulisan
    FILE *file = fopen(filepath, "w");

    // Periksa apakah file berhasil dibuka
    if (file == NULL) {
        printf("Gagal membuka file untuk penyimpanan.\n");
        return;
    }
    // Tulis pesan ke file
    fprintf(file, "Save file berhasil disimpan.\n");
}