#include "sort.h"


/**
 * selection_sort - sorts an array of integer in ascending order
 *
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, smallest;
	int temp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		smallest = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smallest])
				smallest = j;

		}

		if (smallest != i)
		{
			temp = array[i];
			array[i] = array[smallest];
			array[smallest] = temp;
			print_array(array, size);
		}
	}
}
