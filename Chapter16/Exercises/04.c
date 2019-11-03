/*
 * This exercises will use clock() in time.h
 * Input the seconds we want to delay, then delay() function
 * will use clock() to get the start time.
 * In a infinite while loop, calling clock() continuously to get end time,
 * if (end time - start time) / CLOCKS_PER_SEC > delay, then stops delay.
 */
#include <stdio.h>
#include <time.h>

void delay(double seconds);

int main(void)
{
    double seconds;

    printf("Enter the seconds you want to delay (q to quit): ");
    while (scanf("%lf", &seconds) == 1)
    {
        delay(seconds);
        printf("Enter the seconds you want to delay (q to quit): ");
    }
    puts("Bye!");

    return 0;
}

void delay(double seconds)
{
    double start, end;

    printf("Starting delay %.0lf seconds...\n", seconds);
    start = (double) clock();

    while (1)
    {
        end = (double) clock();
        if (((end - start) / CLOCKS_PER_SEC) >= seconds)
            break;
    }

    printf("Finished delaying %.0lf seconds.\n", seconds);
}
