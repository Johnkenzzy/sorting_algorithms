#ifndef __SORT_H__
#define __SORT_H__


#include <stdio.h>
#include <stdlib.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;



/* Main Sorting Functions */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);


/* Print Functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);


/* Helper Functions */
size_t lumoto_array_pt(int *array, size_t low_pt, size_t high_pt, size_t size);
void sort_partition(int *array, size_t low_pt, size_t high_pt, size_t s);
void nodes_swapping(listint_t **list, listint_t *left, listint_t *right);
listint_t *move_left_to_right(listint_t **list, listint_t *curr_node, int *sp);
listint_t *move_right_to_left(listint_t **list, listint_t *curr_node, int *sp);
int *create_count_array(int *array, size_t size, int min, int max);


#endif /* __SORT_H__ */
