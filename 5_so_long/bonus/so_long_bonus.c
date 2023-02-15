/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 07:19:14 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/27 21:50:00 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_find_char_new_bonus(char **map)
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
				&& map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != 'X')
				return (1);
		}
	}
	return (0);
}

int	ft_loop_hook(void *param)
{
	int			i;
	static int	count = 1;
	static int	count_2 = 1;
	t_mlx_img	*my_mlx_img;

	my_mlx_img = ((t_mlx_img *)param);
	if ((*my_mlx_img).enemy != ft_get_char_in_map((*my_mlx_img).map, 'X') || \
		!ft_get_char_in_map((*my_mlx_img).map, 'P'))
		ft_exit("You Lose\n", my_mlx_img);
	count++;
	i = -1;
	mlx_clear_window((*my_mlx_img).mlx, (*my_mlx_img).win);
	while ((*my_mlx_img).map[++i])
		ft_loop_hook_utils(*my_mlx_img, i, -1, count);
	ft_loop_hook_utils_2(my_mlx_img, -1, &count_2, \
						ft_line_column_map((*my_mlx_img).map));
	if (count == 15)
		count = 0;
	if (count_2 == 53)
		count_2 = 0;
	ft_put_str(my_mlx_img);
	return (ft_print_map((*my_mlx_img)), 0);
}

void	ft_loop_hook_utils(t_mlx_img my_mlx_img, int i, int j, int count)
{
	while (my_mlx_img.map[i][++j])
	{
		if (my_mlx_img.map[i][j] == 'X' && count <= 5)
			mlx_put_image_to_window(my_mlx_img.mlx, my_mlx_img.win, \
									my_mlx_img.img_x_1, j * 64, i * 64);
		else if (my_mlx_img.map[i][j] == 'X' && count <= 10)
			mlx_put_image_to_window(my_mlx_img.mlx, my_mlx_img.win, \
									my_mlx_img.img_x_2, j * 64, i * 64);
		else if (my_mlx_img.map[i][j] == 'X' && count <= 15)
			mlx_put_image_to_window(my_mlx_img.mlx, my_mlx_img.win, \
									my_mlx_img.img_x_3, j * 64, i * 64);
	}
}

void	ft_loop_hook_utils_2(t_mlx_img *my_mlx_img, int i, int *count, \
		t_map_i_j map_size)
{
	t_map_i_j	*arr_enemy;
	int			c;
	static int	d = 1;
	int			j;

	if ((*count)++ == 51)
	{
		arr_enemy = malloc(sizeof(t_map_i_j) * (*my_mlx_img).enemy);
		ft_error_malloc(my_mlx_img, arr_enemy);
		c = 0;
		while (++i < map_size.i)
		{
			j = -1;
			while (++j < map_size.j)
			{
				if ((*my_mlx_img).map[i][j] == 'X')
				{
					arr_enemy[c].i = i;
					arr_enemy[c++].j = j;
				}
			}
		}
		ft_loop_hook_utilis_3(my_mlx_img, (*my_mlx_img).enemy, arr_enemy, &d);
		free(arr_enemy);
	}
}

void	ft_loop_hook_utilis_3(t_mlx_img *my_mlx_img, int num_enemy, \
								t_map_i_j *an, int *d)
{
	int	c;

	c = 0;
	while (c < num_enemy)
	{
		if ((*my_mlx_img).map[an[c].i][an[c].j + 1] != '1' && \
			(*my_mlx_img).map[an[c].i][an[c].j + 1] != 'X' && \
			(*my_mlx_img).map[an[c].i][an[c].j + 1] != 'E' && \
			(*my_mlx_img).map[an[c].i][an[c].j + 1] != 'C' && *d != 1)
		{
			(*my_mlx_img).map[an[c].i][an[c].j] = '0';
			(*my_mlx_img).map[an[c].i][an[c].j + 1] = 'X';
			*d = 1;
		}
		else if ((*my_mlx_img).map[an[c].i][an[c].j - 1] != '1' && \
			(*my_mlx_img).map[an[c].i][an[c].j - 1] != 'X' && \
			(*my_mlx_img).map[an[c].i][an[c].j - 1] != 'E' && \
			(*my_mlx_img).map[an[c].i][an[c].j - 1] != 'C' && *d != 2)
		{
			(*my_mlx_img).map[an[c].i][an[c].j] = '0';
			(*my_mlx_img).map[an[c].i][an[c].j - 1] = 'X';
			*d = 2;
		}
		c++;
	}
}
