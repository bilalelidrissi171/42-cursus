# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 23:20:52 by bel-idri          #+#    #+#              #
#    Updated: 2023/01/10 23:46:00 by bel-idri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

SRCS = main.c \
	libft.c \
	libft_2.c \
	libft_3.c \
	instructions.c \
	instructions_utils.c \
	parsing.c \
	parsing_utils.c \
	push_swap.c \
	sorting.c \
	sorting_utils.c \
	sorting_utils_2.c \
	sorting_utils_3.c \
	sorting_utils_4.c \
	largest_increasing_sequence.c \

SRCS_BONUS = main_bonus.c \
	libft.c \
	libft_2.c \
	libft_3.c \
	instructions.c \
	instructions_utils.c \
	parsing.c \
	parsing_utils.c \
	push_swap.c \
	sorting.c \
	sorting_utils.c \
	sorting_utils_2.c \
	sorting_utils_3.c \
	sorting_utils_4.c \
	largest_increasing_sequence.c \
	get_next_line.c \
	instructions_bonus.c \
	push_swap_bonus.c \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)


CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $<

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

%.o: %.c push_swap_bonus.h
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
