#include"load.h"
#include"mesinkata.h"

int main()
{
    // char *file = "user1.txt";
    // STARTWAYANGWAVE(file);
    STARTINPUT();
    Word file = currentInput;
    LOADWAYANGWAVE(file.TabWord);
    return 0;
}