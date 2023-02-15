/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:36:57 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/12 22:34:50 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_bits(int pid, char *s)
{
	int	i;
	int	j;

	i = -1;
	while (s[++i])
	{
		j = -1;
		while (++j < 8)
		{
			if (((s[i] >> j) & 1))
			{
				if (kill(pid, SIGUSR1) == -1)
					return (write(1, "Error\n", 6), 0);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					return (write(1, "Error\n", 6), 0);
			}
			usleep(700);
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		return (write(1, "Error\n", 6), 1);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (write(1, "Error\n", 6), 1);
	if (!send_bits(pid, av[2]))
		return (1);
	return (0);
}
