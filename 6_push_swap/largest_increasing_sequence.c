/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largest_increasing_sequence.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 03:18:23 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/10 19:14:40 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_lst_to_arr(t_list *stack)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * ft_lstsize(stack));
	i = 0;
	while (stack)
	{
		arr[i++] = stack->content;
		stack = stack->next;
	}
	return (arr);
}

int	ft_get_max_lis(int *arr, t_list *stack)
{
	size_t	i;
	int		max;

	i = 0;
	max = arr[0];
	while (i < ft_lstsize(stack))
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

int	*ft_get_lis(t_list **stack)
{
	int		*lis;
	int		*index_lis;
	int		*arr;
	size_t	i;
	size_t	j;

	best_move_lis(stack);
	arr = ft_lst_to_arr(*stack);
	lis = malloc(sizeof(int) * ft_lstsize(*stack));
	index_lis = malloc(sizeof(int) * ft_lstsize(*stack));
	i = -1;
	while (++i < ft_lstsize(*stack))
	{
		lis[i] = 1;
		j = -1;
		while (++j < i)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
			{
				index_lis[i] = j;
				lis[i] = lis[j] + 1;
			}
		}
	}
	return (free(arr), free(lis), index_lis);
}

int	ft_get_index_of_max(int *arr, int max)
{
	int	i;

	i = 0;
	while (arr[i] != max)
		i++;
	return (i);
}

int	*ft_get_content(t_list **stack)
{
	int		*arr;
	int		*index_lis;
	int		*content;
	size_t	i;
	int		next_index;

	content = malloc(sizeof(int) * ft_lstsize(*stack));
	index_lis = ft_get_lis(stack);
	arr = ft_lst_to_arr(*stack);
	i = 0;
	content[i] = \
	arr[ft_get_index_of_max(index_lis, ft_get_max_lis(index_lis, *stack))];
	next_index = index_lis[ft_get_index_of_max \
	(index_lis, ft_get_max_lis(index_lis, *stack))];
	while (++i < ft_lstsize(*stack))
	{
		content[i] = arr[next_index];
		next_index = index_lis[next_index];
	}
	return (free(arr), free(index_lis), content);
}
