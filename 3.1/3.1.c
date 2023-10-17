#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <errno.h>

/**
 * @brief Функция проверяющая существование функции в этой точке.
 * @param x сама точка.
 * @return Возвращает 1 - true или 0 - false
 */
bool answer_possibility(float x);

/**
 * @brief Функция принимающая и проверяющая значение на ввод.
 * @return Значение.
 */
double get_value();

int main()
{
    int res;
    float x, dx;
    puts("Enter x: ");
    x = get_value();
    puts("Enter dx: ");
    dx = get_value();
    do {
        if (answer_possibility(x) == 0) {
            printf("x=%f\n", x);
            printf("%s\n", "No answer");
        }
        x = x + dx;
    } while (x <= 3);
    return 0;
}

bool answer_possibility(float x)
{
    return ((3 * x) - 14 + exp(x) - exp(-x));
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