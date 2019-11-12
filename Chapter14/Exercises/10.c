/*
 * This program declares a function pointer array with five elements.
 * And declare five funtions.
 *
 * Let the user input two integers and show the menu.
 * When the user enter the choice, the program will call the function
 * in function pointer array accroding to user's choice.
 */
#include <stdio.h>
#define MENU_ITEMS 5

int add(int x, int y);
int sub(int x, int y);
int mul(int x, int y);
int div(int x, int y);
int mod(int x, int y);

int (* fp_arr[MENU_ITEMS]) (int, int) = {add, sub, mul, div, mod};

int main(void)
{
    int x, y, result;
    int choice;

    puts("Enter two integers (other characters to quit):");
    while (scanf("%d %d", &x, &y) == 2)
    {
        while (getchar() != '\n')
            continue;

        puts("Enter the action you want to that two integers: ");
        puts("1) add   2) sub   3) mul   4) div   5) mod");
        while (scanf("%d", &choice) && (choice < 1 || choice > 5))
        {
            puts("Please enter between 1 - 5.");
            puts("Enter the action you want to that two integers: ");
            puts("1) add   2) sub   3) mul   4) div   5) mod");
        }                
        
        /* If the choice is div or mod, check that if devisor is 0 */
        if ((choice == 4 || choice == 5) && (y == 0))
        {
            puts("\nThe divisor can't be 0, please enter other integers:");
            continue;
        }

        result = (*fp_arr[choice - 1]) (x, y);

        printf("The result is %d\n", result);

        puts("\nEnter two integers (other characters to quit):");
    }
    puts("Bye!!!");

    return 0;
}

int add(int x, int y) { return (x + y); }
int sub(int x, int y) { return (x - y); }
int mul(int x, int y) { return (x * y); }
int div(int x, int y) { return (x / y); }
int mod(int x, int y) { return (x % y); }
