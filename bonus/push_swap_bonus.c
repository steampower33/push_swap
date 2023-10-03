/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:42:25 by seunlee2          #+#    #+#             */
/*   Updated: 2023/10/03 18:46:40 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_chk_sort(t_ps *ps)
{
	t_node	*a;

	a = ps->a->top;
	if (a == NULL)
	{
		ft_printf("KO\n");
		return ;
	}
	while (a->next)
	{
		if (a->data >= a->next->data)
		{
			ft_printf("KO\n");
			return ;
		}
		a = a->next;
	}
	if (ps->b->cnt != 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

int	main(int argc, char **argv)
{
	t_ps	*ps;
	char	*line;

	if (argc == 1)
		return (0);
	ps = ft_init();
	ft_cnt_num(argc, argv, ps);
	ft_split_arg(argc, argv, ps);
	if (ps->arg_cnt == 0)
		ft_error(1);
	ft_chk_arg(ps);
	ft_set_stack(ps);
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		ft_cmd_center(ps, line);
		free(line);
	}
	ft_chk_sort(ps);
	ft_all_free(ps);
}
