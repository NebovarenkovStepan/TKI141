#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

int get_max(const size_t size, const int* array);

int* get_array(const size_t size);

size_t get_size(const char* message);

/**
* @brief Функция, считающая количество единиц в массиве для его расширения массив.
* @param size - размер массива.
* @param array - массив.
* @return 1 если все хорошо.
*/
int counter_1(size_t size, const int* array);

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
int print_array(size_t size, const int* array);

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
void fill_array_second_task(size_t size, int* array, int* new_array);

void free_array(int* array);

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
	size_t size  = get_size("Enter array size: ");
	int* array = get_array(size);

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

	size_t new_size = size + counter_1(size, array);
	int* new_array = get_array(new_size);
	//get_wider_array(size, array);
	fill_array_second_task(size, array, new_array);
	print_array(new_size, new_array);
	printf("%s\n", "----");

	int* array_m = get_array(new_size);

	fill_array_m(new_size, new_array, array_m);
	print_array(new_size, array_m);


	free_array(array);
	free_array(new_array);
	free_array(array_m);

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
			perror("Wrong  array");
			abort();
		}
		array[i] = c;
	}
	return 1;
}

int print_array(size_t size,const int* array)
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

void fill_array_second_task(size_t size, int* array, int* new_array)
{
	int max_element = get_max(size, array);
	size_t j = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (is_one(array[i]))
		{
			new_array[j++] = max_element;
		}
		new_array[j++] = array[i];
	}
}

void free_array(int* array)
{
	if (array)
	{
		free(array);
	}
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
	if (array == NULL)
	{
		errno = ENOMEM;
		perror("Error!");
	    abort();
	}
}

int get_max(const size_t size, const int* array)
{
	int max_element = array[0];
	for (size_t i = 0; i < size; i++)
	{
		max_element = max(array[i], max_element);
	}

	return max_element;
}

int* get_array(const size_t size)
{
	int* array = (int*)malloc(size * sizeof(int));
	if (array == NULL)
	{
		errno = ENOMEM;
		perror("Error!");
		abort();
	}

	return array;
}

size_t get_size(const char* message)
{
	int int_size = get_value(message);
	if (int_size <= 0)
	{
		errno = EIO;
		perror("Wrong value");
		return 1;
	}

	return (size_t)int_size;
}

int counter_1(size_t size, const int* array)
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
			array_m[i] = ( -array[i] ) * (i + 1);
		}
	}
}