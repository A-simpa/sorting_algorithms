#include "sort.h"

/**
 * selection_sort - sort an array using buble sort
 *
 * @array: the array to sort
 * @size: size of the array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	int min;
	size_t n, i, pos;

	if (size == 0)
		return;
	n = 0;
	while (n < size - 1)
	{
		min = array[n], pos = n;
		for (i = n + 1; i < size; i++)
		{
			if (array[i] < min)
				min = array[i], pos = i;
		}
		if (pos != n)
		{
			array[pos] = array[n];
			array[n] = min;
			print_array(array, size);
		}
		n++;
	}
}

