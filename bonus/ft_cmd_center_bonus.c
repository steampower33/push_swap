/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_center_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:17:18 by seunlee2          #+#    #+#             */
/*   Updated: 2023/10/03 18:43:27 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_cmd_swap(t_ps *ps, char *cmd)
{
	if (ft_strncmp(cmd, "sa\n", 3) == 0)
		ft_swap(ps->a);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		ft_swap(ps->b);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
	{
		ft_swap(ps->a);
		ft_swap(ps->b);
	}
	else
		ft_error(1);
}

static void	ft_cmd_push(t_ps *ps, char *cmd)
{
	if (ft_strncmp(cmd, "pa\n", 3) == 0)
		ft_push(ps->b, ps->a);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		ft_push(ps->a, ps->b);
	else
		ft_error(1);
}

static void	ft_cmd_rotate(t_ps *ps, char *cmd)
{
	if (ft_strncmp(cmd, "ra\n", 3) == 0)
		ft_rotate(ps->a, FRONT);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		ft_rotate(ps->b, FRONT);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
	{
		ft_rotate(ps->a, FRONT);
		ft_rotate(ps->b, FRONT);
	}
	else if (ft_strncmp(cmd, "rra\n", 4) == 0)
		ft_rotate(ps->a, BACK);
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		ft_rotate(ps->b, BACK);
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
	{
		ft_rotate(ps->a, BACK);
		ft_rotate(ps->b, BACK);
	}
	else
		ft_error(1);
}

void	ft_cmd_center(t_ps *ps, char *cmd)
{
	if (ft_strncmp(cmd, "s", 1) == 0)
		ft_cmd_swap(ps, cmd);
	else if (ft_strncmp(cmd, "p", 1) == 0)
		ft_cmd_push(ps, cmd);
	else if (ft_strncmp(cmd, "r", 1) == 0)
		ft_cmd_rotate(ps, cmd);
	else
		ft_error(1);
}
