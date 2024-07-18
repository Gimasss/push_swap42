/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:25:35 by gmastroc          #+#    #+#             */
/*   Updated: 2024/07/18 19:15:22 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	min_to_top(t_list **stack_a)
{
	t_list	*min;
	t_list	*temp;
	int		index;
	int		stack_a_sz;

	index = -1;
	temp = *stack_a;
	min = min_value(*stack_a);
	stack_a_sz = lst_size(*stack_a);
	while (temp && ++index > -1)//ask about this
	{
		if (temp->content == min->content)
			break ;
		temp = temp->next;
	}
	if (index <= stack_a_sz / 2)
		while (index-- > 0)
			rotating_a(stack_a);
	else
		while (stack_a_sz - index++ > 0)
			rev_rotating_a(stack_a);
}

int sort_three(t_list **stack)
{
	int node1;
	int node2;
	int node3;

	if (is_sorted(*stack) == 1)
		return (0);
	if (lst_size(*stack) == 2)
		return (swap_a(stack), 0);
	node1 = (*stack)->content;
	node2 = (*stack)->next->content;
	node3 = (*stack)->next->next->content;
	if ( ((node1 < node2 && node1 < node3)//0 9 5
		|| (node3 > node1 && node2 < node3)// 5 0 9
		|| (node1 > node2 && node2 > node3) ))// 5 9 0
			swap_a(stack);
	node1 = (*stack)->content;
	node2 = (*stack)->next->content;
	if (node1 > node2 && node2 < node3)// 9 0 5
		rotating_a(stack);
	else if (node1 < node2 && node2 > node3)
		rev_rotating_a(stack);
	return (0);
}

int	get_average(t_list *stack)
{
	const int		size = lst_size(stack);
	int				sum;

	sum = 0;
	if (size == 0)
		return (0);
	while (stack)
	{
		sum += stack->content;
		stack = stack->next;
	}
	return (sum / size);
}

int	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int		stack_a_size;

	stack_a_size = lst_size(*stack_a);
	if (is_sorted(*stack_a) == 1)//1 is true
		return (0);
	while (stack_a_size > 3 && !is_sorted(*stack_a))
	{
		if ((*stack_a)->content < get_average(*stack_b))
			push_b(stack_a, stack_b);
		else
		{
			push_b(stack_a, stack_b);
			rotating_b(stack_b);
		}
		stack_a_size--;
	}
	sort_three(stack_a);
	while (*stack_b != NULL)
	{
		calculate_next_move(*stack_a, *stack_b);
		execute_move(stack_a, stack_b);
	}
	min_to_top(stack_a);
	return (0);
}