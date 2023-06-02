#include "sort.h"

/**
 * bitonic_sort - sorts an array of integers in ascending order
 *                using the Bitonic sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sort_helper(array, size, 1);
}

/**
 * bitonic_sort_helper - recursive helper function for bitonic_sort
 * @array: array of integers
 * @size: size of the array
 * @dir: direction of sort (1 for ascending, 0 for descending)
 */
void bitonic_sort_helper(int *array, size_t size, int dir)
{
    if (size < 2)
        return;

    bitonic_merge(array, size, dir);
    bitonic_sort_helper(array, size / 2, dir);
    bitonic_sort_helper(array + size / 2, size / 2, dir);
}

/**
 * bitonic_merge - merges two bitonic sequences into one
 * @array: array of integers
 * @size: size of the array
 * @dir: direction of sort (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t size, int dir)
{
	if (size < 2)
		return;

	int i, j, k, tmp;
	int m = size / 2;

	for (i = 0; i < m; i++)
	{
		if ((array[i] > array[i + m]) == dir)
		{
			tmp = array[i];
			array[i] = array[i + m];
			array[i + m] = tmp;
			printf("Result [%lu/%lu] (%s):\n", size - 2 * m + i, size, dir ? "UP" : "DOWN");
			print_array(array, size);
		}
	}

	bitonic_merge(array, m, dir);
	bitonic_merge(array + m, m, dir);
}
