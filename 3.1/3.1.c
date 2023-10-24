#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <errno.h>
#include <float.h>
/**
 * @brief Функция проверяющая существование функции в этой точке.
 * @param x сама точка.
 * @return Возвращает 1 - true или 0 - false
 */
bool answer_possibility(double x);

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
    const double x_finish = get_value("Finish for x: ");
    const double dx = get_value("Step for x: ");
    while ((x - x_finish) <= DBL_MIN)
    {
        if (answer_possibility(x) == 0) 
        {
            printf("x=%f ", x);
            printf("%s\n", "No answer");
        }
        x += dx;
    }
    return 0;
}

bool answer_possibility(double x)
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