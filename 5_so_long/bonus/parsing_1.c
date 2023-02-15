/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:43:33 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/27 21:40:08 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_map_elem(t_map_elem *map_elem)
{
	(*map_elem).collectible = 0;
	(*map_elem).exit = 0;
	(*map_elem).player = 0;
}

void	ft_error(char *msg, char *free_str1, char *free_str2)
{
	free(free_str1);
	free(free_str2);
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

char	**ft_create_map_matric(char *path_map)
{
	int		num_line;
	char	**map;
	int		i;
	int		fd;
	char	**new_map;

	num_line = ft_cout_new_line(path_map);
	map = malloc((num_line + 1) * sizeof(char *));
	if (!map)
		ft_error("Error\nMalloc failed\n", NULL, NULL);
	map[num_line] = NULL;
	fd = open(path_map, O_RDONLY);
	i = -1;
	while (++i < num_line)
		map[i] = get_next_line(fd);
	close(fd);
	new_map = ft_trim_map(map, num_line);
	return (new_map);
}

int	ft_check_map(char **map)
{
	if (is_not_matrix(map))
		return (ft_free_map(map), 1);
	if (X)
	{
		if (is_find_char_new_bonus(map))
			return (ft_free_map(map), 1);
	}
	else
	{
		if (is_find_char_new(map))
			return (ft_free_map(map), 1);
	}
	if (is_not_find_all_char(map))
		return (ft_free_map(map), 1);
	if (is_not_closed(map))
		return (ft_free_map(map), 1);
	write(1, "", 0);
	if (is_not_valid_path(map))
		return (ft_free_map(map), 1);
	return (0);
}

void	ft_init_images_enemy(t_mlx_img *my_mlx_img)
{
	(*my_mlx_img).img_x_1 = mlx_xpm_file_to_image((*my_mlx_img).mlx, \
	"images/img_X_1.xpm", &(*my_mlx_img).img_width, \
	&(*my_mlx_img).img_height);
	(*my_mlx_img).img_x_2 = mlx_xpm_file_to_image((*my_mlx_img).mlx, \
	"images/img_X_2.xpm", &(*my_mlx_img).img_width, \
	&(*my_mlx_img).img_height);
	(*my_mlx_img).img_x_3 = mlx_xpm_file_to_image((*my_mlx_img).mlx, \
	"images/img_X_3.xpm", &(*my_mlx_img).img_width, \
	&(*my_mlx_img).img_height);
	if (!(*my_mlx_img).img_x_1 || !(*my_mlx_img).img_x_2 \
		|| !(*my_mlx_img).img_x_1)
		ft_exit("Error\nI cant read the XPM File", my_mlx_img);
}
