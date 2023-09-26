/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_a_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:28:31 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/26 21:55:28 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_set_a(t_ps *ps, int data_b)
{
	int	a_loc;

	if (data_b < ft_stack_min(ps->a))
		a_loc = ft_set_min_prev(ps);
	else if (data_b > ft_stack_max(ps->a))
		a_loc = ft_set_max_next(ps);
	else
		a_loc = ft_set_middle(ps, data_b);
	return (a_loc);
}
