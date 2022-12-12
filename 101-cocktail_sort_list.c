#include "sort.h"
/**
 * list_len - calculate the length of list
 *
 * @list: the list
 *
 * Return: the length of list
 */

unsigned long int list_len(listint_t *list)
{
	listint_t *l = list;
	unsigned long int n = 0;

	while (l != NULL)
	{
		n++;
		l = l->next;
	}
	return (n);
}


/**
 * cocktail_sort_list - sort an array using buble sort
 *
 * @list: the double link list to sort
 *
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	unsigned long int swapped, n = list_len(*list);
	listint_t *temp, *btemp, *buf;

	while (n-- > 1)
	{
		temp = *list, swapped = 0;
		while (temp->next != NULL)
		{
			if (temp->n > temp->next->n)
			{
				buf = temp->next, temp->next = buf->next;
				if (buf->next != NULL)
					buf->next->prev = temp;
				if (temp->prev != NULL)
					temp->prev->next = buf;
				else
					*list = buf;
				buf->prev = temp->prev, temp->prev = buf;
				buf->next = temp, swapped++, print_list(*list);
			}
			else
				temp = temp->next;
		}
		if (swapped == 0)
			return;
		btemp = temp;
		while (btemp->prev != NULL)
		{
			if (btemp->n < btemp->prev->n)
			{
				buf = btemp->prev, buf->next = btemp->next;
				if (btemp->next != NULL)
					btemp->next->prev = buf;
				if (buf->prev != NULL)
					buf->prev->next = btemp;
				else
					*list = btemp;
				btemp->prev = buf->prev, buf->prev = btemp;
				btemp->next = buf, print_list(*list);
			}
			else
				btemp = btemp->prev;
		}
	}
}

