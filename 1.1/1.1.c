#include <stdio.h>
#include <math.h>
/**
 * \brief Function that calculates and outputs a
 * \param x is x.
 * \param y is y.
 * \param z is z.
 * \return a.
 */
double get_a(float x, float y, float z);
/**
 * \brief Function calculating and outputting b
 * \param x is x.
 * \param y is y.
 * \param z is z.
 * \return b.
 */
double get_b(float x, float y, float z);
int main()
{
    const double x = 1.4;
    const double y = 3.1;
    const double z = 0.5;
    double a = get_a(x, y, z); // a=0.870404
    double b = get_b(x, y, z); // b=-50.893158
    printf("a= %f\n", a);
    printf("b= %f\n", b);
    return 0;
}
double get_a(float x, float y, float z)
{
    float a = sqrt(z * x * sin(2 * x) + sqrt(expl(-2 * x) * (x + y)));
    float c = expl(-2 * x);
    return a;
}
double get_b(float x, float y, float z)
{
    float b = expl(2 * x) * log(z + x) - pow(y, 3 * x) * log(y - x);
    return b;
}