#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>
#include <float.h>

/**
 * @brief Функция расчитывающая значение y при x > a.
 * @param x Входная величина.
 * @param a Входная величина.
 * @return Значение функции.
 */
double get_y_1(double x, double a);

/**
 * @brief Функция расчитывающая значение y при x < a.
 * @param x Входная величина.
 * @param a Входная величина.
 * @return Значение функции.
 */
double get_y_2(double x, double a);

/**
 * @brief Функция принимающая и проверяющая значение на ввод.
 * @return Значение.
 */
double get_value();


/**
 * @brief Основная функция в программе.
 * @return 0 если процесс завершился без ошибок.
 */
int main()
{
    double x;
    const double a = 1.6;
    puts("Enter x: ");
    x = get_value();
    double result = 0;
    if (x > a) // x строго больше а
    {
        result = get_y_1(x, a);
    }
    else if (fabs(x) <= DBL_MIN)
    {
        result = 3;
    }
    else if (x < a) // x строго меньше а
    {
        result = get_y_2(x, a);
    }
    else
    {
        errno = EIO;
        perror("Wrong value");
        return 1;
    }
    puts("Результат: ");
    printf("%lf", result);
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
