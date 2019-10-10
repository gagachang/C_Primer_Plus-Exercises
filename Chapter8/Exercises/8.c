/*
 * Show a menu to user.
 * Let the user enter a operation and two float numbers.
 * Calculate the result and show it to the user.
 * The program can deal with input error.
 */
#include <stdio.h>
char get_choice(void);
char get_first(void);
float get_number(void);
int main(void)
{
    int choice;
    float first_number;
    float second_number;

    while ( (choice = get_choice()) != 'q')
    {
        printf("Enter first number: ");
        first_number = get_number();
        printf("Enter second number: ");
        second_number = get_number();
        switch (choice)
        {
            case 'a' :  printf("%.1f + %.2f = %.2f\n", first_number, second_number, first_number + second_number);
                        break;
            case 's' :  printf("%.2f - %.2f = %.2f\n", first_number, second_number, first_number - second_number);
                        break;
            case 'm' :  printf("%.2f * %.2f = %.2f\n", first_number, second_number, first_number * second_number);
                        break;
            case 'd' :  while (second_number == 0)
                        {
                            printf("Enter a number other than 0: ");
                            second_number = get_number();
                        }
                        printf("%.2f / %.2f = %.2f\n", first_number, second_number, first_number / second_number);
                        break;
        }
    }
    printf("Bye.\n");

    return 0;
}

char get_choice(void)
{
    int ch;

    printf("Enter the operation of your choice:\n");
    printf("a. add           s. substract\n");
    printf("m. multiply      d. divide\n");
    printf("q. quit\n");
    ch = get_first();
    while (ch != 'a' && ch != 's' && ch != 'm' && ch != 'd' && ch != 'q')
    {
        printf("Please respond with a, s, m, d or q.\n");
        ch = get_first();
    }
    return ch;
}

char get_first(void)
{
    int ch;
    while ((ch = getchar()) == '\n')
        continue;

    while (getchar() != '\n')
        continue;
    return ch;
}

float get_number(void)
{
    float number;
    char ch;

    while (scanf("%f", &number) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not a number.\nPlease enter a ");
        printf("number, such as 2.5, -1.78E8, or 3: ");
    }

    return number;
}
