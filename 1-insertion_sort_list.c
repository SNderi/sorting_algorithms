#include "sort.h"

/**
 * dlistint_len - Counts the number of elements in a doubly linked list
 *
 * @list: Pointer to head of list
 * Return: Number of elements
 */

size_t dlistint_len(const listint_t *list)
{
	size_t count = 0;

	while (list != NULL)
	{
		count++;
		list = list->next;
	}
	return (count);
}

/**
 * insertion_sort_list -  sorts a doubly linked list of integers in
 *			ascending order using the Insertion sort algorithm
 *
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *pre, *h, *tmp, *head;

	if (!list || !(*list) || dlistint_len(*list) < 2)
		return;

	head = *list;

	while (head)
	{
		if (head->prev && head->n < head->prev->n)
		{
			tmp = head;
			temp = head->prev->prev;
			h = head->prev;
			pre = head->next;

			h->next = pre;
			if (pre)
				pre->prev = h;
			tmp->next = h;
			tmp->prev = temp;
			h->prev = tmp;
			if (temp)
				temp->next = tmp;
			else
				*list = tmp;
			h->prev = tmp;
			head = *list;
			print_list(*list);
			continue;
		}
		else
			head = head->next;
	}
}
