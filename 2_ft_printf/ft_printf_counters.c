/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_counters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:20:10 by bel-idri          #+#    #+#             */
/*   Updated: 2022/11/07 19:26:33 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_len_i_d(int s)
{
	int	i;

	ft_putnbr_base_i_d(s, "0123456789");
	i = 0;
	if (s == 0)
		return (1);
	if (s < 0)
		i++;
	while (s)
	{
		s /= 10;
		i++;
	}
	return (i);
}

int	count_len_x(unsigned int s)
{
	int	i;

	ft_putnbr_base_u_x(s, "0123456789abcdef");
	i = 0;
	if (s == 0)
		return (1);
	while (s)
	{
		s /= 16;
		i++;
	}
	return (i);
}

int	count_len_xx(unsigned int s)
{
	int	i;

	ft_putnbr_base_u_x(s, "0123456789ABCDEF");
	i = 0;
	if (s == 0)
		return (1);
	while (s)
	{
		s /= 16;
		i++;
	}
	return (i);
}

int	count_len_p(unsigned long long s)
{
	int	i;

	i = ft_putstr("0x");
	ft_putnbr_base_p(s, "0123456789abcdef");
	if (s == 0)
		return (3);
	while (s)
	{
		s /= 16;
		i++;
	}
	return (i);
}

int	count_len_u(unsigned int s)
{
	int	i;

	ft_putnbr_base_u_x(s, "0123456789");
	i = 0;
	if (s == 0)
		return (1);
	while (s)
	{
		s /= 10;
		i++;
	}
	return (i);
}
