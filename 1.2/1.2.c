#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <float.h>

/**
* @brief Функция принимающая и проверяющая значение на ввод.
* @param message - текст сообщения для пользователя.
* @return Значение.
*/
double get_value(const char* message);

/**
 * @brief Функция расчитывающая площадь круга.
 * \param l - длинна круга.
 * \return Площадь.
 */
double get_area(double l);

/**
* @brief Основная функция в программе.
* @return 0 если процесс завершился без ошибок.
*/
int main()
{
    double l = get_value("Enter the length of the circle: ");
    puts("Area: ");
    printf("%lf", get_area(l));
    return 0;
}



double get_area(double l)
{
    double S = ((pow(l, 2) / (4 * M_PI)));
    return S;
}

double get_value(const char* message)
{
    double a;
    printf("%s", message);
    int res = scanf_s("%lf", &a);
    if (res != 1 || a <= DBL_MIN)
    {
        errno = EIO;
        perror("Wrong value");
        abort();
    }
    return a;
}