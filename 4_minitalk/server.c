/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:37:02 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/12 03:26:51 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handel(int num, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				i = 0;
	static int				pid = 0;

	(void)context;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		i = 0;
		c = 0;
	}
	if (i == 7)
	{
		if (num == SIGUSR1)
			c += 1 << i;
		write (1, &c, 1);
		i = 0;
		c = 0;
		return ;
	}
	if (num == SIGUSR1)
		c += 1 << i;
	i++;
}

int	main(void)
{
	struct sigaction	sa;

	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handel;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
