/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:22:53 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/10 18:53:14 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_steps(int **steps, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
		free(steps[i]);
	free(steps);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

void	ft_push_swap(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*temp1;

	temp = *stack_a;
	temp1 = *stack_b;
	if (ft_lstsize(*stack_a) == 1 || ft_is_sort(*stack_a))
		return ;
	if (ft_lstsize(*stack_a) == 2)
		return (ft_swap_abs(stack_a, stack_b, 'a'));
	if (ft_lstsize(*stack_a) == 3)
		return (ft_sort_three(stack_a));
	if (ft_lstsize(*stack_a) <= 5)
		return (ft_sort_five(stack_a, stack_b));
	if (ft_is_sort_rev(*stack_a))
		return (ft_sort_rev(stack_a, stack_b));
	return (ft_sort(stack_a, stack_b));
}
