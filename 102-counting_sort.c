#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */

void counting_sort(int *array, size_t size)
{
	int i, max = 0;
	int *count, *output;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}

	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	for (i = (int)size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
