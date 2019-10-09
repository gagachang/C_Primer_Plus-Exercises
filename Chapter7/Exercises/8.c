/*
 * Let the user input his/her worktime per week
 * Output the total pay, total tax, and net income
 * (a) The pay per hour is chosen by user
 * (b) The overtime(over 40 hours) pay is $5 per hour
 * (c) The tax rate is 15% under total pay $300
 *                     20% for $301 ~ $450
 *                     25% above $450
 */
#include <stdio.h>
#define PAY_PER_HOUR_1 8.75
#define PAY_PER_HOUR_2 9.33
#define PAY_PER_HOUR_3 10.00
#define PAY_PER_HOUR_4 11.20
#define OVERTIME_PAY_PER_HOUR 5
#define TAX_RATE_UNDER_300 0.15
#define TAX_RATE_UNDER_450 0.20
#define TAX_RATE_ABOVE_450 0.25
int main(void)
{
    int choice;
    int worktime_per_week;
    int total_worktime = 0;
    double total_pay = 0.0;
    double total_tax;
    double net_income;
    int check;

    while (1)
    {
        printf("*****************************************************************\n");
        printf("Enter the number corresponding to the desired pay rate or action:\n");
        printf("1) $8.75/hr                         2) $9.33/hr\n");
        printf("3) $10.00/hr                        4) $11.20/hr\n");
        printf("5) quit\n");
        printf("*****************************************************************\n");
        printf("Your choice: ");
        check = scanf("%d", &choice);
        if ( check == 0 || choice < 1 || choice > 5)
        {
            printf("You should only input 1 ~ 5, please retry it!\n");
            getchar();
            continue;
        }
        else if (choice == 5)
            break;
        else
        {
            printf("Enter your work time of a week: \n");
            scanf("%d", &worktime_per_week);
            total_worktime += worktime_per_week;
            switch (choice)
            {
                case 1 :  total_pay += PAY_PER_HOUR_1 * worktime_per_week;
                          if ( (total_worktime - worktime_per_week) > 40)
                              total_pay += worktime_per_week * (0.5 * PAY_PER_HOUR_1);
                          else
                              total_pay += (total_worktime - 40) * (0.5 * PAY_PER_HOUR_1);
                          break;
                case 2 :  total_pay += PAY_PER_HOUR_2 * worktime_per_week;
                          if ( (total_worktime - worktime_per_week) > 40)
                              total_pay += worktime_per_week * (0.5 * PAY_PER_HOUR_2);
                          else
                              total_pay += (total_worktime - 40) * (0.5 * PAY_PER_HOUR_2);
                          break;
                case 3 :  total_pay += PAY_PER_HOUR_3 * worktime_per_week;
                          if ( (total_worktime - worktime_per_week) > 40)
                              total_pay += worktime_per_week * (0.5 * PAY_PER_HOUR_3);
                          else
                              total_pay += (total_worktime - 40) * (0.5 * PAY_PER_HOUR_3);
                          break;
                case 4 :  total_pay += PAY_PER_HOUR_4 * worktime_per_week;
                          if ( (total_worktime - worktime_per_week) > 40)
                              total_pay += worktime_per_week * (0.5 * PAY_PER_HOUR_4);
                          else
                              total_pay += (total_worktime - 40) * (0.5 * PAY_PER_HOUR_4);
                          break;
            }
        }
    }

    if (total_pay <= 300)
        total_tax = TAX_RATE_UNDER_300 * total_pay;
    else if (total_pay > 300 && total_pay <= 450)
        total_tax = (TAX_RATE_UNDER_300 * 300) + (TAX_RATE_UNDER_450 * (total_pay - 300));
    else
        total_tax = (TAX_RATE_UNDER_300 * 300) + (TAX_RATE_UNDER_450 * 150) + (TAX_RATE_ABOVE_450 * (total_pay - 450));

    net_income = total_pay - total_tax;

    printf("Your total pay is $%lf, and the tax is $%lf.\n", total_pay, total_tax);
    printf("Finally, your net income is $%lf.\n", net_income);

    return 0;
}
