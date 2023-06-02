#include "sort.h"

int lomuto_partition(int *array, int lo, int hi, size_t size);
/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - recursive function that implements
 * the Quick sort algorithm using the Lomuto partition scheme
 *
 * @array: the array to be sorted
 * @lo: the index of the first element of the partition
 * @hi: the index of the last element of the partition
 * @size: the size of the array
 */
void quick_sort_recursive(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = lomuto_partition(array, lo, hi, size);
		quick_sort_recursive(array, lo, p - 1, size);
		quick_sort_recursive(array, p + 1, hi, size);
	}
}

/**
 * lomuto_partition - function that implements the Lomuto
 * partition scheme to partition the array around a pivot
 *
 * @array: the array to be sorted
 * @lo: the index of the first element of the partition
 * @hi: the index of the last element of the partition
 * @size: the size of the array
 *
 * Return: the final index of the pivot element
 */
int lomuto_partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo - 1;
	int j, temp;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
	}

	if (array[i + 1] != array[hi])
	{
		temp = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = temp;
		print_array(array, size);
	}

	return (i + 1);
}
