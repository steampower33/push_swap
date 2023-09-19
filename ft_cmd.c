/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:49:39 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/19 20:29:08 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *st)
{
	t_node	*node1;
	t_node	*node2;

	if (st->cnt < 2)
		return ;
	node1 = ft_deque(st, FRONT);
	node2 = ft_deque(st, FRONT);
	ft_enque(st, FRONT, node1);
	ft_enque(st, FRONT, node2);
}

void	ft_push(t_stack *from, t_stack *to)
{
	t_node	*node;

	if (from->cnt < 1)
		return ;
	node = ft_deque(from, FRONT);
	ft_enque(to, FRONT, node);
}

void	ft_rotate(t_stack *stack, enum e_where w)
{
	t_node	*node;

	if (stack->cnt < 1)
		return ;
	node = ft_deque(stack, w);
	ft_enque(stack, !w, node);
}
