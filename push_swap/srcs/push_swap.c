/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:33:10 by jstrojsa          #+#    #+#             */
/*   Updated: 2024/01/17 11:51:37 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_array_of_strings(char **tmp)
{
	int	i;

	i = 0;
	// printf("jsem v free array\n");
	if (tmp == NULL)
		return ;
	// printf("kontrola NULL pointeru\n");
	while (tmp[i])
	{
		// printf("%p\n", tmp[i]);
		free(tmp[i]);
		i++;
	}
	// printf("jsem za loopem\n");
	free(tmp);
}

static void	ft_sorting(t_list **st1, t_list **st2)
{
	if (stack_len(*st1) == 2)
		sa(st1);
	else if (stack_len(*st1) == 3)
		sort_three(st1);
	else
		sort_stacks(st1, st2);
}

int	main(int argc, char **argv)
{
	t_list	*stack_1;
	t_list	*stack_2;
	char	**tmp;

	stack_1 = NULL;
	stack_2 = NULL;
	tmp = NULL;
	if (argc == 1)
		// free_errors(&stack_1, false, tmp);
		return (1);
	if (argc == 2 && !argv[1][0])
		free_errors(&stack_1, false, tmp);
		// return (1);
	if (argc == 2)
		tmp = mod_split(argv[1], ' ');
	if (argc == 2)
		init_stack_a(&stack_1, tmp, true);
	else
		init_stack_a(&stack_1, argv, false);
	if (!sort_control(stack_1))
		ft_sorting(&stack_1, &stack_2);
	// print_list(stack_1);
	free_stack(&stack_1);
	ft_free_array_of_strings(tmp);
	return (0);
}
