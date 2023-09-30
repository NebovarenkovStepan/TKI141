#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * \brief Function calculating side
 * \param x1 is the first x-coordinate.
 * \param y1 is the first coordinate of the game.
 * \param x2 is the second x-coordinate.
 * \param y2 is the second coordinate along the game.
 * \return Return the side value.
 */
double get_distance(double x1, double y1, double x2, double y2);
/**
 * \brief Function that calculates the possibility of input.
 * \param res is the number of arguments.
 */
void number_of_arguments(int res);
/**
 * \brief Function that calculates the possibility of entering coordinate data
 * \param x1 is the first x-coordinate.
 * \param y1 is the first y-coordinate.
 * \param x2 is the second x-coordinate.
 * \param y2 is the second y-coordinate.
 */
void coordinates(double x1, double y1, double x2, double y2);
int main()
{
    double x1, y1, x2, y2, x3, y3;
    double AB, BC, AC;
    double P, S, p;
    int res;
    printf("%s", "Enter x1 and y1: ");
    res = scanf_s("%lf%lf", &x1, &y1);
    number_of_arguments(res);
    printf("%s", "Enter x2 and y2: ");
    res = scanf_s("%lf%lf", &x2, &y2);
    number_of_arguments(res);
    coordinates(x1, y1, x2, y2);
    printf("%s", "Enter x3 and y3: ");
    res = scanf_s("%lf%lf", &x3, &y3);
    number_of_arguments(res);
    coordinates(x2, y2, x3, y3);
    coordinates(x1, y1, x3, y3);
    AB = get_distance(x1, y1, x2, y2);
    BC = get_distance(x2, y2, x3, y3);
    AC = get_distance(x1, y1, x3, y3);
    P = AB + BC + AC;
    p = P / 2;
    S = sqrt(p * (p - AB) * (p - BC) * (p - AC));
    printf("%s", "Perimetr ");
    printf("P=%lf\n", P);
    printf("%s", "Area ");
    printf("S=%lf\n", S);
    return 0;
}
double get_distance(double x1, double y1, double x2, double y2)
{
    double AB = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    printf("AB=%lf\n", AB);
    return(AB);
}
void number_of_arguments(int res)
{
    if (res != 2)
    {
        puts("Error!");
        abort();
    }
}
void coordinates(double x1, double y1, double x2, double y2)
{
    if (x1 == x2) if (y1 == y2)
    {
        puts("Error!");
        abort();
    }
}