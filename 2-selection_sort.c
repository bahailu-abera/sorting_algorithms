#include "sort.h"

/**
 * selection_sort - sorts an array of integers in
 * ascending order using the Selection sort algorithm
 *
 * @array: the array to be sorted.
 * @size: the size of @array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int temp;

	for (i = 0; i < size; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
			if (array[min_index] > array[j])
				min_index = j;
		temp = array[min_index];
		array[min_index] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
}
