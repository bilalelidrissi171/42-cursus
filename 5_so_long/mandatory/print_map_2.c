/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 04:17:19 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/26 20:56:44 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_trim_map(char **old_map, int cl)
{
	int		i;
	int		j;
	int		k;
	char	**new_map;

	i = 0;
	while (!old_map[i][0])
	{
		i++;
		if (i == cl)
			ft_error("Error\nEmpty Map\n", NULL, NULL);
	}
	while (!old_map[cl - 1][0])
		cl--;
	new_map = malloc(sizeof(char *) * (cl - i + 1));
	if (!new_map)
	{
		ft_free_map(old_map);
		ft_error("Error\nMalloc failed\n", NULL, NULL);
	}
	j = 0;
	k = cl - i;
	while (i < cl)
		new_map[j++] = ft_strdup(old_map[i++]);
	return (new_map[j] = NULL, ft_free_map(old_map), new_map);
}

int	ft_size_of_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	ft_put_str(t_mlx_img *my_mlx_img)
{
	char	*s;

	s = ft_itoa((*my_mlx_img).moves);
	mlx_string_put((*my_mlx_img).mlx, (*my_mlx_img).win, \
		30, 10, 0xFFFFFF, "number of movements: ");
	mlx_string_put((*my_mlx_img).mlx, (*my_mlx_img).win, \
		235, 10, 0xFFFFFF, s);
	free(s);
}

int	ft_exit_cross(void *param)
{
	t_mlx_img	*my_mlx_img;

	my_mlx_img = ((t_mlx_img *)param);
	ft_exit("You Exit the Game\n", my_mlx_img);
	return (0);
}

void	ft_error_malloc(t_mlx_img *my_mlx_img, t_map_i_j *arr_enemy)
{
	if (!arr_enemy)
	{
		free(arr_enemy);
		ft_exit("Error\nMalloc Error\n", my_mlx_img);
	}
}
