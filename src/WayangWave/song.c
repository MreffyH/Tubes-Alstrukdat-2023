#include "stack.h"
#include "queue.h"
#include <stdio.h>

void songNext(Queue *q, Stack *s, currentsong x)
{
    if (isEmpty(*q))
    {
        printf("Queue kosong, memutar kembali lagu");
        printf(/*currentsong*/);
        printf("oleh");
        printf(/*currentsong*/);
    }
    else
    {
        dequeue(q, &x);
        Push(s, x);
        printf("Memutar lagu selanjutnya");
        printf(/*currentsong*/);
        printf("oleh");
        printf(/*currentsong*/)
    }
}

void songPrevious(Queue *q, Stack *s, currentsong x)
{
    if (isEmpty(*q))
    {
        printf("Riwayat lagu kosong, memutar kembali lagu");
        printf(/*current song*/);
        printf("oleh");
        printf(/*currentsong*/);
    }
    else
    {
        Pop(s, &x);
        Push(s, x);
        printf("Memutar lagu sebelumnya");
        printf(/*currentsong*/);
        printf("oleh");
        printf(/*currentsong*/);
    }
}