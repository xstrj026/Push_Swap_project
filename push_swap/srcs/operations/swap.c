/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 21:48:25 by jstrojsa          #+#    #+#             */
/*   Updated: 2024/01/07 21:48:29 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	swap(t_list **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_list	**a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list	**b)
{
	swap(b);
	ft_putstr_fd("sa\n", 1);
}

void	ss(t_list	**a, t_list	**b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("sa\n", 1);
}
