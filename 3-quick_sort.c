#include "sort.h"


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

	sort_partition(array, 0, size - 1, size);
}


/**
 * lumoto_array_pt - divides an array into two partitions
 *
 * @array: array to be partitioned
 * @size: size of the array
 * @low_pt: lower partition of array
 * @high_pt: higher partition of array
 *
 * Return: the index of partition
 */
size_t lumoto_array_pt(int *array, size_t low_pt, size_t high_pt, size_t size)
{
	int pivot;
	size_t temp, pivot_ndx, i;

	pivot = array[high_pt];
	pivot_ndx = low_pt;

	for (i = low_pt; i < high_pt; i++)
	{
		if (array[i] <= pivot)
		{
			if (i != pivot_ndx)
			{
				temp = array[pivot_ndx];
				array[pivot_ndx] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
			pivot_ndx++;
		}
	}

	if (pivot_ndx != high_pt)
	{
		temp = array[pivot_ndx];
		array[pivot_ndx] = array[high_pt];
		array[high_pt] = temp;
		print_array(array, size);
	}

	return (pivot_ndx);
}


/**
 * sort_partition - sorts an int array in ascending order recursively
 *
 * @array: array to be sorted
 * @s: size of the array
 * @low_pt: lower partition of array
 * @high_pt: higher partition of array
 *
 * Return: nothing
 */
void sort_partition(int *array, size_t low_pt, size_t high_pt, size_t s)
{
	size_t partition_ndx, sub_ndx, size;

	size = s;
	if (low_pt < high_pt)
	{
		partition_ndx = lumoto_array_pt(array, low_pt, high_pt, size);

		if (partition_ndx > 0)
		{
			sub_ndx = partition_ndx - 1;
			sort_partition(array, low_pt, sub_ndx, size);
		}

		sort_partition(array, partition_ndx + 1, high_pt, size);
	}
}
