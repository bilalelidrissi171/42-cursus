/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:07:02 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/10 19:44:32 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_moves(t_list **stack_a, t_list **stack_b, int *one_step)
{
	while (one_step[0] < 0 && one_step[1] < 0)
	{
		ft_reverse_rotate_abr(stack_a, stack_b, 'r');
		one_step[0]++;
		one_step[1]++;
	}
	while (one_step[0] > 0 && one_step[1] > 0)
	{
		ft_rotate_abr(stack_a, stack_b, 'r');
		one_step[0]--;
		one_step[1]--;
	}
	while (one_step[0] > 0)
	{
		ft_rotate_abr(stack_a, stack_b, 'b');
		one_step[0]--;
	}
	while (one_step[0] < 0)
	{
		ft_reverse_rotate_abr(stack_a, stack_b, 'b');
		one_step[0]++;
	}
}

void	ft_do_moves_1(t_list **stack_a, t_list **stack_b, int *one_step)
{
	while (one_step[1] > 0)
	{
		ft_rotate_abr(stack_a, stack_b, 'a');
		one_step[1]--;
	}
	while (one_step[1] < 0)
	{
		ft_reverse_rotate_abr(stack_a, stack_b, 'a');
		one_step[1]++;
	}
}

void	ft_init_0(int **steps, size_t num)
{
	size_t	i;

	i = -1;
	while (++i < num)
		steps[i][1] = 0;
}

void	ft_compare_next_prev(int i, t_list *stack_a, t_list *temp, int **steps)
{
	if (ft_is_up_down(stack_a, temp->content))
		steps[i][1] = ft_up_steps(stack_a, temp->next->content);
	else
		steps[i][1] = ft_down_steps(stack_a, temp->next->content);
}
