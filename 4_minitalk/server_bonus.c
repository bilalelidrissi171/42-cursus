/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:49:35 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/12 22:46:08 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	reset_values(int *i, unsigned char *c, int *pid, siginfo_t *info)
{
	*i = 0;
	*c = 0;
	*pid = info->si_pid;
}

int	check_is_null(unsigned char c)
{
	int	i;

	i = -1;
	if (c == 0)
		return (1);
	return (0);
}

void	handel(int num, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				i = 0;
	static int				pid = 0;

	(void)context;
	if (pid != info->si_pid)
		reset_values(&i, &c, &pid, info);
	if (i == 7)
	{
		if (num == SIGUSR1)
			c += 1 << i;
		write (1, &c, 1);
		if (check_is_null(c))
			kill(pid, SIGUSR1);
		reset_values(&i, &c, &pid, info);
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
