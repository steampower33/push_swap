/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:47:55 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/06 19:09:46 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_l {
	int			data;
	struct s_l	*next;
}	t_l;

typedef struct s_ps {
	struct s_l	*s_a;
	struct s_l	*s_b;
	long long	arg_cnt;			
}	t_ps;

void		ft_error(int code);
long long	ft_atoll(const char *str);

#endif