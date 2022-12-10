#include "sort.h"

/**
 * get_gap - get the gap to use for shell sort
 *
 * @prev: previous gap (can be N/2 or actually prev)
 *
 * Return: returns the gap
 */

unsigned long int get_gap(unsigned long int prev)
{
	unsigned long int pow = 1, gap = 1;

	while (gap < prev)
	{
		pow = pow * 3;
		if (pow > prev)
			break;
		gap = (pow - 1) / 2;

	}
	return (gap);
}

/**
 * select_insertion_sort - does a selective insertion_sort
 *
 * @array: the array to sort
 * @size: size of the array
 * @gap: the gap sequence element
 *
 * Return: void
 */

void select_insertion_sort(int *array, size_t size, size_t gap)
{
	size_t b_ind, set = 0, ind;
	int buf, count;

	while (set < gap)
	{
		ind = set;
		count = size / gap;
		while ((ind < size - 1) && count > 0)
		{
			if (array[ind] > array[ind + gap] &&  (ind + gap) < size)
			{
				buf = array[ind];
				array[ind] = array[ind + gap];
				array[ind + gap] = buf;
				b_ind = ind;
				while (b_ind > set)
				{
					if (array[b_ind] >= array[b_ind - gap])
						break;
					buf = array[b_ind];
					array[b_ind] = array[b_ind - gap];
					array[b_ind - gap] = buf;
					b_ind = b_ind - gap;
				}
			}
			ind = ind + gap, count--;
		}
		set++;
	}
	print_array(array, size);
}

/**
 * recursed_shell_sort - egine for shell sort
 *
 * @array: the array to sort
 * @prev: the previous gap
 * @size: the size of the array
 *
 * Return: void
 */

void recursed_shell_sort(int *array, unsigned long int prev, size_t size)
{
	unsigned long int gap;

	if (prev == 1)
		return;

	gap = get_gap(prev);
	select_insertion_sort(array, size, gap);
	recursed_shell_sort(array, gap, size);
}

/**
 * shell_sort - function that implement egine
 *
 * @array: the array to sort
 * @size: size of the array
 *
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	recursed_shell_sort(array, size, size);
}

