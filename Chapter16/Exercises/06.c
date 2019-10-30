/* 
 * Modify example 16.15 qsorter.c
 * Sorting the struct names rather than double array
 * Define a struct names array and call qsort() in C stdlib.
 * First, sorts array by last name, then by first name.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMESIZE 40
#define ARRAYSIZE 5

struct names {
    char first[NAMESIZE];
    char last[NAMESIZE];
};

void show_names(const struct names * pn);
int mycomp(const void * p1, const void * p2);

int main(void)
{
    struct names staff[ARRAYSIZE] = { {"Gaga", "Chang"},
                                      {"Kevin", "Durant"},
                                      {"LeBron", "James"},
                                      {"Kobe", "Bryant"},
                                      {"Michael", "Jordan"} };

    printf("Before qsorting:\n");
    for (int i = 0; i < ARRAYSIZE; i++)
        show_names(&staff[i]);

    printf("\nUsing qsort() in C stdlib.h to sort the names array by last name then first name...\n");
    qsort(staff, ARRAYSIZE, sizeof(struct names), mycomp);

    printf("\nAfter qsorting:\n");
    for (int i = 0; i < ARRAYSIZE; i++)
        show_names(&staff[i]);

    return 0;
}

void show_names(const struct names * pn)
{
    printf("%s %s\n", pn->first, pn->last);
}

/* sort by inceasing ASCII */
int mycomp(const void * p1, const void * p2)
{
    const struct names * a1 = (const struct names *) p1;
    const struct names * a2 = (const struct names *) p2;
    int res;

    res = strcmp(a1->last, a2->last);
    if (res != 0)
        return res;
    else
        return strcmp(a1->first, a2->first);        
}
