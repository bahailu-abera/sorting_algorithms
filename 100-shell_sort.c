#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 *
 * @array: the array to be sorted
 * @size: the size of the @array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, interval = 1;
	int temp;

	while (interval <= (size - 1) / 9)
		interval = 3 * interval + 1;

	while (interval >= 1)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = temp;
		}
		print_array(array, size);
		interval /= 3;
	}
}
