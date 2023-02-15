/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:13:51 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/07 03:25:47 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_list **stack)
{
	int	temp;

	if (!*stack || !((*stack)->next))
		return (0);
	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
	return (1);
}

int	ft_push(t_list **stack_recv, t_list **stack_givn)
{
	t_list	*temp;

	temp = *stack_givn;
	if (!*stack_givn)
		return (0);
	ft_lstadd_front(stack_recv, ft_lstnew((*stack_givn)->content));
	*stack_givn = (*stack_givn)->next;
	free(temp);
	return (1);
}

int	ft_rotate(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	if (!*stack || !((*stack)->next))
		return (0);
	ft_lstadd_back(stack, ft_lstnew((*stack)->content));
	*stack = (*stack)->next;
	free(temp);
	return (1);
}

int	ft_reverse_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*del;

	if (!*stack || !((*stack)->next))
		return (0);
	ft_lstadd_front(stack, ft_lstnew(ft_lstlast(*stack)->content));
	temp = *stack;
	while (temp->next->next)
		temp = temp->next;
	del = temp->next;
	temp->next = NULL;
	free(del);
	return (1);
}
