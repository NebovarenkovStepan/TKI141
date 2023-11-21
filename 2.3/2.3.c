#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <errno.h>
#include <float.h>

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
* @brief Функция принимающая и проверяющая значение на ввод.
* @param message - текст сообщения для пользователя.
* @return Значение.
*/
double get_value(const char* message);

/**
* @brief Функция получения максимально возможной высоты в круге.
* @param r - Радиус.
* @param side - Значение стороны.
* @return Значение высоты.
*/
double get_h(double r, double side);

/**
* @brief Основная функция в программе.
* @return 0 если процесс завершился без ошибок.
*/
int main()
{
	double r, a, b, c, d;
	r = get_value("Enter r: ");
	a = get_value("Enter a: ");
	b = get_value("Enter b: ");
	c = get_value("Enter c: ");
	d = get_value("Enter d: ");
	if (possibility(a, b, c, d, r))
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	return 0;
}

bool possibility(double a, double b, double c, double d, double r)
{
	double x = fmax(a, b);
	double y = fmax(c, d);
	double z = fmin(a, b);
	double w = fmin(c, d);
	double h1 = get_h(r, x);
	double h2 = get_h(r, y);
	double h_summ = h1 + h2;
	double other_sides = z + w;
	return (h_summ >= other_sides);
}

double get_value(const char* message)
{
	double a;
	printf("%s", message);
	int res = scanf_s("%lf", &a);
	if (res != 1 || a <= DBL_EPSILON)
	{
		errno = EIO;
		perror("Wrong value");
		abort();
	}
	return a;
}

double get_h(double r, double side)
{
	return sqrt(pow(r, 2) - pow(side, 2) / 4);
}