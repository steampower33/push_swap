/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:28:31 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/18 17:16:50 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_min(t_stack *a)
{
	int		min_num;
	t_node	*n;
	int		idx;

	min_num = a->top->data;
	n = a->top;
	idx = 0;
	while (idx < a->cnt)
	{
		if (min_num > n->data)
			min_num = n->data;
		n = n->next;
		idx++;
	}
	return (min_num);
}

int	ft_set_min_prev(t_ps *ps)
{
	int		a_loc;
	int		min_num;
	t_node	*a;
	int		idx;

	a_loc = 0;
	min_num = ft_stack_min(ps->a);
	a = ps->a->top;
	idx = 0;
	while (idx < ps->a->cnt)
	{
		if (min_num == a->data)
			break ;
		a_loc++;
		a = a->next;
		idx++;
	}
	if (a_loc >= (ps->a->cnt + 1) / 2)
		a_loc = (ps->a->cnt - a_loc) * -1;
	return (a_loc);
}

int	ft_stack_max(t_stack *a)
{
	int		max_num;
	t_node	*n;
	int		idx;

	max_num = a->top->data;
	n = a->top;
	idx = 0;
	while (idx < a->cnt)
	{
		if (max_num < n->data)
			max_num = n->data;
		n = n->next;
		idx++;
	}
	return (max_num);
}

int	ft_set_max_next(t_ps *ps)
{
	int		a_loc;
	int		max_num;
	t_node	*a;
	int		idx;

	a_loc = 0;
	max_num = ft_stack_max(ps->a);
	a = ps->a->top;
	idx = 0;
	while (idx < ps->a->cnt)
	{
		if (max_num == a->data)
			break ;
		a_loc++;
		a = a->next;
		idx++;
	}
	if (a_loc >= (ps->a->cnt + 1) / 2)
		a_loc = (ps->a->cnt - a_loc) * -1;
	return (a_loc);
}

int	ft_set_middle(t_ps *ps, int data_b)
{
	int		a_loc;
	t_node	*a;
	int		idx;

	a_loc = 1;
	a = ps->a->top;
	idx = 0;
	while (idx < ps->a->cnt)
	{
		if (a->data < data_b && data_b < a->next->data)
			break ;
		a_loc++;
		a = a->next;
		idx++;
	}
	if (a_loc >= (ps->a->cnt + 1) / 2)
		a_loc = (ps->a->cnt - a_loc) * -1;
	return (a_loc);
}
