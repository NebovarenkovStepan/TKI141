#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <time.h>

/**
* @brief Функция находящая первый минимальный элемент массива.
* @param size - размер массива.
* @param array - массив.
* @return Минимальный элемент.
*/
int min_element(size_t size, int* array);

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
* * @param array - массив.
*/
int print_array(size_t size, int* array);

/**
* @brief Функция принимающая и провер¤ющая значение на ввод.
* @param message - текст сообщения для пользователя.
* @return Значение.
*/
int get_value(const char* message);

/**
* @brief Функция вычисляющая максимальный отрицательный элемент массива.
* @param size - размер массива.
* @param array - массив.
* @parm min_e первый минимальный элемент.
* @return максимальный отрицательный элемент массива.
*/
int get_max_element(size_t size, int* array, int min_e);

/**
* @brief Функция считающая количество положительных элементов больших по модулю числу A, которое мы задаем с клавиатуры.
* @param size - размер массива.
* @param array - массив.
* @param a - число A, которое мы задаем с клаиатуры.
* @return количество элементов.
*/
int second_point(size_t size, int* array, int a);

/**
* @brief Функция находящая номер первой пары соседних элементов, сумма которых меньше заданного числа.
* @param size - размер массива.
* @param array - массив.
* @param a - число A, которое мы задаем с клаиатуры.
* @return номер первой пары.
*/
int third_point(size_t size, int* array, int a);

enum random_or_keybord
{
	Keyboard = 1,
	Random = 2
};

/**
 * @brief Функция показывающа¤ какое значение надо ввести для рандома или ввода с клаиатуры.
 */
void names_of_random_and_keyboard();

/**
 * @brief Основная функция, точка входа в программу.
 * @return Возвращает 0, если програма завершилась без ошибок
 */
int main()
{
	size_t size = get_value("Enter array size: ");
    if (size <= 0)
    {
        errno = EIO;
        perror("Wrong value");
        abort();
    }
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
        int min_e = min_element(size, array);
        array[1] = get_max_element(size, array, min_e);
        print_array(size, array);
        int a = get_value("Enter A: ");
        puts("Answer for 2: ");
        int counter = second_point(size, array, a);
        printf("%d\n", counter);
        puts("Answer for 3: ");
        int pair_counter = third_point(size, array, a);
        printf("%d", pair_counter);
        break;
    }
    case Random:
    {
        fill_random(size, array);
        int min_e = min_element(size, array);
        array[1] = get_max_element(size, array, min_e);
        print_array(size, array);
        int a = get_value("Enter A: ");
        puts("Answer for 2: ");
        int counter = second_point(size, array, a);
        printf("%d\n", counter);
        puts("Answer for 3: ");
        int pair_counter = third_point(size, array, a);
        printf("%d", pair_counter);
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

int get_max_element(size_t size, int* array, int min_e)
{
    int amount_max_elements = 0;
    int max_element = min_e;
    for (size_t i = 0; i < size; i++)
    {
        int c = array[i];
        if ( c < 0)
        {
            max_element = max(array[i], max_element);
            amount_max_elements++;
        }
    }
    if (amount_max_elements == 0)
    {
            errno = EIO;
            perror("Wrong array");
            abort();
    }
    else
    {
        return max_element;
    }
}

int second_point(size_t size, int* array, int a)
{
    int counter = 0;
    for (size_t i = 0; i <= size; i++)
    {
        int c = array[i];
        if ( c > 0 && c < abs(a))
            {
                counter++;
            }
    }
    return counter;
}

int third_point(size_t size, int* array, int a)
{
    int pair_counter = 0;
    for (size_t i = 0; i < size - 1; i++)
    {
        pair_counter++;
        if (array[i] + array[i + 1] < a) 
        continue;
    }
    return pair_counter;
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
        array[i] = c ;
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
    unsigned int ttime = time(NULL);
    srand(ttime);
    for (size_t i = 0; i < size; i++)
    {
        array[i] = -10 + rand() % 19;
    }
    return 1;
}

int min_element(size_t size, int* array)
{
    for (size_t i = 0; i < size; i++)
    {
        int c = array[i];
        if (c < 0)
        {
            int min_element = c;
        }
        return min_element;
    }
    errno = EIO;
    perror("Wrong array");
    abort();
}