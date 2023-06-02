#include "sort.h"

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 *                    using the Quick sort algorithm with Hoare scheme
 * @array: the array to sort
 * @size: the size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	qs_helper_hoare(array, 0, size - 1, size);
}

/**
 * qs_helper_hoare - recursive helper function for quick_sort_hoare
 * @array: the array to sort
 * @low: the lowest index of the partition to sort
 * @high: the highest index of the partition to sort
 * @size: the size of the entire array
 */
void qs_helper_hoare(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int p = hoare_partition(array, low, high, size);

		qs_helper_hoare(array, low, p, size);
		qs_helper_hoare(array, p + 1, high, size);
	}
}

/**
 * hoare_partition - performs a partition using the Hoare scheme
 * @array: the array to partition
 * @low: the lowest index of the partition to sort
 * @high: the highest index of the partition to sort
 * @size: the size of the entire array
 *
 * Return: the index of the pivot element
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
		int pivot = array[high];
		int i = low - 1;
		int j = high + 1;

		while (1)
		{
			do {
				i++;
			} while (array[i] < pivot);

			do {
				j--;
			} while (array[j] > pivot);

			if (i >= j)
				return (j);

			swap(&array[i], &array[j]);
			print_array(array, size);
		}
}

/**
 * swap - swaps two integers in an array
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

