/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:35:52 by jstrojsa          #+#    #+#             */
/*   Updated: 2024/01/06 20:36:18 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push(t_list **stack_dst, t_list **stack_src)
{
	t_list	*push_node;

	if (!*stack_src)
		return ;
	push_node = *stack_src;
	*stack_src = (*stack_src)->next;
	if (*stack_src)
		(*stack_src)->prev = NULL;
	push_node->prev = NULL;
	if (!*stack_dst)
	{
		*stack_dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *stack_dst;
		push_node->next->prev = push_node;
		*stack_dst = push_node;
	}
}

void	pa(t_list **a, t_list **b)
{
	push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **b, t_list **a)
{
	push(b, a);
	ft_putstr_fd("pb\n", 1);
}
