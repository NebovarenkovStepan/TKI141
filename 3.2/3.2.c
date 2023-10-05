#include <stdio.h>
#include<math.h>
#include <stdlib.h>
double c;
/**
 * @brief formula for calculating factorial
 * \param parameter m - the factorial number of which must be calculated
 * \return factorial
 */
double factorial(double m);
/**
 * @brief Function that calculates the possibility of input.
 * \param res is the number of arguments.
 */
void number_of_arguments(int res);
int main()
{
    double n, answ;
    answ = 0;
    printf("%s", "Enter n: ");
    int res1 = scanf_s("%lf", &n);
    number_of_arguments(res1);
    for (int i = 1; i <= n; i++) {
        answ = answ + (pow(-1, i) * (1 / (factorial(i) * factorial(i + 1))));
    }
    printf("%lf\n", answ);
}
double factorial(double m)
{
    if (m >= 0 && m <= 1) return 1;
    else
    {
        do {
            return factorial(m-1) * m;
        } while (m > 1);
    } 
}
void number_of_arguments(int res)
{
    if (res != 1)
    {
        puts("Error!");
        abort();
    }
}