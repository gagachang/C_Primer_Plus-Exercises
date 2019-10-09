#include <stdio.h>
#include <math.h>
#define BASE_TAX_RATE 0.15
#define OVER_TAX_RATE 0.28
#define SINGLE_BASE 17850
#define HOST_BASE 23900
#define MARRIED_COMMON_BASE 29750
#define MARRIED_SEPARATE_BASE 14875
int main(void)
{
    int class;
    int income;
    double tax = 0.0;

    while (1)
    {
        printf("Please choose your class (q to quit):\n");
        printf("1) Single   2) Host   3) Married and common   4) Married and seperate\n");
        if ( scanf("%d", &class) )
        {
            if (class < 1 || class > 4)
            {
                printf("The class number should be 1 ~ 4, please retry it!\n");
                getchar();
                continue;
            }
            else
            {
                printf("Please enter your income: ");
                scanf("%d", &income);
                switch (class)
                {
                    case 1 : tax = ((income > SINGLE_BASE) ? (SINGLE_BASE * BASE_TAX_RATE) : (income * BASE_TAX_RATE))
                                   + ((income - SINGLE_BASE) > 0 ? (income - SINGLE_BASE) * OVER_TAX_RATE : 0);
                             break;
                    case 2 : tax = ((income > HOST_BASE) ? (HOST_BASE * BASE_TAX_RATE) : (income * BASE_TAX_RATE))
                                   + ((income - HOST_BASE) > 0 ? (income - HOST_BASE) * OVER_TAX_RATE : 0);
                             break;
                    case 3 : tax = ((income > MARRIED_COMMON_BASE) ? (MARRIED_COMMON_BASE * BASE_TAX_RATE) : (income * BASE_TAX_RATE))
                                   + ((income - MARRIED_COMMON_BASE) > 0 ? (income - MARRIED_COMMON_BASE) * OVER_TAX_RATE : 0);
                             break;
                    case 4 : tax = ((income > MARRIED_SEPARATE_BASE) ? (MARRIED_SEPARATE_BASE * BASE_TAX_RATE) : (income * BASE_TAX_RATE))
                                   + ((income - MARRIED_SEPARATE_BASE) > 0 ? (income - MARRIED_SEPARATE_BASE) * OVER_TAX_RATE : 0);
                             break;
                }
                printf("Your tax is $%lf.\n\n", tax);
            }
        }
        else
            break;
    }
    printf("Bye!\n");

    return 0;
}
