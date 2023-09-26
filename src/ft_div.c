/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:03:19 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/26 17:39:37 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_div_three_cmd(t_ps *ps, int p1, int p2)
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

static void	ft_swap_num(int *p1, int *p2)
{
	int	tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void	ft_div_three(t_ps *ps)
{
	int	idx;
	int	p1;
	int	p2;

	p1 = ps->arg[ps->arg_cnt / 3];
	p2 = ps->arg[ps->arg_cnt * 2 / 3];
	if (p1 > p2)
		ft_swap_num(&p1, &p2);
	idx = 0;
	while (idx < ps->arg_cnt)
	{
		ft_div_three_cmd(ps, p1, p2);
		idx++;
	}
}
