#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 * @brief функция рассчитывающая возможность ввода.
 * \param res количесво аргументов.
 */
void number_of_arguments(int res);

/**
 * @brief Функция расчитывающая площадь круга.
 * \param L длинна круга.
 * \return Площадь.
 */
double get_area(double L);

/**
 * @brief Функция расчитывающая площадь круга.
 * \param L длинна круга.
 * \return Условное значение, true если L > 0 и false если L <=0.
 */
bool right_numb(double L);

int main()
{
    double L;
    puts("Enter the length of the circle: ");
    int res = scanf_s("%lf", &L);
    number_of_arguments(res);
    if (right_numb(L))
    {
        printf("S = %lf", get_area(L));
    }
    else puts("Error!");
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

double get_area(double L)
{
    double S = ((pow(L, 2) / (4 * M_PI)));
    return S;
}

bool right_numb(double L)
{
    return L > 0;
}