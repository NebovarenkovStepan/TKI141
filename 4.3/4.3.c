#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <time.h>

/**
* @brief Функция принимающая и проверяющая значение на ввод.
* @param message - текст сообщение для пользователя.
* @return Значение типа size_t.
*/
int get_parametrs(const char* message);

/**
* @brief Функция, очищающая массив.
* @param array - массив.
* */
void free_array(int** array);

/**
* @brief Функция, создающая двумерный массив.
* @param array - массив.
* @param lines - количество строк.
* @param columns - количество столбцов.
* @return массив.
*/
int** create_arry(lines, columns);

/**
* @brief Функция, проверяющая границы массива.
* @param minimum_limit - нижняя граница массива.
* @param maximum_limit - верхняя граница массива.
*/
void limits_check(const int minimum_limit, const int maximum_limit);

/**
* @brief Выбор заполнения массива.
*/
enum random_or_keybord
{
	/**
	* @brief Ручной способ.
	*/
	Keyboard = 1,

	/**
	* @brief Заполнение массива случайными числами.
	*/
	Random = 2
};

/**
* @brief Функция, находящая максимальный элемент массива по модулю .
* @param array - массив.
* @param lines - количество строк.
* @param columns - количество столбцов.
* @return максимальный элемент по модулю.
*/
int find_max_element(int** array, size_t lines, size_t columns);

/**
* @brief Функция принимающая и проверяющая значение на ввод.
* @param message - текст сообщение для пользователя.
* @return Значение.
*/
int get_value(const char* message);

/**
* @brief Функция, выводящая массив без столбцов, которые начинаются с четного элемента.
* @param array - массив.
* @param lines - количество строк.
* @param columns - количество столбцов.
*/
void print_array_third_point(int** array, size_t lines, size_t columns);

/**
* @brief Функция, заменяющая первые четные элементы каждого столбца в массива максимальным по модулю .
* @param array - массив.
* @param lines - количество строк.
* @param columns - количество столбцов.
*/
void change(int** array, int** new_array, size_t lines, size_t columns);

/**
* @brief Функция, заполняющая массив.
* @param array - массив.
* @param lines - количество строк.
* @param columns - количество столбцов.
*/
void fill_array(int** array, const size_t lines, const size_t columns);

/**
* @brief Функция, заполняющая массив рандомными числами.
* @param array - массив.
* @param lines - количество строк.
* @param columns - количество столбцов.
*/
void fill_random(int** array, const size_t lines, const size_t columns);

/**
* @brief Функция, выводящая массив на экран.
* @param array - массив.
* @param lines - количество строк.
* @param columns - количество столбцов.
*/
void print_array(int** array, size_t lines, size_t columns);

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

	size_t wide = get_parametrs("Enter array wide: ");
	size_t height = get_parametrs("Enter array height: ");
	int** array = create_arry(wide, height);
	names_of_random_and_keyboard();
	int number = get_value("");
	enum random_or_keybord walue = (enum random_or_keybord)(number);
	switch (walue)
	{
	case Keyboard:
	{
		fill_array(array, wide, height);
		break;
	}
	case Random:
	{
		fill_random(array, wide, height);
		break;
	}
	default:
	{
		errno = EIO;
		perror("Wrong value");
		return 1;
	}
	}
	print_array(array, wide, height);
	puts("------");

	int** new_array = create_arry(wide, height);
	change(array, new_array, wide, height);
	puts("------");

	print_array_third_point(array, wide, height);
	
	free_array(array);
	free_array(new_array);
	return 0;
}
int get_value(const char* message)
{
	int value;
	printf("%s", message);
	int res = scanf_s("%d", &value);
	if (res != 1)
	{
		errno = EIO;
		perror("Wrong value");
		abort();
	}
	return value;
}

void names_of_random_and_keyboard()
{
	printf("Keyboard - %d\n", (int)Keyboard);
	printf("Random - %d\n", (int)Random);
}

void print_array(int** array,  size_t lines, size_t columns)
{
	if (lines != columns)
	{
		int filler = lines;
		lines = columns;
		columns = filler;
	}
	for (size_t c = 0; c < lines; c++)
	{
		for (size_t i = 0; i < columns; i++)
		{
			printf("%d\t", array[i][c]);
		}
		printf("\n");
	}
}

void fill_array(int** array, const size_t lines, const size_t columns)
{
	for (size_t i = 0; i < lines; i++)
	{
		for (size_t c = 0; c < columns; c++)
		{
			array[i][c] = get_value("Enter element: ");
		}
	}
}

void fill_random(int** array, const size_t lines, const size_t columns)
{
	const int minimum_limit = get_value("Enter the lower bound of the array: ");
	const int maximum_limit = get_value("Enter the upper bound of the array: ");
	limits_check(minimum_limit, maximum_limit);
	unsigned int ttime = (unsigned int)(time(NULL));
	srand(ttime);
	for (size_t i = 0; i < lines; i++)
	{
		for (size_t c = 0; c < columns; c++)
		{
			array[i][c] = minimum_limit + rand() % (maximum_limit - minimum_limit + 1);
		}
	}
}

void change(const int** array, int** new_array, size_t lines, size_t columns)
{
	for (size_t i = 0; i < lines; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			new_array[i][j] = array[i][j];
		}
	}
	int max_element = find_max_element(array, lines, columns);
	for (size_t i = 0; i < lines; i++)
	{
		int counter = -1;
		for (size_t c = 0; c < columns; c++)
		{
			if (array[i][c] % 2 == 0 && counter != i)
			{
				new_array[i][c] = max_element;
				counter = i;
			}
		}
	}
	print_array(new_array, lines, columns);
}

void print_array_third_point(int** array, size_t lines, size_t columns)
{
	if (lines != columns)
	{
		int filler = lines;
		lines = columns;
		columns = filler;
	}
	for (size_t c = 0; c < lines; c++)
	{
		for (size_t i = 0; i < columns; i++)
		{
			if (array[i][0] % 2 != 0)
			{
				printf("%d\t", array[i][c]);
			}
		}
		printf("\n");
	}
}

int find_max_element(int** array, size_t lines, size_t columns)
{
	int max_element = array[0][0];
	for (size_t i = 0; i < lines; i++)
	{
		for (size_t c = 0; c < columns; c++)
		{
			if ((abs(array[i][c])) > abs(max_element))
			{
				max_element = array[i][c];
			}
		}
	}
	return max_element;
}

int get_parametrs(const char* message)
{
	int value;
	printf("%s", message);
	int res = scanf_s("%d", &value);
	if (res != 1 || value <= 0)
	{
		errno = EIO;
		perror("Wrong value");
		abort();
	}
	return (size_t)value;
}

void limits_check(const int minimum_limit, const int maximum_limit)
{
	if (maximum_limit < minimum_limit)
	{
		errno = EIO;
		perror("Wrong limits");
		abort();
	}
}

int** create_arry(wide, height)
{
	int** array = (int**)malloc(sizeof(int*) * wide);
	for (int i = 0; i < wide; i++)
	{
		array[i] = (int*)malloc(sizeof(int) * height);
	}
	return array;
}

void free_array(int** array)
{
	if (array != NULL)
	{
		free(array);
	}
}