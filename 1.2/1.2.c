#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
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
 * \param length - длинна круга.
 * \return Площадь.
 */
double get_area(double length);

/**
* @brief Основная функция в программе.
* @return 0 если процесс завершился без ошибок.
*/
int main()
{
    double length = get_value("Enter the length of the circle: ");
    puts("Area: ");
    printf("%lf", get_area(length));
    return 0;
}



double get_area(double length)
{
    double area = ((pow(length, 2) / (4 * M_PI)));
    return area;
}

double get_value(const char* message)
{
    double value;
    printf("%s", message);
    int res = scanf_s("%lf", &value);
    if (res != 1 || value <= DBL_MIN)
    {
        errno = EIO;
        perror("Wrong value");
        abort();
    }
    return value;
}