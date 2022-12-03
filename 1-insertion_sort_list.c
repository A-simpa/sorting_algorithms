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
	int swapped = 0;
	listint_t *nh, *ph, *buf;

	nh = *list;
	while (nh->next != NULL)
	{
		if (nh->n > nh->next->n)
		{
			buf = nh->next;
			nh->next = buf->next;
			if (buf->next != NULL)
				buf->next->prev = nh;
			nh->prev->next = buf, buf->prev = nh->prev;
			nh->prev = buf, buf->next = nh;
			print_list(*list), swapped++;
			ph = nh->prev;
			while (ph->prev != NULL)
			{
				if (ph->n >= ph->prev->n)
					break;
				buf = ph->prev, buf->next = ph->next;
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
	}

}

