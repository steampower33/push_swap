/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:47:39 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/06 19:15:59 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_l	*ft_lst_new(t_l *l, int data)
{
	l = (t_l *)malloc(sizeof(t_l));
	if (!l)
		ft_error(1);
	l->data = data;
	l->next = NULL;
	return (l);
}

t_ps	*ft_init(void)
{
	t_ps	*ps;

	ps = (t_ps *)malloc(sizeof(t_ps));
	if (!ps)
		ft_error(1);
	ps->s_a = NULL;
	ps->s_b = NULL;
	ps->arg_cnt = 0;
	return (ps);
}

int	*ft_split_arg(int argc, char **argv, t_ps *ps)
{
	int		idx;
	int		idx2;
	int		*res;
	int		res_idx;
	char	**str;

	res = (int *)malloc(sizeof(int) * ps->arg_cnt);
	if (!res)
		ft_error(1);
	res_idx = 0;
	idx = 1;
	while (idx < argc)
	{
		str = ft_split(argv[idx], ' ');
		idx2 = 0;
		while (str[idx2])
		{
			res[res_idx] = ft_atoll(str[idx2]);
			res_idx++;
			idx2++;
		}
		idx++;
	}
	return (res);
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

int	main(int argc, char **argv)
{
	t_ps	*ps;
	int		*arg;

	ps = ft_init();
	ft_cnt_num(argc, argv, ps);
	printf("%lld\n", ps->arg_cnt);
	arg = ft_split_arg(argc, argv, ps);
	int idx = 0;
	while (idx < ps->arg_cnt)
		printf("%d\n", arg[idx++]);
	return (0);
}
