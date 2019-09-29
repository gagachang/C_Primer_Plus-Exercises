#include <stdio.h>
int main(void)
{
    float megabits_per_second;
    float file_length;

    printf("Please enter the speed of downloading (megabits per second), and the length of file (megabytes): \n");
    scanf("%f %f", &megabits_per_second, &file_length);
    printf("At %.2f megabits per second, a file of %.2f megabytes\n", megabits_per_second, file_length);
    printf("downloads in %.2f seconds.\n", file_length*8 / megabits_per_second);

    return 0;
}
