#include <stdio.h>
#include<math.h>
int c;
/**
 * \brief formula for calculating factorial
 * \param parameter m - the factorial number of which must be calculated
 * \return factorial 
 */
int factorial(int m);
int main()
{
    double n, answ, e;
    printf("%s\n", "Enter n: ");
    scanf("%lf", &n);
    printf("%s\n", "Enter e: ");
    scanf("%lf", &e);
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
int factorial(int m)
{
    c = 1;
    for (int i = 1; i <= m; i++) {
        c = c * i;
    }
    return c;
}