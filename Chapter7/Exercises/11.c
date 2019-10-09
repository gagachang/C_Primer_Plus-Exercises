/*
 * ABC Mail Order Grocery sells these vegetables:
 * Tuberosus $2.05/pound, beet $1.15/pound, carrot $1.09/pound.
 * Let the user order the vegetables.
 * Calculate how many cost the user need to pay.
 * Print the costs to the user.
 */
#include <stdio.h>
#include <stdbool.h>
#define TUBEROSUS_PER_POUND 2.05
#define BEET_PER_POUND 1.15
#define CARROT_PER_POUND 1.09
int main(void)
{
    int pound_tuberosus = 0;
    int pound_beet = 0;
    int pound_carrot = 0;
    char option;
    int pounds;
    _Bool order = true;
    int total_pounds = 0;
    double total_vegetable_cost = 0;
    double transportation_cost = 0;
    double total_cost = 0;

    while (order)
    {
        printf("*******************************\n");
        printf("Enter the vegetable you want:\n");
        printf("a) tuberosus   b) beet\n");
        printf("c) carrot      d) end the order\n");
        printf("*******************************\n");
        printf("Your option: ");
        option = getchar();

        while (getchar() != '\n');
        switch (option)
        {
            case 'a' : printf("Enter how many pounds of tuberosus you want:\n");
                       scanf("%d", &pounds);
                       getchar();
                       pound_tuberosus += pounds;
                       break;
            case 'b' : printf("Enter how many pounds of beet you want:\n");
                       scanf("%d", &pounds);
                       getchar();
                       pound_beet += pounds;
                       break;
            case 'c' : printf("Enter how many pounds of carrot you want:\n");
                       scanf("%d", &pounds);
                       getchar();
                       pound_carrot += pounds;
                       break;
            case 'd' : printf("End the order.\n\n");
                       order = false;
                       break;
            default  : printf("You should only choose a ~ d, please retry it!\n");
                       break;
        } 
    }

    total_pounds = pound_tuberosus + pound_beet + pound_carrot;
    total_vegetable_cost = (pound_tuberosus * TUBEROSUS_PER_POUND) + (pound_beet * BEET_PER_POUND) + (pound_carrot * CARROT_PER_POUND);
    if (total_vegetable_cost > 100)
        total_vegetable_cost *= 0.95;

    if (total_pounds < 5)
        transportation_cost = 6.50;
    else if (total_pounds >= 5 && total_pounds < 20)
        transportation_cost = 14.0;
    else
        transportation_cost = 14.0 + ((total_pounds - 20) * 0.50);

    total_cost = total_vegetable_cost + transportation_cost;

    printf("Tuberosus is $2.05/pound, beet is $1.15/pound, carrot is $1.09/pound\n.");
    printf("You ordered total %d pounds.\n", total_pounds);
    printf("The tuberosus is cost $%.2lf, the beet is cost $%.2lf, and the carrot is cost $%.2lf.\n",
            pound_tuberosus * TUBEROSUS_PER_POUND, pound_beet * BEET_PER_POUND, pound_carrot * CARROT_PER_POUND);
    printf("The total cost of vegetables is $%.2lf.\n", total_vegetable_cost);
    if (total_vegetable_cost > 100)
        printf("You get the 5%% discount!!!\n");
    printf("The transportation cost is $%.2lf.\n", transportation_cost);
    printf("The total cost is $%.2lf.\n", total_cost);

    return 0;
}
