/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:00:03 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/19 19:27:58 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_node_new(int data)
{
	t_node	*s;

	s = (t_node *)malloc(sizeof(t_node));
	if (!s)
		ft_error(1);
	s->data = data;
	s->next = NULL;
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
	n = a->top;
	idx = 1;
	while (idx < ps->arg_cnt)
	{
		n->next = ft_node_new(ps->arg[idx]);
		n = n->next;
		if (idx == ps->arg_cnt - 1)
			a->bottom = n;
		idx++;
	}
}

t_node	*ft_get_last_before_node(t_stack *st, t_node *last_node)
{
	t_node	*node;

	node = st->top;
	while (node)
	{
		if (node->next->data == last_node->data)
			break ;
		node = node->next;
	}
	return (node);
}

t_node	*ft_deque(t_stack *st, enum e_where w)
{
	t_node	*s;

	s = NULL;
	if (st->cnt == 1)
	{
		s = st->top;
		st->top = NULL;
		st->bottom = NULL;
	}
	else if (w == FRONT)
	{
		s = st->top;
		st->top = st->top->next;
		s->next = NULL;
	}
	else if (w == BACK)
	{
		s = st->bottom;
		st->bottom = ft_get_last_before_node(st, s);
		st->bottom->next = NULL;
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
		st->top = node;
	}
	else if (w == BACK)
	{
		st->bottom->next = node;
		st->bottom = node;
	}
	st->cnt++;
}
