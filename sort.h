#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
int partition(int *array, size_t, int, int);
void lomuto(int *array, size_t, int, int);
unsigned long int get_gap(unsigned long int prev);
void select_insertion_sort(int *array, size_t size, size_t gap);
void recursed_shell_sort(int *array, unsigned long int prev, size_t size);
void shell_sort(int *array, size_t size);
unsigned long int list_len(listint_t *list);
void backforward_bubble_sort(listint_t **list, unsigned long int swapped);
void cocktail_sort_list(listint_t **list);
int max_val(int *array, size_t size);
int count_occurence(int num, int *array, size_t size);
int cumm_sum(int *array, size_t size);
void init_output(int *input, int *count, int *output, size_t size);
void counting_sort(int *array, size_t size);

#endif /* sort.h */
