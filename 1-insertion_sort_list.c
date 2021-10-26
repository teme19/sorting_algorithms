#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list  of integers in ascending
* order using the Insertion sort algorithm
*
* @list: double pointer to doubly-linked list
*
* Return: Nothing
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL, *last = NULL, *tmp = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	curr = (*list)->next;
	while (curr)
	{
		last = curr->prev;
		tmp = curr->next;
		while (last && curr->n < last->n)
		{
			if (last->prev)
				last->prev->next = curr;
			last->next = curr->next;
			curr->next = last;
			curr->prev = last->prev;
			last->prev = curr;
			if (last->next)
				last->next->prev = last;
			if (!curr->prev)
				(*list) = curr;
			print_list(*list);
			last = curr->prev;
		}
		curr = tmp;
	}
}
