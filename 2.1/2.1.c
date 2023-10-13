#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum peremetr_or_area
{
    Peremetr = 1,
    Area = 2
};

/**
 * @brief Функция показывающая какое значение надо ввести для площади или периметра.
 */
void names_of_peremetr_and_area();

/**
 * @brief Функция расчитывающая периметр.
 * \param AB это первая сторона.
 * \param BC это вторая сторона.
 * \param AC это третья сторона.
 * \return Возвращает значение периметра.
 */
double get_peremetr(double AB, double BC, double AC);

/**
 * @brief Функция расчитывающая площадь.
 * \param AB это первая сторона.
 * \param BC это вторая сторона.
 * \param AC это третья сторона.
 * \return Возвращает значение площадь.
 */
double get_area(double AB, double BC, double AC);

/**
 * @brief Функция расчитывающая сторону
 * \param x1 это первая x-координата.
 * \param y1 это первая y-координата.
 * \param x2 это вторая x-координата.
 * \param y2 это вторая y-координата.
 * \return Возвращает значение стороны.
 */
double get_distance(double x1, double y1, double x2, double y2);

/**
 * @brief Функция расчитывающая возможность ввода.
 * \param res количество аргументов.
 */
void number_of_arguments(int res);

/**
 * @brief Функция расчитывающая возможность ввода таких координат.
 * \param x1 это первая x-координата.
 * \param y1 это первая y-координата.
 * \param x2 это вторая x-координата.
 * \param y2 это вторая y-координата.
 */
void coordinates(double x1, double y1, double x2, double y2);

int main()
{
    double x1, y1, x2, y2, x3, y3;
    double AB, BC, AC;
    int res, number;
    printf("%s", "Enter x1 and y1: ");
    res = scanf_s("%lf%lf", &x1, &y1);
    number_of_arguments(res);
    printf("%s", "Enter x2 and y2: ");
    res = scanf_s("%lf%lf", &x2, &y2);
    number_of_arguments(res);
    coordinates(x1, y1, x2, y2);
    printf("%s", "Enter x3 and y3: ");
    res = scanf_s("%lf%lf", &x3, &y3);
    number_of_arguments(res);
    coordinates(x2, y2, x3, y3);
    coordinates(x1, y1, x3, y3);
    AB = get_distance(x1, y1, x2, y2);
    BC = get_distance(x2, y2, x3, y3);
    AC = get_distance(x1, y1, x3, y3);
    puts("Enter peremetr or area: ");
    names_of_peremetr_nd_area();
    res = scanf_s("%d", &number);
    enum peremetr_or_area walue = (enum peremetr_or_area)(number);
    switch (walue)
    {
    case Peremetr:
    {
        double P = get_peremetr(AB, BC, AC);
        puts("Peremetr - ");
        printf("%lf", P);
        break;
    }
    case Area:
    {
        double S = get_peremetr(AB, BC, AC);
        puts("Area - ");
        printf("%lf", S);
        break;
    }
    default:
    {
        puts("Error");
        abort();
    }
    }
    return 0;
}
double get_distance(double x1, double y1, double x2, double y2)
{
    double side = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return(side);
}

void number_of_arguments(int res)
{
    if (res != 2)
    {
        puts("Error!");
        abort();
    }
}

void coordinates(double x1, double y1, double x2, double y2)
{
    if (x1 == x2) if (y1 == y2)
    {
        puts("Error!");
        abort();
    }
}

double get_peremetr(double AB, double BC, double AC)
{
    return AB + BC + AC;
}

double get_area(double AB, double BC, double AC)
{
    double P = get_peremetr(AB, BC, AC);
    double p = P / 2;
    return sqrt(p * (p - AB) * (p - BC) * (p - AC));
}

void names_of_peremetr_and_area()
{
    printf("Peremetr - %d\n", (int)Peremetr);
    printf("Area - %d\n", (int)Area);
}