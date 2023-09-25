/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_center.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:17:18 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/25 12:53:54 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cmd_swap(t_ps *ps, char *cmd)
{
	if (ft_strncmp(cmd, "sa", 2) == 0)
		ft_swap(ps->a);
	if (ft_strncmp(cmd, "sb", 2) == 0)
		ft_swap(ps->b);
	if (ft_strncmp(cmd, "ss", 2) == 0)
	{
		ft_swap(ps->a);
		ft_swap(ps->b);
	}
}

void	ft_cmd_push(t_ps *ps, char *cmd)
{
	if (ft_strncmp(cmd, "pa", 2) == 0)
		ft_push(ps->b, ps->a);
	if (ft_strncmp(cmd, "pb", 2) == 0)
		ft_push(ps->a, ps->b);
}

void	ft_cmd_rotate(t_ps *ps, char *cmd)
{
	if (ft_strlen(cmd) == 2)
	{
		if (ft_strncmp(cmd, "ra", 2) == 0)
			ft_rotate(ps->a, FRONT);
		if (ft_strncmp(cmd, "rb", 2) == 0)
			ft_rotate(ps->b, FRONT);
		if (ft_strncmp(cmd, "rr", 2) == 0)
		{
			ft_rotate(ps->a, FRONT);
			ft_rotate(ps->b, FRONT);
		}
	}
	if (ft_strlen(cmd) == 3)
	{
		if (ft_strncmp(cmd, "rra", 3) == 0)
			ft_rotate(ps->a, BACK);
		if (ft_strncmp(cmd, "rrb", 3) == 0)
			ft_rotate(ps->b, BACK);
		if (ft_strncmp(cmd, "rrr", 3) == 0)
		{
			ft_rotate(ps->a, BACK);
			ft_rotate(ps->b, BACK);
		}
	}
}

void	ft_cmd_center(t_ps *ps, char *cmd)
{
	ft_cmd_swap(ps, cmd);
	ft_cmd_push(ps, cmd);
	ft_cmd_rotate(ps, cmd);
	ft_printf("%s\n", cmd);
}
