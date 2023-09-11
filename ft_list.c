/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:00:03 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/11 14:12:52 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_l	*ft_lst_new(int data)
{
	t_l	*l;

	l = (t_l *)malloc(sizeof(t_l));
	if (!l)
		ft_error(1);
	l->data = data;
	l->next = NULL;
	return (l);
}

void	ft_set_list(t_ps *ps)
{
	int	idx;
	t_l	*n;

	n = ps->s_a;
	n->data = ps->arg[0];
	idx = 1;
	while (idx < ps->arg_cnt)
	{
		n->next = ft_lst_new(ps->arg[idx]);
		n = n->next;
		idx++;
	}
}
