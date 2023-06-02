#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array of integers in ascending order.
 *
 * @array: input arrray
 * @size: size of the array
 * Return: no return
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, n = size;
	int j, temp;

	for (temp = 1; n > 0 && temp; n--)
	{
		temp = 0;
		for (i = 0; (i + 1) < n; i++)
		{
			if (array[i] > array[i + 1])
			{
				j = array[i + 1];
				array[i + 1] = array[i];
				array[i] = j;
				print_array(array, size);
				temp = 1;
			}
		}
	}
}
