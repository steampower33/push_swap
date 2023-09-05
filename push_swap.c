/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:47:39 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/05 15:35:58 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int code)
{
	write(2, "Error\n", 6);
	exit(code);
}

int	ft_chk_arg(t_ps *ps, int argc, char **argv)
{

}

int	main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc < 2)
		ft_error(1);
	ps = (t_ps *)malloc(sizeof(t_ps));
	if (!ps)
		ft_error(1);
	ft_chk_arg(ps, argc, argv);
	return (0);
}
