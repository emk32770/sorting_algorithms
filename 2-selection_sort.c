#include "sort.h"

/**
 * selection_sort - selection sort arlgorithmn
 * @array: the array
 * @size: size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t index1, index2, index3;
	int temp_node;


	if (!array || !size)
		return;

	for (index1 = 0; index1 < size - 1; index1++)
	{
		for (index2 = size - 1, index3 = index1 + 1; index2 > index1; index2--)
		{
			if (array[index2] < array[index3])
			{
				index3 = index2;
			}
		}
		if (array[index1] > array[index3])
		{
			temp_node = array[index3];
			array[index3] = array[index1];
			array[index1] = temp_node;
			print_array(array, size);
		}
	}
}
