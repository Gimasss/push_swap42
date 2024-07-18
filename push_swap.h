/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:48:50 by gmastroc          #+#    #+#             */
/*   Updated: 2024/07/18 18:53:39 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_nextplace
{
	struct s_list	*next_bigger;
	int				next_index;
	size_t			next_rot;
	size_t			next_rrot;

	size_t			rot;
	size_t			rrot;

	size_t			totmoves;

}	t_nextplace;

typedef struct s_list
{
	//int value;//?? for min max value
	int				content;
	struct	s_list	*next;
	t_nextplace		target;
}	t_list;

//list functions
int		lst_size(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lst_bfrlast(t_list *lst);
t_list	*ft_lstadd_back(t_list **lst, t_list *new);
t_list	*get_value(t_list *stack, int content);
t_list	*max_value(t_list* stack);
t_list	*min_value(t_list* stack);

//movements
int		sort_three(t_list **stack);
int		sort_stack(t_list **stack_a, t_list **stack_b);
void	swap(t_list **stack);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	push(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	rotating(t_list **stack);
void	rotating_a(t_list **stack_a);
void	rotating_b(t_list **stack_b);
void	rotating_r(t_list **stack_a, t_list **stack_b);
void	rev_rotating(t_list **stack);
void	rev_rotating_a(t_list **stack_a);
void	rev_rotating_b(t_list **stack_b);
void	rev_rotating_r(t_list **stack_a, t_list **stack_b);

//cleaner
void	freefree(char **str);
void	free_stack(t_list *stack);

//parsing and some
int		*atoi_evo(const char *str);
int		is_sorted(t_list *stack);
int		get_next_bigger(t_list *current, t_list *other_stack);
t_list	*best_target(t_list *stack_b);
void	execute_move(t_list **stack_a, t_list **stack_b);
void	calculate_next_move(t_list *stack_a, t_list *stack_b);


//int		where_to_insert(t_list *stack_a, int content);
//void	reintegrate_with_a(t_list **stack_a, t_list **stack_b);



#endif