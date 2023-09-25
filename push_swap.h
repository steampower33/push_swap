/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:47:55 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/25 16:19:15 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_node {
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	int				cnt;
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

typedef struct s_ps {
	struct s_stack	*a;
	struct s_stack	*b;
	int				*arg;
	int				arg_cnt;
}	t_ps;

enum e_where
{
	FRONT = 0,
	BACK = 1,
};

void		ft_error(int code);
long long	ft_atoll(const char *str);

void		ft_split_arg(int argc, char **argv, t_ps *ps);

t_node		*ft_node_new(int data);
void		ft_set_stack(t_ps *ps);
t_node		*ft_deque(t_stack *st, enum e_where w);
void		ft_enque(t_stack *st, enum e_where w, t_node *node);

t_ps		*ft_init(void);

void		ft_div_three_cmd(t_ps *ps, int p1, int p2);
void		ft_div_three(t_ps *ps);

void		ft_sort_three(t_ps *ps);
void		ft_sort(t_ps *ps);

int			ft_set_a(t_ps *ps, int data_b);
int			ft_bigger(int a, int b, int idx_a, int idx_b);
void		ft_get_ab(t_ps *ps, int *a, int *b);

int			ft_stack_min(t_stack *a);
int			ft_set_min_prev(t_ps *ps);
int			ft_stack_max(t_stack *a);
int			ft_set_max_next(t_ps *ps);
int			ft_set_middle(t_ps *ps, int data_b);

void		ft_free_arr2(char **str);
void		ft_cnt_num(int argc, char **argv, t_ps *ps);
void		ft_chk_arg(t_ps *ps);

void		ft_swap(t_stack *st);
void		ft_push(t_stack *from, t_stack *to);
void		ft_rotate(t_stack *stack, enum e_where w);

void		ft_cmd_center(t_ps *ps, char *cmd);

void		ft_rr_rrr(t_ps *ps, int *a, int *b);
void		ft_ra_rra(t_ps *ps, int a);
void		ft_rb_rrb(t_ps *ps, int b);

int			ft_get_mid(t_ps *ps);
void		ft_div_mid(t_ps *ps);
void		ft_sort_five(t_ps *ps);
#endif