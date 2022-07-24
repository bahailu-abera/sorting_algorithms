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
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, max_value, i;
	size_t j;

	max_value = max(array, size);
	max_value += 1;

	count = malloc(sizeof(int) * max_value);
	if (count == NULL)
		return;

	for (i = 0; i < max_value; i++)
		*(count + i) = 0;

	for (j = 0; j < size; j++)
		*(count + array[j]) += 1;

	for (i = 1; i <= max_value; i++)
		*(count + i) += *(count + i - 1);

	print_array(count, max_value);

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	for (j = 0; j < size; j++)
	{
		i = array[j];
		*(output + *(count + i) - 1) = i;
		*(count + i) -= 1;
	}

	for (j = 0; j < size; j++)
		array[j] = *(output + j);
	free(output);
	free(count);
}
