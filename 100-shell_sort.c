#include "sort.h"


/**
 * shell_sort - Sorts and array of integers in ascending order
 * Using Knuth gap sequence (h = 3k + 1; Therefore: n+1 = n * 3 + 1)
 *
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t h, i, j;
	int temp;

	if (!array || size < 2)
		return;

	for (h = 1; h < (size / 3); )
		h = (h * 3) + 1;

	for ( ; h >= 1; h /= 3)
	{
		for (i = h; i < size; i++)
		{
			temp = array[i];

			for (j = i; (j >= h) && (array[j - h] > temp); j -= h)
				array[j] = array[j - h];

			array[j] = temp;
		}

		print_array(array, size);
	}
}
