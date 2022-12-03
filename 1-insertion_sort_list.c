#include "sort.h"

/**
 * insertion_sort_list - sorting a double linked list using insertion
 *
 * @list: double linked list to sort
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *nh, *ph, *buf;
	int swapped = 0;

	if (*list == NULL)
		return;
	nh = *list;
	while (nh->next != NULL)
	{
		if (nh->n > nh->next->n)
		{
			buf = nh->next, nh->next = buf->next;
			if (buf->next != NULL)
				buf->next->prev = nh;
			if (nh->prev != NULL)
				nh->prev->next = buf;
			else
				*list = buf;
			buf->prev = nh->prev, nh->prev = buf;
			buf->next = nh, print_list(*list), ph = nh->prev, swapped++;
			while (ph->prev != NULL)
			{
				if (ph->n >= ph->prev->n)
					break;
				buf = ph->prev, buf->next = ph->next;
				if (ph->next != NULL)
					ph->next->prev = buf;
				if (buf->prev != NULL)
					buf->prev->next = ph;
				else
					*list = ph;
				ph->prev = buf->prev, buf->prev = ph;
				ph->next = buf, print_list(*list);
			}
		}
		else
			nh = nh->next;
		if (nh->next == NULL && swapped == 0)
			return;
	}

}

