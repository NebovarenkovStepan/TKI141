#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
/**
 * @brief Функция расчитывающая возможность ввода.
 * \param res количество аргументов.
 */
void number_of_arguments(int res);
/**
 * @brief Функция расчитывающая 1-ый случай.
 * \param x это x.
 * \param a это a.
 * \return y.
 */
double get_y_1(double x, double a);
/**
 * @brief Функция расчитывающая 2-ой случай.
 * \param x это x.
 * \param a это a.
 * \return y.
 */
double get_y_2(double x, double a);
int main()
{
    double x;
    const double a = 1.6;
    puts("Enter x: ");
    int res = scanf_s("%lf", &x);
    number_of_arguments(res);
    if (x > a) printf("y=%lf\n", get_y_1(x, a));
    else if (x < a && x != 0) printf("y=%lf\n", get_y_2(x, a));
    else if (x == 0) printf("%s\n", "y = 3");
    else
    {
        puts("Error!");
        abort();
    }
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