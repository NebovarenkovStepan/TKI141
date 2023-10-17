#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#include <errno.h>

/**
 * @brief Формула для расчета факториала
 * @param m - число от которого факториал должен быть посчитан.
 * @return факториал.
 */
double factorial(double m);

/**
 * @brief Функция принимающая и проверяющая значение на ввод.
 * @return Значение.
 */
double get_value();

int main()
{
    double n, answ;
    answ = 0;
    printf("%s", "Enter n: ");
    n = get_value();
    for (int i = 1; i <= n; i++)
    {
        answ = answ + (pow(-1, i) * (1 / (factorial(i) * factorial(i + 1))));
    }
    printf("%lf\n", answ);
}
double factorial(double m)
{
    if (m >= 0 && m <= 1) return 1;
    else
    {
        do {
            return factorial(m - 1) * m;
        } while (m > 1);
    }
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