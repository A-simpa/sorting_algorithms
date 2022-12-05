#include "sort.h"

/**
 * quick_sort - implement the quick sort algorithm for an array
 *
 * @size: the size of an array
 * @array: the array to sort
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (size <= 1 || array == NULL)
		return;

	lomuto(array, size, 0, size - 1);
}

/**
 * lomuto - implement the lomuto quick sort scheme
 *
 * @array: the arrray to sort
 * @size: size of the array
 * @start: the start of the sort
 * @end: the end of the sorted array
 *
 * Return: void
 */

void lomuto(int *array, size_t size, int start, int end)
{
	int loc;

	if (start >= end || start < 0)
		return;

	loc = partition(array, size, start, end);
	lomuto(array, size, start, loc - 1);
	lomuto(array, size, loc + 1, end);
}

/**
 * partition - partition using lomuto
 *
 * @array: array to partition
 * @size: size of the original array
 * @start: start index to be sorted
 * @end: end index to be sorted
 *
 * Return: the index int
 */

int partition(int *array, size_t size, int start, int end)
{
	int pos = start - 1, j;
	int pivot = array[end], buf;

	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			pos++;
			if (pos != j)
			{
				buf = array[j];
				array[j] = array[pos];
				array[pos] = buf;
				print_array(array, size);
			}
		}
	}
	pos++;
	if (pos != end)
	{
		array[end] = array[pos];
		array[pos] = pivot;
		print_array(array, size);
	}
	return (pos);
}
