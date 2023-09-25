/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:47:39 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/25 16:04:29 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc == 1)
		return (0);
	ps = ft_init();
	ft_cnt_num(argc, argv, ps);
	if (ps->arg_cnt <= 1)
		ft_error(1);
	ft_split_arg(argc, argv, ps);
	ft_chk_arg(ps);
	ft_set_stack(ps);
	if (ps->a->cnt == 2)
	{
		if (ps->a->top->data > ps->a->top->next->data)
			ft_cmd_center(ps, "sa");
	}
	else if (ps->arg_cnt == 3)
		ft_sort_three(ps);
	else if (3 <= ps->arg_cnt && ps->arg_cnt <= 5)
		ft_sort_five(ps);
	else
		ft_sort(ps);
	return (0);
}
