/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:31:01 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/26 17:42:26 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_bigger(int a, int b, int idx_a, int idx_b)
{
	if (a < 0)
		a = a * -1;
	if (b < 0)
		b = b * -1;
	if (idx_a < 0)
		idx_a = idx_a * -1;
	if (idx_b < 0)
		idx_b = idx_b * -1;
	if (a + b > idx_a + idx_b)
		return (1);
	else
		return (0);
}

void	ft_get_ab(t_ps *ps, int *a, int *b)
{
	int		idx_a;
	int		idx_b;
	int		idx;
	t_node	*s_b;
	int		num;

	idx = 0;
	s_b = ps->b->top;
	while (idx < ps->b->cnt)
	{
		num = s_b->data;
		idx_a = ft_set_a(ps, num);
		if (idx >= (ps->b->cnt + 1) / 2)
			idx_b = (ps->b->cnt - idx) * -1;
		else
			idx_b = idx;
		if (idx == 0 || ft_bigger(*a, *b, idx_a, idx_b))
		{
			*a = idx_a;
			*b = idx_b;
		}
		s_b = s_b->next;
		idx++;
	}
}
