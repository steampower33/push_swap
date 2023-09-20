/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:21:58 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/20 15:54:53 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_ps *ps)
{
	int	fir;
	int	sec;
	int	trd;

	fir = ps->a->top->data;
	sec = ps->a->top->next->data;
	trd = ps->a->top->next->next->data;
	if (trd > fir && fir > sec)
		ft_cmd_center(ps, "sa");
	else if (sec > fir && fir > trd)
		ft_cmd_center(ps, "rra");
	else if (fir > trd && trd > sec)
		ft_cmd_center(ps, "ra");
	else if (fir > sec && sec > trd)
	{
		ft_cmd_center(ps, "sa");
		ft_cmd_center(ps, "rra");
	}
	else if (sec > trd && trd > fir)
	{
		ft_cmd_center(ps, "sa");
		ft_cmd_center(ps, "ra");
	}
}

void	ft_sort_last(t_ps *ps)
{
	int	min;
	int	min_loc;

	min = ft_stack_min(ps->a);
	min_loc = ft_set_min_prev(ps);
	while (min_loc)
	{
		if (min_loc > 0)
		{
			ft_cmd_center(ps, "ra");
			min_loc--;
		}
		else
		{
			ft_cmd_center(ps, "rra");
			min_loc++;
		}
	}
}

void	ft_sort(t_ps *ps)
{
	int	a;
	int	b;

	ft_div_three(ps);
	while (ps->a->cnt > 3)
		ft_cmd_center(ps, "pb");
	if (ps->a->cnt == 2)
	{
		if (ps->a->top->data > ps->a->top->next->data)
			ft_cmd_center(ps, "sa");
	}
	if (ps->a->cnt == 3)
		ft_sort_three(ps);
	while (ps->b->cnt)
	{
		a = 0;
		b = 0;
		ft_get_ab(ps, &a, &b);
		ft_rr_rrr(ps, &a, &b);
		ft_ra_rra(ps, a);
		ft_rb_rrb(ps, b);
		ft_cmd_center(ps, "pa");
	}
	ft_sort_last(ps);
}
