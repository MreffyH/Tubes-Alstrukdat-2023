#include "stack.h"
#include "queue.h"
#include <stdio.h>

void songNext(Queue *q, Stack *s, ElType x)
{
    if (isEmpty(*q))
    {
        printf("Queue kosong, memutar kembali lagu");
        printf(" \" % c \" oleh \"%c\" ");
    }
    else
    {
        dequeue(q, &x);
        Push(s, x);
        printf("");
    }
}

void songPrevious(Queue *q, Stack *s, ElType x)
{
    if (isEmpty(*q))
    {
        printf("memutar lagu sebelumnya");
        printf(" \" % c \" oleh \"%c\" ");
    }
    else
    {
        Pop(s, &x);
        Push(s, x);
        printf("");
    }
}