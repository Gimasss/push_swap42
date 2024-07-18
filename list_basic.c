/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:33:06 by gmastroc          #+#    #+#             */
/*   Updated: 2024/07/18 19:07:48 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//1.creare nuova lista
t_list    *ft_lstnew(int content)
{
	t_list	*new;

	new = ft_calloc(1, sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
//3.o to the end of the list
t_list    *ft_lstlast(t_list *lst)//tail
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
//2.add to front of the list
void    ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
//4.get before last node
t_list *ft_lst_bfrlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next && lst->next->next)
		lst = lst->next;
	return (lst);
}

//5.add to the end of the list
t_list	*ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst)
		return (NULL);
	last = ft_lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
	return (*lst);
}