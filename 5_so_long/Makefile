# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 07:08:50 by bel-idri          #+#    #+#              #
#    Updated: 2023/01/25 09:17:22 by bel-idri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

SRCS = mandatory/get_next_line.c \
	mandatory/libft.c \
	mandatory/main.c \
	mandatory/moving_1.c \
	mandatory/moving_2.c \
	mandatory/parsing_1.c \
	mandatory/parsing_2.c \
	mandatory/so_long_bonus.c \
	mandatory/print_map_1.c \
	mandatory/print_map_2.c \
	mandatory/valid_path.c \

SRCS_BONUS = bonus/so_long_bonus.c \
	bonus/get_next_line.c \
	bonus/libft.c \
	bonus/main.c \
	bonus/moving_1.c \
	bonus/moving_2.c \
	bonus/parsing_1.c \
	bonus/parsing_2.c \
	bonus/print_map_1.c \
	bonus/print_map_2.c \
	bonus/valid_path.c \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -L/usr/local/lib/ -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -L/usr/local/lib/ -lmlx -framework OpenGL -framework AppKit $(OBJS_BONUS) -o $(NAME_BONUS)

mandatory/%.o: mandatory/%.c mandatory/so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/so_long.h
	$(CC) -D X=1 $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
