/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:21:58 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/13 19:07:50 by seunlee2         ###   ########.fr       */
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
	if (fir > sec && sec < trd && fir < trd)
		ft_cmd_center(ps, "sa");
	else if (fir < sec && sec > trd && fir > trd)
		ft_cmd_center(ps, "rra");
	else if (fir > sec && sec > trd && fir > trd)
		ft_cmd_center(ps, "ra");
	else if (fir > sec && sec > trd && fir > trd)
	{
		ft_cmd_center(ps, "sa");
		ft_cmd_center(ps, "rra");
	}
	else if (fir < sec && sec > trd && fir < trd)
	{
		ft_cmd_center(ps, "sa");
		ft_cmd_center(ps, "ra");
	}
}

void	ft_sort(t_ps *ps)
{
	// ft_div_three(ps);
	while (ps->a->cnt > 3)
		ft_cmd_center(ps, "pb");
	if (ps->a->cnt == 2)
	{
		if (ps->a->top->data > ps->a->top->next->data)
			ft_cmd_center(ps, "sa");
	}
	if (ps->a->cnt == 3)
		ft_sort_three(ps);
}
