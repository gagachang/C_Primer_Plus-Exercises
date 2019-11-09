/*
 * This program will use command line arguments.
 * Open two files accroding to the two arguments.
 * Then implement following two functionalities:
 * (a) Output the contents of the two files line by line,
 *     but it needs to be taking turns such as:
 *     first line of first file, first line of second file,
 *     second line of first file, second line of second file
 *     ... etc
 * (b) Print the contents of the same lines in one line.
 */
#include <stdio.h>
#include <stdlib.h>

/* For (a) */
void a(FILE * fp1, FILE *fp2);

/* For (b) */
void b(FILE * fp1, FILE *fp2);

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Usage: %s filename_1 filename_2\n", argv[0]);
        exit(1);
    }

    FILE * fp1, * fp2;

    if ((fp1 = fopen(argv[1], "r")) == NULL)
    {
        printf("Can't open %s\n", argv[1]);
        exit(1);
    }

    if ((fp2 = fopen(argv[2], "r")) == NULL)
    {
        printf("Can't open %s\n", argv[2]);
        exit(1);
    }

    /* (a) */
    puts("For (a):");
    a(fp1, fp2);

    rewind(fp1);
    rewind(fp2);

    /* (b) */
    puts("\nFor (b):");
    b(fp1, fp2);

    if (fclose(fp1) != 0)
        printf("Error in closing file %s", argv[1]);
    if (fclose(fp2) != 0)
        printf("Error in closing file %s", argv[2]);

    return 0;
}

void a(FILE * fp1, FILE * fp2)
{
    int turn = 0;
    char ch;

    while (fp1 && fp2)
    {
        if (turn == 0)
        {
            while ((ch = getc(fp1)) != EOF)
            {
                putc(ch, stdout);
                if (ch == '\n')
                    break;
            }
            if (ch == EOF)
                break;
        }
        else
        {
            while ((ch = getc(fp2)) != EOF)
            {
                putc(ch, stdout);
                if (ch == '\n')
                    break;
            }
            if (ch == EOF)
                break;
        }
        turn = (turn + 1) % 2;
    }

    while ((ch = getc(fp1)) != EOF)
    {
        putc(ch, stdout);
        if (ch == '\n')
            break;
    }
    
    while ((ch = getc(fp2)) != EOF)
    {
        putc(ch, stdout);
        if (ch == '\n')
            break;
    }
}

void b(FILE * fp1, FILE * fp2)
{
    int turn = 0;
    char ch;

    while (fp1 && fp2)
    {
        if (turn == 0)
        {
            while ((ch = getc(fp1)) != EOF)
            {
                if (ch == '\n')
                    break;
                putc(ch, stdout);
            }
            if (ch == EOF)
                break;
        }
        else
        {
            while ((ch = getc(fp2)) != EOF)
            {
                putc(ch, stdout);
                if (ch == '\n')
                    break;
            }
            if (ch == EOF)
                break;
        }
        turn = (turn + 1) % 2;
    }

    while ((ch = getc(fp1)) != EOF)
    {
        putc(ch, stdout);
        if (ch == '\n')
            break;
    }
    
    while ((ch = getc(fp2)) != EOF)
    {
        putc(ch, stdout);
        if (ch == '\n')
            break;
    }
}
