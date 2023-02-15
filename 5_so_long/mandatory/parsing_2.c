/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:43:36 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/24 04:14:16 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_not_matrix(char **map)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i])
		if (ft_strlen(map[i++]) != len)
			return (1);
	return (0);
}

int	is_find_char_new(char **map)
{
	int	i;
	int	j;
	int	cl;

	i = -1;
	cl = ft_size_of_map(map);
	while (++i < cl)
	{
		j = -1;
		while (++j < ft_strlen(map[i]))
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' \
				&& map[i][j] != 'E' && map[i][j] != 'P')
				return (1);
		}
	}
	return (0);
}

int	is_not_find_all_char(char **map)
{
	t_map_elem	map_elem;
	int			i;
	int			j;
	int			cl;

	ft_init_map_elem(&map_elem);
	i = -1;
	cl = ft_size_of_map(map);
	while (++i < cl)
	{
		j = -1;
		while (++j < ft_strlen(map[i]))
		{
			if (map[i][j] == 'E')
				map_elem.exit++;
			if (map[i][j] == 'C')
				map_elem.collectible++;
			if (map[i][j] == 'P')
				map_elem.player++;
		}
	}
	if (map_elem.exit == 1 && map_elem.player == 1 && map_elem.collectible >= 1)
		return (0);
	return (1);
}

int	is_not_closed(char **map)
{
	int	j;
	int	cl;
	int	c;

	c = 0;
	j = -1;
	cl = ft_size_of_map(map);
	while (++j < ft_strlen(map[0]))
		if (map[0][j] != '1')
			return (1);
	j = -1;
	while (++j < ft_strlen(map[cl - 1]))
		if (map[cl - 1][j] != '1')
			return (1);
	j = -1;
	while (++j < cl)
		if (map[j][ft_strlen(map[j]) - 1] != '1' || map[j][0] != '1')
			return (1);
	return (0);
}

int	ft_cout_new_line(char *path_map)
{
	int		i;
	int		c;
	char	*s;
	int		fd;

	fd = open(path_map, O_RDONLY);
	s = get_next_line_all(fd);
	close(fd);
	i = 0;
	c = 0;
	while (s[i])
		if (s[i++] == '\n')
			c++;
	if (s[--i] != '\n')
		c++;
	free(s);
	return (c);
}
