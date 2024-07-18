/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:48:10 by gmastroc          #+#    #+#             */
/*   Updated: 2024/07/18 19:29:07 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


char	**mat_dupl(char **str, int argc)
{
	//int argc mi da' la dimensione
	int		i;
	char	**matrix;

	matrix = ft_calloc(argc + 1, sizeof(char *));
	if (!matrix)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		matrix[i] = ft_strdup(str[i]);
		if (!matrix[i])
			return (freefree(matrix), NULL);
	}
	return (matrix);
}
t_list	*parse(char **string)
{
	int	i;
	int	*number;
	t_list *stack_a;
	t_list *node;

	i = -1;
	stack_a = NULL;
	while (string[++i])
	{
		number = atoi_evo(string[i]);
		if (!number)//qualcosa non numero
			return(ft_putendl_fd("Error", 2), free_stack(stack_a), NULL);
		if (get_value(stack_a, *number))//if del doppione
			return(ft_putendl_fd("Error", 2), free_stack(stack_a), free(number), NULL);
		node = ft_lstnew(*number);
		free(number);
		if (!node)//error in list creation
			return(ft_putendl_fd("Error", 2), free_stack(stack_a), NULL);
		ft_lstadd_back(&stack_a, node);
	}
	return (stack_a);
}
t_list	*parse_and_make_list(int argc, char *argv[])
{
	char	**string;
	t_list	*stack_a;

	if (argc == 1)//one arg is not enough
		return (NULL);
	if (argc == 2)//second argument is between brackets, split content
		string = ft_split(argv[1], ' ');
	else//if not bracketed, assumes each argument is a separate value and duplicates the array of arguments (excluding the program name) using mat_dupl.
		string = mat_dupl(&argv[1], argc - 1);//I use the address to skip argv[0]
	if (!string)
		return (ft_putendl_fd("Error", 2), exit (1), NULL);
	stack_a = parse(string);
	if (stack_a == NULL && string[0])//error in parsing
		return (freefree(string), exit (1), NULL);
	freefree(string);
	return (stack_a);
}

int	main(int argc, char *argv[])
{	
	t_list *stack_a;
	t_list *stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = parse_and_make_list(argc, argv);
	if (stack_a == NULL)//error in list creation
		return (0);
	sort_stack(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}