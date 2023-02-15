/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:10:55 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/10 20:15:48 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*read_newline(int fd, char *my_backup)
{
	int		nb;
	char	*buff;

	nb = -1;
	while (!is_newline(my_backup) && nb)
	{
		buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return (free(my_backup), NULL);
		nb = read(fd, buff, BUFFER_SIZE);
		if (nb == -1)
			return (free(my_backup), free(buff), NULL);
		if (nb == 0)
			return (free(buff), my_backup);
		buff[nb] = '\0';
		my_backup = ft_strjoin(my_backup, buff);
		free(buff);
	}
	return (my_backup);
}

char	*extract_newline(char **my_backup)
{
	char	*len;
	size_t	i;

	i = 0;
	if (!is_newline(*my_backup))
	{
		if (**my_backup == '\0')
			return (NULL);
		len = *my_backup;
		*my_backup = NULL;
		return (len);
	}
	while ((*my_backup)[i] != '\n')
		i++;
	len = (char *)malloc((i + 2) * sizeof(char));
	if (!len)
		return (NULL);
	i = -1;
	while ((*my_backup)[++i] != '\n')
		len[i] = (*my_backup)[i];
	len[i++] = '\n';
	len[i] = '\0';
	return (len);
}

char	*extract_after_newline(char *my_backup)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!my_backup || *my_backup == '\0')
		return (free(my_backup), NULL);
	while (my_backup[i] != '\n' && my_backup[i])
		i++;
	res = (char *)malloc((ft_strlen(my_backup) - i) * sizeof(char));
	if (!res)
		return (free(my_backup), NULL);
	i++;
	while (my_backup[i])
	{
		res[j] = my_backup[i];
		i++;
		j++;
	}
	res[j] = '\0';
	free(my_backup);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*my_backup = NULL;
	char		*for_return;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	my_backup = read_newline(fd, my_backup);
	if (!my_backup)
		return (NULL);
	for_return = extract_newline(&my_backup);
	my_backup = extract_after_newline(my_backup);
	return (for_return);
}
