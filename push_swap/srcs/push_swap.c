/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:33:10 by jstrojsa          #+#    #+#             */
/*   Updated: 2024/01/15 21:40:19 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"



int	main(int argc, char **argv)
{
	t_list	*stack_1;
	t_list	*stack_2;

	stack_1 = NULL;
	stack_2 = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		argv = mod_split(argv[1], ' ');
	}
	init_stack_a(&stack_1, argv + 1);
	if (!sort_control(stack_1))
	{
		if (stack_len(stack_1) == 2)
			sa(&stack_1);
		else if (stack_len(stack_1) == 3)
			sort_three(&stack_1);
		else
			sort_stacks(&stack_1, &stack_2);
	}
	free_stack(&stack_1);
	return (0);
}

//testovaci koment