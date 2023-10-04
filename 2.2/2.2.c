#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
/**
 * \brief Function that calculates the possibility of input.
 * \param res is the number of arguments.
 */
void number_of_arguments(int res);
/**
 * \brief Function that calculates y in the first case.
 * \param x is the x parameter.
 * \param a is the a parameter.
 * \return y.
 */
double get_y_1(double x, double a);
/**
 * \brief Function that calculates y in the second case.
 * \param x is the x parameter.
 * \param a is the a parameter.
 * \return y.
 */
double get_y_2(double x, double a);
int main()
{
    double x;
    const double a = 1.6;
    puts("Enter x: ");
    int res = scanf_s("%lf", &x);
    printf("res=%d\n", res);
    number_of_arguments(res);
    if (x > a) printf("y=%lf\n", get_y_1(x, a));
    else if (x < a && x != 0) printf("y=%lf\n", get_y_2(x, a));
    else printf("%s\n", "y = 3");
    return 0;
}
void number_of_arguments(int res)
{
    if (res != 1)
    {
        puts("Error!");
        abort();
    }
}
double get_y_1(double x, double a)
{
    double y = exp(a * x) - 2.5;
    return y;
}
double get_y_2(double x, double a)
{
    double y = a / x + sin(x);
    return y;
}