/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:10:34 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/25 21:16:33 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_error(int code)
{
	write(2, "Error\n", 6);
	exit(code);
}
