#include "sort.h"


/**
 * bubble_sort - sorts array of integers, by swapping them
 *
 * @array: the array/list to be sorted
 * @size: size of the array/list to be sortted
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int temp, swap;

	if (size < 2)
		return;

	while (1)
	{
		swap = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temp;
				swap = 1;
				print_array(array, size);
			}
		}

		if (swap == 1)
			continue;
		else
			break;
	}
}
