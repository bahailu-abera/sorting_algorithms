#include "sort.h"
#include <stdio.h>

/**
 * print_left_right - prints the left and right array
 *
 * @array: the array to be printed
 * @mid: the middle index
 * @size: the size of the @array
 *
 * Return: void
 */
void print_left_right(int *array, int mid, int size)
{
	int i;

	printf("Merging...\n");
	printf("[left]: ");

	for (i = 0; i <= mid; i++)
	{
		printf("%d", array[i]);
		if (i != mid)
			printf(", ");
	}
	printf("\n[right]: ");

	for (i = mid + 1; i < size; i++)
	{
		printf("%d", array[i]);
		if (i != size - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 * __merge - merges the the divided array by sorting
 *
 * @array: the array to be merged
 * @low: the lower index
 * @middle: the middle index
 * @high: the last index
 *
 * Return: void
 */
void __merge(int *array, int low, int middle, int high)
{
	int *tmp_array, i, j, k, mid, hi;

	tmp_array = malloc(sizeof(int) * (high - low + 1));
	if (tmp_array == NULL)
	{
		printf("insufficient memmory\n");
		exit(1);
	}
	for (i = low; i <= high; i++)
		*(tmp_array + i - low) = array[i];
	i = 0, mid = middle - low, hi = high - low, j = mid + 1, k = low;
	print_left_right(tmp_array, mid, hi + 1);
	while (i <= mid && j <= hi)
	{
		if (tmp_array[i] < tmp_array[j])
			array[k] = tmp_array[i], i++;
		else
			array[k] = tmp_array[j], j++;
		k += 1;
	}
	while (i <= mid)
		array[k] = tmp_array[i], i += 1, k += 1;

	while (j <= hi)
		array[k] = tmp_array[j], k += 1, j += 1;
	free(tmp_array);

	printf("[Done]: ");
	for (i = low; i <= high; i++)
	{
		printf("%d", array[i]);
		if (i != high)
			printf(", ");
	}
	printf("\n");
}

/**
 * divide - divides an array into two recursively
 *
 * @array: the array to be divided
 * @low: the lower index
 * @high: the last or higher index
 *
 * Return: void
 */
void divide(int *array, int low, int high)
{
	int middle;

	if (high <= low)
		return;

	middle = (low + high - 1) / 2;
	divide(array, low, middle);
	divide(array, middle + 1, high);
	__merge(array, low, middle, high);
}

/**
 * merge_sort - sorts an array in ascending order using
 * merge sort algorithm
 *
 * @array: the array to be sorted
 * @size: theh size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	divide(array, 0, (int)size - 1);
}
