#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/**
 * \brief Function that calculates the possibility of input.
 * \param res is the number of arguments.
 */
void number_of_arguments(int res);
/**
 * \brief Function that calculates y in the first case.
 * \param x is the x parameter.
 * \param a is the a parameter.
 */
void get_y_1(double x, double a);
/**
 * \brief Function that calculates y in the second case.
 * \param x is the x parameter.
 * \param a is the a parameter.
 */
void get_y_2(double x, double a);
int main()
{
    double x, a;
    a = 1.6;
    puts("Enter x: ");
    int res = scanf_s("%lf", &x);
    printf("res=%d\n", res);
    number_of_arguments(res);
    if (x > a) get_y_1(x, a);
    if (x == 0) printf("%s\n", "y = 3");
    if (x < a) if (x != 0) get_y_2(x, a);
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
void get_y_1(double x, double a)
{
    double y = exp(a * x) - 2.5;
    printf("y=%lf\n", y);
}
void get_y_2(double x, double a)
{
    double y = a / x + sin(x);
    printf("y=%lf\n", y);
}