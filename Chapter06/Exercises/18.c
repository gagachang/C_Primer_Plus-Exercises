/* In the beginning, Rabnud has 5 friends, and
 * Bunbar has 150 friends.
 * Rabnud's growth of number of friends is like below:
 * First week, the number will be (5 - 1) * 2 = 8
 * Second week, the number will be (8 - 2) * 2 = 12
 * ...
 * After Nth week, the number will be (last week - N) * 2
 * Please figure out that how many weeks Rabnud's number of friends
 * will be more than Bunbar's?
 */
#include <stdio.h>
int main(void)
{
    int friends_of_Rabnud = 5;
    const int friends_of_Dunbar = 150;

    for (int i = 1; friends_of_Rabnud < friends_of_Dunbar; i++)
    {
        friends_of_Rabnud = (friends_of_Rabnud - i) * 2;
        printf("The number of Rabnud's friend is %d after %d week(s).\n", friends_of_Rabnud, i);
    }

    return 0;
}
