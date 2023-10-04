#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
double L, S;
/**
 * \brief Function that calculates the possibility of input.
 * \param res is the number of arguments.
 */
void number_of_arguments(int res);
/**
 * \brief Function that calculates the area of ​​a circle.
 * \param L is the length of the circle.
 * \return area
 */
double get_area(double L);
/**
 * \brief Function that checks the area of ​​a circle.
 * \param L is the length of the circle.
 * \return Returns a boolean value, true if L > 0 and false if L <=0.
 */
bool right_numb(double L);
int main()
{
    printf("%s", "Enter the length of the circle: ");
    int res = scanf_s("%lf", &L);
    number_of_arguments(res);
    if (right_numb(L) == 1) printf("S=%lf\n", get_area);
    else printf("%s", "Error!");
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
    double S;
    S = ((pow(L, 2) / (4 * M_PI)));
    return S;
}
bool right_numb(double L)
{
    return L > 0;
}