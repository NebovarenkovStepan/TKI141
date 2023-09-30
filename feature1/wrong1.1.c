#include <stdio.h>
#include <math.h>
/**
 * \brief Function that calculates and outputs a
 * \param x is x.
 * \param y is y.
 * \param z is z.
 */
void get_a(float x, float y, float z);
/**
 * \brief Function calculating and outputting b
 * \param x is x.
 * \param y is y.
 * \param z is z.
 */
void get_b(float x, float y, float z);
int main()
{
    get_a(1.4, 3.1, 0.5); // a=0.870404
    get_b(1.4, 3.1, 0.5); // b=-50.893158
    return 0;
}
void get_a(float x, float y, float z)
{
    float a = sqrt(z * x * sin(2 * x) + sqrt(expl(-2 * x) * (x + y)));
    float c = expl(-2 * x);
    printf("a= %f\n", a);
}
void get_b(float x, float y, float z)
{
    float b = expl(2 * x) * log(z + x) - pow(y, 3 * x) * log(y - x);
    printf("b= %f\n", b);
}