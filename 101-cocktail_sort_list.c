#include "sort.h"


/**
 * swap_node - swapes two nodes of a DDL
 *
 * @node: the node to be swapped with its next node.
 *
 * Return: void
 */
void swap_node(listint_t **node)
{
	listint_t *cur = *node;

	if (cur == NULL)
		return;
	cur->next->prev = cur->prev;
	cur->prev = cur->next;
	cur->next = cur->prev->next;
	cur->prev->next = cur;
	if (cur->next != NULL)
		cur->next->prev = cur;
	if (cur->prev->prev != NULL)
		cur->prev->prev->next = cur->prev;
}
/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 *
 * @list: pointer to the head of the DDL
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *cur;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped == 1)
	{
		swapped = 0;
		for (cur = *list; cur->next != NULL;)
		{
			if (cur->n > cur->next->n)
			{
				if (cur->prev == NULL)
					*list = cur->next;
				swap_node(&cur);
				swapped = 1;
				print_list(*list);
			}
			else
				cur = cur->next;
		}

		if (swapped == 0)
			break;
		swapped = 0;
		for (; cur->prev != NULL;)
		{
			if (cur->n < cur->prev->n)
			{
				if (cur->prev->prev == NULL)
					*list = cur;
				swap_node(&(cur->prev));
				swapped = 1;
				print_list(*list);
			}
			else
				cur = cur->prev;
		}
	}
}
