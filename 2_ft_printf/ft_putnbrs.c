/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 00:24:13 by bel-idri          #+#    #+#             */
/*   Updated: 2022/11/07 19:20:01 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_i_d(int nbr, char *base)
{
	if (nbr == -2147483648)
		ft_putstr("-2147483648");
	else if (nbr < 0)
	{
		ft_putchr('-');
		nbr *= -1;
		ft_putnbr_base_i_d(nbr, base);
	}
	else if (nbr >= (int)ft_strlen(base))
	{
		ft_putnbr_base_i_d(nbr / ft_strlen(base), base);
		ft_putchr(base[nbr % ft_strlen(base)]);
	}
	else
		ft_putchr(base[nbr % ft_strlen(base)]);
}

void	ft_putnbr_base_u_x(unsigned int nbr, char *base)
{
	if (nbr >= (unsigned int)ft_strlen(base))
	{
		ft_putnbr_base_u_x(nbr / ft_strlen(base), base);
		ft_putchr(base[nbr % ft_strlen(base)]);
	}
	else
		ft_putchr(base[nbr % ft_strlen(base)]);
}

void	ft_putnbr_base_p(unsigned long long nbr, char *base)
{
	if (nbr >= (unsigned long long)ft_strlen(base))
	{
		ft_putnbr_base_p(nbr / ft_strlen(base), base);
		ft_putchr(base[nbr % ft_strlen(base)]);
	}
	else
		ft_putchr(base[nbr % ft_strlen(base)]);
}
