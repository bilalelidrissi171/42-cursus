/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 07:42:44 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/25 18:09:54 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_key_hook_utils(int key, t_mlx_img *my_mlx_img, int *i)
{
	static int	collectible_player = 0;

	if (ft_check_if_e(key, (*my_mlx_img).map))
	{
		if ((*my_mlx_img).collectible_map == collectible_player)
		{
			if (!X)
				ft_print_count_moves(i);
			ft_exit("You Win\n", &(*my_mlx_img));
		}
	}
	else
	{
		if (ft_check_if_c(key, (*my_mlx_img).map))
			collectible_player++;
		if (ft_move(key, (*my_mlx_img).map))
		{
			mlx_clear_window((*my_mlx_img).mlx, (*my_mlx_img).win);
			if (X)
				(*my_mlx_img).moves++;
			else
				ft_print_count_moves(i);
		}
	}
}

int	ft_key_hook(int key, void *param)
{
	static int	i = 1;
	t_mlx_img	*my_mlx_img;

	my_mlx_img = ((t_mlx_img *)param);
	if (key == 53)
		ft_exit("You Exit the Game\n", my_mlx_img);
	ft_key_hook_utils(key, my_mlx_img, &i);
	ft_print_map(*my_mlx_img);
	return (0);
}

int	ft_check_if_e(int key, char **map)
{
	t_map_i_j	map_i_j;
	t_map_i_j	map_size;

	map_size = ft_line_column_map(map);
	map_i_j = ft_find(map, 'P');
	if (key == 13 && map[map_i_j.i - 1][map_i_j.j] == 'E')
		return (1);
	if (key == 1 && map[map_i_j.i + 1][map_i_j.j] == 'E')
		return (1);
	if (key == 0 && map[map_i_j.i][map_i_j.j - 1] == 'E')
		return (1);
	if (key == 2 && map[map_i_j.i][map_i_j.j + 1] == 'E')
		return (1);
	return (0);
}

int	ft_check_if_c(int key, char **map)
{
	t_map_i_j	map_i_j;
	t_map_i_j	map_size;

	map_size = ft_line_column_map(map);
	map_i_j = ft_find(map, 'P');
	if (key == 13 && map[map_i_j.i - 1][map_i_j.j] == 'C')
		return (1);
	if (key == 1 && map[map_i_j.i + 1][map_i_j.j] == 'C')
		return (1);
	if (key == 0 && map[map_i_j.i][map_i_j.j - 1] == 'C')
		return (1);
	if (key == 2 && map[map_i_j.i][map_i_j.j + 1] == 'C')
		return (1);
	return (0);
}

int	ft_move(int key, char **map)
{
	t_map_i_j	map_i_j;
	t_map_i_j	map_size;

	map_size = ft_line_column_map(map);
	map_i_j = ft_find(map, 'P');
	if (key == 13 && map[map_i_j.i - 1][map_i_j.j] != '1')
		return (map[map_i_j.i][map_i_j.j] = '0', \
			map[map_i_j.i - 1][map_i_j.j] = 'P', 1);
	if (key == 1 && map[map_i_j.i + 1][map_i_j.j] != '1')
		return (map[map_i_j.i][map_i_j.j] = '0', \
			map[map_i_j.i + 1][map_i_j.j] = 'P', 1);
	if (key == 0 && map[map_i_j.i][map_i_j.j - 1] != '1')
		return (map[map_i_j.i][map_i_j.j] = '0', \
			map[map_i_j.i][map_i_j.j - 1] = 'P', 1);
	if (key == 2 && map[map_i_j.i][map_i_j.j + 1] != '1')
		return (map[map_i_j.i][map_i_j.j] = '0', \
			map[map_i_j.i][map_i_j.j + 1] = 'P', 1);
	return (0);
}
