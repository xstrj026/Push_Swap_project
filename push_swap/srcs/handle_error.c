/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:39:22 by jstrojsa          #+#    #+#             */
/*   Updated: 2024/01/16 22:52:51 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	error_syntax(char *str_n)
{
	// printf("%c\n", *str_n);
	if (!(*str_n == '+'
			|| *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9')))
		return (1);
	//printf("%c\n", *str_n);
	if ((*str_n == '+'
			|| *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		// printf("%c\n", *str_n);
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_list *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_list **a, bool tmp, char **array)
{
	ft_putstr_fd("Error\n", 2);
	free_stack(a);
	// printf("free_stack\n");
	if (tmp)
		ft_free_array_of_strings(array);
	exit(1);
}
