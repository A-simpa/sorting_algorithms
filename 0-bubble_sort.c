#include "sort.h"

/**
 * bubble_sort - sort an array using buble sort
 *
 * @array: the array to sort
 * @size: size of the array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	int buf, swapped = 0;
	size_t n, i;

	n = size;
	while (n > 1)
	{
		for (i = 0; i < n - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				buf = array[i];
				array[i] = array[i + 1];
				array[i + 1] = buf, swapped++;
				print_array(array, size);
			}
			if (i == n - 2 && swapped == 0)
				return;
		}
		n--;
	}
}

