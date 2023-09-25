/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:09:59 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/25 22:05:44 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free_arr2(char **str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		free(str[idx]);
		idx++;
	}
	free(str);
}

void	ft_cnt_num(int argc, char **argv, t_ps *ps)
{
	int		idx;
	int		idx2;
	char	**str;

	idx = 1;
	while (idx < argc)
	{
		str = ft_split(argv[idx], ' ');
		idx2 = 0;
		while (str[idx2])
			idx2++;
		ps->arg_cnt += idx2;
		ft_free_arr2(str);
		idx++;
	}
}

void	ft_chk_arg(t_ps *ps)
{
	int	idx;
	int	idx2;

	idx = 0;
	while (idx < ps->arg_cnt)
	{
		idx2 = idx + 1;
		while (idx2 < ps->arg_cnt)
		{
			if (ps->arg[idx] == ps->arg[idx2])
				ft_error(1);
			idx2++;
		}
		idx++;
	}
}
