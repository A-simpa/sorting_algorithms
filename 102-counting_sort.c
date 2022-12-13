#include "sort.h"

/**
 * max_val - gets the maximum value in an array
 *
 * @array: the array to check
 * @size: the size of the array
 *
 * Return: returns the maximum value(unsigned long int)
 */

int max_val(int *array, size_t size)
{
	unsigned long int n;
	int max = 0;

	for (n = 0; n < size; n++)
	{
		if (array[n] > max)
			max = array[n];
	}
	return (max);
}

/**
 * count_occurence - count the occurence of a number in an array
 *
 * @array: the array to search
 * @size: the size of the array
 * @num: the number to search for
 *
 * Return: return count
 */

int count_occurence(int num, int *array, size_t size)
{
	int count = 0;
	unsigned long int n;

	for (n = 0; n < size; n++)
	{
		if (array[n] == num)
			count++;
	}
	return (count);

}

/**
 * cumm_sum - compute the cummulative sum of an array
 *
 * @array: array to use
 * @size: size of array
 *
 * Return: the total sum
 */

int cumm_sum(int *array, size_t size)
{
	unsigned long int n;

	for (n = 1; n < size; n++)
	{
		array[n] = array[n] + array[n - 1];
	}
	print_array(array, size);
	return (array[n - 1]);
}

/**
 * init_output - initializes the output array
 *
 * @input: input array
 * @count: count array from cumm_sum
 * @output: output array
 * @size: size of input and output
 *
 * Return void
 */

void init_output(int *input, int *count, int *output, size_t size)
{
	unsigned long int n;

	for (n = 0; n < size; n++)
	{
		output[count[input[n]] - 1] = input[n];
		count[input[n]] = count[input[n]] - 1;
	}
}


/**
 * counting_sort - sort using counting sort algorithm
 *
 * @array: the array to sort
 * @size: size of the array
 *
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int *count, *output;
	unsigned long int max, k;

	if (array == NULL || size < 2)
		return;

	max = max_val(array, size);
	count = malloc(sizeof(int) * (max + 1))
	if (count == NULL)
	{
		free(count);
		return;
	}

	for (k = 0; k <= max; k++)
	{
		count[k] = count_occurence(k, array, size);
	}

	cumm_sum(count, max + 1);

	output = malloc(sizeof(int) * (size))
	if (output == NULL)
	{
		free(output);
		return;
	}

	init_output(array, count, output, size);
	for (k = 0; k < size; k++)
	{
		array[k] = output[k];
	}
	free(output), free(count);
}
