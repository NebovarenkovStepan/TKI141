#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

/**
* @brief Функция, считающая количество единиц в массиве для его расширения массив.
* @param size - размер массива.
* @param array - массив.
* @return 1 если все хорошо.
*/
int counter_1(size_t size, int* array);

/**
* @brief Функция заполняющая массив m.
* @param size - размер массива.
* @param array - массив.
*/
void fill_array_m(size_t size, int* array, int* array_m);

/**
* @brief Функция, проверяющая содержит ли число единицу.
* @param number - число которое поступает на ввод
* @return 1 если все хорошо.
*/
bool is_one(int number);

/**
* @brief Функция, расширяющая массив.
* @param size - размер массива.
* @param array - массив.
* @return 1 если все хорошо.
*/
int get_wider_array(size_t size, int* array);

/**
* @brief Функция заполняющая массив.
* @param size - размер массива.
* @param array - массив.
* @return 1 если все хорошо.
*/
int fill_array(size_t size, int* array);

/**
* @brief Функция заполняющая массив рандомными числами.
* @param size - размер массива.
* @param array - массив.
* @return 1 если все хорошо.
*/
int fill_random(size_t size, int* array);

/**
* @brief Функция выводящая заполненный массив.
* @param size - размер массива.
* @param array - массив.
* @return 1 если функци¤ завершена без ошибок.
*/
int print_array(size_t size, int* array);

/**
* @brief Функция принимающая и проверяющая значение на ввод.
* @param message - текст сообщение для пользователя.
* @return Значение.
*/
int get_value(const char* message);

/**
* @brief Функция вычисляющая максимальный отрицательный элемент массива.
* @param size - размер массива.
* @param array - массив.
* @return 1 если функция завершена без ошибок.
*/
int change(size_t size, int* array);

/**
 * @brief Функция, показывающая какое значение надо ввести дл¤ рандома или ввода с клаиатуры.
 */
void names_of_random_and_keyboard();

/**
* @brief Функция, вставляющая максимальный элемент массива перед числами, имеющими в своей записи единицу.
* @param size - размер массива.
* @param array - массив.
* @return 1 если функция завершена без ошибок.
*/
int incret_max_element(size_t size, int* array);
enum random_or_keybord
{
	Keyboard = 1,
	Random = 2
};

/**
 * @brief Основная функция, точка входа в программу.
 * @return Возвращает 0, если програма завершилась без ошибок
 */
int main()
{
	int int_size = get_value("Enter array size: ");
	if (int_size <= 0)
	{
		errno = EIO;
		perror("Wrong value");
		return 1;
	}
	size_t size = (size_t)(int_size);
	int* array = (int*)malloc(size * sizeof(int));
	if (array == NULL)
	{
		errno = ENOMEM;
		perror("Error!");
		exit(0);
	}
	names_of_random_and_keyboard();
	int number = get_value("");
	enum random_or_keybord walue = (enum random_or_keybord)(number);
	switch (walue)
	{
	case Keyboard:
	{
		fill_array(size, array);
		break;
	}
	case Random:
	{
		fill_random(size, array);
		break;
	}
	default:
	{
		puts("Error");
		return 1;
	}
	}
	print_array(size, array);
	printf("%s\n", "----");
	change(size, array);
	print_array(size, array);
	printf("%s\n", "----");
	size += counter_1(size, array);
	get_wider_array(size, array);
	incret_max_element(size, array);
	print_array(size, array);
	printf("%s\n", "----");
	int* array_m = (int*)malloc(size * sizeof(int));
	fill_array_m(size, array, array_m);
	print_array(size, array_m);
	free(array);
	free(array_m);
	return 0;
}

int get_value(const char* message)
{
	int a;
	printf("%s", message);
	int res = scanf_s("%d", &a);
	if (res != 1)
	{
		errno = EIO;
		perror("Wrong value");
		abort();
	}
	return a;
}

void names_of_random_and_keyboard()
{
	printf("Keyboard - %d\n", (int)Keyboard);
	printf("Random - %d\n", (int)Random);
}

int fill_array(size_t size, int* array)
{
	for (size_t i = 0; i < size; i++)
	{
		int c = get_value("Enter number from -10 to 10: ");
		if (c < -10 || c > 10)
		{
			errno = EIO;
			perror("Wrong array");
			abort();
		}
		array[i] = c;
	}
	return 1;
}

int print_array(size_t size, int* array)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("%Iu\t%d\n", i, array[i]);
	}
	return 1;
}

int fill_random(size_t size, int* array)
{
	unsigned int ttime = (unsigned int)(time(NULL));
	srand(ttime);
	for (size_t i = 0; i < size; i++)
	{
		array[i] = -10 + rand() % 21;
	}
	return 1;
}

int change(size_t size, int* array)
{
	for (size_t i = size - 1; i > 0; i--)
	{
		if (array[i] > 0)
		{
			array[i] = array[1];
			return 1;
		}
	}
	return 1;
}

int incret_max_element(size_t size, int* array)
{
	const int lowest_element = -10;
	int max_element = lowest_element;
	for (size_t i = 0; i < size; i++)
	{
		int c = array[i];
		max_element = max(array[i], max_element);
	}
	size_t counter_1 = 0;
	int i = 0;
	while (i < size)
	{
		size_t position = i;
		int number = array[i];
		if (is_one(array[i]))
		{
			for (size_t i = size - 1; i > position; i--)
			{
				array[i + 1] = array[i];
			}
			array[position + 1] = number;
			i++;
			array[position] = max_element;
		}
		i++;
	}
	return 1;
}

bool is_one(int number)
{
	number = abs(number);
	while (number > 0)
	{
		if (number % 10 == 1)
		{
			return true;
		}
		number = number / 10;
	}
	return false;
}

int get_wider_array(size_t size, int* array)
{
	array = realloc(array, size * sizeof(int));
	return 1;
}

int counter_1(size_t size, int* array)
{
	int counter_1 = 0;
	for (size_t i = 0; i < size; i++)
	{
		size_t position = i;
		if (is_one(array[i]))
		{
			counter_1++;
		}
	}
	return counter_1;
}

void fill_array_m(size_t size, int* array, int* array_m)
{
	int counter = 0;
	for (size_t i = 0; i < size; i++)
	{
		counter++;
		if (counter == 3)
		{
			counter = 0;
			array_m[i] = i * array[i];
		}
		else
		{
			array_m[i] = -1 * array[i] * (i + 1);
		}
	}
}
