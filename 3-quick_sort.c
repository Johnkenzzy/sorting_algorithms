#include "sort.h"


/**
 * lumoto_partition - divides an array into two partitions
 *
 * @array: array to be partitioned
 * @low_part: lower partition of array
 * @high_part: higher partition of array
 *
 * Return: the index of partition
 */
size_t lumoto_partition(int *array, size_t low_part, size_t high_part)
{
	int pivot;
	size_t temp, pivot_ndx, i;

	pivot = array[high_part];
	pivot_ndx = low_part;

	for (i = low_part; i < high_part; i++)
	{
		if (array[i] <= pivot)
		{
			temp = array[pivot_ndx];
			array[pivot_ndx] = array[i];
			array[i] = temp;
			pivot_ndx++;
		}
	}

	temp = array[pivot_ndx];
	array[pivot_ndx] = array[high_part];
	array[high_part] = temp;

	return (pivot_ndx);
}


/**
 * quick_sort_recursive - sorts an int array in ascending order recursively
 *
 * @array: array to be sorted
 * @low_part: lower partition of array
 * @high_part: higher partition of array
 *
 * Return: nothing
 */
void quick_sort_recursive(int *array, size_t low_part, size_t high_part)
{
	size_t partition_ndx;

	if (low_part < high_part)
		partition_ndx = lumoto_partition(array, low_part, high_part);

	if (partition_ndx > 0)
		quick_sort_recursive(array, low_part, partition_ndx - 1);

	quick_sort_recursive(array, partition_ndx + 1, high_part);
}


/**
 * quick_sort - sorts an array integers in ascending order
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{

	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1);
}
