/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:09:59 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/26 22:14:29 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_all_free(t_ps *ps)
{
	t_node	*now;
	t_node	*nex;

	now = ps->a->top;
	nex = ps->a->top;
	while (now)
	{
		nex = now->next;
		free(now);
		now = nex;
	}
	now = ps->b->top;
	nex = ps->b->top;
	while (now)
	{
		nex = now->next;
		free(now);
		now = nex;
	}
	free(ps->a);
	free(ps->b);
	free(ps->arg);
	free(ps);
}

t_ps	*ft_init(void)
{
	t_ps	*ps;

	ps = (t_ps *)malloc(sizeof(t_ps));
	if (!ps)
		ft_error(1);
	ps->arg_cnt = 0;
	ps->a = (t_stack *)malloc(sizeof(t_stack));
	ps->a->top = NULL;
	ps->a->bottom = NULL;
	ps->a->cnt = 0;
	ps->b = (t_stack *)malloc(sizeof(t_stack));
	ps->b->top = NULL;
	ps->b->bottom = NULL;
	ps->b->cnt = 0;
	if (!ps->a || !ps->b)
		ft_error(1);
	return (ps);
}

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
