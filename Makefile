# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 17:31:22 by seunlee2          #+#    #+#              #
#    Updated: 2023/09/18 17:29:36 by seunlee2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = push_swap.c ft_error.c ft_atoll.c ft_split_arg.c ft_stack.c ft_cmd.c ft_utils.c ft_cmd_center.c ft_sort.c ft_div.c ft_get_ab.c ft_set_a.c ft_rotate_ab.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft
PRINTF = printf

%.o: %.c
	$(CC) $(CFLAGS) -I $(LIBFT) -o $@ -c $<

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) \
		-L./$(LIBFT) $(LIBFT)/libft.a \
		-L./$(PRINTF) $(PRINTF)/libftprintf.a

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(PRINTF) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(PRINTF) fclean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE)

.PHONY: all clean fclean re