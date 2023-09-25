/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_arg_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:58:39 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/25 21:16:14 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_split_arg(int argc, char **argv, t_ps *ps)
{
	int		idx;
	int		idx2;
	int		res_idx;
	char	**str;

	ps->arg = (int *)malloc(sizeof(int) * ps->arg_cnt);
	if (!ps->arg)
		ft_error(1);
	res_idx = 0;
	idx = 1;
	while (idx < argc)
	{
		str = ft_split(argv[idx], ' ');
		idx2 = 0;
		while (str[idx2])
		{
			ps->arg[res_idx] = ft_atoll(str[idx2]);
			res_idx++;
			idx2++;
		}
		idx++;
	}
}
