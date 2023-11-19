

void SAVE(ArrayDin *Games, Stack *History, ArrayDin_SB *Scoreboard, char *inputfile)
{
    #ifdef _WIN32
        char *placeholder = ".\\data\\";
    #else
        char *placeholder = "./data/";
    #endif
    char *txt = ".txt";
    char *filename;
    char *directory;
    filename = (char *) malloc (25 * sizeof(char));
    directory = (char *) malloc (50 * sizeof(char));
    concat(inputfile, txt, filename);
    concat(placeholder, filename, directory);

    FILE *open;
    open = fopen(directory, "w");

    fprintf(open, "%d\n", Games->Neff);
    for (int i = 0; i < Games->Neff; i++)
    {
        fprintf(open, "%s\n", Games->A[i]);
    }

    fprintf(open, "%d\n", Top(*History) + 1);
    for (int i = 0; i <= Top(*History); i++)
    {
        fprintf(open, "%s\n", History->T[i]);
    }

    for (int i = 0; i < Scoreboard->Neff; i++)
    {
        fprintf(open, "%d\n", Scoreboard->A[i].Count);
        for (int j = 0; j < Scoreboard->A[i].Count; j++)
        {
            fprintf(open, "%s %d\n", Scoreboard->A[i].Elements[j].Key, Scoreboard->A[i].Elements[j].Value);
        }
    }

    fprintf(open, ".");
    fclose(open);
    printf("Save file berhasil disimpan.\n");
}`