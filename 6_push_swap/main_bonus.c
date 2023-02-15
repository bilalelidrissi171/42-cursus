/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:09:39 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/10 23:49:20 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (1);
	if (!ft_parsing(&stack_a, av))
		return (write(1, "Error\n", 6), 1);
	if (push_swap_bonus(&stack_a, &stack_b))
	{
		if (!stack_b && ft_is_sort(stack_a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		ft_free_stack(&stack_a);
		ft_free_stack(&stack_b);
		return (0);
	}
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (1);
}
