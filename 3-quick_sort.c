#include "sort.h"

/**
 * swap_func - swap the array
 * @array: the array
 * @size: the size
 * @first_node: the first node
 * @second_node : the second node
 * Return: 0
 */
void swap_func(int *array, size_t size, int *first_node, int *second_node)
{
	if (*first_node != *second_node)
	{
		*first_node = *first_node + *second_node;
		*second_node = *first_node - *second_node;
		*first_node = *first_node - *second_node;
		print_array((const int *)array, size);
	}
}



/**
 * lomuto_algor - the partiton of the array
 * @array: the array
 * @size: the size
 * @lower: lower bound
 * @higher: higher bound
 * Return: 0
 */
size_t lomuto_algor(int *array, size_t size, ssize_t lower, ssize_t higher)
{
	int index1, index2, pvot = array[higher];

	for (index1 = index2 = lower; index2 < higher; index2++)
	{
		if (array[index2] < pvot)
			swap_func(array, size, &array[index2], &array[index1++]);
	}
	swap_func(array, size, &array[index1], &array[higher]);

	return (index1);
}



/**
 * sort_quick - using lomuto partiiotn
 * @array: the array
 * @size: the size
 * @lower: the lower bound
 * @higher: the higher bound
 * Return: 0 or void
 */
void sort_quick(int *array, size_t size, ssize_t lower, ssize_t higher)
{
	if (lower < higher)
	{
		size_t partition = lomuto_algor(array, size, lower, higher);

		sort_quick(array, size, lower, partition - 1);
		sort_quick(array, size, partition + 1, higher);
	}
}


/**
 * quick_sort - implement a quick sort
 * @array: array
 * @size: size of array
 * Return: 0 void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	sort_quick(array, size, 0, size - 1);
}
