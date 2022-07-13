#include "sort.h"
#include <stdbool.h>
#include <stdio.h>

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm.
 *
 * @array: the array of integers
 * @size: the size of the @array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int swapped = 1;
	size_t count;
	int tmp;

	while (swapped != 0)
	{
		swapped = 0;
		for (count = 1; count < size; count++)
		{
			if (array[count - 1] > array[count])
			{
				tmp = array[count];
				array[count] = array[count - 1];
				array[count - 1] = tmp;
				swapped = 1;
				print_array((const int *)array, size);
			}
		}
	}
}
