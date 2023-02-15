/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:50:31 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/25 17:59:26 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_count_moves(int *i)
{
	write(1, "number of movements: ", 21);
	ft_putnbr((*i)++);
	write(1, "\n", 1);
}

void	ft_exit(char *msg, t_mlx_img *my_mlx_img)
{
	write(1, msg, ft_strlen(msg));
	mlx_destroy_image((*my_mlx_img).mlx, (*my_mlx_img).img_1);
	mlx_destroy_image((*my_mlx_img).mlx, (*my_mlx_img).img_c);
	mlx_destroy_image((*my_mlx_img).mlx, (*my_mlx_img).img_e);
	mlx_destroy_image((*my_mlx_img).mlx, (*my_mlx_img).img_p);
	if (X)
	{
		mlx_destroy_image((*my_mlx_img).mlx, (*my_mlx_img).img_x_1);
		mlx_destroy_image((*my_mlx_img).mlx, (*my_mlx_img).img_x_2);
		mlx_destroy_image((*my_mlx_img).mlx, (*my_mlx_img).img_x_3);
	}
	mlx_destroy_window((*my_mlx_img).mlx, (*my_mlx_img).win);
	ft_free_map((*my_mlx_img).map);
	exit(EXIT_SUCCESS);
}

t_map_i_j	ft_line_column_map(char **map)
{
	t_map_i_j	map_i_j;

	map_i_j.i = 0;
	map_i_j.j = 0;
	while (map[map_i_j.i])
	{
		map_i_j.j = 0;
		while (map[map_i_j.i][map_i_j.j])
			map_i_j.j++;
		map_i_j.i++;
	}
	return (map_i_j);
}

t_map_i_j	ft_find(char **map, char c)
{
	t_map_i_j	map_i_j;
	t_map_i_j	map_size;

	map_size = ft_line_column_map(map);
	map_i_j.i = -1;
	while (++map_i_j.i < map_size.i)
	{
		map_i_j.j = -1;
		while (++map_i_j.j < map_size.j)
			if (map[map_i_j.i][map_i_j.j] == c)
				return (map_i_j);
	}
	return (map_i_j);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}
