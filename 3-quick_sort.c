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
 * quick_lomuto - performs the lomuto partitions and choice of pivots for the
 * quick sort algorithm
 * @array: array on which the lomuto partition scheme will be applied
 * @idx_pos_pivot: lowest index of the current partition, it corresponds to the
 * initial guess for the final position of the pivot
 * @idx_pivot_choice: highest index of the current partition, it corresponds to
 * the current position of the selected pivot
 * @size: number of elements of the array to be sorted via Quick sort following
 * the lomuto scheme (full array, not a partition of it).
 */

void quick_lomuto(int *array, int idx_pos_pivot, int idx_pivot_choice,
	size_t size)
{
	int idx_initial = idx_pos_pivot, idx_compare = idx_initial;

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
	if (idx_pos_pivot - idx_initial > 1)
		quick_lomuto(array, idx_initial, idx_pos_pivot - 1, size);
	if (idx_pivot_choice - idx_pos_pivot > 1)
		quick_lomuto(array, idx_pos_pivot + 1, idx_pivot_choice, size);
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
	if (array == NULL || size < 2)
		return;
	if (size == 2 && array[0] > array[1])
		swap_array(array, 0, 1, 2);
	if (size > 2)
		quick_lomuto(array, 0, size - 1, size);
}
