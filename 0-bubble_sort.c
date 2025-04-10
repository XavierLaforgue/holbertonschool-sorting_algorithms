#include "sort.h"

/**
 * swap - swaps two elements in an array
 * @array: pointer to the array whose elements will be swapped
 * @idx: index of the element to be swapped with the next one
 * Return: nothing
 */

void swap(int *array, size_t idx)
{
	int tmp = array[idx + 1];

	array[idx + 1] = array[idx];
	array[idx] = tmp;
}

/**
 * bubble_sort - sorts an array of integersin ascending order using the bubble
 * sort algorithm
 * @array: the array to be sorted
 * @size: number of elements in the array
 * Return: nothing, but it prints the array every time a swap is performed
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (array[j] > array[j + 1])
			{
				swap(array, j);
				print_array(array, size);
			}
			++j;
		}
		++i;
	}
}
