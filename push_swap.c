/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:47:39 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/12 14:52:29 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*ft_init(void)
{
	t_ps	*ps;

	ps = (t_ps *)malloc(sizeof(t_ps));
	if (!ps)
		ft_error(1);
	ps->arg_cnt = 0;
	ps->a = (t_stack *)malloc(sizeof(t_stack));
	ps->a->top = NULL;
	ps->a->bottom = NULL;
	ps->a->cnt = 0;
	ps->b = (t_stack *)malloc(sizeof(t_stack));
	ps->b->top = NULL;
	ps->b->bottom = NULL;
	ps->b->cnt = 0;
	if (!ps->a || !ps->b)
		ft_error(1);
	return (ps);
}

void	p(t_stack *s)
{
	unsigned int	idx;
	t_node			*n;

	idx = 0;
	n = s->top;
	while (idx < s->cnt)
	{
		ft_printf("%d ", n->data);
		n = n->next;
		idx++;
	}
	ft_printf("\n");
}

void	ft_div_three_cmd(t_ps *ps, int p1, int p2)
{
	if (ps->a->top->data < p1)
	{
		ft_push(ps->a, ps->b);
		ft_rotate(ps->b, FRONT);
		ft_printf("pb ");
		ft_printf("rb ");
	}
	else if (ps->a->top->data < p2)
	{
		ft_push(ps->a, ps->b);
		ft_printf("pb ");
	}
	else
	{
		ft_rotate(ps->a, FRONT);
		ft_printf("ra ");
	}
}

void	ft_div_three(t_ps *ps)
{
	unsigned int	idx;
	int				p1;
	int				p2;

	p1 = ps->arg_cnt / 3;
	p2 = ps->arg_cnt * 2 / 3;
	idx = ps->arg_cnt;
	ft_printf("%d %d\n", p1, p2);
	while (idx)
	{
		ft_div_three_cmd(ps, p1, p2);
		idx--;
	}
}

void	ft_sort(t_ps *ps)
{
	ft_div_three(ps);
}

int	main(int argc, char **argv)
{
	t_ps	*ps;

	ps = ft_init();
	ft_cnt_num(argc, argv, ps);
	if (ps->arg_cnt <= 1)
		ft_error(1);
	ft_split_arg(argc, argv, ps);
	ft_chk_arg(ps);
	ft_set_stack(ps);
	ft_sort(ps);
	return (0);
}
