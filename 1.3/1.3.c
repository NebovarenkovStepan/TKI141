#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/**
 * @brief Функция расчитывающая возможность ввода.
 * \param res количество аргументов.
 */
void number_of_arguments(int res);
/**
 * @brief Функция расчитывающая давление на дно.
 * \param q это плотность воды.
 * \param g это ускорение свободного падения.
 * \param h это высота столба воды.
 * \return Давление.
 */
double get_pressure(const double q, const double g, double h);
int main()
{
	double h;
	int res;
	const double g = 9.8;
	const double q = 1000;
	printf("%s", "Enter h: ");
	res = scanf_s("%lf", &h);
	number_of_arguments(res);
	puts("Bottom pressure: ");
	printf("P=%lf\n", get_pressure(q, g, h));
	return 0;
}
double get_pressure(double q, double g, double h)
{
	double pressure = q * g * h;
	return pressure;
}
void number_of_arguments(int res)
{
	if (res != 1)
	{
		puts("Error!");
		abort();
	}
}