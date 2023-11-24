#include <stdio.h>
#include "playlist.h"

void CreatePlaylist(ArrayDin *PLY)
{
    IsiPlaylist detil_playlist;
    ListLin IsiLagu;
    CreateEmptyListLin(&IsiLagu);
    (detil_playlist).countlaguLL = NbElmtLL(IsiLagu);
    printf("Masukkan nama playlist yang ingin dibuat : ");
    STARTINPUT();
    detil_playlist.nama_PlayList = currentInput;
    InsertLastArrayDin(PLY, detil_playlist);
    printf("Playlist \"");
    printWord(detil_playlist.nama_PlayList);
    printf("\" berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n");
}

void PlaylistADDSong(ArrayDin *PLY, ListPenyanyi penyanyi)
{
    printf("Daftar Penyanyi : \n");
    int i;
    for (i = 0; i < Jumlahpenyanyi(penyanyi); i++)
    {
        Word name;
        name = DuplicateKata(penyanyi.penyanyi_ke[i].namaPenyanyi);
        printf("%d. ", i + 1);
        printWord(name);
        printf("\n");
    }

    printf("\nMasukkan Nama Penyanyi yang dipilih: ");
    STARTINPUT();
    Word nama_penyanyi = DuplicateKata(currentInput);
    int urutan = SearchPenyanyi_ke(penyanyi, currentInput);
    if (urutan != NOTFOUND)
    {
        printf("\nDaftar Album oleh \"");
        printWord(penyanyi.penyanyi_ke[urutan].namaPenyanyi);
        printf("\" :\n");
        int jum_album;
        jum_album = penyanyi.penyanyi_ke[urutan].countalbum;
        for (i = 0; i < jum_album; i++)
        {
            printf("%d. ", i + 1);
            Word name_album;
            name_album = penyanyi.penyanyi_ke[urutan].mapalbum[i].namaAlbum;
            printWord(name_album);
            printf("\n");
        }

        printf("\nMasukkan Judul Album yang dipilih : ");
        STARTINPUT();
        Word name_Album = DuplicateKata(currentInput);
        int search_album = SearchAlbum_ke(penyanyi, nama_penyanyi, currentInput);
        if (search_album != NOTFOUND)
        {
            printf("\nDaftar Lagu Album \"");
            printWord(penyanyi.penyanyi_ke[urutan].mapalbum[search_album].namaAlbum);
            printf("\" oleh \"");
            printWord(penyanyi.penyanyi_ke[urutan].namaPenyanyi);
            printf(":\n");
            int jum_lagu;
            jum_lagu = penyanyi.penyanyi_ke[urutan].mapalbum[search_album].setlagu.Count;
            for (i = 0; i < jum_lagu; i++)
            {
                printf("%d. ", i + 1);
                Word name_lagu;
                name_lagu = penyanyi.penyanyi_ke[urutan].mapalbum[search_album].setlagu.Elements[i];
                printWord(name_lagu);
                printf("\n");
            }
            printf("\nMasukkan ID Lagu yang dipilih : ");
            STARTINPUT();
            int hasil = strToInteger(currentInput);
            Word LAGU_PANGGIL;
            LAGU_PANGGIL = penyanyi.penyanyi_ke[urutan].mapalbum[search_album].setlagu.Elements[hasil - 1];
            // printf("Memutar lagu |");
            // printWord(LAGU_PANGGIL);
            // printf("| oleh |");
            // printWord(penyanyi.penyanyi_ke[urutan].namaPenyanyi);
            // printf("|.");

            DetailSongLL LL;

            LL.namaPenyanyi = penyanyi.penyanyi_ke[urutan].namaPenyanyi;
            LL.namaAlbum = penyanyi.penyanyi_ke[urutan].mapalbum[search_album].namaAlbum;
            LL.namaLagu = LAGU_PANGGIL;

            printf("\n");
            printf("Daftar playlist pengguna :\n");
            if (!IsEmptyArrayDin(*PLY))
            {
                for (int i = 0; i < LengthArrayDin(*PLY); i++)
                {
                    printf("%d. ", i + 1);
                    printWord((*PLY).detil_playlist[i].nama_PlayList);
                    printf("\n");
                }

                printf("\nMasukkan ID playlist yang dipilih : ");
                STARTINPUT();
                int idPlaylist = strToInteger(currentInput);
                if ((idPlaylist <= (*PLY).Neff) && (idPlaylist >= 0))
                {
                    InsVLast(&(*PLY).detil_playlist[idPlaylist].IsiLagu, LL);
                    printf("\nLagu dengan judul ");
                    printf("\"");
                    printWord(penyanyi.penyanyi_ke[urutan].mapalbum[search_album].setlagu.Elements[hasil - 1]);
                    printf("\"");
                    printf(" pada album ");
                    printf("\"");
                    printWord(penyanyi.penyanyi_ke[urutan].mapalbum[search_album].namaAlbum);
                    printf("\"");
                    printf(" oleh penyanyi ");
                    printf("\"");
                    printWord(penyanyi.penyanyi_ke[urutan].namaPenyanyi);
                    printf("\"");
                    printf(" berhasil ditambahkan ke dalam playlist ");
                    printWord(PLY->detil_playlist[idPlaylist - 1].nama_PlayList);
                }
                else
                {
                   printf("ID Playlist tersebut tidak ada dalam daftar playlist."); 
                }
            }
            else
            {
                printf("Kamu tidak memiliki playlist.\n");
            }
        }
        else
        {
            printf("Album ");
            printWord(name_Album);
            printf(" tidak ada dalam daftar. Silakan coba lagi.");
        }
    }
    else
    {
        printf("Penyanyi ");
        printWord(nama_penyanyi);
        printf(" tidak ada dalam daftar. Silakan coba lagi.");
    }
}

void PlaylistADDAlbum(ArrayDin *PLY, ListPenyanyi penyanyi)
{
    printf("Daftar Penyanyi : \n");
    int i;
    for (i = 0; i < Jumlahpenyanyi(penyanyi); i++)
    {
        Word name;
        name = DuplicateKata(penyanyi.penyanyi_ke[i].namaPenyanyi);
        printf("%d. ", i + 1);
        printWord(name);
        printf("\n");
    }

    printf("\nMasukkan Nama Penyanyi yang dipilih: ");
    STARTINPUT();
    printf("\n");
    Word nama_penyanyi = DuplicateKata(currentInput);
    int urutan = SearchPenyanyi_ke(penyanyi, currentInput);
    if (urutan != NOTFOUND)
    {
        printf("Daftar Album oleh");
        printWord(penyanyi.penyanyi_ke[urutan].namaPenyanyi);
        printf(" :\n");
        int jum_album;
        jum_album = penyanyi.penyanyi_ke[urutan].countalbum;
        for (i = 0; i < jum_album; i++)
        {
            printf("%d. ", i + 1);
            Word name_album;
            name_album = penyanyi.penyanyi_ke[urutan].mapalbum[i].namaAlbum;
            printWord(name_album);
            printf("\n");
        }

        printf("\nMasukkan Judul Album yang dipilih : ");
        STARTINPUT();
        Word name_album = DuplicateKata(currentInput);
        int search_album = SearchAlbum_ke(penyanyi, nama_penyanyi, currentInput);
        if (search_album != NOTFOUND)
        {
            printf("\n");
            printf("Daftar playlist pengguna :\n");
            if (!IsEmptyArrayDin(*PLY))
            {
                for (int i = 0; i < LengthArrayDin(*PLY); i++)
                {
                    printf("%d. ", i + 1);
                    printWord((*PLY).detil_playlist[i].nama_PlayList);
                    printf("\n");
                }
                printf("\nMasukkan ID Playlist yang dipilih : ");
                STARTINPUT();
                int idPlaylist = strToInteger(currentInput);
                if ((idPlaylist <= (*PLY).Neff) && (idPlaylist >= 0))
                {
                    DetailSongLL newSongAdded;
                    int i = 0;
                    newSongAdded.namaPenyanyi = nama_penyanyi;
                    newSongAdded.namaAlbum = name_album;
                    while (i < penyanyi.penyanyi_ke[urutan].mapalbum[search_album].setlagu.Count)
                    {
                        newSongAdded.namaLagu = penyanyi.penyanyi_ke[urutan].mapalbum[search_album].setlagu.Elements[i];
                        i++;
                        InsVLast(&((*PLY).detil_playlist[idPlaylist - 1].IsiLagu), newSongAdded);
                        (*PLY).detil_playlist[idPlaylist - 1].countlaguLL++;
                    }
                    printf("\nAlbum dengan judul ");
                    printf("\"");
                    printWord(newSongAdded.namaAlbum);
                    printf("\"");
                    printf(" berhasil ditambahkan ke dalam pada playlist pengguna ");
                    printf("\"");
                    printWord((*PLY).detil_playlist[idPlaylist - 1].nama_PlayList);
                    printf("\"");
                    printf(".");
                }
                else
                {
                    printf("ID Playlist tersebut tidak ada dalam daftar playlist.");
                }
            }
            else
            {
                printf("Kamu tidak memiliki playlist.\n");
            }
        }
        else
        {
            printf("Album ");
            printWord(name_album);
            printf(" tidak ada dalam daftar. Silakan coba lagi.");
        }
    }

    else
    {
        printf("Penyanyi ");
        printWord(nama_penyanyi);
        printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
    }
}

void PlaylistRemove(ArrayDin *PLY, int id, int n)
{
    if ((id < ((*PLY).Neff)) && (id >= 0))
    {
        if (n < ((*PLY).detil_playlist[id - 1].countlaguLL) && (n >= 0))
        {
            printf("Lagu ");
            address P = First((*PLY).detil_playlist[id - 1].IsiLagu);
            address Prec = NilLin;
            int i = 0;
            while (i < n - 1)
            {
                Prec = P;
                P = Next(P);
                i++;
            }
            printf("\"");
            printWord(InfoJudul(P));
            printf("\"");
            printf(" oleh ");
            printf("\"");
            printWord(InfoPenyanyi(P));
            printf("\"");
            printf(" telah dihapus dari playlist ");
            printf("\"");
            printWord((*PLY).detil_playlist[id - 1].nama_PlayList);
            printf("\"");
            if (Prec == NilLin)
            {
                DelFirstLL(&((*PLY).detil_playlist[id].IsiLagu), &P);
            }
            else
            {
                DelAfterLL(&((*PLY).detil_playlist[id].IsiLagu), &P, Prec);
            }
            (*PLY).detil_playlist[id].countlaguLL--;
        }
        else
        {
            printf("Tidak ada lagu dengan urutan %d di playlist ", n);
            printWord((*PLY).detil_playlist[id].nama_PlayList);
            printf("\"!");
        }
    }
    else
    {
        printf("Tidak ada playlist dengan ID ");
        printf("%d.", id);
    }
}

void PlaylistSwap(ArrayDin *PLY, int id, int x, int y)
{
    if ((id <= ((*PLY).Neff)) && (id > 0))
    {
        if (x <= ((*PLY).detil_playlist[id - 1].countlaguLL) && (x > 0) && (y <= ((*PLY).detil_playlist[id - 1].countlaguLL)) && (y > 0))
        {
            IsiPlaylist swappedPlaylist = GetPlaylist(*PLY, id - 1);
            address PX = First(swappedPlaylist.IsiLagu);
            int i = 0;
            while (i < (x - 1))
            {
                PX = Next(PX);
                i++;
            }
            address PY = First(swappedPlaylist.IsiLagu);
            i = 0;
            while (i < (y - 1))
            {
                PY = Next(PY);
                i++;
            }
            address Ptemp = PX;
            PX = PY;
            PY = Ptemp;
            printf("Berhasil menukar lagu dengan nama ");
            printf("\"");
            printWord(InfoJudul(PY));
            printf("\"");
            printf(" dengan ");
            printf("\"");
            printWord(InfoJudul(PX));
            printf("\"");
            printf(" di playlist ");
            printf("\"");
            printWord(swappedPlaylist.nama_PlayList);
            printf("\"");
        }
        else
        {
            printf("Tidak ada lagu dengan urutan");
            if (x <= 0 || x > ((*PLY).detil_playlist[id - 1].countlaguLL))
                printf(" %d", x);
            if (y <= 0 || y > ((*PLY).detil_playlist[id - 1].countlaguLL))
                printf(" %d", y);
        }
    }
    else
    {
        printf("Tidak ada playlist dengan playlist ID %d", id - 1);
    }
}

void PlaylistDelete(ArrayDin *PLY)
{
    printf("\n");
    printf("Daftar playlist pengguna :\n");
    if (!IsEmptyArrayDin(*PLY))
    {
        for (int i = 0; i < LengthArrayDin(*PLY); i++)
        {
            printf("%d. ", i + 1);
            printWord((*PLY).detil_playlist[i].nama_PlayList);
            printf("\n");
        }
    }
    printf("Masukkan ID Playlist yang dipilih : ");
    STARTINPUT();
    int idPlaylist = strToInteger(currentInput);
    printf("\nPlaylist ID %d dengan judul ", idPlaylist);
    printf("\"");
    printWord((*PLY).detil_playlist[idPlaylist - 1].nama_PlayList);
    printf("\"");
    printf(" berhasil dihapus.");
    DeleteAtArrayDin(PLY, idPlaylist - 1);
}
