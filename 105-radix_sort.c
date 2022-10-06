#include "sort.h"


/**
 * max - a function to find the maximum value in array of integer.
 *
 * @array: the input array
 * @size: the size of the array
 *
 * Return: the maximum integer from the array
 */
int max(int *array, size_t size)
{
	size_t i;
	int max_value;

	if (array == NULL || *array == '\0')
		return (0);
	max_value = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	return (max_value);
}

/**
 * _counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 * @place: the place value to sort by
 * Return: void
 */
void _counting_sort(int *array, size_t size, int place)
{
	int const UNIT_DIGIT = 10;
	int const _size = (int)size;
	int count[10];
	int *output;
	int i, j;

	if (size < 2)
		return;

	for (i = 0; i < UNIT_DIGIT; i++)
		count[i] = 0;

	for (i = 0; i < _size; i++)
		count[(array[i] / place) % 10] += 1;

	for (i = 1; i < UNIT_DIGIT; i++)
		count[i] += count[i - 1];

	output = malloc(sizeof(int) * _size);
	if (!output)
		return;
	for (j = _size - 1; j >= 0; j--)
	{
		i = (array[j] / place) % 10;
		count[i] -= 1;
		output[count[i]] = array[j];
	}

	for (j = 0; j < _size; j++)
		array[j] = output[j];
	free(output);
}

/**
 * radix_sort - sorts an array of integers in ascending order
 *
 * @array: a pointer to the first element to sort
 * @size: the number of elements in @array
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int max_value = 0, place;

	if (size < 2)
		return;
	max_value = max(array, size);

	for (place = 1; max_value / place > 0; place *= 10)
	{
		_counting_sort(array, size, place);
		print_array(array, size);
	}
}
