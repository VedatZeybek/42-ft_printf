# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzeybek <vzeybek@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 16:23:11 by vzeybek           #+#    #+#              #
#    Updated: 2025/06/17 19:43:06 by vzeybek          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_print_utils.c

OBJS = $(SRC:.c=.o)

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf
LIBFT = ./libft/libft.a




all: $(LIBFT) $(NAME)


$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C ./libft all

clean:
	$(RM) $(OBJS)
	make -C ./libft clean

fclean:
	$(RM) $(OBJS) $(NAME)
	make -C ./libft fclean

re: fclean all


.PHONY: all clean fclean re 