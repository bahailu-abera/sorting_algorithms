#include "sort.h"
#include <stdlib.h>

/**
 * max_heapify - maintains the max heap property
 *
 * @heap: the heap data structure
 * @index: the index of the element that violate the max heap property
 *
 * Return: void
 */
void max_heapify(heap_t heap, int index)
{
	int largest, left, right, temp;


	while (index < heap.size)
	{
		largest = index;
		left = (2 * index) + 1;
		right = (2 * index) + 2;

		if (left < heap.size && heap.array[left] > heap.array[largest])
			largest = left;
		if (right < heap.size && heap.array[right] > heap.array[largest])
			largest = right;
		if (largest == index)
			break;
		temp = heap.array[index];
		heap.array[index] = heap.array[largest];
		heap.array[largest] = temp;
		print_array(heap.array, heap.length);
		index = largest;
	}
}

/**
 * build_max_heap - builds max heap from unordered array
 *
 * @heap: the heap data structure
 *
 * Return: void
 */
void build_max_heap(heap_t heap)
{
	int n;

	n = heap.size;

	n = (n / 2) - 1;
	while (n >= 0)
		max_heapify(heap, n), n -= 1;
}

/**
 * heap_sort - sorts an unordered array using heap sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the @array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int n, temp;
	heap_t heap;

	n = (int)size;
	heap.array = array;
	heap.size = n;
	heap.length = n;
	build_max_heap(heap);
	n -= 1;

	for (; n > 0; n--)
	{
		temp = heap.array[0];
		heap.array[0] = heap.array[n];
		heap.array[n] = temp;
		heap.size -= 1;
		print_array(heap.array, heap.length);
		max_heapify(heap, 0);
	}
}
