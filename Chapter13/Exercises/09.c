/* 
 * Modifies examples 13.3 addaword.c
 * When each word added into the file, it will have a number.
 * For example,
 * "The fabulous programmer" will be following format in the file:
 * 1 The
 * 2 fabulous
 * 3 programmer
 *
 * Everytime when executes this program, the number needs to start from one.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void)
{
    FILE *fp;
    char words[MAX];
    int count = 1;

    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%d %s\n", count++, words);

    puts("File contents:");
    rewind(fp);           /* go back to beginning of file */
    while (fscanf(fp, "%d %s", &count, words) == 2)
        printf("%d %s\n", count, words);
    puts("Done!");
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;
}
