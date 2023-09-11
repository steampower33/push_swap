/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:49:39 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/11 19:12:17 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *st)
{
	t_node	*node[2];

	if (st->cnt < 2)
		return ;
	node[0] = ft_deque(st, FRONT);
	node[1] = ft_deque(st, FRONT);
	ft_enque(st, FRONT, node[0]);
	ft_enque(st, FRONT, node[1]);
}
