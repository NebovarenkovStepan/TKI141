#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
/**
 * @brief Функция показывает возможность вписания двух прямоугольников в круг.
 * \param a первая сторона первого прямоугольника.
 * \param b вторая сторона первого прямоугольника.
 * \param c первая сторона второго прямоугольника.
 * \param d вторая сторона второго прямоугольника.
 * \param r это радиус.
 * \return возможность.
 */
bool possibility(double a, double b, double c, double d, double r);

/**
 * @brief Функция проеряющая количество аргументов(для 2-ух).
 * \param res количество аргументов.
 */
void number_of_arguments_for_two(int res);

/**
 * @brief Функция проеряющая количество аргументов(для 1-ого).
 * \param res количество аргументов.
 */
void number_of_arguments_for_one(int res);

int main()
{
	double r, a, b, c, d;
	puts("Enter r: ");
	int res1 = scanf_s("%lf", &r);
	number_of_arguments_for_one(res1);
	puts("Enter a, b: ");
	int res2 = scanf_s("%lf%lf", &a, &b);
	number_of_arguments_for_two(res2);
	puts("Enter c, d: ");
	int res3 = scanf_s("%lf%lf", &c, &d);
	number_of_arguments_for_two(res3);
	if (possibility(a, b, c, d, r)) puts("Yes");
	else puts("No");
	return 0;
}

bool possibility(double a, double b, double c, double d, double r)
{
	double x = fmax(a, b);
	double y = fmax(c, d);
	double z = fmin(a, b);
	double w = fmin(c, d);
	double h1 = sqrt(pow(r, 2) - pow(x, 2) / 4);
	double h2 = sqrt(pow(r, 2) - pow(y, 2) / 4);
	double h_summ = h1 + h2;
	double other_sides = z + w;
	return (h_summ >= other_sides);
}

void number_of_arguments_for_two(int res)
{
	if (res != 2)
	{
		puts("Error! ");
		abort();
	}
}

void number_of_arguments_for_one(int res)
{
	if (res != 1)
	{
		puts("Error! ");
		abort();
	}
}