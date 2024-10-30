#include "sort.h"


/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *
 * @list: Pointer to the head of the list to be sorted
 *
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr_node;
	int swapped_node = 1;

	if (!list || !*list || !(*list)->next)
		return;

	while (swapped_node)
	{
		curr_node = *list;

		printf("Left_To_Right\n");
		swapped_node = move_left_to_right(list, curr_node, swapped_node);

		if (!swapped_node)
			break;

		printf("Right_To_Left\n");
		curr_node = curr_node->prev;
		swapped_node = move_right_to_left(list, curr_node, swapped_node);
	}
}


/**
 * nodes_swapping - Swaps two nodes in a doubly linked list
 *
 * @list: Pointer to the head of the list
 * @left: The left node to be swapped
 * @right: The right node to be swapped
 *
 * Return: Nothing
 */
void nodes_swapping(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;
	left->prev = right;
	right->next = left;
}


/**
 * move_left_to_right - Traverses a doubly linked list from left to right
 * @list: Pointer to the list
 * @curr_node: Pointer to the current node of the list
 * @swap: Updates if swap occurs
 *
 * Return: 1 if swap occur, else 0
 */
int move_left_to_right(listint_t **list, listint_t *curr_node, int swap)
{
	swap = 0;

	while (curr_node->next)
	{
		if (curr_node->n > curr_node->next->n)
		{
			nodes_swapping(list, curr_node, curr_node->next);
			print_list(*list);
			swap = 1;
		}
		else
			curr_node = curr_node->next;
	}

	return (swap);
}


/**
 * move_right_to_left - Traverses a doubly linked list from right to left
 * @list: Pointer to the list
 * @curr_node: Pointer to the current node of the list
 * @swap: Updates if swap occurs
 *
 * Return: 1 if swap occur, else 0
 */
int move_right_to_left(listint_t **list, listint_t *curr_node, int swap)
{
	swap = 0;

	printf("Inside_Right_To_Left\n");
	while (curr_node->prev)
	{
		printf("Inside_Right_To_Left_Loop\n");
		if (curr_node->n < curr_node->prev->n)
		{
			nodes_swapping(list, curr_node->prev, curr_node);
			print_list(*list);
			swap = 1;
		}
		else
			curr_node = curr_node->prev;
	}

	return (swap);
}
