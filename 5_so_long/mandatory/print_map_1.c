/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 04:17:39 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/27 21:43:20 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_i_j	ft_get_map_i_j(char **map)
{
	t_map_i_j	map_i_j;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	while (map[0][j])
		j++;
	map_i_j.i = i;
	map_i_j.j = j;
	return (map_i_j);
}

int	ft_get_char_in_map(char **map, char ch)
{
	int	i;
	int	j;
	int	c;

	i = -1;
	c = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == ch)
				c++;
	}
	return (c);
}

void	ft_print_win(char **map)
{
	t_mlx_img	my_mlx_img;
	t_map_i_j	map_i_j;

	my_mlx_img.moves = 0;
	ft_init_images(&my_mlx_img);
	my_mlx_img.mlx = mlx_init();
	if (!my_mlx_img.mlx)
		ft_exit("Error\nmlx_init Error\n", &my_mlx_img);
	map_i_j = ft_get_map_i_j(map);
	my_mlx_img.win = mlx_new_window(my_mlx_img.mlx, map_i_j.j * 64, \
										map_i_j.i * 64, "so_long");
	if (!my_mlx_img.win)
		ft_exit("Error\nmlx_new_window Error\n", &my_mlx_img);
	my_mlx_img.map = map;
	my_mlx_img.collectible_map = ft_get_char_in_map(map, 'C');
	if (X)
		my_mlx_img.enemy = ft_get_char_in_map(map, 'X');
	ft_print_map(my_mlx_img);
	if (X)
		mlx_loop_hook(my_mlx_img.mlx, ft_loop_hook, &my_mlx_img);
	mlx_key_hook(my_mlx_img.win, ft_key_hook, &my_mlx_img);
	mlx_hook(my_mlx_img.win, 17, 0, ft_exit_cross, &my_mlx_img);
	mlx_loop(my_mlx_img.mlx);
}

void	ft_print_map(t_mlx_img my_mlx_img)
{
	int		i;
	int		j;

	i = -1;
	while (my_mlx_img.map[++i])
	{
		j = -1;
		while (my_mlx_img.map[i][++j])
		{
			if (my_mlx_img.map[i][j] == '1')
				mlx_put_image_to_window(my_mlx_img.mlx, my_mlx_img.win, \
										my_mlx_img.img_1, j * 64, i * 64);
			else if (my_mlx_img.map[i][j] == 'C')
				mlx_put_image_to_window(my_mlx_img.mlx, my_mlx_img.win, \
										my_mlx_img.img_c, j * 64, i * 64);
			else if (my_mlx_img.map[i][j] == 'E')
				mlx_put_image_to_window(my_mlx_img.mlx, my_mlx_img.win, \
										my_mlx_img.img_e, j * 64, i * 64);
			else if (my_mlx_img.map[i][j] == 'P')
				mlx_put_image_to_window(my_mlx_img.mlx, my_mlx_img.win, \
										my_mlx_img.img_p, j * 64, i * 64);
		}
	}
}

void	ft_init_images(t_mlx_img *my_mlx_img)
{
	(*my_mlx_img).img_1 = mlx_xpm_file_to_image((*my_mlx_img).mlx, \
	"images/img_1.xpm", &(*my_mlx_img).img_width, \
	&(*my_mlx_img).img_height);
	(*my_mlx_img).img_c = mlx_xpm_file_to_image((*my_mlx_img).mlx, \
	"images/img_C.xpm", &(*my_mlx_img).img_width, \
	&(*my_mlx_img).img_height);
	(*my_mlx_img).img_e = mlx_xpm_file_to_image((*my_mlx_img).mlx, \
	"images/img_E.xpm", &(*my_mlx_img).img_width, \
	&(*my_mlx_img).img_height);
	(*my_mlx_img).img_p = mlx_xpm_file_to_image((*my_mlx_img).mlx, \
	"images/img_P.xpm", &(*my_mlx_img).img_width, \
	&(*my_mlx_img).img_height);
	if (!(*my_mlx_img).img_1 || !(*my_mlx_img).img_c || \
		!(*my_mlx_img).img_e || !(*my_mlx_img).img_p)
		ft_exit("Error\nI cant read the XPM File", my_mlx_img);
	if (X)
		ft_init_images_enemy(my_mlx_img);
}
