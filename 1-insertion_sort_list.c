#include "sort.h"

/**
 * swap_list_d - swaps nodes of a doubly-linked list
 * @inserted: pointer to the list node to swap with its preceding node
 * Return: nothing, but it prints the list after the swap
 */

void swap_list_d(listint_t *inserted)
{
	if (inserted->prev->prev)
		inserted->prev->prev->next = inserted;
	inserted->prev->next = inserted->next;
	inserted->next = inserted->prev;
	inserted->prev = inserted->prev->prev;
	inserted->next->prev = inserted;
	if (inserted->next->next)
		inserted->next->next->prev = inserted->next;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: doubly-linked list to be sorted
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *sorted, *inserting;

	if (*list && (*list)->next)
	{
		sorted = (*list)->next;
		while (sorted)
		{
			inserting = sorted;
			while (inserting->prev && inserting->n < inserting->prev->n)
			{
				swap_list_d(inserting);
				if (sorted == inserting)
					sorted = sorted->next;
				if (inserting->prev == NULL)
					*list = inserting;
				print_list(*list);
			}
			sorted = sorted->next;
		}
	}
}
