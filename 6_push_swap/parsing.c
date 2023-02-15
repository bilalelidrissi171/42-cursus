/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:16:30 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/10 23:40:35 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_digit(char **av)
{
	size_t		i;

	i = 0;
	while (av[i])
	{
		if (!av[i])
			return (0);
		if (ft_atoi(av[i]) == MAX + 1ull)
			return (1);
		i++;
	}
	return (0);
}

int	ft_longer(char **av)
{
	size_t		i;

	i = 0;
	while (av[i])
	{
		if (ft_atoi(av[i]) > MAX || ft_atoi(av[i]) < MIN)
			return (1);
		i++;
	}
	return (0);
}

int	ft_duplicat(char **av)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_onlyspaces(char *av)
{
	size_t	i;
	size_t	c;

	c = 0;
	i = 0;
	while (av[i])
	{
		if (av[i] == ' ')
			c++;
		i++;
	}
	if (ft_strlen(av) == c)
		return (1);
	return (0);
}

int	ft_parsing(t_list **stack_a, char **av)
{
	char	**ss;
	size_t	i;

	ss = ft_joinargv(av);
	if (!ss)
		return (0);
	if (ft_digit(ss))
		return (ft_free_tab(ss), 0);
	if (ft_longer(ss))
		return (ft_free_tab(ss), 0);
	if (ft_duplicat(ss))
		return (ft_free_tab(ss), 0);
	i = 0;
	while (ss[i])
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(ss[i++])));
	return (ft_free_tab(ss), 1);
}
