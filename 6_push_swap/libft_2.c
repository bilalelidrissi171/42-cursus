/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:07:23 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/10 23:40:35 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(char *s1)
{
	char	*s;
	int		i;

	i = 0;
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

long long	ft_my_atio(char *str, int i, int sign)
{
	size_t	res;
	size_t	temp;

	res = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		temp = res;
		res = (res * 10) + (str[i] - 48);
		if (temp != res / 10 && sign == 1)
			return (MAX + 1ll);
		if (temp != res / 10 && sign == -1)
			return (MAX + 1ll);
		i++;
	}
	if (str[i])
		return (MAX + 1ll);
	if (res > MAX && sign == 1)
		return (MAX + 1ll);
	if (res > MAX + 1ll && sign == -1)
		return (MAX + 1ll);
	return (res * sign);
}

int	ft_count_words(char *s, char c)
{
	int	index;
	int	counter;

	index = 0;
	counter = 0;
	if (ft_strlen(s) == 0)
		return (0);
	while (s[index] == c)
		index++;
	while (s[index])
	{
		if (s[index] == c)
		{
			counter++;
			while (s[index] == c)
				index++;
		}
		else
			index++;
	}
	if (s[index - 1] != c)
		counter++;
	return (counter);
}

void	ft_free(char **str)
{
	int	index;

	index = 0;
	while (str[index])
		free(str[index++]);
	free(str);
}

char	**ft_my_split(char *s, char c, int start, int end)
{
	char	**str;
	int		index;

	index = 0;
	str = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (index < ft_count_words(s, c) && s[start])
	{
		start = end;
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		str[index] = ft_substr(s, start, end - start);
		if (!str[index])
		{
			ft_free(str);
			return (NULL);
		}
		index++;
	}
	str[index] = NULL;
	return (str);
}
