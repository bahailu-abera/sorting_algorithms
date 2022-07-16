#include "sort.h"
#include <stdlib.h>


/* of the array to be sorted */
static size_t length;

/**
 * swap - swap two values of an array
 *
 * @array: the array
 * @first: the index of the first element
 * @second: the index of the second element
 *
 * Return: void
 */
void swap(int *array, int first, int second)
{
	int temp;

	if (first == second || first < 0 || second < 0)
		return;
	temp = array[first];
	array[first] = array[second];
	array[second] = temp;
	print_array(array, length);
}

/**
 * lomuto_partition - chooses as the pivot the last element in the array
 *
 * @array: the array to be partitioned
 * @lo: the lower index for the partition
 * @hi: the higher index for the partition
 *
 * Return: the index for position of the pivot on success
 * or NULL if the index is not correct
 */
int lomuto_partition(int *array, int lo, int hi)
{
	int pivot, i, j;

	pivot = array[hi];
	i = lo - 1;

	for (j = lo; j < hi; j++)
		if (array[j] <= pivot)
		{
			i += 1, swap(array, i, j);
		}
	i += 1;
	swap(array, i, hi);

	return (i);
}

/**
 * recurse_quick_sort - recursively divide and conquer the problem.
 *
 * @array: the array
 * @lo: the lower index
 * @hi: the higher index
 *
 * Return: void
 */
void recurse_quick_sort(int *array, int lo, int hi)
{
	int p;

	if (lo >= hi || lo < 0)
		return;

	p = lomuto_partition(array, lo, hi);
	recurse_quick_sort(array, lo, p - 1);
	recurse_quick_sort(array, p + 1, hi);
}

/**
 * quick_sort  - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: the array to be sorted
 * @size: the length of the @array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	length = size;

	recurse_quick_sort(array, 0, size - 1);
}
