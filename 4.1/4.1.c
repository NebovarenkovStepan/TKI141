#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <time.h>
/**
* @brief ‘ункци€ принимающа€ и провер€юща€ значение на ввод.
* @param message - текст сообщени€ дл€ пользовател€.
* @return «начение размера массива.
*/
int get_size(const char* message);

/**
* @brief ‘ункци€ принимающа€ и провер€юща€ значение на ввод.
* @param message - текст сообщени€ дл€ пользовател€.
* @return «начение.
*/
int get_value(const char* message);

/**
* @brief ‘ункци€ вычисл€юща€ максимальный отрицательный элемент массива.
* @param size - размер массива.
* @param array - массив.
* @return максимальный отрицательный элемент массива.
*/
int get_max_element(size_t size, int array[]);

/**
* @brief ‘ункци€ считающа€ количество положительных элементов больших по модулю числу A, которое мы задаем с клавиатуры.
* @param size - размер массива.
* @param array - массив.
* @param a - число A, которое мы задаем с клаиатуры.
* @return количество элементов.
*/
int second_point(size_t size, int array[], int a);

/**
* @brief ‘ункци€ наход€ща€ номер первой пары соседних элементов, сумма которых меньше заданного числа.
* @param size - размер массива.
* @param array - массив.
* @param a - число A, которое мы задаем с клаиатуры.
* @return номер первой пары.
*/
int third_point(size_t size, int array[], int a);

enum random_or_keybord
{
	Keyboard = 1,
	Random = 2
};

/**
 * @brief ‘ункци€ показывающа€ какое значение надо ввести дл€ рандома или ввода с клаиатуры.
 */
void names_of_random_and_keyboard();

int main()
{
    unsigned int ttime = time(NULL);
    srand(ttime);
	size_t size = get_size("Enter array size: ");
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
        for (int i = 0; i < size; i++)
        {
            array[i] = get_value("Enter number from -10 to 10: ");
        }
        array[1] = get_max_element(size, array);
        for (int i = 0; i < size; i++)
        {
            printf("%d\t%d\n", i, array[i]);
        }
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
        for (int i = 0; i < size; i++)
        {
            array[i] = -10 + rand() % 19;
        }
        array[1] = get_max_element(size, array);
        for (int i = 0; i < size; i++)
        {
            printf("%d\t%d\n", i, array[i]);
        }
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

int get_size(const char* message)
{
	int a;
	printf("%s", message);
	int res = scanf_s("%d", &a);
	if (res != 1 || a <= 0)
	{
		errno = EIO;
		perror("Wrong value");
		abort();
	}
	return a;
}

int get_value(const char* message)
{
	int a;
	printf("%s", message);
	int res = scanf_s("%d", &a);
	if (res != 1 || 10 <= a <= -10)
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

int get_max_element(size_t size, int array[])
{
    int max_element = -11;
    for (int i = 0; i < size; i++)
    {
        int c = array[i];
        if ( c < 0 && c > max_element)
        {
            max_element = array[i];
        }
    }
    if (max_element <= -11)
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

int second_point(size_t size, int array[], int a)
{
    int counter = 0;
    for (int i = 0; i <= size; i++)
    {
        int c = array[i];
        if ( c > 0 && c < abs(a))
            {
                counter++;
            }
    }
    return counter;
}

int third_point(size_t size, int array[], int a)
{
    int pair_counter = 0;
    for (int i = 0; i < size - 1; i++)
    {
        pair_counter++;
        if (array[i] + array[i + 1] < a) 
        continue;
    }
    return pair_counter;
}