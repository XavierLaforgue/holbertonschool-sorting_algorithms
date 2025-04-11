#include "sort.h"

/**
 * swap_array - swaps two elements in the array
 * @array: array whose pair of elements will be swapped
 * @idx1: first index
 * @idx2: second index
 * Return: nothing
 */

void swap_array(int *array, int idx1, int idx2)
{
	int tmp;

	tmp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = tmp;
}

/**
 * selection_sort - sorts an array of integers in ascending order using the
 * Selection sort algorithm
 * @array: array to be sorted
 * @size: number of elements of the array
 * Return: nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, selected;

	for (i = 0; i < size - 1; ++i)
	{
		selected = i;
		for (j = i + 1; j < size; ++j)
		{
			if (array[selected] > array[j])
				selected = j;
		}
		if (selected != i)
		{
			swap_array(array, i, selected);
			print_array(array, size);
		}
	}
}
