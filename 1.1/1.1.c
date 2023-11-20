#include <stdio.h>
#include <math.h>
/**
 * @brief Функция расчитывающая и выводящая a
 * \param x это x.
 * \param y это y.
 * \param z это z.
 * \return a.
 */

float get_a(float x, float y, float z);

/**
 * @brief Функция расчитывающая и выводящая b
 * \param x это x.
 * \param y это y.
 * \param z это z.
 * \return b.
 */

float get_b(float x, float y, float z);

int main()
{
    const float x = 1.4;
    const float y = 3.1;
    const float z = 0.5;
    float a = get_a(x, y, z); // a=0.870404
    float b = get_b(x, y, z); // b=-50.893158
    printf("a= %f\n", a);
    printf("b= %f\n", b);
    return 0;
}

float get_a(float x, float y, float z)
{
    float a = sqrt(z * x * sin(2 * x) + sqrt(expl(-2 * x) * (x + y)));
    float c = expl(-2 * x);
    return a;
}

float get_b(float x, float y, float z)
{
    float b = expl(2 * x) * log(z + x) - pow(y, 3 * x) * log(y - x);
    return b;
}