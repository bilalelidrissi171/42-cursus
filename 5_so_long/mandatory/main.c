/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:43:58 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/27 21:37:57 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	**map;
	int		i;

	if (ac != 2)
		ft_error("Error\nMore or Less tha 2 args", NULL, NULL);
	i = ft_strlen(av[1]) - 1;
	if (av[1][i] != 'r' || av[1][i - 1] != 'e' || \
		av[1][i - 2] != 'b' || av[1][i - 3] != '.' || ft_strlen(av[1]) < 3)
		ft_error("Error\nThe Extension not Valid", NULL, NULL);
	map = ft_create_map_matric(av[1]);
	if (ft_check_map(map))
		ft_error("Error\nInvaid Map\n", NULL, NULL);
	ft_print_win(map);
	return (0);
}
