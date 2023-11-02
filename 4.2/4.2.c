#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <time.h>

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
int print_array(const size_t size, const int* array);

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
* @return максимальный элемент.
*/
int get_max_element(size_t size, int* array);

/**
* @brief Функция вычисляющая максимальный отрицательный элемент массива.
* @param size - размер массива.
* @param array - массив.
* @return 1 если функция завершена без ошибок.
*/
int change(size_t size, int* array);

enum random_or_keybord
{
	Keyboard = 1,
	Random = 2
};

/**
 * @brief Функция показывающая какое значение надо ввести дл¤ рандома или ввода с клаиатуры.
 */
void names_of_random_and_keyboard();

 /**
 * @brief Функция, вставляющая максимальный элемент массива перед числами, имеющими в своей записи единицу.
 * @param size - размер массива.
 * @param array - массив.
 * @return 1 если функция завершена без ошибок.
 */
int incret_max_element(size_t size, int* array, int max_element);

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
		abort();
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
		change(size, array);
		int max_element = get_max_element;

		break;
	}
	case Random:
	{
		fill_random(size, array);
		change(size, array);
		int max_element = get_max_element;

		break;
	}
	default:
	{
		puts("Error");
		abort();
	}
	}
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

int print_array(const size_t size, const int* array)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("%Iu\t%d\n", i, array[i]);
	}
	free(array);
	return 1;
}

int fill_random(size_t size, int* array)
{
	unsigned int ttime = time(NULL);
	srand(ttime);
	for (size_t i = 0; i < size; i++)
	{
		array[i] = -10 + rand() % 19;
	}
	return 1;
}

int change(size_t size, int* array)
{
	for (size_t i = size; i > 0; --i)
	{
		if (array[i] > 0)
		{
			array[i] = array[1];
			return 1;
		}
	}
}

int get_max_element(size_t size, int* array)
{
	const int lowest_element = -10;
	int max_element = lowest_element;
	for (size_t i = 0; i < size; i++)
	{
		int c = array[i];
		max_element = max(array[i], max_element);
	}
	return max_element;
}

int incret_max_element(size_t size, int* array, int max_element)
{
	for (size_t i = 0; i < size; i++)
	{
		char c = (char)(array[i]);
		size_t position = i;
		if (strstr(c,"1") != NULL)
		{
			array = realoloc(array, (int*)malloc((size + 1) * sizeof(int)));
			for (size_t i = size - 1; i >= position - 1; i--)
			{
				array[i + 1] = array[i];
			}
			array[position - 1] = max_element;
		}
	}
}

