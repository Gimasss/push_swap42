/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:43:40 by gmastroc          #+#    #+#             */
/*   Updated: 2024/07/18 17:10:43 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_value(t_list *stack, int content)
{
	t_list *current;

	current = stack;
	while (current)
	{
		if (current->content == content)
			return (current);
		current = current->next;
	}
	return (NULL);
}

t_list	*max_value(t_list* head)//delete?
{
	if (!head)
		return NULL;

	t_list* max_val = head;
	while (head != NULL)
	{
		if (head->content > max_val->content)
		{
			max_val = head;
		}
		head = head->next;
	}
	return (max_val);
}

t_list	*min_value(t_list *stack)//find min value
{
	if (stack == NULL) {
		return NULL;
	}
	t_list* min_val = stack;
	while (stack != NULL)
	{
		if (stack->content < min_val->content)
			min_val = stack;
		stack = stack->next;
	}
	return (min_val);
}
int	lst_size(t_list *stack)//get the size of the list
{
	int i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	is_sorted(t_list *stack)//single pointer as im just reading the content
{
	if (stack == NULL)
		return (0);
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)// 3 2 1
			return (0);
		stack = stack->next;//aggiorno mettendo nodo successivo
	}
	return (1);//if it gets here the thing is sorted
}