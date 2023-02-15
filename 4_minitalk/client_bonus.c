/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:49:25 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/12 22:47:59 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handel(int num)
{
	(void)num;
	write(1, "The msessage is sended\n", 22);
}

void	sent_null(int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			write(1, "Error\n", 6);
			return ;
		}
		usleep(700);
	}
}

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
	sent_null(pid);
	return (1);
}

int	main(int ac, char **av)
{
	int	pid;

	signal(SIGUSR1, handel);
	if (ac != 3)
		return (write(1, "Error\n", 6), 1);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (write(1, "Error\n", 6), 1);
	if (!send_bits(pid, av[2]))
		return (1);
	return (0);
}
