/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:01:47 by bel-idri          #+#    #+#             */
/*   Updated: 2022/11/07 19:26:53 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str_format, ...);
size_t	ft_strlen(const char *s);
int		ft_putstr(char *s);
int		ft_putchr(char c);
void	ft_putnbr_base_i_d(int nbr, char *base);
void	ft_putnbr_base_u_x(unsigned int nbr, char *base);
void	ft_putnbr_base_p(unsigned long long nbr, char *base);
int		count_len_i_d(int s);
int		count_len_x(unsigned int s);
int		count_len_xx(unsigned int s);
int		count_len_p(unsigned long long s);
int		count_len_u(unsigned int s);

#endif
