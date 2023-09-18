/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:00:03 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/18 18:04:07 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_node_new(int data, t_node *prev)
{
	t_node	*s;

	s = (t_node *)malloc(sizeof(t_node));
	if (!s)
		ft_error(1);
	s->data = data;
	s->next = NULL;
	s->prev = prev;
	return (s);
}

void	ft_set_stack(t_ps *ps)
{
	int		idx;
	t_stack	*a;
	t_node	*n;

	ps->a->cnt = ps->arg_cnt;
	a = ps->a;
	a->top = (t_node *)malloc(sizeof(t_node));
	a->top->data = ps->arg[0];
	n = ps->a->top;
	idx = 1;
	while (idx < ps->arg_cnt)
	{
		n->next = ft_node_new(ps->arg[idx], n);
		n = n->next;
		if (idx == ps->arg_cnt - 1)
		{
			a->bottom = n;
			a->bottom->next = a->top;
			a->top->prev = a->bottom;
		}
		idx++;
	}
}

t_node	*ft_deque(t_stack *st, enum e_where w)
{
	t_node	*s;

	s = NULL;
	if (st->cnt == 1)
	{
		s = st->top;
		st->top->next = NULL;
		st->top->prev = NULL;
	}
	else if (w == FRONT)
	{
		s = st->top;
		st->top->next->prev = st->bottom;
		st->top = st->top->next;
	}
	else if (w == BACK)
	{
		s = st->bottom;
		st->bottom->prev->next = st->top;
		st->bottom = st->bottom->prev;
	}
	st->cnt--;
	return (s);
}

void	ft_enque(t_stack *st, enum e_where w, t_node *node)
{
	if (st->cnt == 0)
	{
		st->top = node;
		st->bottom = node;
	}
	else if (w == FRONT)
	{
		node->next = st->top;
		node->prev = st->bottom;
		st->top->prev = node;
		st->bottom->next = node;
		st->top = node;
	}
	else if (w == BACK)
	{
		node->next = st->top;
		node->prev = st->bottom;
		st->bottom->next = node;
		st->top->prev = node;
		st->bottom = node;
	}
	st->cnt++;
}
