#include "sort.h"

/**
  * heap_sort - sor a list using heap sort algorithm
  * @array: arr to be sorted
  * @size: size of the gven array
  */

void heap_sort(int *array, size_t size)
{
	int i, tmp;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, i, size, size);
	for (i = size - 1; i >= 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}

/* heapify - swap an array using the heap algorithm
*@array: list o elments
*@idx: list of ids
*@idx2: list of elements 2
*@size: sie of a given array
*/

void heapify(int *array, int idx, int idx2, size_t size)
{
	int max = idx2;
	int left = 2 * idx2 + 1;
	int right = 2 * idx2 + 2;
	int tmp;

	if (left < idx && array[left] > array[max])
		max = left;
	if (right < idx && array[right] > array[max])
		max = right;
	if (max != idx2)
	{
		tmp = array[idx2];
		array[idx2] = array[max];
		array[max] = tmp;
		print_array(array, size);
		heapify(array, idx, max, size);
	}
}
