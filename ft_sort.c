/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:21:58 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/12 15:22:14 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_div_three_cmd(t_ps *ps, int p1, int p2)
{
	if (ps->a->top->data < p1)
	{
		ft_cmd_center(ps, "pb");
		ft_cmd_center(ps, "rb");
	}
	else if (ps->a->top->data < p2)
		ft_cmd_center(ps, "pb");
	else
		ft_cmd_center(ps, "ra");
}

void	ft_div_three(t_ps *ps)
{
	unsigned int	idx;
	int				p1;
	int				p2;

	p1 = ps->arg_cnt / 3;
	p2 = ps->arg_cnt * 2 / 3;
	idx = ps->arg_cnt;
	while (idx)
	{
		ft_div_three_cmd(ps, p1, p2);
		idx--;
	}
}

void	ft_sort(t_ps *ps)
{
	ft_div_three(ps);
	while (ps->a->cnt > 3)
		ft_cmd_center(ps, "pb");
}
