/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:12:30 by gmastroc          #+#    #+#             */
/*   Updated: 2024/07/18 18:49:06 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list	*best_target(t_list *stack_b)
{
	t_list		*best;

	best = stack_b;
	while (stack_b)
	{
		if (best->target.totmoves > stack_b->target.totmoves)
			best = stack_b;
		stack_b = stack_b->next;
	}
	return (best);
}

//current is the number in stack b
//other_stack is the number in stack a
int	get_next_bigger(t_list *current, t_list *other_stack)
{
	const int		content = current->content;
	t_list			*cur;
	int				res;
	int				i;

	cur = other_stack;//nodo target
	other_stack = other_stack->next;
	i = 0;
	res = -1;
	if (cur->content > content)
		res = 0;
	while (other_stack && ++i)
	{
		if (other_stack->content > content
			&& (res == -1 || (other_stack->content < cur->content)))
		{
			cur = other_stack;
			res = i;
		}
		other_stack = other_stack->next;
	}
	current->target.next_bigger = cur;
	current->target.next_index = res;
	return (res);
}
