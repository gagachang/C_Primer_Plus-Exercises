/* In the beginning, Chuckie Lucky has 1 million dollars
 * He takes 100 thousands every year, and owns 8% (interest)
 * Please calculate that he will have no money after a few years
 */
#include <stdio.h>
int main(void)
{
    double dollars = 1000000;
    const double interest = 0.08;
    const double take_away = 100000;
    int year = 0;

    while (dollars > 0)
    {
        dollars = (dollars - take_away) * (1 + interest);
        year++;
        printf("%lf\n", dollars);
    }

    printf("After %d years, Chuckie Lucky will be out of money.\n", year);

    return 0;
}
