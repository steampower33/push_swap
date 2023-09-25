/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:13:48 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/25 21:16:44 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_isspace(const char *str, int len)
{
	while (str[len])
	{
		if (!(str[len] == '\t' || str[len] == '\n' || str[len] == '\v'
				|| str[len] == '\f' || str[len] == '\r' || str[len] == ' '))
			break ;
		len++;
	}
	return (len);
}

static int	ft_issign(const char *str, int str_len, int *minus)
{
	int	sign_cnt;

	sign_cnt = 0;
	*minus = 1;
	while (str[str_len])
	{
		if (sign_cnt > 1)
			return (-1);
		if (str[str_len] == '-')
		{
			*minus = -1;
			sign_cnt++;
		}
		else if (str[str_len] == '+')
			sign_cnt++;
		else
			break ;
		str_len++;
	}
	return (str_len);
}

long long	ft_atoll(const char *str)
{
	long long	res;
	int			minus;
	int			idx;

	idx = ft_isspace(str, 0);
	idx = ft_issign(str, idx, &minus);
	if (idx == -1)
		ft_error(1);
	res = 0;
	while (str[idx])
	{
		if (!ft_isdigit(str[idx]))
			ft_error(1);
		res = res * 10 + (str[idx] - '0');
		idx++;
	}
	res *= minus;
	if (res > 2147483647 || res < -2147483648)
		ft_error(1);
	return (res);
}
