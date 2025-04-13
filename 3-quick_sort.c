#include "sort.h"

/**
 * swap_array - swaps two different elements of the array and prints the array
 * after the swap. It does nothing if the indices are the same.
 * @array: array whose pair of elements will be swapped
 * @idx1: first index
 * @idx2: second index
 * @size: number of elements of the array
 * Return: nothing
 */

void swap_array(int *array, int idx1, int idx2, size_t size)
{
	int tmp;

	if (idx1 != idx2)
	{
		tmp = array[idx1];
		array[idx1] = array[idx2];
		array[idx2] = tmp;
		print_array(array, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using the Quick
 * sort algorithm
 * @array: array to be sorted with the quick sort algorithm
 * @size: size of the array
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	size_t idx_compare, idx_pos_pivot, idx_pivot_choice = size - 1;

	while (idx_pivot_choice > 0)
	{
		idx_compare = 0;
		idx_pos_pivot = 0;
		while (idx_compare < idx_pivot_choice)
		{
			if (array[idx_compare] < array[idx_pivot_choice])
			{
				swap_array(array, idx_compare, idx_pos_pivot, size);
				++idx_pos_pivot;
			}
			++idx_compare;
		}
		swap_array(array, idx_pos_pivot, idx_pivot_choice, size);
		if (idx_pos_pivot == idx_pivot_choice)
			--idx_pivot_choice;
	}
}
