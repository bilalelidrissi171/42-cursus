/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:34:52 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/10 23:12:35 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swap_abs_b(t_list **stack_a, t_list **stack_b, char c)
{
	if (c == 'a')
		ft_swap(stack_a);
	if (c == 'b')
		ft_swap(stack_b);
	if (c == 's')
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
	}
}

void	ft_push_ab_b(t_list **stack_a, t_list **stack_b, char c)
{
	if (c == 'a')
		ft_push(stack_a, stack_b);
	if (c == 'b')
		ft_push(stack_b, stack_a);
}

void	ft_rotate_abr_b(t_list **stack_a, t_list **stack_b, char c)
{
	if (c == 'a')
		ft_rotate(stack_a);
	if (c == 'b')
		ft_rotate(stack_b);
	if (c == 'r')
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
}

void	ft_reverse_rotate_abr_b(t_list **stack_a, t_list **stack_b, char c)
{
	if (c == 'a')
		ft_reverse_rotate(stack_a);
	if (c == 'b')
		ft_reverse_rotate(stack_b);
	if (c == 'r')
	{
		ft_reverse_rotate(stack_a);
		ft_reverse_rotate(stack_b);
	}
}
