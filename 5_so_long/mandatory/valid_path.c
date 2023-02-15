/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:37:51 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/25 14:31:42 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_fill_one(char **map, t_map_i_j pos)
{
	t_map_i_j	up;
	t_map_i_j	down;
	t_map_i_j	left;
	t_map_i_j	right;

	if (map[pos.i][pos.j] == 'E')
		map[pos.i][pos.j] = '2';
	if (map[pos.i][pos.j] == '1' || map[pos.i][pos.j] == '2')
		return ;
	map[pos.i][pos.j] = '1';
	up.i = pos.i + 1;
	up.j = pos.j;
	down.i = pos.i - 1;
	down.j = pos.j;
	left.i = pos.i;
	left.j = pos.j - 1;
	right.i = pos.i;
	right.j = pos.j + 1;
	ft_fill_one(map, up);
	ft_fill_one(map, down);
	ft_fill_one(map, left);
	ft_fill_one(map, right);
}

int	is_not_valid_path(char **map)
{
	char	**map_copy;
	int		collectibles;
	int		exits;

	map_copy = ft_copy_map(map);
	ft_fill_one(map_copy, ft_find(map_copy, 'P'));
	collectibles = ft_get_char_in_map(map_copy, 'C');
	exits = ft_get_char_in_map(map_copy, 'E');
	ft_free_map(map_copy);
	if (collectibles || exits)
		return (1);
	return (0);
}

char	**ft_copy_map(char **map)
{
	char	**map_copy;
	int		i;
	int		j;

	j = 0;
	while (map[j])
		j++;
	map_copy = malloc((j + 1) * sizeof(char *));
	if (!map_copy)
		ft_error("Error\nMalloc Error\n", NULL, NULL);
	i = -1;
	while (map[++i])
		map_copy[i] = ft_strdup(map[i]);
	map_copy[i] = NULL;
	return (map_copy);
}
