#include <stdio.h>
#include "point.h"

Point createPoint(int x, int y) {
    Point P;
    P.x = x;
    P.y = y;
    return P;
}

boolean isPointEqual(Point A, Point B) {
    if (A.x != -999 && A.y != -999 && B.x != -999 && B.y != -999) {
        return A.x == B.x && A.y == B.y;
    }
    return false;
}

void cetakPoint(Point P) {
    printf("<%d,%d>\n", P.x, P.y);
}

void setPointNull(Point* P) {
    (*P).x = -999;
    (*P).y = -999;
}