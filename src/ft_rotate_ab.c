/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_ab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:28:57 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/18 17:46:19 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr_rrr(t_ps *ps, int *a, int *b)
{
	while (*a && *b && (*a > 0 && *b > 0))
	{
		ft_cmd_center(ps, "rr");
		*a = *a - 1;
		*b = *b - 1;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		ft_cmd_center(ps, "rrr");
		*a = *a + 1;
		*b = *b + 1;
	}
}

void	ft_ra_rra(t_ps *ps, int a)
{
	while (a)
	{
		if (a > 0)
		{
			ft_cmd_center(ps, "ra");
			a--;
		}
		else
		{
			ft_cmd_center(ps, "rra");
			a++;
		}
	}
}

void	ft_rb_rrb(t_ps *ps, int b)
{
	while (b)
	{
		if (b > 0)
		{
			ft_cmd_center(ps, "rb");
			b--;
		}
		else
		{
			ft_cmd_center(ps, "rrb");
			b++;
		}
	}
}
