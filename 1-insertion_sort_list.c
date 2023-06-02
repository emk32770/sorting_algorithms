#include "sort.h"

/**
 * swap_func - swap the two list
 *@first_node: the first node
 *@second_node : second node
 * Return : the nodes
 */
void swap_func(listint_t *first_node, listint_t *second_node)
{
	if (first_node->prev)
		first_node->prev->next = second_node;
	if (second_node->next)
		second_node->next->prev = first_node;

	first_node->next = second_node->next;
	second_node->prev = first_node->prev;
	first_node->prev = second_node;
	second_node->next = first_node;
}




/**
 * insertion_sort_list - sort the linked list using insertion
 * *@list: the linked list
 * Return: sorted linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *index1, *index2;

	if (!*list || !list || !(*list)->next)
		return;
	for (index1 = (*list)->next; index1;)
	{
		index2 = index1;
		index1 = index1->next;
		while (index2 && index2->prev)
		{
			if (index2->prev->n > index2->n)
			{
				swap_func(index2->prev, index2);
				if (!index2->prev)
					*list = index2;
				print_list((const listint_t *)*list);
			}
			else
				index2 = index2->prev;
		}
	}
}
