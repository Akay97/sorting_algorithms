#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 * order using the shell sort algorithm
 * @array: An array of integers.
 * @size: The size of the array.
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t spacing, i, j;

	if (array == NULL || size < 2)
		return;

	for (spacing = 1; spacing < (size / 3);)
		spacing = spacing * 3 + 1;

	for (; spacing >= 1; spacing /= 3)
	{
		for (i = spacing; i < size; i++)
		{
			j = i;
			while (j >= spacing && array[j - spacing] > array[j])
			{
				swap_ints(array + j, array + (j - spacing));
				j -= spacing;
			}
		}
		print_array(array, size);
	}
}
