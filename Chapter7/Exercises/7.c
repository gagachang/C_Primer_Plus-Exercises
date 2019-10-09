/*
 * Let the user input his/her worktime per week
 * Output the total pay, total tax, and net income
 * (a) The pay is $10 per hour
 * (b) The overtime(over 40 hours) pay is $5 per hour
 * (c) The tax rate is 15% under total pay $300
 *                     20% for $301 ~ $450
 *                     25% above $450
 */
#include <stdio.h>
#define PAY_PER_HOUR 10
#define OVERTIME_PAY_PER_HOUR 5
#define TAX_RATE_UNDER_300 0.15
#define TAX_RATE_UNDER_450 0.20
#define TAX_RATE_ABOVE_450 0.25
int main(void)
{
    int worktime_per_week;
    int total_worktime = 0;
    int total_pay = 0;
    double total_tax;
    double net_income;

    printf("Please enter your worktime per week, (q to quit):\n");
    while (scanf("%d", &worktime_per_week))
    {
        total_worktime += worktime_per_week;
        total_pay += worktime_per_week * PAY_PER_HOUR;
    }
    if (total_worktime > 40)
        total_pay += OVERTIME_PAY_PER_HOUR * (total_worktime - 40);

    if (total_pay <= 300)
        total_tax = TAX_RATE_UNDER_300 * total_pay;
    else if (total_pay > 300 && total_pay <= 450)
        total_tax = (TAX_RATE_UNDER_300 * 300) + (TAX_RATE_UNDER_450 * (total_pay - 300));
    else
        total_tax = (TAX_RATE_UNDER_300 * 300) + (TAX_RATE_UNDER_450 * 150) + (TAX_RATE_ABOVE_450 * (total_pay - 450));

    net_income = total_pay - total_tax;

    printf("Your total pay is $%d, and the tax is $%lf.\n", total_pay, total_tax);
    printf("Finally, your net income is $%lf.\n", net_income);

    return 0;
}
