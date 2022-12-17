#include "sort.h"

/**
 * print_part - print parts of an array
 *
 * @array: the array to print
 * @begin: the begining index
 * @end: the ending index
 *
 * Return: void
 */

void print_part(int *array, int begin, int end)
{
	int i;

	for (i = begin; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i != end)
			printf(", ");
		else
			printf("\n");
	}
}

/**
 * merge - merge two part together
 *
 * @b: the copy of the array
 * @a: the array to merge into
 * @begin: the beginning index
 * @mid: the middle index
 * @end: the end index
 *
 * Return: void
 */

void merge(int *b, int begin, int mid, int end, int *a)
{
	int i, j, k;

	i = begin, j = mid;

	printf("Merging...\n");
	printf("[left]: ");
	print_part(b, begin, mid - 1);
	printf("[right]: ");
	print_part(b, mid, end);

	for (k = begin; k <= end; k++)
	{
		if (i < mid && (j > end || b[i] <= b[j]))
		{
			a[k] = b[i];
			i++;
		}
		else
		{
			a[k] = b[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_part(a, begin, end);
}

/**
 * replicate - copy's an array
 *
 * @array: the array to copy
 * @n: the size of the array
 * @b: the array to copy into
 *
 * Return: void
 */

void replicate(int *array, int n, int *b)
{
	int i;

	for (i = 0; i < n; i++)
	{
		b[i] = array[i];
	}
}

/**
 * divide_till_one_merge - divide into partition of one
 *
 * @b: the array to merge into
 * @begin: the begining index of the array
 * @end: the end index of the array
 * @a: the array a
 *
 * Return: void
 */

void divide_till_one_merge(int *b, int begin, int end, int *a)
{
	int mid;

	if (begin >= end)
		return;

	mid = ((end - begin + 1) / 2) + begin;

	divide_till_one_merge(a, begin, mid - 1, b);
	divide_till_one_merge(a, mid, end, b);

	merge(b, begin, mid, end, a);
}

/**
 * merge_sort - merge sort implementation
 *
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	int *b;

	if (array == NULL || size < 2)
		return;

	b = malloc(sizeof(int) * size);
	if (b == NULL)
	{
		free(b);
		return;
	}
	replicate(array, size, b);
	divide_till_one_merge(b, 0, size - 1, array);
	free(b);
}
