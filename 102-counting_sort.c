#include "sort.h"


/**
 * counting_sort - Sorts an  array in ascending order with count sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int min, max, *count, *output, i;
	size_t j;

	if (!array || size < 2)
		return;

	min = array[0];
	max = array[0];

	for (j = 1; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
		if (array[j] < min)
			min = array[j];
	}

	count = create_count_array(array, size, min, max);
	if (!count)
		return;

	print_array(count, ((max + 1) - min));
	output = malloc(size * sizeof(int));
	if (!output)
	{
		free(count);
		return;
	}

	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i] - min] - 1] = array[i];
		count[array[i] - min]--;
	}

	for (j = 0; j < size; j++)
		array[j] = output[j];

	free(count);
	free(output);
}


/**
 * create_count_array - Creates and populates the count array with cum. counts.
 * @array: The input array to be sorted.
 * @size: The size of the input array.
 * @min: The minimum value in the input array.
 * @max: The maximum value in the input array.
 *
 * Return: A pointer to the count array, or NULL if memory allocation fails.
 */
int *create_count_array(int *array, size_t size, int min, int max)
{
	int range, *count, i;
	size_t j;

	range = max - min + 1;
	count = malloc(range * sizeof(int));
	if (!count)
		return (NULL);

	for (i = 0; i < range; i++)
		count[i] = 0;

	for (j = 0; j < size; j++)
		count[array[j] - min]++;

	for (i = 1; i < range; i++)
		count[i] += count[i - 1];

	return (count);
}
