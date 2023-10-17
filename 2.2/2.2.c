#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>

/**
 * @brief Функция расчитывающая 1-ый случай.
 * @param x это x.
 * @param a это a.
 * @return y.
 */
double get_y_1(double x, double a);

/**
 * @brief Функция расчитывающая 2-ой случай.
 * @param x это x.
 * @param a это a.
 * @return y.
 */
double get_y_2(double x, double a);

/**
 * @brief Функция принимающая и проверяющая значение на ввод.
 * @return Значение.
 */
double get_value();

int main()
{
    double x;
    const double a = 1.6;
    puts("Enter x: ");
    x = get_value();
    if (x > a) printf("y=%lf\n", get_y_1(x, a));
    else if (x == 0) printf("%s\n", "y = 3");
    else if (x < a) printf("y=%lf\n", get_y_2(x, a));
    else
    {
        errno = EIO;
        perror("Wrong value");
        return 1;
    }
    return 0;
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

double get_value()
{
    double a;
    int res = scanf_s("%lf", &a);
    if (res != 1)
    {
        errno = EIO;
        perror("Wrong value");
        abort();
    }
    return a;
}