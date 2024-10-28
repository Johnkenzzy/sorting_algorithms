#include "sort.h"


/**
 * insertion_sort_list - sorts a doubly linked list of ints in ascending order
 *
 * @list: the doubly linked list to be sorted
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr_node, *temp;

	if (!list || !(*list) || (*list)->next == NULL)
		return;

	curr_node = (*list)->next;

	while (curr_node)
	{

		while (curr_node->prev && (curr_node->prev)->n > curr_node->n)
		{
			temp = curr_node->prev;
			temp->next = curr_node->next;

			if (curr_node->next)
				curr_node->next->prev = temp;

			curr_node->prev = temp->prev;
			curr_node->next = temp;

			if (temp->prev)
				temp->prev->next = curr_node;
			else
				*list = curr_node;

			temp->prev = curr_node;
			print_list(*list);
		}

		curr_node = curr_node->next;
	}
}
