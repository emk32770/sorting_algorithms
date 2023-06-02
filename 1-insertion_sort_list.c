#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - insertion sort in ascending order
 * 
 * @list: doubly linked list
 * Return: no return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *inst, *temp;

	if (!list)
		return;

	inst = *list;

	while (inst)
	{
		while (inst->next && (inst->n > inst->next->n))
		{
			temp = inst->next;
			inst->next = temp->next;
			temp->prev = inst->prev;

			if (inst->prev)
				inst->prev->next = temp;

			if (temp->next)
				temp->next->prev = inst;

			inst->prev = temp;
			temp->next = inst;

			if (temp->prev)
				inst = temp->prev;
			else
				*list = temp;

			print_list(*list);
		}
		inst = inst->next;
	}
}
