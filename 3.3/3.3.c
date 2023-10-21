#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <errno.h>

/**
 * @brief Функция принимающая и проверяющая значение на ввод.
 * @return Значение.
 */
double get_value();

/**
 * @brief Функция возвращающая значение функции.
 * @param x - параметр.
 * @return Значение функции.
 */
double function(double x);

/**
 * @brief Функция возвращающая значение функции.
 * @param x - параметр.
 * @return Значение функции.
 */
double summ(double x, double e);

int main()
{
	double step;
	double const a = 0.1;
	double x = a;
	double const b = 0.8;
	puts("Enter step: ");
	step = get_value();
	double e = pow(40, -5);
	for (double i = a; i - b <= DBL_MIN; i += step)
	{
		printf("%lf\t%lf\t%lf\t\n", i, function(i), summ(i, e));
	}

}

double function(double x)
{
	return log(1 / (2 + 2 * x + pow(x, 2)));
}

double summ(double x, double e)
{
	double sum = 0;
	int i = 1;
	double s_i = pow(-1, i) * (pow((1 + x), 2 * i) / (i + 1));
	sum += s_i;
	for (int i = 2; s_i > e; i++)
	{
		s_i += pow(-1, i) * (pow((1 + x), 2 * i) / (i + 1));
		sum += s_i;
	}
	return sum;
}

double get_value()
{
	double a;
	int res = scanf_s("%lf", &a);
	if (res != 1)
	{
		errno = EIO;
		perror("Wrong value");
		abort();
	}
	return a;
}