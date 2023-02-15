/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:27:49 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/25 07:18:12 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *s)
{
	size_t	x;

	x = 0;
	if (!s)
		return (0);
	while (s[x])
		x++;
	return (x);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		ls1;
	int		ls2;

	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	str = (char *)malloc((ls1 + ls2 + 1) * sizeof(char));
	if (!str)
		return (free(s1), NULL);
	i = -1;
	j = -1;
	while (++i < ls1)
		str[i] = s1[i];
	while (++j < ls2)
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strdup(char *s1)
{
	char	*s;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	s = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

char	*ft_itoa(int n)
{
	int		counter;
	char	*str;
	int		n_copy;

	if (n == 0)
		return (ft_strdup("0"));
	n_copy = n;
	counter = 0;
	while (n_copy > 0)
	{
		n_copy /= 10;
		counter++;
	}
	str = (char *)malloc((counter + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[counter] = '\0';
	while (--counter >= 0)
	{
		str[counter] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}
