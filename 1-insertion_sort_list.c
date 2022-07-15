#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: pointer to the header of the DDL.
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *temp, *next;

	if (list == NULL)
		return;

	cur = *list;

	if (cur == NULL || cur->next == NULL)
		return;
	cur = cur->next;
	while (cur != NULL)
	{
		temp = cur->prev;
		next = cur->next;

		while ((temp != NULL) && (temp->n > cur->n))
		{
			temp->next = cur->next;
			if (cur->next != NULL)
				cur->next->prev = temp;
			cur->next = temp;
			cur->prev = temp->prev;

			if (temp->prev != NULL)
				temp->prev->next = cur;
			else
				*list = cur;
			temp->prev = cur;
			temp = cur->prev;
			print_list(*list);
		}

		cur = next;

	}
}
