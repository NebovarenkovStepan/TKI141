#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

enum peremetr_or_area
{
    Peremetr = 1,
    Area = 2
};

/**
 * @brief Функция считывающая и проверяющая значение.
 * @return Значение перменной.
 */
int get_value();

/**
 * @brief Функция считывающая и проверяющая значения координат.
 * @return Значение координат.
 */
double get_coord();

/**
 * @brief Функция показывающая какое значение надо ввести для площади или периметра.
 */
void names_of_peremetr_and_area();

/**
 * @brief Функция расчитывающая периметр.
 * @param AB это первая сторона.
 * @param BC это вторая сторона.
 * @param AC это третья сторона.
 * @return Возвращает значение периметра.
 */
double get_peremetr(double AB, double BC, double AC);

/**
 * @brief Функция расчитывающая площадь.
 * @param AB это первая сторона.
 * @param BC это вторая сторона.
 * @param AC это третья сторона.
 * @return Возвращает значение площадь.
 */
double get_area(double AB, double BC, double AC);

/**
 * @brief Функция расчитывающая сторону
 * @param x1 это первая x-координата.
 * @param y1 это первая y-координата.
 * @param x2 это вторая x-координата.
 * @param y2 это вторая y-координата.
 * @return Возвращает значение стороны.
 */
double get_distance(double x1, double y1, double x2, double y2);

/**
 * @brief Функция расчитывающая возможность ввода таких координат.
 * @param x1 это первая x-координата.
 * @param y1 это первая y-координата.
 * @param x2 это вторая x-координата.
 * @param y2 это вторая y-координата.
 */
void coordinates(double x1, double y1, double x2, double y2);

int main()
{
    double x1, y1, x2, y2, x3, y3;
    double AB, BC, AC;
    int number;
    printf("%s", "Enter x1: ");
    x1 = get_coord();
    puts("Enter y1: ");
    y1 = get_coord();
    printf("%s", "Enter x2: ");
    x2= get_coord();
    puts("Enter y2: ");
    y2 = get_coord();
    coordinates(x1, y1, x2, y2);
    printf("%s", "Enter x3: ");
    x3 = get_coord();
    puts("Enter y3: ");
    y3 = get_coord();
    coordinates(x2, y2, x3, y3);
    coordinates(x1, y1, x3, y3);
    AB = get_distance(x1, y1, x2, y2);
    BC = get_distance(x2, y2, x3, y3);
    AC = get_distance(x1, y1, x3, y3);
    puts("Enter peremetr or area: ");
    names_of_peremetr_and_area();
    number = get_value();
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
        double S = get_area(AB, BC, AC);
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

void coordinates(double x1, double y1, double x2, double y2)
{
    if (fabs(x1-x2) <= DBL_MIN) if (fabs((y1-y2) <= DBL_MIN))
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

double get_coord()
{
    double a;
    int res = scanf_s("%lf", &a);
    if (res != 1)
    {
        puts("Error");
        abort();
    }
    return a;
}

int get_value()
{
    int meaning;
    int res = scanf_s("%d", &meaning);
    if (res != 1)
    {
        puts("Error");
        abort();
    }
    return meaning;
}
