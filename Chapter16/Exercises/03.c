/*
 * A program that converts the polar coordinate to rectangular.
 * Input will be the magnitude and angle.
 * Output will be x and y.
 *
 * Note:
 * First converting the angle to rad (angle * PI / 180)
 * PI can be calculated as (atan(1) * 4)
 * Then x = magnitude * cos(rad), y = magnitude * sin(rad)
 */
#include <stdio.h>
#include <math.h>

#define DEG_TO_RAD ((4 * atan(1)) / 180)

typedef struct polar {
    double magnitude;
    double angle;
} Polar;

typedef struct rect {
    double x;
    double y;
} Rect;

Rect polar_to_rect(Polar);

int main(void)
{
    Polar input;
    Rect result;

    puts("Enter the magnitude and angle; enter q to quit: ");
    while (scanf("%lf %lf", &input.magnitude, &input.angle) == 2)
    {
        result = polar_to_rect(input);
        printf("x = %.2f, y = %.2f\n", result.x, result.y);
    }
    puts("Bye!");

    return 0;
}

Rect polar_to_rect(Polar p)
{
    Rect r;
    double rad = p.angle * DEG_TO_RAD;

    r.x = p.magnitude * cos(rad);
    r.y = p.magnitude * sin(rad);

    return r;
}
