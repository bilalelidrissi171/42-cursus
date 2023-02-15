/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:45:47 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/26 20:57:06 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef X
#  define X 0
# endif

# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_mlx_img
{
	int		enemy;
	void	*mlx;
	void	*win;
	void	*img_1;
	void	*img_x_1;
	void	*img_x_2;
	void	*img_x_3;
	void	*img_e;
	void	*img_p;
	void	*img_c;
	char	*relative_path;
	int		img_width;
	int		img_height;
	char	**map;
	int		collectible_map;
	int		moves;
}				t_mlx_img;

typedef struct s_map_elem
{
	int	exit;
	int	collectible;
	int	player;
}				t_map_elem;

typedef struct s_map_i_j
{
	int	i;
	int	j;
}				t_map_i_j;

char		*get_next_line(int fd);
char		*get_next_line_all(int fd);
int			is_newline(char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *s1);
int			ft_strlen(char *s);
void		ft_error(char *msg, char *free_str1, char *free_str2);
int			ft_cout_new_line(char *path_map);
char		**ft_create_map_matric(char *path_map);
int			is_not_matrix(char **map);
void		ft_error_open(int fd);
int			is_find_char_new(char **map);
int			is_not_find_all_char(char **map);
void		ft_init_map_elem(t_map_elem *map_elem);
int			is_not_closed(char **map);
int			ft_check_map(char **map);
t_map_i_j	ft_get_map_i_j(char **map);
void		ft_print_win(char **map);
t_map_i_j	ft_line_column_map(char **map);
t_map_i_j	ft_find(char **map, char c);
int			ft_key_hook(int key, void *param);
int			ft_move(int key, char **map);
void		ft_print_map(t_mlx_img my_mlx_img);
void		ft_putnbr(int n);
void		ft_print_count_moves(int *i);
int			ft_check_if_e(int key, char **map);
void		ft_exit(char *msg, t_mlx_img *my_mlx_img);
int			ft_get_char_in_map(char **map, char ch);
int			ft_check_if_c(int key, char **map);
void		ft_key_hook_utils(int key, t_mlx_img *my_mlx_img, int *i);
void		ft_init_images(t_mlx_img *my_mlx_img);
void		ft_free_map(char **map);
char		**ft_trim_map(char **old_map, int cl);
int			ft_size_of_map(char **map);
int			is_find_char_new_bonus(char **map);
int			ft_loop_hook(void *param);
void		ft_loop_hook_utils(t_mlx_img my_mlx_img, int i, int j, int count);
char		*ft_itoa(int n);
void		ft_init_images_enemy(t_mlx_img *my_mlx_img);
void		ft_fill_one(char **map, t_map_i_j pos);
int			is_not_valid_path(char **map);
char		**ft_copy_map(char **map);
void		ft_loop_hook_utils_2(t_mlx_img *my_mlx_img, int i, int *count, \
								t_map_i_j map_size);
void		ft_loop_hook_utilis_3(t_mlx_img *my_mlx_img, int num_enemy, \
			t_map_i_j *arr_enemy, int *d);
void		ft_put_str(t_mlx_img *my_mlx_img);
int			ft_exit_cross(void *param);
void		ft_error_malloc(t_mlx_img *my_mlx_img, t_map_i_j *arr_enemy);

#endif
