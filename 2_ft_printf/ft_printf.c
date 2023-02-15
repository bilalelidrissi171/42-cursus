/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:01:50 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/29 09:28:46 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_char(const char *str_format, int *res, size_t *i, va_list	*ap)
{
	if (str_format[*i] == 'c')
		*res += ft_putchr(va_arg(*ap, int));
	else if (str_format[*i] == 's')
		*res += ft_putstr(va_arg(*ap, char *));
	else if (str_format[*i] == 'p')
		*res += count_len_p(va_arg(*ap,unsigned long long));
	else if (str_format[*i] == 'd' || str_format[*i] == 'i')
		*res += count_len_i_d(va_arg(*ap, int));
	else if (str_format[*i] == 'u')
		*res += count_len_u(va_arg(*ap,unsigned int));
	else if (str_format[*i] == 'x')
		*res += count_len_x(va_arg(*ap,unsigned long));
	else if (str_format[*i] == 'X')
		*res += count_len_xx(va_arg(*ap,unsigned long));
	else if (str_format[*i] == '%')
		*res += ft_putchr('%');
	else
		(*i)--;
}

int	ft_printf(const char *str_format, ...)
{
	va_list	ap;
	size_t	i;
	int		res;

	if (write(1, 0, 0) == -1)
		return (-1);
	res = 0;
	i = 0;
	va_start(ap, str_format);
	while (i < ft_strlen(str_format))
	{
		if (str_format[i] != '%')
			res += ft_putchr(str_format[i]);
		else
		{
			i++;
			check_char(str_format, &res, &i, &ap);
		}
		i++;
	}
	va_end(ap);
	return (res);
}
