/*
 * This program will use a function to output the 
 * person's information, iIncluding personal social_code,
 * and a struct contains first name, middle name and last name.
 * 
 * If the middle name is empty, do not output it.
 * Otherwise output the first character of middle name and '.'
 *
 * For (a), the argument of function is a structure array.
 * For (b), the argument of function is a structure.
 */
#include <stdio.h>

struct person {
    int social_code;
    struct {
        char first_name[10];
        char middle_name[10];
        char last_name[10]; 
    };
};

/* (a) */
void print_info(const struct person people[], int n);

/* (b) */
void print_personal_info(struct person p);

int main(void)
{
    int n = 3;
    struct person people[3] = {
        {
            302039823,
            {
                "Flossie",
                "M",
                "Dribble"
            }
        },
        {
            123456789,
            {
                "GAGA",
                "C",
                "Chang"
            }
        },
        {
            987654321,
            {
                "YOYO",
                "",
                "Lee"
            }
        }
    };

    /* (a) */
    printf("Call the first function:\nThere are %d people:\n", n);
    print_info(people, n);

    /* (b) */
    printf("\nCall the second function:\nThere are %d people:\n", n);
    for (int i = 0; i < n; i++)
        print_personal_info(people[i]);

    return 0;
}

void print_info(const struct person people[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s, %s ", people[i].last_name, people[i].first_name);
        if (people[i].middle_name[0] != '\0')
            printf("%c. ", people[i].middle_name[0]);
        printf("- %d\n", people[i].social_code);
    }
}

void print_personal_info(struct person p)
{
    printf("%s, %s ", p.last_name, p.first_name);
    if (p.middle_name[0] != '\0')
        printf("%c. ", p.middle_name[0]);
    printf("- %d\n", p.social_code);
}
