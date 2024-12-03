# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npolack <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 13:32:41 by npolack           #+#    #+#              #
#    Updated: 2024/12/03 16:08:56 by npolack          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft/libft.a

SRCS = push_swap.c\
	   push_swap_utils.c\
	   sorting.c\
	   sorting2.c\
	   sorting3.c\
	   input.c\
	   swap_basics.c\
	   swap_advenced.c\
	   check.c\
	   trim_instructions.c\
	   trim_instructions2.c\
	   make_list.c\

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all		: $(NAME)

%.o		: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(LIBFT):
	make -C libft

clean	:
	make clean -C libft
	$(RM) $(OBJS)

fclean	: clean
	make fclean -C libft
	$(RM) $(NAME)

re		: fclean all

.PHONY : all clean fclean re


