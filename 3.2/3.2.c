#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>
#include <float.h>

/**
 * @brief Формула для расчета факториала
 * @param m - число от которого факториал должен быть посчитан.
 * @return факториал.
 */
double factorial(double m);

/**
* @brief Функция принимающая и проверяющая значение на ввод.
* @param message - текст сообщения для пользователя.
* @return Значение.
*/
double get_value(const char* message);

/**
 * @brief Основная функция в программе.
 * @return 0 если процесс завершился без ошибок.
 */
int main()
{
    double answer_a = 0;
    double answer_b = 0;
    double e = get_value("Enter e: ");
    double n = get_value("Enter n: ");
    for (int i = 1; i <= n; i++)
    {
        answer_a = answer_a +  factorial(i);
    }
    for (int i = 1; i <= n; i++)
    {
        double element = factorial(i);
        if (element - e > DBL_MIN)
        {
            answer_b += element;
        }
    }
    puts("Answer for a: ");
    printf("%lf\n", answer_a);
    puts("Answer for b: ");
    printf("%lf\n", answer_b);
    return 0;
}

double factorial(double m)
{
    if (m < 2)
    {
        return 1;
    }
    else
    {
        return -(1/(m+2)*(m+1));
    }
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