/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:10:55 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/18 21:53:21 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_newline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_error_open(int fd)
{
	if (fd < 0)
		ft_error("Error\nOpen Error", NULL, NULL);
}

char	*get_next_line(int fd)
{
	char	*my_backup;
	char	*buff;
	int		nb;

	ft_error_open(fd);
	my_backup = ft_strdup("");
	nb = -1;
	while (!is_newline(my_backup))
	{
		buff = (char *)malloc(2 * sizeof(char));
		if (!buff)
			ft_error("Error\nMalloc Error", my_backup, NULL);
		nb = read(fd, buff, 1);
		if (nb == -1)
			ft_error("Error\nRead Error", my_backup, buff);
		if (nb == 0 && my_backup[0])
			return (free(buff), my_backup);
		if (nb == 0)
			return (free(buff), free(my_backup), NULL);
		buff[nb] = '\0';
		my_backup = ft_strjoin(my_backup, buff);
		free(buff);
	}
	my_backup[ft_strlen(my_backup) - 1] = '\0';
	return (my_backup);
}

char	*get_next_line_all(int fd)
{
	char	*my_backup;
	char	*buff;
	int		nb;

	ft_error_open(fd);
	my_backup = ft_strdup("");
	nb = -1;
	while (1)
	{
		buff = (char *)malloc(2 * sizeof(char));
		if (!buff)
			ft_error("Error\nMalloc Error", my_backup, NULL);
		nb = read(fd, buff, 1);
		if (nb == -1)
			ft_error("Error\nRead Error", my_backup, buff);
		if (nb == 0 && my_backup[0])
			return (free(buff), my_backup);
		if (nb == 0)
			ft_error("Error\nThe map is empty", my_backup, NULL);
		buff[nb] = '\0';
		my_backup = ft_strjoin(my_backup, buff);
		free(buff);
	}
	return (my_backup);
}
