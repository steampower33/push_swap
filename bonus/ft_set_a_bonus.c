/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_a_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:28:31 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/25 21:16:24 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_stack_min(t_stack *a)
{
	int		min_num;
	t_node	*n;

	min_num = a->top->data;
	n = a->top;
	while (n)
	{
		if (min_num > n->data)
			min_num = n->data;
		n = n->next;
	}
	return (min_num);
}

int	ft_set_min_prev(t_ps *ps)
{
	int		a_loc;
	int		min_num;
	t_node	*n;

	a_loc = 0;
	min_num = ft_stack_min(ps->a);
	n = ps->a->top;
	while (n)
	{
		if (min_num == n->data)
			break ;
		a_loc++;
		n = n->next;
	}
	if (a_loc >= (ps->a->cnt + 1) / 2)
		a_loc = (ps->a->cnt - a_loc) * -1;
	return (a_loc);
}

int	ft_stack_max(t_stack *a)
{
	int		max_num;
	t_node	*n;

	max_num = a->top->data;
	n = a->top;
	while (n)
	{
		if (max_num < n->data)
			max_num = n->data;
		n = n->next;
	}
	return (max_num);
}

int	ft_set_max_next(t_ps *ps)
{
	int		a_loc;
	int		max_num;
	t_node	*n;

	a_loc = 0;
	max_num = ft_stack_max(ps->a);
	n = ps->a->top;
	while (n)
	{
		if (max_num == n->data)
			break ;
		a_loc++;
		n = n->next;
	}
	a_loc++;
	if (a_loc >= (ps->a->cnt + 1) / 2)
		a_loc = (ps->a->cnt - a_loc) * -1;
	return (a_loc);
}

int	ft_set_middle(t_ps *ps, int data_b)
{
	int		a_loc;
	t_node	*n;

	a_loc = 1;
	n = ps->a->top;
	while (n->next)
	{
		if (n->data < data_b && data_b < n->next->data)
			break ;
		a_loc++;
		n = n->next;
	}
	if (a_loc >= (ps->a->cnt + 1) / 2)
		a_loc = (ps->a->cnt - a_loc) * -1;
	return (a_loc);
}
