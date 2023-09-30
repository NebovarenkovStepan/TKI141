#include <stdio.h>
#include<math.h>
#include <stdlib.h>
double c;
/**
 * \brief formula for calculating factorial
 * \param parameter m - the factorial number of which must be calculated
 * \return factorial
 */
double factorial(double m);
/**
 * \brief Function that calculates the possibility of input.
 * \param res is the number of arguments.
 */
void number_of_arguments(int res);
int main()
{
    double n, answ, e;
    answ = 0;
    printf("%s", "Enter n: ");
    int res1 = scanf_s("%lf", &n);
    number_of_arguments(res1);
    printf("%s", "Enter e: ");
    int res2 = scanf_s("%lf", &e);
    number_of_arguments(res2);
    for (int i = 1; i <= n; i++) {
        answ = answ + (pow(-1, i) * (1 / (factorial(i) * factorial(i + 1))));
    }
    printf("%lf\n", answ);
    do {
        answ = answ + (pow(-1, e) * (1 / (factorial(e) * factorial(e + 1))));
        e = e + 1;
    } while (e <= n);
    return 0;
}
double factorial(double m)
{
    c = 1;
    for (int i = 1; i <= m; i++) {
        c = c * i;
    }
    return c;
}
void number_of_arguments(int res)
{
    if (res != 1)
    {
        puts("Error!");
        abort();
    }
}