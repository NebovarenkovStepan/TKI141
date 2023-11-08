#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <time.h>

enum random_or_keybord
{
	Keyboard = 1,
	Random = 2
};

/**
* @brief Функция, выводящая массив без столбцов, которые начинаются с четного элемента.
* @param array - массив.
* @param wide - ширина массива.
* @param высота - ширина массива.
* @return 1 если все хорошо.
*/
int print_array_third_point(int** array, size_t wide, size_t height);

/**
* @brief Функция, заменяющая первые четные элементы каждого столбца в массива максимальным по модулю .
* @param array - массив.
* @param wide - ширина массива.
* @param высота - ширина массива.
* @return 1 если все хорошо.
*/
int change(int** array, size_t wide, size_t hight);

/**
* @brief Функция, заполняющая массив.
* @param array - массив.
* @param wide - ширина массива.
* @param высота - ширина массива.
* @return 1 если все хорошо.
*/
int fill_array(int** array, const size_t wide, const size_t height);

/**
* @brief Функция, заполняющая массив рандомными числами.
* @param array - массив.
* @param wide - ширина массива.
* @param высота - ширина массива.
* @return 1 если все хорошо.
*/
int fill_random(int** array, const size_t wide, const size_t hight);

/**
* @brief Функция, выводящая массив на экран.
* @param array - массив.
* @param wide - ширина массива.
* @param высота - ширина массива.
* @return 1 если все хорошо.
*/
int print_array(int** array, size_t wide, size_t height);

/**
 * @brief Функция, показывающая какое значение надо ввести для рандома или ввода с клаиатуры.
 */
void names_of_random_and_keyboard();

/**
 * @brief Основная функция, точка входа в программу.
 * @return Возвращает 0, если програма завершилась без ошибок
 */
int main()
{
	int int_wide = get_value("Enter array wide: ");
	if (int_wide <= 0)
	{
		errno = EIO;
		perror("Wrong value");
		return 1;
	}
	size_t wide = (size_t)(int_wide);
	int int_height = get_value("Enter array height: ");
	if (int_height <= 0)
	{
		errno = EIO;
		perror("Wrong value");
		return 1;
	}
	size_t height = (size_t)(int_height);
	int** array = (int**)malloc(sizeof(int*) * wide);
	for (int i = 0; i < wide; i++)
	{
		array[i] = (int*)malloc(sizeof(int) * height);
	}
	names_of_random_and_keyboard();
	int number = get_value("");
	enum random_or_keybord walue = (enum random_or_keybord)(number);
	switch (walue)
	{
	case Keyboard:
	{
		fill_array(array, wide, height);
		print_array(array, wide, height);
		puts("------");
		change(array, wide, height);
		print_array(array, wide, height);
		puts("------");
		print_array_third_point(array, wide, height);
		break;
	}
	case Random:
	{
		fill_random(array, wide, height);
		print_array(array, wide, height);
		puts("------");
		change(array, wide, height);
		print_array(array, wide, height);
		puts("------");
		print_array_third_point(array, wide, height);
		break;
	}
	free(array);
	return 0;
	}
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

int print_array(int** array,  size_t wide, size_t height)
{
	if (wide != height)
	{
		int filler = wide;
		wide = height;
		height = filler;
	}
	for (size_t c = 0; c < wide; c++)
	{
		for (size_t i = 0; i < height; i++)
		{
			printf(" %d", array[i][c]);
		}
		printf("\n");
	}
	return 1;
}

int fill_array(int** array, const size_t wide, const size_t height)
{
	for (size_t i = 0; i < wide; i++)
	{
		for (size_t c = 0; c < height; c++)
		{
			array[i][c] = get_value("Enter element: ");
		}
	}
	return 1;
}

int fill_random(int** array, const size_t wide, const size_t height)
{
	unsigned int ttime = (unsigned int)(time(NULL));
	srand(ttime);
	for (size_t i = 0; i < wide; i++)
	{
		for (size_t c = 0; c < height; c++)
		{
			array[i][c] = rand();
		}
	}
	return 1;
}

int change(int** array, size_t wide, size_t height)
{
	int max_element = 0;
	for (size_t i = 0; i < wide; i++)
	{
		for (size_t c = 0; c < height; c++)
		{
			max_element = max(max_element, abs(array[i][c]));
		}
	}
	for (size_t i = 0; i < wide; i++)
	{
		int counter = -1;
		for (size_t c = 0; c < height; c++)
		{
			if (array[i][c] % 2 == 0 && counter != i)
			{
				array[i][c] = max_element;
				counter = i;
			}
		}
	}
	return 1;
}

int print_array_third_point(int** array, size_t wide, size_t height)
{
	if (wide != height)
	{
		int filler = wide;
		wide = height;
		height = filler;
	}
	for (size_t c = 0; c < wide; c++)
	{
		for (size_t i = 0; i < height; i++)
		{
			if (array[i][0] % 2 != 0)
			{
				printf(" %d", array[i][c]);
			}
		}
		printf("\n");
	}
	return 1;
}