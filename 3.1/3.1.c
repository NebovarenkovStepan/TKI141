#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <errno.h>
#include <float.h>
/**
 * @brief Функция проверяющая существование функции в этой точке.
 * @param x Входной параметр - точка x.
 * @return Возвращает результат.
 */
double result(double x);

/**
* @brief Функция принимающая и проверяющая значение на ввод.
* @param message - текст сообщения для пользователя.
* @return Значение.
*/
double get_value(const char* message);

int main()
{
    const double x_start = get_value("Start for x: ");
    double x = x_start;
    const double dx = get_value("Step for x: ");
    if (dx < 0)
    {
        errno = EIO;
        perror("Wrong value");
        retrun 1;
    }
    const double x_finish = dx + get_value("Finish for x: ");
    while ((x - x_finish) < DBL_EPSILON)
    {
        double y = result(x);
        printf("%lf\t%0.2lf\t\n", x, y);
        x += dx;
    }
    return 0;
}

double result(double x)
{
    return ((3 * x) - 14 + exp(x) - exp(-x));
}

double get_value(const char* message)
{
    double a;
    printf("%s", message);
    int res = scanf_s("%lf", &a);
    if (res != 1)
    {
        errno = EIO;
        perror("Wrong value");
        abort();
    }
    return a;
}
