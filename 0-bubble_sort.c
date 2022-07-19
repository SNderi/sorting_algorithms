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
 * bubble_sort - sorts an array of integers in ascending order using
 *		Bubble sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_array(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
