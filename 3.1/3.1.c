#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
/**
 * \brief A function that calculates the possibility of evaluating an expression for a given value of x.
 * \param x is the argument.
 * \return Return 1 - true and 0 - false
 */
bool answer_possibility(float x);
/**
 * \brief Function that calculates the possibility of input.
 * \param res is the number of arguments.
 */
void number_of_arguments(int res);
int main()
{
    int res;
    float x, dx;
    puts("Enter x: ");
    res = scanf_s("%f", &x);
    number_of_arguments(res);
    puts("Enter dx: ");
    int res1 = scanf_s("%f", &dx);
    number_of_arguments(res1);
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
void number_of_arguments(int res)
{
    if (res != 1)
    {
        puts("Error!");
        abort();
    }
}
