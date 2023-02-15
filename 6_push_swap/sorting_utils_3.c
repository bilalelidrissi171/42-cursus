/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:50:27 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/10 19:34:05 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_move_lis(t_list **stack)
{
	if (ft_is_up_down(*stack, ft_get_min(*stack)))
		while (ft_get_min(*stack) != (*stack)->content)
			ft_rotate_abr(stack, NULL, 'a');
	else
		while (ft_get_min(*stack) != (*stack)->content)
			ft_reverse_rotate_abr(stack, NULL, 'a');
}

int	*ft_samller_steps(int **steps, size_t size)
{
	int		*smaller;
	int		min;
	size_t	i;

	smaller = (int *)malloc(sizeof(int) * 2);
	i = 0;
	min = MAX;
	while (i < size)
	{
		if ((steps[i][0] >= 0 && steps[i][1] >= 0) || \
			(steps[i][0] <= 0 && steps[i][1] <= 0))
		{
			if (ft_abs(steps[i][0]) >= ft_abs(steps[i][1]))
				steps[i][2] = ft_abs(steps[i][0]);
			else
				steps[i][2] = ft_abs(steps[i][1]);
		}
		else
			steps[i][2] = ft_abs(steps[i][0]) + ft_abs(steps[i][1]);
		if (steps[i][2] < min)
			min = steps[i][2];
		i++;
	}
	return (ft_find_samller_steps(steps, size, min, smaller));
}

int	*ft_find_samller_steps(int **steps, size_t size, int min, int *smaller)
{
	size_t	i;

	i = -1;
	while (++i < size)
	{
		if (steps[i][2] == min)
		{
			smaller[0] = steps[i][0];
			smaller[1] = steps[i][1];
		}
	}
	return (smaller);
}

int	ft_up_steps(t_list *stack, int content)
{
	size_t	i;

	i = 0;
	while (stack)
	{
		if (stack->content == content)
			return (i);
		stack = stack->next;
		i++;
	}
	return (0);
}

int	ft_down_steps(t_list *stack, int content)
{
	size_t	i;

	i = 0;
	while (stack)
	{
		if (stack->content == content)
			i = 0;
		stack = stack->next;
		i++;
	}
	return (i * -1);
}
