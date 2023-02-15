/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:07:55 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/10 19:57:39 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_to_b(t_list **stack_a, t_list **stack_b, int *a)
{
	size_t	i;
	size_t	j;
	size_t	size;
	t_list	*temp;

	temp = *stack_a;
	j = -1;
	size = ft_lstsize(*stack_a);
	while (++j < size)
	{
		i = -1;
		while (++i < ft_lstsize(temp))
			if (temp->content == a[i])
				temp->found = 1;
		temp = temp->next;
	}
	j = -1;
	while (++j < size)
	{
		if ((*stack_a)->found == 1)
			ft_rotate_abr(stack_a, stack_b, 'a');
		else
			ft_push_ab(stack_a, stack_b, 'b');
	}
}

int	**ft_malloc_steps(t_list *stack_b)
{
	size_t	i;
	int		**steps;

	i = -1;
	steps = (int **)malloc(sizeof(int *) * ft_lstsize(stack_b));
	while (++i < ft_lstsize(stack_b))
		steps[i] = (int *)malloc(sizeof(int) * 3);
	return (steps);
}

void	ft_steps_b(t_list *stack_b, int **steps)
{
	size_t	i;
	t_list	*temp;

	temp = stack_b;
	i = -1;
	while (++i < ft_lstsize(stack_b))
	{
		if (ft_is_up_down(stack_b, temp->content))
			steps[i][0] = ft_up_steps(stack_b, temp->content);
		else
			steps[i][0] = ft_down_steps(stack_b, temp->content);
		temp = temp->next;
	}
}

void	ft_compare_max_min(int i, t_list *stack_a, t_list *temp1, int **steps)
{
	if (ft_get_min(stack_a) > temp1->content)
	{
		if (ft_is_up_down(stack_a, ft_get_min(stack_a)))
			steps[i][1] = ft_up_steps(stack_a, ft_get_min(stack_a));
		else
			steps[i][1] = ft_down_steps(stack_a, ft_get_min(stack_a));
	}
	else if (ft_get_max(stack_a) < temp1->content)
	{
		if (ft_is_up_down(stack_a, ft_get_min(stack_a)))
			steps[i][1] = ft_up_steps(stack_a, ft_get_min(stack_a));
		else
			steps[i][1] = ft_down_steps(stack_a, ft_get_min(stack_a));
	}
}

void	ft_steps_a(t_list *stack_a, t_list *stack_b, int **steps)
{
	size_t	i;
	size_t	j;
	t_list	*temp;
	t_list	*temp1;

	ft_init_0(steps, ft_lstsize(stack_b));
	i = -1;
	temp1 = stack_b;
	while (++i < ft_lstsize(stack_b))
	{
		j = -1;
		temp = stack_a;
		while (++j < ft_lstsize(stack_a) - 1)
		{
			ft_compare_max_min(i, stack_a, temp1, steps);
			if (temp->content < temp1->content && \
				temp->next->content > temp1->content)
				ft_compare_next_prev(i, stack_a, temp, steps);
			temp = temp->next;
		}
		temp1 = temp1->next;
	}
}
