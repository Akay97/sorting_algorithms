#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 *
 * Return: Index of the pivot element
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 * quicksort_recursive - Recursive function to perform Quick sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 */
void quicksort_recursive(int *array, size_t size, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, size, low, high);

		quicksort_recursive(array, size, low, pivot_index - 1);
		quicksort_recursive(array, size, pivot_index + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in
 * ascending order using Quick sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	quicksort_recursive(array, size, 0, size - 1);
}
