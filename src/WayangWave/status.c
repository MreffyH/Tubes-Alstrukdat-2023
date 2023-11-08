#include <stdio.h>

void stat(List *song, List *queue, List *playlist)
{
    if(song.count == Nil) 
    {   // tidak ada lagu yang diputar
        printf("Now Playing:\n");
        printf("No songs have been played yet. Please search for a song to begin playback.\n");
        printf("\n");
        printf("Queue:\n");
        printf("Your queue is empty.\n");
    }
    else
    {
        if(queue.count == Nil)
        {   // ada lagu, queue kosong
            printf("Now Playing:\n");
            printf("%d\n", lagu);
            printf("Queue:\n");
            printf("Your queue is empty.\n");          
        }
        else
        {   
            if(playlist.count == 1)
            {   // ada lagu, ada queue, ada 1 playlist
                printf("Current Playlist: %d", playlist);
                printf("Now Playing:\n");
                printf("%d\n", lagu);
                printf("Queue:\n");
                printf("%d\n", queue);     
            }
            else
            {   // ada lagu, ada queue
                printf("Now Playing:\n");
                printf("%d\n", lagu);
                printf("Queue:\n");
                printf("%d\n", queue);   
            }            
        }
    }       
}