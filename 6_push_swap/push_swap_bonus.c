/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:05:29 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/10 23:45:04 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_check_1(char *s, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(s, "sa\n", 3) && ft_strlen(s) == 3)
		return (ft_swap_abs_b(stack_a, stack_b, 'a'), 1);
	else if (!ft_strncmp(s, "sb\n", 3) && ft_strlen(s) == 3)
		return (ft_swap_abs_b(stack_a, stack_b, 'b'), 1);
	else if (!ft_strncmp(s, "ss\n", 3) && ft_strlen(s) == 3)
		return (ft_swap_abs_b(stack_a, stack_b, 's'), 1);
	else if (!ft_strncmp(s, "pa\n", 3) && ft_strlen(s) == 3)
		return (ft_push_ab_b(stack_a, stack_b, 'a'), 1);
	else if (!ft_strncmp(s, "pb\n", 3) && ft_strlen(s) == 3)
		return (ft_push_ab_b(stack_a, stack_b, 'b'), 1);
	return (0);
}

int	ft_check_2(char *s, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(s, "ra\n", 3) && ft_strlen(s) == 3)
		return (ft_rotate_abr_b(stack_a, stack_b, 'a'), 1);
	else if (!ft_strncmp(s, "rb\n", 3) && ft_strlen(s) == 3)
		return (ft_rotate_abr_b(stack_a, stack_b, 'b'), 1);
	else if (!ft_strncmp(s, "rr\n", 3) && ft_strlen(s) == 3)
		return (ft_rotate_abr_b(stack_a, stack_b, 'r'), 1);
	else if (!ft_strncmp(s, "rra\n", 4) && ft_strlen(s) == 4)
		return (ft_reverse_rotate_abr_b(stack_a, stack_b, 'a'), 1);
	else if (!ft_strncmp(s, "rrb\n", 4) && ft_strlen(s) == 4)
		return (ft_reverse_rotate_abr_b(stack_a, stack_b, 'b'), 1);
	else if (!ft_strncmp(s, "rrr\n", 4) && ft_strlen(s) == 4)
		return (ft_reverse_rotate_abr_b(stack_a, stack_b, 'r'), 1);
	return (0);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	if (!s1[i] || !s2[i])
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	is_newline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	push_swap_bonus(t_list **stack_a, t_list **stack_b)
{
	char	*s;

	s = get_next_line(STDIN_FILENO);
	while (s)
	{
		if (!ft_check_1(s, stack_a, stack_b))
		{
			if (!ft_check_2(s, stack_a, stack_b))
			{
				write(1, "Error\n", 6);
				free(s);
				return (ft_free_stack(stack_a), ft_free_stack(stack_b), 0);
			}
		}
		free(s);
		s = get_next_line(STDIN_FILENO);
	}
	return (1);
}
