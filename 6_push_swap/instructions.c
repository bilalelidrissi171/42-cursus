/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:12:47 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/06 23:13:12 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_abs(t_list **stack_a, t_list **stack_b, char c)
{
	if (c == 'a')
	{
		if (ft_swap(stack_a))
			write(1, "sa\n", 3);
	}
	if (c == 'b')
	{
		if (ft_swap(stack_b))
			write(1, "sb\n", 3);
	}
	if (c == 's')
	{
		if (ft_swap(stack_a) && ft_swap(stack_b))
			write(1, "ss\n", 3);
	}
}

void	ft_push_ab(t_list **stack_a, t_list **stack_b, char c)
{
	if (c == 'a')
	{
		if (ft_push(stack_a, stack_b))
			write(1, "pa\n", 3);
	}
	if (c == 'b')
	{
		if (ft_push(stack_b, stack_a))
			write(1, "pb\n", 3);
	}
}

void	ft_rotate_abr(t_list **stack_a, t_list **stack_b, char c)
{
	if (c == 'a')
	{
		if (ft_rotate(stack_a))
			write(1, "ra\n", 3);
	}
	if (c == 'b')
	{
		if (ft_rotate(stack_b))
			write(1, "rb\n", 3);
	}
	if (c == 'r')
	{
		if (ft_rotate(stack_a) && ft_rotate(stack_b))
			write(1, "rr\n", 3);
	}
}

void	ft_reverse_rotate_abr(t_list **stack_a, t_list **stack_b, char c)
{
	if (c == 'a')
	{
		if (ft_reverse_rotate(stack_a))
			write(1, "rra\n", 4);
	}
	if (c == 'b')
	{
		if (ft_reverse_rotate(stack_b))
			write(1, "rrb\n", 4);
	}
	if (c == 'r')
	{
		if (ft_reverse_rotate(stack_a) && ft_reverse_rotate(stack_b))
			write(1, "rrr\n", 4);
	}
}
