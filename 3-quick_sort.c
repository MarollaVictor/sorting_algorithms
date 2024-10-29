#include "sort.h"

/**
 * swap - swap 2 integer values
 * @array: array to be sorted
 * @size: size of the array
 * @a: address of 1st value
 * @b: address of 2nd value
 *
 * Return: void
 */

void swap(int *array, size_t size, int *a, int *b)
{
	/* Arithemtic base */
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto - partitions the array
 * @array: array of integers to be sorted
 * @size: size of the array
 * @l: low index of the sort range
 * @h: high index of the sort range
 *
 * Return: size_t
 */

size_t lomuto(int *array, size_t size, ssize_t l, ssize_t h)
{
	int i, j, pivot = array[h];

	i = j;
	while(j < h)
	{
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[i++]);
		j++;
	}
	swap(array, size, &array[i], &array[h]);

	return (i);
}

/**
 * quicksort - sorting through lomuto
 *	prtitionning scheme
 * @array: array of integers to be sorted
 * @size: size of the array
 * @l: low index of the sort range
 * @h: high index of the sort range
 *
 * Return: void
 */

void quicksort(int *array, size_t size, ssize_t l, ssize_t h)
{
	if (l < h)
	{
		size_t par = lomuto(array, size, l, h);

		quicksort(array, size, l, par - 1);
		quicksort(array, size, par + 1, h);
	}
}

/**
 * quick_sort - calls quicksort algorithm function
 * @array: array of integers to be sorted
 * @size: size of the array
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}
