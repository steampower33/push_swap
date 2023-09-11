/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:47:39 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/11 19:35:04 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*ft_init(void)
{
	t_ps	*ps;

	ps = (t_ps *)malloc(sizeof(t_ps));
	if (!ps)
		ft_error(1);
	ps->a = (t_stack *)malloc(sizeof(t_stack));
	ps->b = (t_stack *)malloc(sizeof(t_stack));
	if (!ps->a || !ps->b)
		ft_error(1);
	ps->arg_cnt = 0;
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
	unsigned int	idx;
	unsigned int	idx2;
	unsigned int	cnt;

	cnt = 1;
	idx = 0;
	while (idx < ps->arg_cnt)
	{
		idx2 = idx + 1;
		while (idx2 < ps->arg_cnt)
		{
			if (ps->arg[idx] == ps->arg[idx2])
				ft_error(1);
			if (idx == 0 && ps->arg[idx2 - 1] < ps->arg[idx2])
				cnt++;
			idx2++;
		}
		if (idx == 0 && cnt == ps->arg_cnt)
			exit(0);
		idx++;
	}
}

void	p(t_stack *s)
{
	unsigned int	idx;
	t_node			*n;

	idx = 0;
	n = s->top;
	while (idx < s->cnt)
	{
		printf("%d ", n->data);
		n = n->next;
		idx++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_ps	*ps;

	ps = ft_init();
	ft_cnt_num(argc, argv, ps);
	if (ps->arg_cnt <= 1)
		ft_error(1);
	ft_split_arg(argc, argv, ps);
	ft_chk_arg(ps);
	ft_set_stack(ps);
	p(ps->a);
	t_node *s = ft_deque(ps->a, FRONT);
	printf("deque => %d\n", s->data);
	p(ps->a);
	ft_enque(ps->a, FRONT, s);
	p(ps->a);
	return (0);
}
