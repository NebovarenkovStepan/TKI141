#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <time.h>

int print_array(int* array, const size_t wide, const size_t height);

enum random_or_keybord
{
    Keyboard = 1,
    Random = 2
};

/**
 * @brief Функция показывающая какое значение надо ввести для рандома или ввода с клаиатуры.
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
		abort();
	}
	size_t wide = (size_t)(int_wide);
	int int_height = get_value("Enter array height: ");
	if (int_height <= 0)
	{
		errno = EIO;
		perror("Wrong value");
		abort();
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
		break;
	}
	case Random:
	{

		break;
	}
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

	int print_array(int* array, const size_t wide, const size_t height)
	{
		for (size_t i = 0; i < wide; i++)
		{
			for (size_t c = 0; c < height; c++)
			{
				int a = *(array + i * i + c);
				printf("%Iu\t%d\n", i, a);
			}
		}
	

		return 1;
	}

	int fill_array(int* array, const size_t wide, const size_t height)
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