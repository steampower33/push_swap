/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:47:39 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/26 22:31:50 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc == 1)
		return (0);
	ps = ft_init();
	ft_cnt_num(argc, argv, ps);
	ft_split_arg(argc, argv, ps);
	if (ps->arg_cnt == 0)
		ft_error(1);
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
	// ft_all_free(ps);
	// system("leaks push_swap");
	return (0);
}
