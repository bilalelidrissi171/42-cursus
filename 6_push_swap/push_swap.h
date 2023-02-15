/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:59:31 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/10 23:40:35 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define MAX INT_MAX
# define MIN INT_MIN

typedef struct s_list
{
	int				content;
	int				found;
	struct s_list	*next;
}	t_list;

long long	ft_my_atio(char *str, int i, int sign);
int			ft_count_words(char *s, char c);
long long	ft_atoi(char *str);
size_t		ft_strlen(char *s);
char		**ft_split(char *s, char c);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *s1);
void		ft_free(char **str);
char		**ft_my_split(char *s, char c, int start, int end);
t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
size_t		ft_lstsize(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_swap(t_list **stack);
void		ft_swap_abs(t_list **stack_a, t_list **stack_b, char c);
int			ft_push(t_list **stack_recv, t_list **stack_givn);
void		ft_push_ab(t_list **stack_a, t_list **stack_b, char c);
int			ft_rotate(t_list **stack);
void		ft_rotate_abr(t_list **stack_a, t_list **stack_b, char c);
void		ft_reverse_rotate_abr(t_list **stack_a, t_list **stack_b, char c);
int			ft_reverse_rotate(t_list **stack);
int			ft_onlyspaces(char *av);
int			ft_digit(char **av);
int			ft_longer(char **av);
int			ft_duplicat(char **av);
int			ft_parsing(t_list **stack_a, char **av);
char		**ft_joinargv(char **av);
void		ft_free_tab(char **ss);
void		ft_push_swap(t_list **stack_a, t_list **stack_b);
int			ft_get_min(t_list *stack);
int			ft_get_max(t_list *stack);
int			ft_is_sort_rev(t_list *stack);
int			ft_is_sort(t_list *stack);
void		ft_sort_rev(t_list **stack_a, t_list **stack_b);
void		ft_sort_three(t_list **stack_a);
void		ft_sort_five(t_list **stack_a, t_list **stack_b);
void		ft_sort(t_list **stack_a, t_list **stack_b);
int			ft_is_up_down(t_list *stack, int num);
int			*ft_lst_to_arr(t_list *stack);
int			ft_get_max_lis(int *arr, t_list *stack);
int			*ft_get_lis(t_list **stack);
void		ft_free_stack(t_list **stack);
int			*ft_get_content(t_list **stack);
int			ft_get_index_of_max(int *arr, int max);
void		best_move_lis(t_list **stack);
void		ft_push_to_b(t_list **stack_a, t_list **stack_b, int *a);
void		ft_best_move_to_push_a(t_list **stack_a, t_list **stack_b);
int			ft_up_steps(t_list *stack, int content);
int			ft_down_steps(t_list *stack, int content);
int			ft_abs(int num);
int			**ft_malloc_steps(t_list *stack_b);
void		ft_steps_b(t_list *stack_b, int **steps);
void		ft_steps_a(t_list *stack_a, t_list *stack_b, int **steps);
void		ft_compare_max_min(int i, t_list *stack_a, \
			t_list *temp1, int **steps);
int			*ft_samller_steps(int **steps, size_t size);
int			*ft_find_samller_steps(int **steps, size_t size, \
			int min, int *smaller);
void		ft_free_steps(int **steps, size_t size);
void		ft_do_moves(t_list **stack_a, t_list **stack_b, int *one_step);
void		ft_do_moves_1(t_list **stack_a, t_list **stack_b, int *one_step);
void		ft_init_0(int **steps, size_t num);
void		ft_compare_next_prev(int i, t_list *stack_a, \
			t_list *temp, int **steps);

#endif
