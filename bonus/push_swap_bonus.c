/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:42:25 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/25 22:00:02 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	ft_chk_sort(t_ps *ps)
{
	t_node	*a;

	a = ps->a->top;
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
	if (ps->arg_cnt <= 1)
		ft_error(1);
	ft_split_arg(argc, argv, ps);
	ft_chk_arg(ps);
	ft_set_stack(ps);
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		ft_cmd_center(ps, line);
	}
	ft_chk_sort(ps);
}
