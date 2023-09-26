/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:35:25 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/26 21:55:25 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_get_mid(t_ps *ps)
{
	int	i;
	int	j;
	int	mid;
	int	cnt;

	mid = 0;
	i = 0;
	while (i < ps->arg_cnt)
	{
		cnt = 0;
		j = 0;
		while (j < ps->arg_cnt)
		{
			if (ps->arg[j] < ps->arg[i])
				cnt++;
			j++;
		}
		if (cnt == 2)
			mid = ps->arg[i];
		i++;
	}
	return (mid);
}

static void	ft_div_mid(t_ps *ps)
{
	int		mid;
	t_node	*a;
	int		idx;

	mid = ft_get_mid(ps);
	a = ps->a->top;
	idx = 0;
	while (idx < ps->arg_cnt)
	{
		if (a->data < mid)
			ft_cmd_center(ps, "pb");
		else if (a->data >= mid)
			ft_cmd_center(ps, "ra");
		a = ps->a->top;
		idx++;
	}
}

void	ft_sort_five(t_ps *ps)
{
	if (ps->arg_cnt > 5)
		return ;
	ft_div_mid(ps);
	if (ps->a->cnt == 2)
	{
		if (ps->a->top->data > ps->a->top->next->data)
			ft_cmd_center(ps, "sa");
	}
	else if (ps->a->cnt == 3)
		ft_sort_three(ps);
	if (ps->b->top->data < ps->b->top->next->data)
		ft_cmd_center(ps, "sb");
	while (ps->b->cnt)
		ft_cmd_center(ps, "pa");
}
