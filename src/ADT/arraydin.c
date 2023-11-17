#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arrayfirst()
{
    FILE *f = fopen("../../save/config.txt", "r");

    if (f == NULL)
    {
        printf("file tidak ditemukan");
        return 0;
        fclose(f);
    }
    else
    {
        int i;
        char *temp;
        fgets(temp, sizeof(temp), f);
        i = atoi(temp);
        fclose(f);
        return i;
    }
}

void

    int
    main()
{
    FILE *f = fopen("../../save/config.txt", "r");

    if (f == NULL)
    {
        printf("File tidak ditemukan\n");
        return -1; // Indicate failure
    }
    else
    {
        extractData(f, 2); // Extract data for the first two entries
        fclose(f);
        return 0; // Indicate success
    }
}

// Data ke-1:
// Artist: BLACKPINK
// Jumlah Album: 4
// Nama Album: BORN PINK

// Data ke-2:
// Artist: <Nama Penyanyi Berikutnya>
// Jumlah Album: <Jumlah Album>
// Nama Album: <Nama Album>