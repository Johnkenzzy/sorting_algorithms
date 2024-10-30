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

		curr_node = move_left_to_right(list, curr_node, &swapped_node);

		if (!swapped_node)
			break;

		curr_node = curr_node->prev;
		curr_node = move_right_to_left(list, curr_node, &swapped_node);
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
 * @sp: Updates if swap occurs
 *
 * Return: The current node
 */
listint_t *move_left_to_right(listint_t **list, listint_t *curr_node, int *sp)
{
	sp[0] = 0;

	while (curr_node->next)
	{
		if (curr_node->n > curr_node->next->n)
		{
			nodes_swapping(list, curr_node, curr_node->next);
			print_list(*list);
			sp[0] = 1;
		}
		else
		{
			curr_node = curr_node->next;
		}
	}

	return (curr_node);
}


/**
 * move_right_to_left - Traverses a doubly linked list from right to left
 * @list: Pointer to the list
 * @curr_node: Pointer to the current node of the list
 * @sp: Updates if swap occurs
 *
 * Return: The current node
 */
listint_t *move_right_to_left(listint_t **list, listint_t *curr_node, int *sp)
{
	sp[0] = 0;

	while (curr_node->prev)
	{
		if (curr_node->n < curr_node->prev->n)
		{
			nodes_swapping(list, curr_node->prev, curr_node);
			print_list(*list);
			sp[0] = 1;
		}
		else
			curr_node = curr_node->prev;
	}

	return (curr_node);
}
