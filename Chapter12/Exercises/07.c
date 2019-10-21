/* 
 * Modified from example 12.13 manydice.c
 * Add some additional functions: number of sets
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static int rollem(int sides);
int roll_n_dice(int dice, int sides);

int main(void)
{
    char * sets;
    int set;
    int dice, roll;
    int sides;
    int status;

    srand((unsigned int) time(0));
    printf("Enter the number of sets; enter q to stop: ");
    while (scanf("%s", sets))
    {
        if (strcmp(sets, "q") == 0)
            break;

        while (getchar() != '\n')
            continue;

        set = atoi(sets);
        printf("How many sides and how many dice? ");
        while (status = scanf("%d %d", &sides, &dice))
        {
            if (status != 2)
            {
                if (status == EOF)
                    break;
                else
                {
                    printf("You should have entered two integers.");
                    printf("Let's begin again.\n");
                    while (getchar() != '\n')
                        continue;
                    printf("How many sides and how many dice? \n");
                    continue;
                }
            }
            else
                break;
        }
        if ((roll = roll_n_dice(dice, sides)) > 0)
        {
            printf("Here are %d sets of %d %d-sided throws.\n",
                   set, dice, sides);
            printf("%4d", roll);
            for (int i = 1; i < set; i++)
            {
                roll = roll_n_dice(dice, sides);
                printf("%4d", roll);
                if (i % 14 == 0)
                    printf("\n");
            }
            printf("\n");
        }
        printf("\nHow many sets? Enter q to stop: ");
        
    }
    printf("GOOD FORTUNE TO YOU!\n");

    return 0;
}

static int rollem(int sides)
{
    int roll;

    roll = rand() % sides + 1;

    return roll;
}

int roll_n_dice(int dice, int sides)
{
    int d;
    int total = 0;
    if (sides < 2)
    {
        printf("Need at least 2 sides.\n");
        return -2;
    }
    if (dice < 1)
    {
        printf("Need at least 1 die.\n");
        return -1;
    }

    for (d = 0; d < dice; d++)
        total += rollem(sides);

    return total;
}
