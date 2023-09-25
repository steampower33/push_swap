# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 17:31:22 by seunlee2          #+#    #+#              #
#    Updated: 2023/09/25 21:25:39 by seunlee2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
SRCS = src/ft_atoll.c src/ft_cmd.c src/ft_cmd_center.c src/ft_div.c src/ft_error.c src/ft_get_ab.c src/ft_rotate_ab.c \
		src/ft_set_a.c src/ft_sort.c src/ft_sort_five.c src/ft_split_arg.c src/ft_stack.c src/ft_utils.c src/push_swap.c
SRCS_BONUS = bonus/ft_atoll_bonus.c bonus/ft_cmd_bonus.c bonus/ft_cmd_center_bonus.c bonus/ft_div_bonus.c bonus/ft_error_bonus.c \
			bonus/ft_get_ab_bonus.c bonus/ft_rotate_ab_bonus.c bonus/ft_set_a_bonus.c bonus/ft_sort_bonus.c bonus/ft_sort_five_bonus.c \
			bonus/ft_split_arg_bonus.c bonus/ft_stack_bonus.c bonus/ft_utils_bonus.c bonus/push_swap_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
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

$(BONUS_NAME): $(OBJS_BONUS)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS_NAME) \
		-L./$(LIBFT) $(LIBFT)/libft.a \
		-L./$(PRINTF) $(PRINTF)/libftprintf.a

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(PRINTF) clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(PRINTF) fclean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re:
	$(MAKE) fclean
	$(MAKE)

bonus: $(BONUS_NAME)

.PHONY: all clean fclean re bonus