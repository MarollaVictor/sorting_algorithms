#include "sort.h"

/**
*swap - the positions of two elements in a given array
*@array: array of elements
*@item1: array element to check
*@item2: array element to swap to order
*/

void swap(int *array, int item1, int item2)
{

	int tmp;

	tmp = array[item1];  /*init of index[0]*/
	array[item1] = array[item2]; /*init of index[1]*/
	array[item2] = tmp; /*swap according to order*/
}
/**
 * shell_sort - function that sorts an array of ints in ascending
 * order using the Shell sort algorithm and the Knuth sequence
 * @size: size of the array
 * @array: array of elments
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, index = 0;

	if (array == NULL || size < 2) /*check if array is empty*/
		return;
	while (gap < size / 3) /*determine gap size by Knuth euqation*/
		gap = 3 * gap + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
			for (index = i; index >= gap &&
			 (array[index] < array[index - gap]); index -= gap)
				swap(array, index, index - gap);
		print_array(array, size);
		gap /= 3;
	}
}
