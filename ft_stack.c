/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:00:03 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/11 17:38:06 by seunlee2         ###   ########.fr       */
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
	unsigned int	idx;
	t_stack			*a;
	t_node			*n;

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
