#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * \brief A function that calculates the possibility of evaluating an expression for a given value of x.
 * \param x is the argument.
 * \return Return 1 - true and 0 - false
 */
float answer_possibility(float x);
/**
 * \brief Function that calculates the possibility of input.
 * \param res is the number of arguments.
 */
void number_of_arguments(int res);
int main()
{
    int res;
    float x, dx;
    res = scanf_s("%f", &x);
    number_of_arguments(res);
    scanf_s("%f", &dx);
    number_of_arguments(res);
    do {
        if (answer_possibility(x) == 0) printf("x=%f\n", x);
        if (answer_possibility(x) == 0) printf("%s\n", "No answer");
        x = x + dx;
    } while (x <= 3);
    return 0;
}
float answer_possibility(float x)
{
    if ((3 * x) - 14 + exp(x) - exp(-x)) return 1;
    else return 0;
}
void number_of_arguments(int res)
{
    if (res != 2)
    {
        puts("Error!");
        abort();
    }
}
