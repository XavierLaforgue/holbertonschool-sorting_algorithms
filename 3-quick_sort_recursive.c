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
 * quick_sort - sorts an array of integers in ascending order using the Quick
 * sort algorithm
 * @array: array to be sorted with the quick sort algorithm
 * @size: size of the array
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	size_t size_left, size_right;

	while (j < size - 1)
	{
		if (array[j] < array[size - 1])
		{
			swap_array(array, i, j);
			print_array(array, size);
			++i;
		}
		++j;
	}
	size_left = i;
	size_right = size - i - 1;
	swap_array(array, i, size - 1);
	print_array(array, size);
	if (size_left > 1)
		quick_sort(array, size_left);
	if (size_right > 1)
		quick_sort(array + i + 1, size_right);
}
