/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:47:55 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/11 19:11:31 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_node {
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack {
	unsigned int	cnt;
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

typedef struct s_ps {
	struct s_stack	*a;
	struct s_stack	*b;
	int				*arg;
	unsigned int	arg_cnt;	
}	t_ps;

enum e_where
{
	FRONT = 0,
	BACK = 1,
};

void		ft_error(int code);
long long	ft_atoll(const char *str);

void		ft_split_arg(int argc, char **argv, t_ps *ps);

t_node		*ft_node_new(int data, t_node *prev);
void		ft_set_stack(t_ps *ps);
t_node		*ft_deque(t_stack *st, enum e_where w);
void		ft_enque(t_stack *st, enum e_where w, t_node *node);

t_ps		*ft_init(void);
void		ft_free_arr2(char **str);
void		ft_cnt_num(int argc, char **argv, t_ps *ps);
void		ft_chk_arg(t_ps *ps);

void		ft_swap(t_stack *st);

#endif