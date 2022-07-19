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
 * partition - finds the pivot index
 *
 * @array: array to partition
 * @low: Leftmost element
 * @high: Rightmost element
 * @size: Length of array
 *
 * Return: pivot final position
 */
int partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap_array(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (pivot < array[i + 1])
	{
		swap_array(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_recursion - recurse function for Quicksort
 *
 * @array: array to sort
 * @low: index of the leftmost element
 * @high: index of the rightmost element
 * @size: size of the array
 */
void quick_recursion(int *array, int low, int high, size_t size)
{
	int piv;

	if (low < high)
	{
		piv = partition(array, low, high, size);
		quick_recursion(array, low, piv - 1, size);
		quick_recursion(array, piv + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 *		using the Quick sort algorithm
 *
 * @array: array to sort
 * @size: length of array
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_recursion(array, 0, (int)size - 1, size);
}
