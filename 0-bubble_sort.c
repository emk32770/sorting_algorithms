#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - Function bubble sort
 * @array: the array input
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t index;
	size_t index2;
	int temp_array;

	if (!size || !array)
		return;

	for (index = 0; index < size; index++)
	{
		for (index2 = 0; index2 < size - 1; index2++)
		{
			if (array[index2] > array[index2 + 1])
			{
				temp_array = array[index2];
				array[index2] = array[index2 + 1];
				array[index2 + 1] = temp_array;
				print_array(array, size);
			}
		}
	}
}



