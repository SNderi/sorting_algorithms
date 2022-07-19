#include "sort.h"

/**
 * swap_array - swaps array elements
 * @fir: first element
 * @sec: second element
 */
void swap_array(int *fir, int *sec)
{
	int temp = *fir;
	*fir = *sec;
	*sec = temp;
}

/**
 * selection_sort - sorts an array of integers in ascending order
 *		using the Selection sort algorithm
 *
 * @array: array to sort
 * @size: length of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int pos;

	for (i = 0; i < size - 1; i++)
	{
		pos = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[pos])
				pos = j;
		}
		swap_array(&array[pos], &array[i]);
		print_array(array, size);
	}
}
