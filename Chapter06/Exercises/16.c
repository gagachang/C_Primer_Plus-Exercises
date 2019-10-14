#include <stdio.h>
int main(void)
{
    double Daphne = 100.0;
    const double Daphne_interest = 0.1;

    double Deirdre = 100.0;
    const double Deirdre_interest = 1.05;

    int year = 0;

    while (Daphne >= Deirdre)
    {
        Daphne += 100 * Daphne_interest;
        Deirdre *= Deirdre_interest;
        year++;

        printf("The %d years: \nDaphne: %lf \nDeirdre: %lf\n", year, Daphne, Deirdre);
    }

    return 0;
}
