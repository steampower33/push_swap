/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:47:55 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/05 15:37:14 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_l {
	int			data;
	struct s_l	*next;
}	t_l;

typedef struct s_ps {
	t_l		*s_a;
	t_l		*s_b;
}	t_ps;

#endif