#include "set.h"
// #include "set.c"
// #include "../mesin/mesinkalimat.c"
// #include "../mesin/mesinkata.c"
// #include "../mesin/mesinkarakter.c"
#include <stdio.h>

int main() {
    Set s1, s2, s3, s4, s5;

    CreateEmptySet(&s1);
    CreateEmptySet(&s2);
    CreateEmptySet(&s3);
    CreateEmptySet(&s4);
    CreateEmptySet(&s5);
    Word kalimat;
    kalimat.TabWord[0] = 'a';
    kalimat.TabWord[1] = 'p';
    kalimat.TabWord[2] = 'p';
    kalimat.TabWord[3] = 'l';
    kalimat.TabWord[4] = 'e';
    kalimat.Length = 5;
    InsertSet(&s1, kalimat);
    kalimat.TabWord[0] = 'b';
    kalimat.TabWord[1] = 'a';
    kalimat.TabWord[2] = 'n';
    kalimat.TabWord[3] = 'a';
    kalimat.TabWord[4] = 'n';
    kalimat.TabWord[5] = 'a';
    kalimat.Length = 6;
    InsertSet(&s1, kalimat);
    kalimat.TabWord[0] = 'o';
    kalimat.TabWord[1] = 'r';
    kalimat.TabWord[2] = 'a';
    kalimat.TabWord[3] = 'n';
    kalimat.TabWord[4] = 'g';
    kalimat.TabWord[5] = 'e';
    kalimat.Length = 6;
    InsertSet(&s1, kalimat);

    kalimat.TabWord[0] = 'b';
    kalimat.TabWord[1] = 'a';
    kalimat.TabWord[2] = 'n';
    kalimat.TabWord[3] = 'a';
    kalimat.TabWord[4] = 'n';
    kalimat.TabWord[5] = 'a';
    kalimat.Length = 6;
    InsertSet(&s2, kalimat);
    kalimat.TabWord[0] = 'g';
    kalimat.TabWord[1] = 'r';
    kalimat.TabWord[2] = 'a';
    kalimat.TabWord[3] = 'p';
    kalimat.TabWord[4] = 'e';
    kalimat.Length = 5;
    InsertSet(&s2, kalimat);
    kalimat.TabWord[0] = 'k';
    kalimat.TabWord[1] = 'i';
    kalimat.TabWord[2] = 'w';
    kalimat.TabWord[3] = 'i';
    kalimat.Length = 4;
    InsertSet(&s2, kalimat);

    printf("Set 1: ");
    PrintSet(s1);
    printf("Set 2: ");
    PrintSet(s2);

    s3 = SetUnion(s1, s2);
    printf("Union: ");
    PrintSet(s3);

    s4 = SetIntersection(s1, s2);
    printf("Intersection: ");
    PrintSet(s4);

    s5 = SetSymmetricDifference(s1, s2);
    printf("Symmetric Difference: ");
    PrintSet(s5);

    kalimat.TabWord[0] = 'b';
    kalimat.TabWord[1] = 'a';
    kalimat.TabWord[2] = 'n';
    kalimat.TabWord[3] = 'a';
    kalimat.TabWord[4] = 'n';
    kalimat.TabWord[5] = 'a';
    kalimat.Length = 6;
    DeleteSet(&s1, kalimat);
    printf("After deleting 'banana' from Set 1: ");
    PrintSet(s1);

    if (IsMemberSet(s1, kalimat)) {
        printf("'banana' is a member of Set 1\n");
    } else {
        printf("'banana' is not a member of Set 1\n");
    }

    return 0;
}